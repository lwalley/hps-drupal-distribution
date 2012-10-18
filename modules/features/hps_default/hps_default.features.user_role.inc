<?php
/**
 * @file
 * hps_default.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hps_default_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '2',
  );

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => '3',
  );

  return $roles;
}
