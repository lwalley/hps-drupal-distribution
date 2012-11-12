<?php
/**
 * @file
 * hps_browse.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_browse_user_default_permissions() {
  $permissions = array();

  // Exported permission: create hps_browse_by content.
  $permissions['create hps_browse_by content'] = array(
    'name' => 'create hps_browse_by content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_browse_by content.
  $permissions['delete any hps_browse_by content'] = array(
    'name' => 'delete any hps_browse_by content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_browse_by content.
  $permissions['delete own hps_browse_by content'] = array(
    'name' => 'delete own hps_browse_by content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_browse_by content.
  $permissions['edit any hps_browse_by content'] = array(
    'name' => 'edit any hps_browse_by content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_browse_by content.
  $permissions['edit own hps_browse_by content'] = array(
    'name' => 'edit own hps_browse_by content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
