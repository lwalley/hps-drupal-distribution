<?php

/**
 * @file
 * Contains Feeds hooks for HPS Courses module.
 */
define('HPS_COURSES_DATATYPE_COURSE', 'Course');
define('HPS_COURSES_DATATYPE_AFFILIATIONS', 'Affiliations');
define('HPS_COURSES_DATATYPE_PERSON_AUTHORITIES', 'Authority List');

/**
 * Implements hook_feeds_after_parse().
 */
function hps_courses_feeds_after_parse(FeedsSource $source, FeedsParserResult $result) {
  if ($source->importer->id == 'hps_course') {
    // Bit of a hack but want to use source URL as unique field so adding fake
    // field to course item 'Replace Me:URL' which is mapped to the URL field.
    $config = $source->getConfig();
    foreach ($result->items as $i => $item) {
      $result->items[$i]['Replace Me:URL'] = $config['FeedsHTTPFetcher']['source'];
    }
  }
}
/**
 * Implements hook_feeds_after_import().
 *
 * Trigger imports for courses, affiliations and person authorities datasets.
 */
function hps_courses_feeds_after_import($source) {
  if ($source->importer->id == 'dspaced_item' && array_key_exists('process', $source->state) &&
      ($source->state['process']->created || $source->state['process']->updated)) {
    // @note When we import a dspace item containing data bitstream url
    //       we want to then trigger the import of the actual data into other
    //       entities e.g. create or update the hps_course node. We can't limit
    //       this trigger to the dspace item created state because the dspace
    //       item may already exist.
    if (($node = node_load($source->feed_nid)) && is_object($node)) {

      $is_course = _hps_courses_is_dataset($node, HPS_COURSES_DATATYPE_COURSE);
      $is_affiliations = _hps_courses_is_dataset($node, HPS_COURSES_DATATYPE_AFFILIATIONS);
      $is_person_authorities = _hps_courses_is_dataset($node, HPS_COURSES_DATATYPE_PERSON_AUTHORITIES);

      if (($is_course || $is_affiliations || $is_person_authorities) &&
         ($xlsx_url = _hps_courses_get_xlsx_url($node))) {

        if ($is_course) {
          // @note Because the course nodes are self updating we have to create
          //       the node first before it can self update. Importer should be
          //       configured to import itself after node creation so we just
          //       have to pass it the xlsx URL.
          //
          //       Unfortunately since the node is self updating we can't rely
          //       on a unique field value to prevent duplicate nodes, so we do
          //       some checking here. We don't have a guid for a course node
          //       but the feed URLs should be unique along with the importer
          //       id/name. We make sure the URL is added to feeds_item table
          //       so we can query it for it here - we could also make a guid
          //       using the handle in the feeds_url but for now lets just use
          //       the url.
          //       @see hps_courses_feeds_after_parse()
          $feed_item = db_select('feeds_item')
            ->fields('feeds_item')
            ->condition('id', 'hps_course')
            ->condition('url', $xlsx_url)
            ->execute()
            ->fetchObject();
          if ($feed_item) {
            // We already have a course node using this bitstream URL so just
            // trigger an update.
            // @note We probably don't need to do this because the node be
            //       updating itself but lets do it anyway.
            $data_source = feeds_source($feed_item->id, $feed_item->feed_nid);
            $data_source->startImport();
          }
          else {
            // We didn't find a matching feed_item course node so we create a
            // new one.
            // @note Importer should be configured to automatically trigger
            //       the import upon node creation, so we just need to give it
            //       the bitstream URL here.
            $course_node = new stdClass();
            $course_node->type = 'hps_course';
            node_object_prepare($course_node);
            $course_node->feeds['FeedsHTTPFetcher']['source'] = $xlsx_url;
            node_save($course_node);
          }
        }
        elseif ($is_affiliations) {
          // @todo $source = feeds_source('hps_affiliations');
        }
        elseif ($is_person_authorities) {
          //$data_source = feeds_source('hps_person_authorities');
          //$data_source->addConfig(array('FeedsHTTPFetcher' => array('source' => $xlsx_url)));
          //$data_source->save();
          //$data_source->startImport();
        }
      }
    }
  }
}

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * Provides additional targets for mapping sources.
 */
function hps_courses_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    switch ($name) {
      case 'hps_person_authority':
        // Find and assign reference to the person authority term for this
        // participant.
        $callback = '_hps_courses_participant_authority_set_target';
        break;
      case 'hps_course_item_entity':
        // Find and assign reference to the dspace item from the item URI.
        $callback = '_hps_courses_item_set_target';
        break;
      case 'hps_person_authority_ids':
        // Authority list term will be created and updated from multiple items,
        // so on update append new ids rather than replace existing.
        $callback = '_hps_courses_person_ids_set_target';
        break;
      case 'hps_person_authority_names':
        // Authority list term will be created and updated from multiple items,
        // so on update append new names rather than replace existing.
        $callback = '_hps_courses_person_names_set_target';
        break;
    }
    // Assign callbacks to new custom targets.
    if (isset($callback) && $callback) {
      $targets[$name . ':hps_courses'] = array(
        'name' => 'HPS Courses ' . check_plain($instance['label']),
        'callback' => $callback,
        'description' => t('The HPS Courses custom target for field instance ' .
                           '@label of @name.', array(
                           '@label' => $instance['label'],
                           '@name' => $name)),
        'real_target' => $name,
      );
    }
    unset($callback);
  }
}

/**
 * Target callback for course participant authority term.
 */
function _hps_courses_participant_authority_set_target($source, $entity, $target, $value) {
  if (empty($value)) {
    return;
  }
  if (is_array($value)) {
    $values = $value;
  } else {
    $values = array($value);
  }
  list($field_name, $custom_suffix) = explode(':', $target, 2);
  $info = field_info_field($field_name);
  $i = 0;
  $field = isset($entity->$field_name) ? $entity->$field_name : array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('hps_person_authority');
  foreach ($values as $value) {
    if ($info['cardinality'] == $i) {
      break;
    }
    if ($value) {
      // Find person authority term that has $value in ids.
      //$field[LANGUAGE_NONE][$i] = $term->tid;
      //$i++;
    }
  }
  $entity->$field_name = $field;
}

/**
 * Target callback for course item node reference.
 * @see entityreference_feeds_set_target
 */
function _hps_courses_item_set_target($source, $entity, $target, $value) {
  // Find and reference course items dspace item node.
  if (empty($value)) {
    return;
  }
  if (is_array($value)) {
    $values = $value;
  }
  else {
    $values = array($value);
  }

  // Extract handles from uri which we expect to be http://hdl.handle.net/10776/3494
  $handles = array();
  foreach ($values as $uri) {
    $parsed = parse_url($uri);
    $handles[] = preg_replace('/^\//', '', $parsed['path']);
  }

  // Find all item nodes by handle
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'dspaced_entities_item')
    ->fieldCondition('dspace_handle', 'value', $handles, 'IN')
    ->execute();

  $nodes = node_load_multiple(array_keys($result['node']));

  list($field_name, $custom_suffix) = explode(':', $target, 2);
  $info = field_info_field($field_name);
  $i = 0;
  $field = isset($entity->$field_name) ? $entity->$field_name : array();
  foreach ($nodes as $node) {
    if ($info['cardinality'] == $i) {
      break;
    }
    $field[LANGUAGE_NONE][$i]['target_id'] = $node->nid;
    $i++;
  }
  $entity->$field_name = $field;
}

/**
 * Target callback for person authority ids.
 */
function _hps_courses_person_ids_set_target($source, $entity, $target, $value) {
  // Append ids if node exists.
}

/**
 * Target callback for person authority names.
 */
function _hps_courses_person_names_set_target($source, $entity, $target, $value) {
  // Append names if node exists.
}



/**
 * Helper function to return the xlsx bitstream url from node.
 *
 * @param $node
 *   Node object of type dspaced_entities_item.
 * @return
 *   String containing the xlsx bitstream url or empty if not found.
 */
function _hps_courses_get_xlsx_url($node) {
  $language = (isset($node->language) || property_exists($node, $language)) ? $node->language : LANGUAGE_NONE;
  $bitstreams = field_get_items('node', $node, 'dspace_bitstream_url', $language);
  $xlsx_url = '';
  foreach ($bitstreams as $bitstream) {
    $parsed_url = parse_url($bitstream['url']);
    $info = pathinfo($parsed_url['path']);
    if ($info['extension'] == 'xlsx') {
      $xlsx_url = trim($bitstream['url']);
      break;
    }
  }
  return $xlsx_url;
}

/**
 * Helper function to determine if a node is the source dspace item for a type
 * of dataset.
 */
function _hps_courses_is_dataset($node, $dataset_type) {
  $language = (isset($node->language) || property_exists($node, $language)) ? $node->language : LANGUAGE_NONE;
  $tids = array();
  foreach (array('dc_type', 'dc_type_mblhistory') as $field) {
    if ($items = field_get_items('node', $node, $field, $language)) {
      $tids[$field] = $items[0]['tid'];
    }
  }
  $terms = taxonomy_term_load_multiple($tids);
  if ($terms[$tids['dc_type']]->name == 'Dataset' &&
      $terms[$tids['dc_type_mblhistory']]->name == $dataset_type) {
    return TRUE;
  }
  return FALSE;
}

