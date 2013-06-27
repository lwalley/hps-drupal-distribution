<?php
/**
 * @file
 * hps_exhibits.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_exhibits_ctools_plugin_api() {
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
function hps_exhibits_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hps_exhibits_node_info() {
  $items = array(
    'hps_exhibit' => array(
      'name' => t('Exhibit'),
      'base' => 'node_content',
      'description' => t('Use <em>exhibits</em> to create a microsite in which you can gather related content and tell a story.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'hps_exhibit_information_page' => array(
      'name' => t('Exhibit information page'),
      'base' => 'node_content',
      'description' => t('Use <em>exhibit information pages</em> to add a basic page to an exhibit that is not part of the story, e.g. an \'About\' or \'Credit\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'hps_exhibit_narrative' => array(
      'name' => t('Exhibit narrative'),
      'base' => 'node_content',
      'description' => t('Use <em>exhibit narratives</em> to create multi-page stories, with built-in hierarchical navigation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
