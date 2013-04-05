<?php
/**
 * @file
 * hps_courses_ui.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_courses_ui_user_default_permissions() {
  $permissions = array();

  // Exported permission: create hps_course content.
  $permissions['create hps_course content'] = array(
    'name' => 'create hps_course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_course content.
  $permissions['delete any hps_course content'] = array(
    'name' => 'delete any hps_course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_course content.
  $permissions['delete own hps_course content'] = array(
    'name' => 'delete own hps_course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in hps_course_item_type.
  $permissions['delete terms in hps_course_item_type'] = array(
    'name' => 'delete terms in hps_course_item_type',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in hps_participant_role.
  $permissions['delete terms in hps_participant_role'] = array(
    'name' => 'delete terms in hps_participant_role',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any hps_course content.
  $permissions['edit any hps_course content'] = array(
    'name' => 'edit any hps_course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_course content.
  $permissions['edit own hps_course content'] = array(
    'name' => 'edit own hps_course content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in hps_course_item_type.
  $permissions['edit terms in hps_course_item_type'] = array(
    'name' => 'edit terms in hps_course_item_type',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in hps_participant_role.
  $permissions['edit terms in hps_participant_role'] = array(
    'name' => 'edit terms in hps_participant_role',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: enter hps_course revision log entry.
  $permissions['enter hps_course revision log entry'] = array(
    'name' => 'enter hps_course revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_course authored by option.
  $permissions['override hps_course authored by option'] = array(
    'name' => 'override hps_course authored by option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_course authored on option.
  $permissions['override hps_course authored on option'] = array(
    'name' => 'override hps_course authored on option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_course promote to front page option.
  $permissions['override hps_course promote to front page option'] = array(
    'name' => 'override hps_course promote to front page option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_course published option.
  $permissions['override hps_course published option'] = array(
    'name' => 'override hps_course published option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_course revision option.
  $permissions['override hps_course revision option'] = array(
    'name' => 'override hps_course revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_course sticky option.
  $permissions['override hps_course sticky option'] = array(
    'name' => 'override hps_course sticky option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}
