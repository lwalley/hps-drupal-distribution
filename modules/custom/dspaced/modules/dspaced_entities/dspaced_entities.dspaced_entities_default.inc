<?php

/**
 * @file
 * Defines default bundles, fields and field instances.
 */

/**
 * Implements hook_dspaced_entities_default().
 */
function dspaced_entities_dspaced_entities_default() {
  return array(
    'bundles' => _dspaced_entities_bundles(),
    'fields' => _dspaced_entities_fields(),
    'instances' => _dspaced_entities_instances(),
  );
}

/**
 * Helper function to define bundles.
 */
function _dspaced_entities_bundles() {
  $bundles = array(
    'taxonomy_term' => array(
      'dc_description_type' => array(
        'name' => t("DC Description Type"),
        'description' => t("Type qualifier of the Dublin Core description property. " .
          "Contains terms that describe the resource type."),
        'machine_name' => 'dc_description_type',
      ),
      'dc_relation_ispartof' => array(
        'name' => t("DC Relation IsPartOf"),
        'description' => t("IsPartOf qualifier for the Dublin Core relation " .
          "property. Contains references to related resources in which " .
          "the described resource is physically or logically included."),
        'machine_name' => 'dc_relation_ispartof',
      ),
      'dc_subject' => array(
        'name' => t("DC Subject"),
        'description' => t("Subject property of the Dublin Core schema. " .
          "Contains terms that describes the topic of a resource."),
        'machine_name' => 'dc_subject',
      ),
      'dc_subject_lcsh' => array(
        'name' => t("DC Subject LCSH"),
        'description' => t("LCSH qualifier of the Dublin Core subject property." .
          "Contains a set of labeled concepts specified by the Library of " .
          "Congress Subject Headings."),
        'machine_name' => 'dc_subject_lcsh',
      ),
      'dc_subject_mesh' => array(
        'name' => t("DC Subject MeSH"),
        'description' => t("MeSH qualifier of the Dublin Core subject property. " .
          "Contains a set of labeled concepts specified by the Medical Subject " .
          "Headings."),
        'machine_name' => 'dc_subject_mesh',
      ),
      'dc_subject_tag' => array(
        'name' => t("DC Subject Tag"),
        'description' => t("Tag qualifier of the Dublin Core subject property. " .
          "Contains terms that describe the topic of a resource."),
        'machine_name' => 'dc_subject_tag',
      ),
      'dc_type' => array(
        'name' => t("DC Type"),
        'description' => t("Type property of the Dublin Core schema. " .
          "Contains terms that describes the nature or genre of the resource."),
        'machine_name' => 'dc_type',
      ),
    ),
  );

  return $bundles;
}

/**
 * Helper function to define fields.
 */
function _dspaced_entities_fields() {

  return array(
    'dspace_type' => array(
      'field_name' => 'dspace_type',
      'label' => t('DSpace Type Number'),
      'cardinality' => 1,
      'type' => 'number_integer',
      'xpath' => 'type',
    ),
    'dspace_is_withdrawn' => array(
      'field_name' => 'dspace_is_withdrawn',
      'label' => t('Withdrawn'),
      'cardinality' => 1,
      'type' => 'list_boolean',
      'settings' => array(
        'allowed_values' => array(1 => 'true', 0 => 'false'),
      ),
      'default_widget' => 'options_onoff',
      'xpath' => 'isWithdrawn',
    ),
    'dspace_is_archived' => array(
      'field_name' => 'dspace_is_archived',
      'label' => t('Archived'),
      'cardinality' => 1,
      'type' => 'list_boolean',
      'settings' => array(
        'allowed_values' => array(1 => 'true', 0 => 'false'),
      ),
      'default_widget' => 'options_onoff',
      'xpath' => 'isArchived',
    ),
    'dspace_handle' => array(
      'field_name' => 'dspace_handle',
      'label' => t('Handle'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 50),
      'xpath' => 'handle',
    ),
    'dspace_entity_id' => array(
      'field_name' => 'dspace_entity_id',
      'label' => t('DSpace Entity ID'),
      'cardinality' => 1,
      'type' => 'number_integer',
      'required' => TRUE,
      'settings' => array('min' => 1),
      'xpath' => 'entityId',
    ),
    'dspace_name' => array(
      'field_name' => 'dspace_name',
      'label' => t('Name'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => 'name',
    ),
    'dspace_bitstream_url' => array(
      'field_name' => 'dspace_bitstream_url',
      'label' => t('Bitstreams'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'link_field',
      'settings' => array(
        'attributes' => array('target' => 'default', 'class' => '', 'rel' => ''),
      ),
      'xpath' => '//bitstreamentity/name',
    ),
    'dspace_image' => array(
      'field_name' => 'dspace_image',
      'label' => t('Image'),
      'cardinality' => 1,
      'type' => 'image',
      'xpath' => 'bitstreams/bitstreamentity[not(contains(description, "Thumbnail")) and contains(name, ".web.j")]/name',
      'settings' => array(
        'file_extensions' => 'png gif jpg jpeg',
        'file_directory' => 'dspaced',
        'max_filesize' => '', // Leave blank to limit by PHP settings only
        'alt_field' => 0, // @todo find some appropriate text for alt
        'title_field' => 0,
        'max_resolution' => '',
        'min_resolution' => '',
        'default_image' => 0,
      ),
      'widget' => array(
        'type' => 'image_image',
        'settings' => array(
          'progress_indicator' => 'throbber',
          'preview_image_style' => 'thumbnail',
        ),
        'weight' => -1,
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'large', 'image_link' => ''),
          'weight' => -1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'settings' => array('image_style' => 'medium', 'image_link' => 'content'),
          'weight' => -1,
        ),
      ),
    ),
    'dspace_lastmodified' => array(
      'field_name' => 'dspace_lastmodified',
      'label' => t('Last Modified'),
      'cardinality' => 1,
      'type' => 'datetime',
      'default_formatter' => 'date_plain',
      'default_token_formatter' => 'date_plain',
      'default_widget' => 'date_text',
      'settings' => array(
        'granularity' => drupal_map_assoc(array('year', 'month', 'day', 'hour', 'minute', 'second')),
        'todate' => '',
        'tz_handling' => 'none',
        'timezone_db' => date_get_timezone_db('none'),
        'default_value' => 'blank',
        'default_value2' => 'blank',
      ),
      'widget' => array(
        'type' => 'date_text',
        'settings' => array(
          'input_format' => 'custom',
          'input_format_custom' => DATE_FORMAT_ISO,
          'increment' => 0,
          'text_parts' => array(),
          'year_range' => '-2:0',
          'label_position' => 'none',
        ),
      ),
      'xpath' => 'lastModified/@date',
    ),
    'dc_contributor' => array(
      'field_name' => 'dc_contributor',
      'label' => t('DC Contributor'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor'),
    ),
    'dc_contributor_editor' => array(
      'field_name' => 'dc_contributor_editor',
      'label' => t('DC Contributor Editor'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'editor'),
    ),
    'dc_contributor_illustrator' => array(
      'field_name' => 'dc_contributor_illustrator',
      'label' => t('DC Contributor Illustrator'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'illustrator'),
    ),
    'dc_contributor_interviewee' => array(
      'field_name' => 'dc_contributor_interviewee',
      'label' => t('DC Contributor Interviewee'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'interviewee'),
    ),
    'dc_contributor_interviewer' => array(
      'field_name' => 'dc_contributor_interviewer',
      'label' => t('DC Contributor Interviewer'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'interviewer'),
    ),
    'dc_contributor_narrator' => array(
      'field_name' => 'dc_contributor_narrator',
      'label' => t('DC Contributor Narrator'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'narrator'),
    ),
    'dc_contributor_photographer' => array(
      'field_name' => 'dc_contributor_photographer',
      'label' => t('DC Contributor Photographer'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'photographer'),
    ),
    'dc_contributor_correspondent' => array(
      'field_name' => 'dc_contributor_correspondent',
      'label' => t('DC Contributor Correspondent'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'correspondent'),
    ),
    'dc_contributor_speaker' => array(
      'field_name' => 'dc_contributor_speaker',
      'label' => t('DC Contributor Speaker'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'speaker'),
    ),
    'dc_contributor_translator' => array(
      'field_name' => 'dc_contributor_translator',
      'label' => t('DC Contributor Translator'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'translator'),
    ),
    'dc_contributor_videographer' => array(
      'field_name' => 'dc_contributor_videographer',
      'label' => t('DC Contributor Videographer'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'contributor', 'videographer'),
    ),
    'dc_coverage' => array(
      'field_name' => 'dc_coverage',
      'label' => t('DC Coverage'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'coverage'),
    ),
    'dc_coverage_spatial' => array(
      'field_name' => 'dc_coverage_spatial',
      'label' => t('DC Coverage Spatial'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'coverage', 'spatial'),
    ),
    'dc_coverage_temporal' => array(
      'field_name' => 'dc_coverage_temporal',
      'label' => t('DC Coverage Temporal'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'coverage', 'temporal'),
    ),
    'dc_creator' => array(
      'field_name' => 'dc_creator',
      'label' => t('DC Creator'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'creator'),
    ),
    'dc_date' => array(
      'field_name' => 'dc_date',
      'label' => t('DC Date'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'datetime',
      'xpath' => _dspaced_metadata_xpath('dc', 'date'),
    ),
    'dc_date_accessioned' => array(
      'field_name' => 'dc_date_accessioned',
      'label' => t('DC Date Accessioned'),
      'cardinality' => 1,
      'type' => 'datetime',
      'default_formatter' => 'date_plain',
      'default_token_formatter' => 'date_plain',
      'default_widget' => 'date_text',
      'settings' => array(
        'granularity' => drupal_map_assoc(array('year', 'month', 'day', 'hour', 'minute', 'second')),
        'todate' => '',
        'tz_handling' => 'none',
        'timezone_db' => date_get_timezone_db('none'),
        'default_value' => 'blank',
        'default_value2' => 'blank',
      ),
      'widget' => array(
        'type' => 'date_text',
        'settings' => array(
          'input_format' => 'custom',
          'input_format_custom' => DATE_FORMAT_ISO,
          'increment' => 0,
          'text_parts' => array(),
          'year_range' => '',
          'label_position' => 'none',
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'date', 'accessioned'),
    ),
    'dc_date_available' => array(
      'field_name' => 'dc_date_available',
      'label' => t('DC Date Available'),
      'cardinality' => 1,
      'type' => 'datetime',
      'default_formatter' => 'date_plain',
      'default_token_formatter' => 'date_plain',
      'default_widget' => 'date_text',
      'settings' => array(
        'granularity' => drupal_map_assoc(array('year', 'month', 'day', 'hour', 'minute', 'second')),
        'todate' => '',
        'tz_handling' => 'none',
        'timezone_db' => date_get_timezone_db('none'),
        'default_value' => 'blank',
        'default_value2' => 'blank',
      ),
      'widget' => array(
        'type' => 'date_text',
        'settings' => array(
          'input_format' => 'custom',
          'input_format_custom' => DATE_FORMAT_ISO,
          'increment' => 0,
          'text_parts' => array(),
          'year_range' => '',
          'label_position' => 'none',
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'date', 'available'),
    ),
    'dc_date_created' => array(
      'field_name' => 'dc_date_created',
      'label' => t('DC Date Created'),
      'cardinality' => 1,
      'type' => 'datetime',
      'default_formatter' => 'date_plain',
      'default_token_formatter' => 'date_plain',
      'default_widget' => 'date_text',
      'settings' => array(
        'granularity' => drupal_map_assoc(array('year', 'month', 'day', 'hour', 'minute', 'second')),
        'todate' => '',
        'tz_handling' => 'none',
        'timezone_db' => date_get_timezone_db('none'),
        'default_value' => 'blank',
        'default_value2' => 'blank',
      ),
      'widget' => array(
        'type' => 'date_text',
        'settings' => array(
          'input_format' => 'custom',
          'input_format_custom' => DATE_FORMAT_ISO,
          'increment' => 0,
          'text_parts' => array(),
          'year_range' => '',
          'label_position' => 'none',
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'date', 'created'),
    ),
    'dc_date_issued' => array(
      'field_name' => 'dc_date_issued',
      'label' => t('DC Date Issued'),
      'cardinality' => 1,
      'type' => 'datetime',
      'default_formatter' => 'date_plain',
      'default_token_formatter' => 'date_plain',
      'default_widget' => 'date_text',
      'settings' => array(
        'granularity' => drupal_map_assoc(array('year', 'month', 'day', 'hour', 'minute', 'second')),
        'todate' => '',
        'tz_handling' => 'none',
        'timezone_db' => date_get_timezone_db('none'),
        'default_value' => 'blank',
        'default_value2' => 'blank',
      ),
      'widget' => array(
        'type' => 'date_text',
        'settings' => array(
          'input_format' => 'custom',
          'input_format_custom' => DATE_FORMAT_ISO,
          'increment' => 0,
          'text_parts' => array(),
          'year_range' => '',
          'label_position' => 'none',
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'date', 'issued'),
    ),
    'dc_description' => array(
      'field_name' => 'dc_description',
      'label' => t('DC Description'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text_long',
      'xpath' => _dspaced_metadata_xpath('dc', 'description'),
    ),
    'dc_description_abstract' => array(
      'field_name' => 'dc_description_abstract',
      'label' => t('DC Description Abstract'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text_long',
      'xpath' => _dspaced_metadata_xpath('dc', 'description', 'abstract'),
    ),
    'dc_description_provenance' => array(
      'field_name' => 'dc_description_provenance',
      'label' => t('DC Description Provenance'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text_long',
      'xpath' => _dspaced_metadata_xpath('dc', 'description', 'provenance'),
    ),
    'dc_description_tableofcontents' => array(
      'field_name' => 'dc_description_tableofcontents',
      'label' => t('DC Description Table of Contents'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text_long',
      'xpath' => _dspaced_metadata_xpath('dc', 'description', 'tableofcontents'),
    ),
    'dc_description_type' => array(
      'field_name' => 'dc_description_type',
      'label' => t('DC Description Type'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'dc_description_type',
            'parent' => 0,
          ),
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'description', 'type'),
    ),
    'dc_format' => array(
      'field_name' => 'dc_format',
      'label' => t('DC Format'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'format'),
    ),
    'dc_format_extent' => array(
      'field_name' => 'dc_format_extent',
      'label' => t('DC Format Extent'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'format', 'extent'),
    ),
    'dc_format_medium' => array(
      'field_name' => 'dc_format_medium',
      'label' => t('DC Format Medium'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'format', 'medium'),
    ),
    'dc_identifier' => array(
      'field_name' => 'dc_identifier',
      'label' => t('DC Identifier'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'identifier'),
    ),
    'dc_identifier_citation' => array(
      'field_name' => 'dc_identifier_citation',
      'label' => t('DC Identifier Citation'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'identifier', 'citation'),
    ),
    'dc_identifier_issn' => array(
      'field_name' => 'dc_identifier_issn',
      'label' => t('DC Identifier ISSN'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'identifier', 'issn'),
    ),
    'dc_identifier_uri' => array(
      'field_name' => 'dc_identifier_uri',
      'label' => t('DC Identifier URI'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'link_field',
      'settings' => array(
        'attributes' => array('target' => 'default', 'class' => '', 'rel' => ''),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'identifier', 'uri'),
    ),
    'dc_language' => array(
      'field_name' => 'dc_language',
      'label' => t('DC Language'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings'    => array('max_length' => 20),
      'xpath' => _dspaced_metadata_xpath('dc', 'language'),
    ),
    'dc_language_iso' => array(
      'field_name' => 'dc_language_iso',
      'label' => t('DC Language ISO'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings'    => array('max_length' => 10),
      'xpath' => _dspaced_metadata_xpath('dc', 'language', 'iso'),
    ),
    'dc_publisher' => array(
      'field_name' => 'dc_publisher',
      'label' => t('DC Publisher'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'publisher'),
    ),
    'dc_publisher_digital' => array(
      'field_name' => 'dc_publisher_digital',
      'label' => t('DC Publisher Digital'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'publisher', 'digital'),
    ),
    'dc_publisher_original' => array(
      'field_name' => 'dc_publisher_original',
      'label' => t('DC Publisher Original'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'publisher', 'original'),
    ),
    'dc_relation_hasformat' => array(
      'field_name' => 'dc_relation_hasformat',
      'label' => t('DC Relation Has Format'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'relation', 'hasformat'),
    ),
    'dc_relation_haspart' => array(
      'field_name' => 'dc_relation_haspart',
      'label' => t('DC Relation Has Part'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'relation', 'haspart'),
    ),
    'dc_relation_hasversion' => array(
      'field_name' => 'dc_relation_hasversion',
      'label' => t('DC Relation Has Version'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'relation', 'hasversion'),
    ),
    'dc_relation_isformatof' => array(
      'field_name' => 'dc_relation_isformatof',
      'label' => t('DC Relation Is Format Of'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'relation', 'isformatof'),
    ),
    'dc_relation_ispartof' => array(
      'field_name' => 'dc_relation_ispartof',
      'label' => t('DC Relation Is Part Of'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'relation', 'ispartof'),
    ),
    'dc_relation_isversionof' => array(
      'field_name' => 'dc_relation_isversionof',
      'label' => t('DC Relation Is Version Of'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'relation', 'isversionof'),
    ),
    'dc_rights' => array(
      'field_name' => 'dc_rights',
      'label' => t('DC Rights'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 1000),
      'xpath' => _dspaced_metadata_xpath('dc', 'rights'),
    ),
    'dc_rights_copyright' => array(
      'field_name' => 'dc_rights_copyright',
      'label' => t('DC Rights Copyright'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 1000),
      'xpath' => _dspaced_metadata_xpath('dc', 'rights', 'copyright'),
    ),
    'dc_rights_holder' => array(
      'field_name' => 'dc_rights_holder',
      'label' => t('DC Rights Holder'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'rights', 'holder'),
    ),
    'dc_rights_license' => array(
      'field_name' => 'dc_rights_license',
      'label' => t('DC Rights License'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 1000),
      'xpath' => _dspaced_metadata_xpath('dc', 'rights', 'license'),
    ),
    'dc_rights_uri' => array(
      'field_name' => 'dc_rights_uri',
      'label' => t('DC Rights URI'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'link_field',
      'settings' => array(
        'attributes' => array('target' => 'default', 'class' => '', 'rel' => ''),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'rights', 'uri'),
    ),
    'dc_source' => array(
      'field_name' => 'dc_source',
      'label' => t('DC Source'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'source'),
    ),
    'dc_subject' => array(
      'field_name' => 'dc_subject',
      'label' => t('DC Subject'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'dc_subject',
            'parent' => 0,
          ),
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'subject'),
    ),
    'dc_subject_lcsh' => array(
      'field_name' => 'dc_subject_lcsh',
      'label' => t('DC Subject LCSH'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'dc_subject_lcsh',
            'parent' => 0,
          ),
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'subject', 'lcsh'),
    ),
    'dc_subject_mesh' => array(
      'field_name' => 'dc_subject_mesh',
      'label' => t('DC Subject Mesh'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'dc_subject_mesh',
            'parent' => 0,
          ),
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'subject', 'mesh'),
    ),
    'dc_subject_tag' => array(
      'field_name' => 'dc_subject_tag',
      'label' => t('DC Subject Tag'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'dc_subject_tag',
            'parent' => 0,
          ),
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'subject', 'tag'),
    ),
    'dc_type' => array(
      'field_name' => 'dc_type',
      'label' => t('DC Type'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          array(
            'vocabulary' => 'dc_type',
            'parent' => 0,
          ),
        ),
      ),
      'xpath' => _dspaced_metadata_xpath('dc', 'type'),
    ),
    'dc_title' => array(
      'field_name' => 'dc_title',
      'label' => t('DC Title'),
      'cardinality' => 1,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'title'),
    ),
    'dc_title_alternative' => array(
      'field_name' => 'dc_title_alternative',
      'label' => t('DC Title Alternative'),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
      'type' => 'text',
      'settings' => array('max_length' => 255),
      'xpath' => _dspaced_metadata_xpath('dc', 'title', 'alternative'),
    ),
    'dspace_pdf_text' => array(
      'field_name' => 'dspace_pdf_text',
      'label' => t('PDF Text'),
      'cardinality' => 1,
      'type' => 'text_long',
      'xpath' => 'bitstreams/bitstreamentity' .
        '[(mimeType = "text/plain" and contains(name, ".pdf.txt"))]/name'),
    ),
  );
}

/**
 * Helper function to get metadata xpath.
 */
function _dspaced_metadata_xpath($schema, $element, $qualifier = '') {
  return "metadata/metadataentity[schema = '{$schema}' and " .
    "element = '{$element}' and qualifier = '{$qualifier}']/value";
}

/**
 * Helper function to define field instances.
 */
function _dspaced_entities_instances() {
  $fields = _dspaced_entities_fields();
  return array(
    'node' => array(
      'dspaced_entities_item' => $fields,
      'dspaced_entities_community' => array(
        'dspace_entity_id' => $fields['dspace_entity_id'],
        'dspace_handle' => $fields['dspace_handle'],
      ),
    ),
  );
}

