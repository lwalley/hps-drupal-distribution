<?php

/**
 * @file dspaced_entities.dspaced.inc
 * File containing hooks for dspaced module.
 */

/**
 * Implements hook_dspaced_item_feeds_importer_fields_alter().
 */
function dspaced_entities_dspaced_item_feeds_importer_fields_alter(&$fields) {
  module_load_include('inc', 'dspaced_entities', 'dspaced_entities.dspaced_entities_default');
  $fields = array_merge($fields, _dspaced_entities_fields());
}
