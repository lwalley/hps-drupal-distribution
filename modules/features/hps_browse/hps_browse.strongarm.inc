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
  $strongarm->name = 'page_manager_term_view_disabled';
  $strongarm->value = TRUE;
  $export['page_manager_term_view_disabled'] = $strongarm;

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
  $strongarm->value = 1;
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
  $strongarm->value = '385';
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
