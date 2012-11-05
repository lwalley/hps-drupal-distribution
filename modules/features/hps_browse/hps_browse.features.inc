<?php
/**
 * @file
 * hps_browse.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_browse_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hps_browse_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hps_browse_node_info() {
  $items = array(
    'hps_browse_by' => array(
      'name' => t('Browse By'),
      'base' => 'node_content',
      'description' => t('Landing page for browse by vocabulary terms feature.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
