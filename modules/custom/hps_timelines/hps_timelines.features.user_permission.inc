<?php
/**
 * @file
 * hps_timelines.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_timelines_user_default_permissions() {
  $permissions = array();

  // Exported permission: create hps_timeline_event content.
  $permissions['create hps_timeline_event content'] = array(
    'name' => 'create hps_timeline_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_timeline_event content.
  $permissions['delete any hps_timeline_event content'] = array(
    'name' => 'delete any hps_timeline_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_timeline_event content.
  $permissions['delete own hps_timeline_event content'] = array(
    'name' => 'delete own hps_timeline_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_timeline_event content.
  $permissions['edit any hps_timeline_event content'] = array(
    'name' => 'edit any hps_timeline_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_timeline_event content.
  $permissions['edit own hps_timeline_event content'] = array(
    'name' => 'edit own hps_timeline_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
