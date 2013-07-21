<?php
/**
 * @file
 * hps_timelines.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_timelines_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hps_timelines_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hps_timelines_node_info() {
  $items = array(
    'hps_timeline_event' => array(
      'name' => t('Timeline event'),
      'base' => 'node_content',
      'description' => t('Use <em>timeline events</em> to create a short event that can be added to a timeline.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
