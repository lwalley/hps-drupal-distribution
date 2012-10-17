<?php

/**
 * @file
 */

/**
 * Page callback for /admin/reports/dspaced.
 */
function dspaced_ui_overview() {
  $variables = array();
  $variables['community_nodes'] = _dspaced_find_community_nodes();
  $variables['item_count'] = array();
  foreach ($variables['community_nodes'] as $nid => $node) {
    $importer_id = feeds_get_importer_id($node->type);
    $source = feeds_source($importer_id, $node->nid);
    $variables['item_count'][$nid] = $source->itemCount();
    $variables['community_nodes'][$nid]->schedule = views_embed_view('dspaced_job_schedule', 'attachment_1', $nid);
    // TODO: view block of job schedule with community job id argument
  }
  // TODO: view block of job schedule with community job id argument
  return theme('dspaced_ui_overview', $variables);
}

/**
 * Displays summary of community item import schedules.
 * @ingroup themeable
 */
function theme_dspaced_ui_overview($variables) {
  // TODO: Use preprocess to convert variables to renderable e.g. create link from
  // node title etc. pluralize item count etc.
  $community_nodes = $variables['community_nodes'];
  $item_count = $variables['item_count'];
  $output = '';

  foreach ($community_nodes as $nid => $node) {
    $output = "<h3>{$node->title}</h3>" .
              "<p>Item count: {$item_count[$nid]}</p>" .
              $node->schedule;
  }

  return $output;

}
