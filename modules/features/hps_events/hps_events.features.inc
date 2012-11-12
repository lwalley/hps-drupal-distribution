<?php
/**
 * @file
 * hps_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_events_ctools_plugin_api() {
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
function hps_events_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hps_events_node_info() {
  $items = array(
    'hps_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use <em>events</em> to describe upcoming occasions.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
