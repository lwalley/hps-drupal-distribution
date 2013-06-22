<?php

/**
 * @file
 * Contains custom actions for Rules.
 */

/**
 * Implements hook_rules_action_info().
 */
function hps_courses_rules_action_info() {
  return array(
    'hps_courses_action_import_course' => array(
      'label' => t('Import Course'),
      'group' => t('HPS'),
      'parameter' => array(
        'hps_courses_parameter_course_node' => array(
          'type' => 'node',
          'label' => t('Course Node'),
        ),
      ),
    ),
  );
}

/**
 * Callback for rules action.
 *
 * Triggers import of Course node with Feeds.
 *
 * @param $node
 *   Feeds node object to run import on. Node must be attached to a Feed.
 */
function hps_courses_action_import_course($node) {
  if (!is_object($node)) {
    drupal_set_message(t('Imported cancelled. Missing Course node.', 'error'));
    return false;
  }
  if ($node->type != 'hps_course') {
    drupal_set_message(t('Import aborted. Node is not a Course.', 'error'));
    return false;
  }
  $source = feeds_source('hps_course', $node->nid);
  $source->startImport();
}
