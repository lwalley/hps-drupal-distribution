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

  // Exported permission: enter hps_featured_content revision log entry.
  $permissions['enter hps_featured_content revision log entry'] = array(
    'name' => 'enter hps_featured_content revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_featured_content authored by option.
  $permissions['override hps_featured_content authored by option'] = array(
    'name' => 'override hps_featured_content authored by option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_featured_content authored on option.
  $permissions['override hps_featured_content authored on option'] = array(
    'name' => 'override hps_featured_content authored on option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_featured_content promote to front page option.
  $permissions['override hps_featured_content promote to front page option'] = array(
    'name' => 'override hps_featured_content promote to front page option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_featured_content published option.
  $permissions['override hps_featured_content published option'] = array(
    'name' => 'override hps_featured_content published option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_featured_content revision option.
  $permissions['override hps_featured_content revision option'] = array(
    'name' => 'override hps_featured_content revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_featured_content sticky option.
  $permissions['override hps_featured_content sticky option'] = array(
    'name' => 'override hps_featured_content sticky option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}
