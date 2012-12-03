<?php

/**
 * @file
 */

/**
 * Implements hook_feeds_importer_default().
 *
 * @note Job Scheduler will wait one hour after putting a job in the Queue
 * before rescheduling it. Feeds workers will spend 15 seconds on each queue,
 * each time cron is run. The minimum frequency for poor mans cron is one hour.
 *
 * @note Mappings requiring complex conditionals or absolute URLs are handled
 * with hook_feeds_parser_sources_alter().
 */
function dspaced_feeds_importer_default() {

  module_load_include('inc', 'dspaced_entities', 'dspaced_entities.dspaced_entities_info');

  $importers = array();
  $importers['dspaced_communities'] = _dspaced_communities_feeds_importer();
  $importers['dspaced_community'] = _dspaced_community_feeds_importer();
  $importers['dspaced_harvest'] = _dspaced_harvest_feeds_importer();
  $importers['dspaced_item'] = _dspaced_item_feeds_importer();
  return $importers;
}


/**
 * Importer for DSpace REST communities results.
 * /communities.xml
 *
 * @note We assume the number is small and load all at once. We skip save for
 * this import using it simply to retrieve community items for display in
 * settings form
 */
function _dspaced_communities_feeds_importer() {

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dspaced_communities';
  $feeds_importer->config = array(
    'name' => 'DSpaced Communities',
    'description' => 'Fetches all communities in single request (assumes small ' .
                     'count). Does not create nodes (skipped in presave).',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'entityId',
          'xpathparser:1' => 'name',
          'xpathparser:2' => '0',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
        ),
        'context' => '//communities',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'dspaced_entities_community',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'status',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'dspace_entity_id',
            'unique' => 1,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 0,
    'process_in_background' => 0,
  );

  return $feeds_importer;
}

/**
 * Importer for a single community.
 * /communities/:id.xml
 *
 * @note Individual community imports are triggered when a community is chosen
 * in the settings form. On import of a community we create a
 * dspaced_entity_community node and set it's feeds source URL to
 * /harvest.xml?idOnly=true&community=:id
 * @see dspaced_harvest importer.
 */
function _dspaced_community_feeds_importer() {

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dspaced_community';
  $feeds_importer->config = array(
    'name' => 'DSpaced Community',
    'description' => 'Imports a single community and creates node. Triggered by ' .
                     'selecting a community in dspaced admin settings.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'concat("communities/", entityId)',
          'xpathparser:1' => 'name',
          'xpathparser:2' => '0',
          'xpathparser:3' => 'entityId',
          'xpathparser:4' => 'handle',
          'xpathparser:5' => 'concat("/harvest.xml?idOnly=true&community=", entityId)',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '/communities',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'dspaced_entities_community',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'status',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'dspace_entity_id',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'dspace_handle',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'feeds_source',
            'unique' => 1,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 0,
    'process_in_background' => 1,
  );

  return $feeds_importer;
}


/**
 * Importer for all community items (imports dspace entity id only).
 * /harvest.xml?idOnly=true&community=:id
 *
 * @note Harvest imports are attached to and triggered by the creation of a
 * dspaced_entities_community node types.
 * @see dspaced_community importer for creation of community nodes.
 */
function _dspaced_harvest_feeds_importer() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dspaced_harvest';
  $feeds_importer->config = array(
    'name' => 'DSpaced Harvest',
    'description' => 'Import items returned by DSpace REST harvest ' .
      'results by community. Used with idOnly=true harvest parameter.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'concat("items/", entityId)',
          'xpathparser:1' => 'entityId',
          'xpathparser:2' => 'concat("/items/", entityId, ".xml")',
          'xpathparser:3' => '0',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
        ),
        'context' => '//harvest[entityId > 0]',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'dspaced_entities_item',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'dspace_entity_id',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'feeds_source',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'status',
            'unique' => 0,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => 'dspaced_entities_community',
    'update' => 0,
    'import_period' => '86400',  // Get new community items daily.
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  return $feeds_importer;
}

/**
 * Importer for an individual item.
 * /items/:id.xml
 *
 * @note Item imports are attached to and triggered by the creation of a
 * dspaced_entities_item node types and use FeedsSelfNodeProcessor to self
 * update.
 * @see dspaced_harvest importer for creation of item nodes.
 */
function _dspaced_item_feeds_importer() {
  $fields = array(
    'guid' => array('xpath' => 'concat("items/", entityId)'),
    'title' => array('xpath' => 'name'),
    'body' => array('xpath' => 'bitstreams/bitstreamentity' .
      '[((mimeType = "text/xhtml" or mimeType = "application/octet-stream") ' .
      'and contains(name, ".xhtml")) or (mimeType = "text/plain" and contains(name, ".pdf.txt"))]/name'),
    'status' => array('xpath' => 1), // Publish items on import of full data
    'feeds_source' => array('xpath' => 'concat("/items/", entityId, ".xml")'),
    'url' => array('xpath' => 'concat("/items/", entityId, ".xml")'),
  );

  drupal_alter('dspaced_item_feeds_importer_fields', $fields);

  // Move body to the bottom because it needs the item handle
  // @see _dspaced_body_set_target().
  $body_field = $fields['body'];
  unset($fields['body']);
  $fields['body'] = $body_field;
  unset($body_field);

  $unique = array('guid', 'dspace_entity_id', 'dspace_handle');
  $mappings = array();
  $sources = array();
  $raw_xml = array();
  $debug = array();
  foreach(array_keys($fields) as $i => $field_name) {
    $target = $field_name;
    // Add custom subfield to body. Target value is altered later.
    // @see dspaced_feeds_processor_target_alter().
    // @see _dspaced_body_set_target().
    if ($target == 'body') {
      $target .= ':dspaced';
    }
    if (array_key_exists('type', $fields[$field_name])) {
      // Target subfields for link, date and image fields:
      switch ($fields[$field_name]['type']) {
        case 'datetime':
          $target .= ":start";
        break;
        case 'link_field':
          $target .= ":url";
          break;
        case 'image':
          // Add custom subfield to image fields. Target value is altered later.
          // @see dspaced_feeds_processor_target_alter().
          // @see _dspaced_image_set_target().
          $target .= ":dspaced";
          break;
      }
    }
    $mappings[$i] = array(
      'source' => "xpathparser:{$i}",
      'target' => $target,
      'unique' => in_array($field_name, $unique) ? TRUE : FALSE,
    );
    $sources[$mappings[$i]['source']] = $fields[$field_name]['xpath'];
    $raw_xml[$mappings[$i]['source']] = FALSE;
    $debug[$mappings[$i]['source']] = FALSE;
  }
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'dspaced_item';
  $feeds_importer->config = array(
    'name' => 'DSpaced Item',
    'description' => 'Importer for a single DSpace item. Triggered on node ' .
        'creation after harvest and then updated periodically on cron.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => $sources,
        'rawXML' => $raw_xml,
        'context' => '/items',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => $debug,
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsSelfNodeProcessor',
      'config' => array(
        'content_type' => '',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => $mappings,
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
      ),
    ),
    'content_type' => 'dspaced_entities_item',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );

  return $feeds_importer;
}
