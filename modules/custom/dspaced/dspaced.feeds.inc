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
    // Add custom target for downloading XHTML
    // @see _dspaced_bitstream_get_contents_set_target
    if ($name == 'body' || $name == 'dspace_pdf_text') {
      $targets[$name . ':dspaced'] = array(
        'name' => 'DSpaced ' . check_plain($instance['label']),
        'callback' => '_dspaced_bitstream_get_contents_set_target',
        'description' => t('The DSpaced @label field of the node.',
                           array('@label' => $instance['label'])),
        'real_target' => $name,
      );
      continue;
    }
    $info = field_info_field($name);
    if ($info['type'] == 'image') {
      // Add a custom target for downloading still images.
      // @see _dspaced_image_set_target
      $targets[$name . ':dspaced'] = array(
        'name' => 'DSpaced ' . check_plain($instance['label']),
        'callback' => '_dspaced_image_set_target',
        'description' => t('The DSpaced @label field of the node.',
                           array('@label' => $instance['label'])),
        'real_target' => $name,
      );
    }
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
    if ($file) {
      $field['und'][$i] = (array)$file;
      $field['und'][$i]['display'] = 1;
      $i++;
    }
  }
  $entity->$field_name = $field;
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
