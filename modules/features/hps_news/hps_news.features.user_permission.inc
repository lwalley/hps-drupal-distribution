<?php
/**
 * @file
 * hps_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: create hps_news content.
  $permissions['create hps_news content'] = array(
    'name' => 'create hps_news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_news content.
  $permissions['delete any hps_news content'] = array(
    'name' => 'delete any hps_news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_news content.
  $permissions['delete own hps_news content'] = array(
    'name' => 'delete own hps_news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_news content.
  $permissions['edit any hps_news content'] = array(
    'name' => 'edit any hps_news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_news content.
  $permissions['edit own hps_news content'] = array(
    'name' => 'edit own hps_news content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
