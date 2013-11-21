<?php
/**
 * @file
 * hps_browse.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hps_browse_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_hps_browse_by';
  $strongarm->value = 'edit-print';
  $export['additional_settings__active_tab_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_hps_browse_by';
  $strongarm->value = 1;
  $export['enable_revisions_page_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hps_browse_by';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hps_browse_by';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hps_browse_by';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hps_browse_by';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hps_browse_by';
  $strongarm->value = '1';
  $export['node_preview_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hps_browse_by';
  $strongarm->value = 0;
  $export['node_submitted_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hps_browse_by_pattern';
  $strongarm->value = 'browse/[node:title]';
  $export['pathauto_node_hps_browse_by_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_hps_browse_by';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_hps_browse_by';
  $strongarm->value = 0;
  $export['show_diff_inline_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_hps_browse_by';
  $strongarm->value = 1;
  $export['show_preview_changes_hps_browse_by'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_display_descendants_dc_description_type';
  $strongarm->value = 1;
  $export['taxonomy_menu_display_descendants_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_display_num_dc_description_type';
  $strongarm->value = 0;
  $export['taxonomy_menu_display_num_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_end_all_dc_description_type';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_end_all_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_expanded_dc_description_type';
  $strongarm->value = 1;
  $export['taxonomy_menu_expanded_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_flat_dc_description_type';
  $strongarm->value = 0;
  $export['taxonomy_menu_flat_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_hide_empty_terms_dc_description_type';
  $strongarm->value = 1;
  $export['taxonomy_menu_hide_empty_terms_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_path_dc_description_type';
  $strongarm->value = 'taxonomy_menu_path_default';
  $export['taxonomy_menu_path_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_rebuild_dc_description_type';
  $strongarm->value = 0;
  $export['taxonomy_menu_rebuild_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_sync_dc_description_type';
  $strongarm->value = 1;
  $export['taxonomy_menu_sync_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_term_item_description_dc_description_type';
  $strongarm->value = 0;
  $export['taxonomy_menu_term_item_description_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_vocab_menu_dc_description_type';
  $strongarm->value = 'main-menu';
  $export['taxonomy_menu_vocab_menu_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_vocab_parent_dc_description_type';
  $strongarm->value = '0';
  $export['taxonomy_menu_vocab_parent_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_dc_description_type';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_item_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_description_dc_description_type';
  $strongarm->value = 0;
  $export['taxonomy_menu_voc_item_description_dc_description_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_name_dc_description_type';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_name_dc_description_type'] = $strongarm;

  return $export;
}
