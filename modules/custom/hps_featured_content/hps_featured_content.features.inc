<?php
/**
 * @file
 * hps_featured_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_featured_content_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hps_featured_content_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hps_featured_content_node_info() {
  $items = array(
    'hps_featured_content' => array(
      'name' => t('Featured Content'),
      'base' => 'node_content',
      'description' => t('Use <em>featured content</em> to select and describe existing entities, such as DSpace items, that you would like to promote.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
