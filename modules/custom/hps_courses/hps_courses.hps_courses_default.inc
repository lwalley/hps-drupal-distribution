<?php

/**
 * @file
 * Defines default bundles, fields and field instances.
 */

/**
 * Implements hook_hps_courses_default().
 */
function hps_courses_hps_courses_default() {
  return array(
    'bundles' => _hps_courses_bundles(),
    'fields' => _hps_courses_fields(),
    'instances' => _hps_courses_instances(),
  );
}

/**
 * Helper function to define bundles.
 */
function _hps_courses_bundles() {
  $bundles = array(
    'taxonomy_term' => array(
      'hps_participant_role' => array(
        'name' => t("HPS Courses Participant Role"),
        'description' => t("Contains roles of course participants."),
        'machine_name' => 'hps_participant_role',
      ),
      'hps_person_authority' => array(
        'name' => t("HPS Person Authority"),
        'description' => t("Contains authority records for people names."),
        'machine_name' => 'hps_person_authority',
      ),
      'hps_course_item_type' => array(
        'name' => t("HPS Course Item Type"),
        'description' => t('Terms describe the type of item associated with '.
                           'a course e.g. official course photo, syllabus etc.'),
        'machine_name' => 'hps_course_item_type',
      ),
    ),
  );
  return $bundles;
}

/**
 * Helper function to define fields.
 */
function _hps_courses_fields() {

  return array(
    'hps_course_name' => array(
      'field_name' => 'hps_course_name',
      'label' => t('Course name'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_course_year' => array(
      'field_name' => 'hps_course_year',
      'label' => t('Course year'),
      'cardinality' => 1,
      'type' => 'number_integer',
    ),
    'hps_course_notes' => array(
      'field_name' => 'hps_course_notes',
      'label' => t('Notes'),
      'cardinality' => 1,
      'type' => 'text_long',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_course_participants' => array(
      'field_name' => 'hps_course_participants',
      'label' => t('Participants'),
      'type' => 'field_collection',
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'settings' => array(
        'hide_blank_items' => TRUE,
      ),
      'widget' => array(
        'type' => 'field_collection_embed',
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'field_collection_view',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_participant_first_name' => array(
      'field_name' => 'hps_participant_first_name',
      'label' => t('Participant first name'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_participant_last_name' => array(
      'field_name' => 'hps_participant_last_name',
      'label' => t('Participant last name'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_participant_id' => array(
      'field_name' => 'hps_participant_id',
      'label' => t('Participant ID'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 50),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_participant_notes' => array(
      'field_name' => 'hps_participant_notes',
      'label' => t('Notes'),
      'cardinality' => 1,
      'type' => 'text_long',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_person_authority' => array(
      'field_name' => 'hps_person_authority',
      'label' => t('Person authority'),
      'cardinality' => 1,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'hps_person_authority',
            'parent' => 0,
          ),
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_participant_role' => array(
      'field_name' => 'hps_participant_role',
      'label' => t('Role'),
      'cardinality' => 1,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'hps_participant_role',
            'parent' => 0,
          ),
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'taxonomy_term_reference_plain',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_course_items' => array(
      'field_name' => 'hps_course_items',
      'label' => t('Items'),
      'type' => 'field_collection',
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'settings' => array(
        'hide_blank_items' => TRUE,
      ),
      'widget' => array(
        'type' => 'field_collection_embed',
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_course_item_type' => array(
      'field_name' => 'hps_course_item_type',
      'label' => t('Type'),
      'cardinality' => 1,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'hps_course_item_type',
            'parent' => 0,
          ),
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_course_item_uri' => array(
      'field_name' => 'hps_course_item_uri',
      'label' => t('Course item URI'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_course_item_entity' => array(
      'field_name' => 'hps_course_item_entity',
      'label' => t('Course item entity'),
      'cardinality' => 1,
      'type' => 'entityreference',
      'settings' => array(
        'target_type' => 'node',
        'handler' => 'base',
        'handler_settings' => array(
          'target_bundles' => array(
            'dspaced_entities_item' => 'dspaced_entities_item',
          ),
          'sort' => array(
            'type' => 'property',
            'property' => 'title',
            'direction' => 'ASC',
          ),
        ),
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_person_authority_uuid' => array(
      'field_name' => 'hps_person_authority_uuid',
      'label' => t('Person authority UUID'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 36),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
        ),
      ),
    ),
    'hps_person_authority_ids' => array(
      'field_name' => 'hps_person_authority_ids',
      'label' => t('Alternative IDs'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
    ),
    'hps_person_authority_names' => array(
      'field_name' => 'hps_person_authority_names',
      'label' => t('Alternative names'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
    ),
  );
}

/**
 * Helper function to define field instances.
 */
function _hps_courses_instances() {
  $fields = _hps_courses_fields();
  return array(
    'field_collection_item' => array(
      'hps_course_participants' => array(
        'hps_participant_first_name' => $fields['hps_participant_first_name'],
        'hps_participant_last_name' => $fields['hps_participant_last_name'],
        'hps_participant_id' => $fields['hps_participant_id'],
        'hps_participant_role' => $fields['hps_participant_role'],
        'hps_participant_notes' => $fields['hps_participant_notes'],
        'hps_person_authority' => $fields['hps_person_authority'],
      ),
      'hps_course_items' => array(
        'hps_course_item_type' => $fields['hps_course_item_type'],
        'hps_course_item_uri' => $fields['hps_course_item_uri'],
        'hps_course_item_entity' => $fields['hps_course_item_entity'],
      ),
    ),
    'node' => array(
      'hps_course' => array(
        'hps_course_name' => $fields['hps_course_name'],
        'hps_course_year' => $fields['hps_course_year'],
        'hps_course_notes' => $fields['hps_course_notes'],
        'hps_course_participants' => $fields['hps_course_participants'],
        'hps_course_items' => $fields['hps_course_items'],
      ),
    ),
    'taxonomy_term' => array(
      'hps_person_authority' => array(
        'hps_person_authority_uuid' => $fields['hps_person_authority_uuid'],
        'hps_person_authority_ids' => $fields['hps_person_authority_ids'],
        'hps_person_authority_names' => $fields['hps_person_authority_names'],
      ),
    ),
  );
}

