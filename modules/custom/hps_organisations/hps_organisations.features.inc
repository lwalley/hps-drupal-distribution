<?php
/**
 * @file
 * hps_organisations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_organisations_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hps_organisations_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hps_organisations_node_info() {
  $items = array(
    'hps_organisation' => array(
      'name' => t('Organisation'),
      'base' => 'node_content',
      'description' => t('Use <em>Organisation</em> to add details about an administrative body.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
