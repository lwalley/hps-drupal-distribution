<?php
/**
 * @file
 * hps_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: create hps_event content.
  $permissions['create hps_event content'] = array(
    'name' => 'create hps_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_event content.
  $permissions['delete any hps_event content'] = array(
    'name' => 'delete any hps_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_event content.
  $permissions['delete own hps_event content'] = array(
    'name' => 'delete own hps_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_event content.
  $permissions['edit any hps_event content'] = array(
    'name' => 'edit any hps_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_event content.
  $permissions['edit own hps_event content'] = array(
    'name' => 'edit own hps_event content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: enter hps_event revision log entry.
  $permissions['enter hps_event revision log entry'] = array(
    'name' => 'enter hps_event revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_event authored by option.
  $permissions['override hps_event authored by option'] = array(
    'name' => 'override hps_event authored by option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_event authored on option.
  $permissions['override hps_event authored on option'] = array(
    'name' => 'override hps_event authored on option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_event promote to front page option.
  $permissions['override hps_event promote to front page option'] = array(
    'name' => 'override hps_event promote to front page option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_event published option.
  $permissions['override hps_event published option'] = array(
    'name' => 'override hps_event published option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_event revision option.
  $permissions['override hps_event revision option'] = array(
    'name' => 'override hps_event revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_event sticky option.
  $permissions['override hps_event sticky option'] = array(
    'name' => 'override hps_event sticky option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}
