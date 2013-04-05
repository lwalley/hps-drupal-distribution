<?php

/**
 * @file
 * Contains default Feeds importers.
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hps_courses_feeds_importer_default() {

  $importers = array();
  $importers['hps_course'] = _hps_course_feeds_importer();
  $importers['hps_person_authorities'] = _hps_person_authorities_feeds_importer();
  return $importers;
}

/**
 * Helper method to define default Feeds importer for importing Courses.
 */
function _hps_course_feeds_importer() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hps_course';
  $feeds_importer->config = array(
    'name' => 'Course',
    'description' => 'Imports course data from xlsx file.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXLSXParser',
      'config' => array(
        'no_headers' => 0,
        'one_item' => 1,
        'sheets_to_parse' => '',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsSelfNodeProcessor',
      'config' => array(
        'content_type' => 'hps_course',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Metadata:Course Name',
            'target' => 'hps_course_name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Metadata:Course Year',
            'target' => 'hps_course_year',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Participants:Person ID',
            'target' => 'hps_course_participants:hps_participant_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Participants:Person First Name',
            'target' => 'hps_course_participants:hps_participant_first_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Participants:Person Last Name',
            'target' => 'hps_course_participants:hps_participant_last_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Participants:Notes',
            'target' => 'hps_course_participants:hps_participant_notes',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Participants:Role Name',
            'target' => 'hps_course_participants:hps_participant_role',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Participants:Person ID',
            'target' => 'hps_course_participants:hps_person_authority:hps_courses',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Items:Item Type',
            'target' => 'hps_course_items:hps_course_item_type',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Items:Item URI',
            'target' => 'hps_course_items:hps_course_item_uri',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Items:Item URI',
            'target' => 'hps_course_items:hps_course_item_entity:hps_courses',
            'unique' => FALSE,
          ),
          // Fake field which we add a value to in after parse hook.
          // @see hook_feeds_after_parse
          11 => array(
            'source' => 'Replace Me:URL',
            'target' => 'url',
            'unique' => 1,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
      ),
    ),
    'content_type' => 'hps_course',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  return $feeds_importer;
}

/**
 * Helper method to define default Feeds importer for importing Courses.
 */
function _hps_person_authorities_feeds_importer() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hps_person_authorities';
  $feeds_importer->config = array(
    'name' => 'Person Authorities',
    'description' => 'Imports people names, their UUIDs and other IDs.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXLSXParser',
      'config' => array(
        'no_headers' => 0,
        'one_item' => 0,
        'sheets_to_parse' => 'Authority List',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'hps_person_authority',
        'mappings' => array(
          0 => array(
            'source' => 'Authority List:Locally Authorized UUID',
            'target' => 'guid',
            'unique' => TRUE,
          ),
          1 => array(
            'source' => 'Authority List:Locally Authorized UUID',
            'target' => 'hps_person_authority_uuid',
            'unique' => TRUE,
          ),
          2 => array(
            'source' => 'Authority List:Person Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Authority List:Local ID',
            'target' => 'hps_person_authority_ids:hps_courses',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Authority List:Person Name',
            'target' => 'hps_person_authority_names:hps_courses',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '604800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  return $feeds_importer;
}

