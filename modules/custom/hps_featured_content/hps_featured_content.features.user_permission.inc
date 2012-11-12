<?php
/**
 * @file
 * hps_featured_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_featured_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: create hps_featured_content content.
  $permissions['create hps_featured_content content'] = array(
    'name' => 'create hps_featured_content content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_featured_content content.
  $permissions['delete any hps_featured_content content'] = array(
    'name' => 'delete any hps_featured_content content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_featured_content content.
  $permissions['delete own hps_featured_content content'] = array(
    'name' => 'delete own hps_featured_content content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_featured_content content.
  $permissions['edit any hps_featured_content content'] = array(
    'name' => 'edit any hps_featured_content content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_featured_content content.
  $permissions['edit own hps_featured_content content'] = array(
    'name' => 'edit own hps_featured_content content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
