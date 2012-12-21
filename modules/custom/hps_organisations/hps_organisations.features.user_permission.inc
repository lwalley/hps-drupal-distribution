<?php
/**
 * @file
 * hps_organisations.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_organisations_user_default_permissions() {
  $permissions = array();

  // Exported permission: create hps_organisation content.
  $permissions['create hps_organisation content'] = array(
    'name' => 'create hps_organisation content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_organisation content.
  $permissions['delete any hps_organisation content'] = array(
    'name' => 'delete any hps_organisation content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_organisation content.
  $permissions['delete own hps_organisation content'] = array(
    'name' => 'delete own hps_organisation content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_organisation content.
  $permissions['edit any hps_organisation content'] = array(
    'name' => 'edit any hps_organisation content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_organisation content.
  $permissions['edit own hps_organisation content'] = array(
    'name' => 'edit own hps_organisation content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
