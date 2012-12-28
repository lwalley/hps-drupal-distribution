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

  // Exported permission: enter hps_news revision log entry.
  $permissions['enter hps_news revision log entry'] = array(
    'name' => 'enter hps_news revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_news authored by option.
  $permissions['override hps_news authored by option'] = array(
    'name' => 'override hps_news authored by option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_news authored on option.
  $permissions['override hps_news authored on option'] = array(
    'name' => 'override hps_news authored on option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_news promote to front page option.
  $permissions['override hps_news promote to front page option'] = array(
    'name' => 'override hps_news promote to front page option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_news published option.
  $permissions['override hps_news published option'] = array(
    'name' => 'override hps_news published option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_news revision option.
  $permissions['override hps_news revision option'] = array(
    'name' => 'override hps_news revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_news sticky option.
  $permissions['override hps_news sticky option'] = array(
    'name' => 'override hps_news sticky option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}
