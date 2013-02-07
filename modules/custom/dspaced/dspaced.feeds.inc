<?php

/**
 * @file
 * Feeds hooks and helper methods for the DSpaced module.
 */

// Delta values for failed ping responses.
define('DSPACED_PING_MISSING_REST_BASEURL', 1);
define('DSPACED_PING_REQUEST_ERROR', 2);
define('DSPACED_PING_RESPONSE_ERROR', 3);

/**
 * Implements hook_feeds_presave().
 */
function dspaced_feeds_presave(FeedsSource $source, $entity) {
  if ($entity->type == 'dspaced_entities_community' &&
      $entity->feeds_item->id == 'dspaced_communities') {
    // Don't create community nodes from dspaced_communities import.
    $entity->feeds_item->skip = TRUE;
  }
  elseif (in_array($entity->type, array('dspaced_entities_item',
                                        'dspaced_entities_community'))) {
    _dspaced_feeds_source_alter($entity);
    if ($entity->type == 'dspaced_entities_item' &&
        $entity->feeds_item->id == 'dspaced_item') {
      _dspaced_dspace_bitstream_url_alter($entity);
    }
  }
}

/**
 * Implements hook_feeds_after_import().
 */
function dspaced_feeds_after_import($source) {
  if ($source->importer->id == 'dspaced_community' &&
      $source->state['process']->created) {
    // @note When we first import a community it creates a dspace_harvest job
    //   but doesn't trigger it. It sets the next schedule to be sometime in
    //   the future i.e. whenever the periodic import time to wait is set to.
    //   So here we trigger the harvest manually after a community node is first
    //   created rather than wait for the next execution time which could be
    //   tomorrow.
    $config = $source->getConfig();
    $dspace_entity_id = str_replace('.xml', '', basename($config['FeedsHTTPFetcher']['source']));
    if ($community_node_nid = _dspaced_find_community_node($dspace_entity_id, TRUE)) {
      _dspaced_import_community_items($community_node_nid);
    }
    // @todo Getting the nid in this way is a bit of a hack. Also this manual
    //   trigger only solves triggering the harvest, we have the same problem
    //   for each individual dspace_item import, i.e. after items are harvested
    //   we have to wait until the next scheduled execution for the full item
    //   data to be imported. So how else could we do this?
  }
}

/**
 * Implements hook_feeds_after_clear().
 */
function dspaced_feeds_after_clear($source) {
  // Delete deselected community nodes, once their items have been cleared.
  // @see _dspaced_clear_community().
  $selected_community_dspace_entity_ids = _dspaced_selected_community_dspace_entity_ids();
  if ($nid = $source->feed_nid) {
    if (($node = node_load($nid)) && $node->type == 'dspaced_entities_community') {
      $dspace_entity_id = _dspaced_get_dspace_entity_id($node);
      if (!in_array($dspace_entity_id, $selected_community_dspace_entity_ids)) {
        node_delete($nid);
      }
    }
  }
}

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 */
function dspaced_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    if ($name == 'body' || $name == 'dspace_pdf_text') {
      // Set callback for altering the body field content from XHTML bitstream
      // URL to the actual content of the bitstream.
      $callback = '_dspaced_bitstream_get_contents_set_target';
    }
    else {
      $info = field_info_field($name);
      switch ($info['type']) {
        case 'image':
          // Set callback for altering image field from bitstream URL to local
          // file.
          $callback = '_dspaced_image_set_target';
          break;
        case 'date':
          // Set callback for checking date field is in an accepted ISO format
          // before inserting into :start or :end subfields
          $callback = '_dspaced_date_set_target';
          break;
      }
    }

    // Assign callbacks for altering the content and/or target field:subfield.
    if (isset($callback) && $callback) {
      $targets[$name . ':dspaced'] = array(
        'name' => 'DSpaced ' . check_plain($instance['label']),
        'callback' => $callback,
        'description' => t('The DSpaced @label field of the node.',
                           array('@label' => $instance['label'])),
        'real_target' => $name,
      );
    }
    unset($callback);
  }
}

/**
 * Set custom bitstream contents field target for :dspaced suffix.
 *
 * Callback for dspaced_feeds_processor_targets_alter().
 *
 * In default dspaced_item Feeds importer the body field target is set to a
 * conditional xpath of a bitstream URL e.g. to the first bitstream URL with
 * mimeType text/xhtml or application/octet-stream with file extension .xhtml,
 * and the dspace_pdf_text field is set to the first bitstream with mimeType
 * text/plain with file extension .pdf.txt.
 *
 * The following callback replaces the parsed value (the bistream URL) with the
 * actual contents of the bitstream.
 *
 * @note Based on files_feeds_set_target and link_feeds_set_target from
 *   Feeds 7.x-2.0-alpha6. Check for modifications whenever Feeds module is
 *   upgraded.
 *
 * @see _dspaced_item_feeds_importer()
 * @see hook_feeds_processor_target_alter()
 * @see file_feeds_set_target()
 * @see link_feeds_set_target()
 *
 */
function _dspaced_bitstream_get_contents_set_target($source, $entity, $target, $value) {

  if (empty($value)) {
    return;
  }

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = array($value);
  }
  // Make sure each url is absolute and is a FeedsEnclosure instance
  foreach ($value as $k => $v) {
    // @todo: test what happens if $v is already an instance of FeedsEnclosure?
    if (!($v instanceof FeedsEnclosure)) {
      if (is_string($v)) {
        $v = _dspaced_build_bitstream_absolute_url($entity, $v);
        $value[$k] = new FeedsEnclosure($v, file_get_mimetype($v));
      }
      else {
        unset($value[$k]);
      }
    }
  }
  if (empty($value)) {
    return;
  }

  list($field_name, $custom_suffix) = explode(':', $target, 2);
  $info = field_info_field($field_name);
  // Iterate over all values and populate entity.
  $field = isset($entity->$field_name) ? $entity->$field_name : array();
  $i = 0;
  foreach ($value as $v) {
    if ($info['cardinality'] == $i) {
      break;
    }
    $field_value = '';
    try {
      if (($content = $v->getContent()) && ($mime_type = $v->getMimeType())) {
        switch ($mime_type) {
          // @todo Check if we've covered all the relevant mime types
          case 'application/xhtml+xml':
            $xhtml = simplexml_load_string($content);
            if ($xhtml && !preg_match('/not found/', $xhtml->head->title)) {
              $field_value = check_markup((string) $xhtml->body->asXML(), 'full_html');
              if ($field_value) {
                $field['und'][$i] = array(
                  'value' => trim($field_value),
                  'format' => 'full_html',
                );
                $i++;
              }
            }
            break;
          case 'text/plain':
            // Applies to pdf.txt files
            // @see default _dspaced_item_feeds_importer() definition
            $field_value = check_plain($content);
            if ($field_value) {
              $field['und'][$i] = array(
                'value' => trim($field_value),
              );
              $i++;
            }
            break;
        }
      }
    }
    catch (Exception $e) {
      watchdog_exception('Feeds', $e, nl2br(check_plain($e)));
    }
  }
  $entity->$field_name = $field;

}

/**
 * Set custom image field target for :dspaced suffix.
 *
 * Callback for dspaced_feeds_processor_targets_alter().
 *
 * @note Based on files_feeds_set_target and link_feeds_set_target from
 *   Feeds 7.x-2.0-alpha6. Check for modifications whenever Feeds module is
 *   upgraded.
 *
 * @see hook_feeds_processor_target_alter()
 * @see file_feeds_set_target()
 * @see link_feeds_set_target()
 */
function _dspaced_image_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }

  // Handle non-multiple value fields.
  if (!is_array($value)) {
    $value = array($value);
  }

  // Make sure each url is absolute and is a FeedsEnclosure instance
  foreach ($value as $k => $v) {
    // @todo: test what happens if $v is already an instance of FeedsEnclosure?
    if (!($v instanceof FeedsEnclosure)) {
      if (is_string($v)) {
        $v = _dspaced_build_bitstream_absolute_url($entity, $v);
        $value[$k] = new FeedsEnclosure($v, file_get_mimetype($v));
      }
      else {
        unset($value[$k]);
      }
    }
  }
  if (empty($value)) {
    return;
  }

  // Determine file destination.
  list($field_name, $custom_suffix) = explode(':', $target, 2);
  list($entity_id, $vid, $bundle_name) = entity_extract_ids($entity->feeds_item->entity_type, $entity);
  $instance_info = field_info_instance($entity->feeds_item->entity_type, $field_name, $bundle_name);
  $info = field_info_field($field_name);
  $data = array();
  if (!empty($entity->uid)) {
    $data[$entity->feeds_item->entity_type] = $entity;
  }
  $destination = file_field_widget_uri($info, $instance_info, $data);

  // Iterate over all values and populate entity.
  $field = isset($entity->$field_name) ? $entity->$field_name : array();
  $i = 0;
  foreach ($value as $v) {
    if ($info['cardinality'] == $i) {
      break;
    }
    try {
      $file = $v->getFile($destination, FILE_EXISTS_REPLACE);
    }
    catch (Exception $e) {
      watchdog_exception('Feeds', $e, nl2br(check_plain($e)));
    }
    if (isset($file) && $file) {
      $field['und'][$i] = (array)$file;
      $field['und'][$i]['display'] = 1;
      $i++;
    }
  }
  $entity->$field_name = $field;
}

/**
 * Check, parse and convert date values as needed prior to switching target to
 * :start or :end date subfields.
 *
 * Callback for dspaced_feeds_processor_targets_alter().
 *
 * @note Assumes desired format is ISO 8601:2004 for Date field type date which
 *       requires partial dates to be padded with zeros.
 *
 * @see http://drupal.org/node/1326872
 *
 * @see hook_feeds_processor_target_alter()
 * @see date_feeds_set_target()
 */
function _dspaced_date_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }

  list($field_name, $custom_suffix) = explode(':', $target, 2);

  // @todo Do we need this? When would it be an instanceof FeedsDateTimeElement?
  if ($value instanceof FeedsDateTimeElement) {
    $value->buildDateField($entity, $field_name);
    return;
  }

  // Parse string and convert to FeedsDateTimeElement
  $info = field_info_field($field_name);
  // Find the field or default Drupal timezone and set as default for dates with
  // missing timezones.
  $default_timezone = new DateTimeZone(date_get_timezone($info['settings']['tz_handling'], date_default_timezone()));
  date_default_timezone_set($default_timezone->getName());
  $input_format = $info['widget']['settings']['input_format_custom'];
  $field = isset($entity->$field_name) ? $entity->$field_name : array();
  $i = 0;
  if (!is_array($value)) {
    $value = array($value);
  }
  foreach ($value as $v) {
    if ($info['cardinality'] == $i) {
      break;
    }
    try {
      if (($datetimes = _dspaced_parse_date($v, $field_name, $entity)) && $datetimes['start']) {
        // Convert dates to field or default Drupal timezone before adding to field
        foreach ($datetimes as $k => $datetime) {
          if ($datetime) $datetimes[$k]->setTimezone($default_timezone);
        }
        $field['und'][$i]['timezone'] = $default_timezone->getName();
        $field['und'][$i]['offset'] = $datetimes['start']->getOffset();
        $field['und'][$i]['date'] = $datetimes['start'];
        $field['und'][$i]['value'] = $datetimes['start']->format($input_format);
        if ($datetimes['end']) {
          $field['und'][$i]['value2'] = $datetimes['end']->format($input_format);
          // We have artificially created start and end datetimes from partial
          // strings, e.g. YY-MM-DD has become YY-MM-DDT00:00:00/YY-MM-DDT23:59:59.
          // However, if the granularity of the field is only YY-MM-DD then our
          // magic is redundant and we'll have ended up with start and end values
          // that are the same. So we do a quick check for that here and remove
          // redundant end values.
          if ($field['und'][$i]['value2'] == $field['und'][$i]['value']) {
            unset($field['und'][$i]['value2']);
          }
          else {
            $field['und'][$i]['date2'] = $datetimes['end'];
          }
        }
        unset($datetimes);
        $i++;
      }
    }
    catch (Exception $e) {
      watchdog_exception('Feeds', $e, nl2br(check_plain($e)));
    }
  }
  $entity->$field_name = $field;
}

/**
 * Helper function to parse date strings from DSpace and convert into complete
 * ISO 8601 format, and to range if partial dates provided.
 *
 * @param String $date
 *   Assumes date string in one of the following ISO 8601 formats (DATE_W3C)
 *   and may be partial (i.e. parts starting from right to left may be missing,
 *   minimum is [Y] indicating a millenium):
 *     YYYY-MM-DDThh:mm:ssZ
 *     YYYY-MM-DDThh:mm:ss-hh:mm
 *     YYYY-MM-DDThh:mm:ss+hh:mm
 *   Assumes intervals (intervening time between two time points) are
 *   represented by a [/] separator
 *   (e.g. YYYY-MM-DDThh:mm:ssZ/YYYY-MM-DDThh:mm:ssZ). If time zone is not
 *   included we assume UTC.
 *   Assumes intervals are in CAL_GREGORIAN.
 *
 * @return Array
 *   Dates in ISO format as array of subfields with keys start and end.
 *
 * @note Does not currently support other ISO 8601 formats or other date strings
 *       and since DSpace dates can be user entered this means some dates may be
 *       ignored and not imported. Does not solve the issue of uncertainty e.g.
 *       "Probably after 1928" however since partial iso regex can appear
 *       anywhere in the string it should pick up the year from "Probably after
 *       1928".
 *
 * @todo Figure out how to handle uncertainty in dates e.g. "Probably after 1928".
 */
function _dspaced_parse_date($date, $field_name, $entity) {

  // Expects ISO intervals as expressed by / separator.
  $points = array_filter(explode('/', trim($date)), '_dspaced_parse_date_filter');

  // More than two interval points indicates $date is not in expected ISO format
  if (!$points || count($points) > 2) return NULL;

  $complete_iso_regex = '/(\d{4})-(\d{2})-(\d{2})T(\d{2}):(\d{2}):(\d{2})(Z|[-+]\d{2}:\d{2})/';
  $partial_iso_regex = '/(\d{1,4})-?(\d{0,2})-?(\d{0,2})T?(\d{0,2}):?(\d{0,2}):?(\d{0,2})(Z|[-+]\d{2}:\d{2}|[-+]\d{2})?/';

  $iso_dates = array();
  foreach ($points as $point) {
    if (preg_match($complete_iso_regex, $point)) {
      // DSpace interval point is already in complete ISO format.
      $iso_dates[] = $point;
      continue;
    }

    if (preg_match($partial_iso_regex, $point, $match)) {
      // DSpace interval point has partially matched ISO format.
      // 1 => Millenium [Y], Century [YY], Decade [YYY], Year [YYYY]
      // 2 => Month
      // 3 => Day
      // 4 => Hour
      // 5 => Minutes
      // 6 => Seconds
      // 7 => Timezone or difference from UTC

      $match = array_pad($match, 8, NULL);
      $partial = $match;
      $match[1] = str_pad($match[1], 4, '#');
      for ($i = 2; $i <= 6; $i++) {
        $match[$i] = str_pad($match[$i], 2, '#');
      }

      // Create range values based on position of first missing value
      // @note We don't care about validation at this point, we'll check the
      //       dates later.
      $pos = strpos("{$match[1]}-{$match[2]}-{$match[3]}T{$match[4]}:{$match[5]}:{$match[6]}", '#');
      switch ($pos) {
        case '1': // Millenium Y#
        case '2': // Century YY#
        case '3': // Decade YYY#
        case '5': // Year YYYY-#
          $iso_dates[] = str_pad($partial[1], 4, '0') . '-01-01T00:00:00';
          $iso_dates[] = str_pad($partial[1], 4, '9') . '-12-31T23:59:59';
          break;
        case '6': // Month range YYYY-M# (not iso 8601 but assume range intended)
          switch ($partial[2]) {
            case '0':
              $start_month = '01';
              $end_month = '09';
              break;
            case '1':
              $start_month = '10';
              $end_month = '12';
              break;
          }
          if ($start_month) {
            $iso_dates[] = "{$partial[1]}-{$start_month}-01T00:00:00";
          }

          if ($end_month && ($days_in_month = cal_days_in_month(CAL_GREGORIAN, $end_month, $partial[1]))) {
            $iso_dates[] = "{$partial[1]}-{$end_month}-{$days_in_month}T23:59:59";
          }
          elseif ($start_month && ($days_in_month = cal_days_in_month(CAL_GREGORIAN, $start_month, $partial[1]))) {
            $iso_dates[] = "{$partial[1]}-{$start_month}-{$days_in_month}T23:59:59";
          }
          unset($start_month);
          unset($end_month);
          unset($days_in_month);
          break;
        case '8': // Month YYYY-MM-#
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-01T00:00:00";
          if ($days_in_month = cal_days_in_month(CAL_GREGORIAN, $partial[2], $partial[1])) {
            $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$days_in_month}T23:59:59";
          }
          unset($days_in_month);
          break;
        case '9': // Day range YYYY-MM-D# (not iso 8601 but assume range intended)
          if ($days_in_month = cal_days_in_month(CAL_GREGORIAN, $partial[2], $partial[1])) {
            switch ($partial[3]) {
              case '0':
                $start_day = '01';
                $end_day = '09';
                break;
              case '1':
              case '2':
              case '3':
                $start_day = "{$partial[3]}0";
                $end_day = "{$partial[3]}9";
                break;
            }
            if ($start_day > $days_in_month) $start_day = $days_in_month;
            if ($end_day > $days_in_month) $end_day = $days_in_month;

            if ($start_day) $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$start_day}T00:00:00";
            if ($end_day) $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$end_day}T23:59:59";

            unset($start_day);
            unset($end_day);
          }
          unset($days_in_month);
          break;
        case '11': // Day YYYY-MM-DDT#
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T00:00:00";
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T23:59:59";
          break;
        case '12': // Hour range YYYY-MM-DDTh# (not iso 8601 but assume range intended)
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}0:00:00";
          $end_hour = (intval("{$partial[4]}9") > 23) ? '23' : "{$partial[4]}9";
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$end_hour}:59:59";
          unset($end_hour);
          break;
        case '14': // Hour YYYY-MM-DDThh:#
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:00:00";
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:59:59";
          break;
        case '15': // Minute range YYYY-MM-DDThh:m# (not iso 8601 but assume range intended)
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:{$partial[5]}0:00";
          $end_minute = (intval("{$partial[5]}9") > 59) ? '59' : "{$partial[5]}9";
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:{$end_minute}:59";
          unset($end_minute);
          break;
        case '17': // Minute YYYY-MM-DDThh:mm:#
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:{$partial[5]}:00";
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:{$partial[5]}:59";
          break;
        case '18': // Second range YYYY-MM-DDThh:mm:s# (not iso 8601 but assume range intended)
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:{$partial[5]}:{$partial[6]}0";
          $end_second = (intval("{$partial[6]}9") > 59) ? '59' : "{$partial[6]}9";
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:{$partial[5]}:{$end_second}";
          unset($end_second);
          break;
        case '19': // Second YYYY-MM-DDThh:mm:ss# (just missing TimeZone assume UTC)
          $iso_dates[] = "{$partial[1]}-{$partial[2]}-{$partial[3]}T{$partial[4]}:{$partial[5]}:{$partial[6]}";
          break;
      }
      unset($partial);
      unset($pos);
      unset($match);
    }
  }

  $datetimes = array();
  foreach ($iso_dates as $i => $iso_date) {
    // Check and ignore invalid dates
    list($date, $time) = explode('T', $iso_date);
    list($year, $month, $day) = explode('-', $date);
    if (!checkdate($month, $day, $year)) {
      // @todo: Add entity type and id to watchdog message:
      watchdog('dspaced', 'Invalid date @iso_date parsed from DSpace field !field_name. Date value has been removed.',
        array('@iso_date' => $iso_date, '!field_name' => $field_name), WATCHDOG_WARNING);
      continue;
    }

    // We have a valid date so replace Z with difference from UTC
    if (substr($iso_date, -1) == 'Z') $iso_date = str_replace('Z', '+00:00', $iso_date);
    // @note If time values are larger than expected then when Date object is
    //       created the date will be adjusted e.g. hours value of 70 would move
    //       date forward a couple of days. We could make an assumption here
    //       and try to correct it... but instead lets just let it happen. If
    //       our code is right then it would be a data entry error and therefore
    //       should be corrected in DSpace not here.
    // list($hours, $minutes, $seconds) = explode(':', substr($time, 0, 8));
    if (($datetime = DateTime::createFromFormat(DATE_W3C, $iso_date)) ||
    ($datetime = DateTime::createFromFormat('Y-m-d\TH:i:s', $iso_date))) {
      $datetimes[] = $datetime;
    }
  }

  asort($datetimes);
  $start = array_shift($datetimes);
  $end = array_pop($datetimes);

  return array('start' => $start, 'end' => $end);

}

/**
 * Helper callback function for array_filter to determine whether to keep or
 * discard interval points from parsed ISO date string.
 *
 * @param String $interval_point
 *   Expected to be full or partial ISO 8601 date string.
 *
 * @return Boolean
 *   True if interval_point should be kept. False if interval point should be
 *   discarded.
 *
 * @note Using custom callback rather than default array_filter callback in
 *   order to preserve point values of '0'.
 *
 * @see http://php.net/manual/en/function.array-filter.php
 *
 */
function _dspaced_parse_date_filter($interval_point) {
  return ($interval_point === '0' || $interval_point);
}

/**
 * Helper function to alter Feeds source URL before entity is saved.
 *
 * @see dspaced_feeds_presave()
 *
 * @param Object $node
 *   Drupal entity containing feeds property that needs to be altered.
 *
 * @return NULL
 *   Entity is modified by reference.
 */
function _dspaced_feeds_source_alter($entity) {
  if (array_key_exists('FeedsHTTPFetcher', $entity->feeds)) {
    $entity->feeds['FeedsHTTPFetcher']['source'] =
      _dspaced_repository_rest_baseurl() .
      $entity->feeds['FeedsHTTPFetcher']['source'];
  }
}

/**
 * Helper function to alter DSpace bitstream URL before entity is saved.
 *
 * @see dspaced_feeds_presave()
 *
 * @param Object $node
 *   Drupal entity containing feeds property that needs to be altered.
 * @return NULL
 *   Entity is modified by reference.
 */
function _dspaced_dspace_bitstream_url_alter($entity) {
  foreach ($entity->dspace_bitstream_url as $lang => $urls) {
    foreach ($urls as $i => $url) {
      $entity->dspace_bitstream_url[$lang][$i]['url'] =
        _dspaced_build_bitstream_absolute_url($entity, $url['url']);
    }
  }
}

/**
 * Helper function to build an absolute URL for a bistream.
 *
 * @param object $entity
 *   Standard class containing entity data, must include field name
 *   dspace_handle.
 * @param string $file_name
 *   The file name of the bitstream.
 * @return string
 *   Absolute URL to an item's bitstream in DSpace.
 */
function _dspaced_build_bitstream_absolute_url($entity, $file_name) {

  if (parse_url($file_name, PHP_URL_SCHEME)) return $file_name;
  return _dspaced_repository_bitstream_baseurl() .
         _dspaced_get_dspace_handle($entity) . '/' .
         $file_name;
}

/**
 * Helper method to return the base URL of a repository bitstream.
 *
 * @return string
 *   Base URL for a DSpace bitstream.
 */
function _dspaced_repository_bitstream_baseurl() {
  $dspaced_repository_bitstream_baseurl = &drupal_static(__FUNCTION__);
  if (!isset($dspaced_repository_bitstream_baseurl)) {
    $parsed_url = parse_url(_dspaced_repository_rest_baseurl());
    $parsed_url['path'] = '/bitstream/handle/';
    $dspaced_repository_bitstream_baseurl = _dspaced_unparse_url($parsed_url);
  }
  return $dspaced_repository_bitstream_baseurl;
}

/**
 * Helper function to unparse an array of URL parts.
 *
 * @param array $parsed_url
 *   A URL that has been parsed using parse_url.
 * @return string
 *   A URL imploded from the given array.
 */
function _dspaced_unparse_url($parsed_url) {
  foreach (array('scheme', 'user', 'pass', 'host', 'port', 'path', 'query', 'fragment') as $part) {
    ${$part} = isset($parsed_url[$part]) ? $parsed_url[$part] : '';
    if (${$part}) {
      switch ($part) {
        case 'scheme':
          ${$part} .= '://';
          break;
        case 'port':
        case 'pass':
          ${$part} = ':' . ${$part};
          break;
        case 'query':
          ${$part} = '?' . ${$part};
          break;
        case 'fragment':
          ${$part} = '#' . ${$part};
          break;
      }
    }
  }
  if ($user || $pass) $pass .= '@';
  return $scheme . $user . $pass . $host . $port . $path . $query . $fragment;
}

/**
 * Helper function to ping and check availability of repository.
 *
 * @note REST API doesn't have a decent ping option so we go ahead and import
 * communities since that's the most likely data we'll need next.
 *
 * @return array|int
 *   Available communities with Dspace community entity IDs as key and community
 *   name as value, or an integer indicating an unsuccessful ping.
 */
function _dspaced_ping_repository() {
  if (!($rest_baseurl = _dspaced_repository_rest_baseurl())) {
    return DSPACED_PING_MISSING_REST_BASEURL;
  }
  try {
    $communities = _dspaced_fetch_communities();
  }
  catch (Exception $e) {
    error_log($e); // Log error to default operating system error logs.
    if (preg_match('/^Download of.*?501./', $e->getMessage())) {
      return DSPACED_PING_REQUEST_ERROR;
    }
    else {
      return DSPACED_PING_RESPONSE_ERROR;
    }
  }
  return $communities;
}

/**
 * Helper function to fetch communities from DSpace.
 *
 * @return array
 *   Available communities with Dspace community entity IDs as key and community
 *   name as value.
 */
function _dspaced_fetch_communities() {
  $source = feeds_source('dspaced_communities');
  $source->addConfig(array(
    'FeedsHTTPFetcher' => array(
      'source' => _dspaced_repository_rest_baseurl() . '/communities.xml',
    ),
  ));
  $source->save();
  $items = $source->preview()->items;
  $communities = array();
  foreach ($items as $item) {
    // @todo more intelligent selection of xpathparser keys
    $communities[$item['xpathparser:0']] = $item['xpathparser:1'];
  }
  return $communities;
}

/**
 * Helper function to return DSpace handle from node.
 *
 * @param object $node
 *   Node object containing handle field.
 * @return string
 *   DSpace handle value.
 */
function _dspaced_get_dspace_handle($node) {
  return _dspaced_get_raw_field_value($node, 'dspace_handle');
}
/**
 * Helper function to return a DSpace entityId from node.
 *
 * @param object $node
 *   Node object containing dspace entity id field.
 * @return int
 *   DSpace entity ID value.
 */
function _dspaced_get_dspace_entity_id($node) {
  return _dspaced_get_raw_field_value($node, 'dspace_entity_id');
}
/**
 * Helper function to return a single value field from a node.
 *
 * @param object $node
 *   Node object containing field to get value from.
 * @param string $field_name
 *   The machine name of the field to get the value from.
 * @return mixed
 *   The field's first value. Assumes field has cardinality == 1.
 *   @todo we could check cardinality and adjust the return appropriately.
 */
function _dspaced_get_raw_field_value($node, $field_name) {
  $field_value = field_get_items('node', $node, $field_name);
  if (is_array($field_value)) {
    $field_value = $field_value[0]['value'];
  }
  return $field_value;
}

/**
 * Helper function to import multiple communities.
 *
 * @param array $community_dspace_entity_ids
 *   DSpace entity IDs of communities to be imported.
 *
 * @note It doesn't do much but makes it consistent with clearing which
 * benefits from having two methods for clearing one versus multiple communities
 * at a time.
 */
function _dspaced_import_communities($community_dspace_entity_ids) {
  foreach ($community_dspace_entity_ids as $id) {
    _dspaced_import_community($id);
  }
}

/**
 * Helper function to import a DSpace community.
 *
 * @param int $community_dspace_entity_id
 *   The DSpace entity ID of a community to be imported. Inserted into
 *   FeedsHTTPFetcher source URL /communities/{$community_dspace_entity_id}.xml
 * @return null
 *   Triggers the start of a community import, does not return anything.
 *
 * @note A community import is triggered on submit of the DSpace system settings
 * form for each selected community.
 */
function _dspaced_import_community($community_dspace_entity_id) {
  $source = feeds_source('dspaced_community');
  $source->addConfig(array(
    'FeedsHTTPFetcher' => array(
      'source' => _dspaced_repository_rest_baseurl() .
                  "/communities/{$community_dspace_entity_id}.xml",
    ),
  ));
  $source->save();
  $source->startImport();
}

/**
 * Helper function to delete multiple community nodes and all their items.
 *
 * @param array $community_dspace_entity_ids
 *   DSpace entity IDs of communities to be deleted and cleared of their
 *   imported items. Used to find the community nodes.
 */
function _dspaced_clear_communities($community_dspace_entity_ids) {
  $nodes = _dspaced_find_community_nodes($community_dspace_entity_ids);
  foreach ($nodes as $node) {
    _dspaced_clear_community($node);
  }
}

/**
 * Helper function to delete community node and all its items.
 *
 * @param object $community_node
 *   The community node to be deleted and cleared of it's imported items.
 * @return null
 *   Triggers the start of a community clearance, does not return anything.
 *
 * @note A community clearance is triggered on submit of the DSpace system
 * settings form for each deselected community. If the community has items to
 * clear then the community node will not be deleted at this time, instead it
 * will be deleted with hook_feeds_after_clear().
 * @see dspaced_feeds_after_clear()
 */
function _dspaced_clear_community($community_node) {
  $importer_id = feeds_get_importer_id($community_node->type);
  $source = feeds_source($importer_id, $community_node->nid);
  if ($source->itemCount()) {
    // Clear community items.
    $source->startClear();
    // Creates a single job schedule to clear all harvest items in batches.
    // First batch is deleted immediately.
    // Once all items have been deleted the community node will be deleted.
    // @see hook_feeds_after_clear().
    drupal_set_message(
      t("@community_title community and it's items have " .
        "been scheduled for deletion. If background processing is set then " .
        "items will be deleted in batches on cron. Depending on the number " .
        "of items and the frequency of the cron schedule, it could therefore " .
        "take a few minutes or a few hours to remove all items. You can " .
        "monitor progress of the deletion on the " .
        "<a href=\"!community_delete_items_url\">community's delete items page</a>.",
        array(
          '@community_title' => $community_node->title,
          '!community_delete_items_url' => url("node/{$community_node->nid}/delete-items"),
        )
      ),
      'status',
      FALSE
    );
  }
  else {
    // No items to clear so delete node.
    node_delete($community_node->nid);
    drupal_set_message(t("@community_title community has been deleted. It did " .
      "not have any imported items.", array('@community_title' => $community_node->title)));
  }
}

/**
 * Import community items, dspace entity id only.
 *
 * @param int $community_nid
 *   ID of the community node to import items for.
 *
 * @return null
 *   Schedules an import, doesn not return anything.
 *
 * @note This triggers a dspaced_harvest import for a community node. Normally
 * harvests are triggered by cron but we also want to trigger it right after a
 * community import. Community imports only happen when the DSpaced system
 * settings form is submitted so this won't get called very often.
 */
function _dspaced_import_community_items($community_nid) {
  $source = feeds_source('dspaced_harvest', $community_nid);
  $source->startImport();
}
