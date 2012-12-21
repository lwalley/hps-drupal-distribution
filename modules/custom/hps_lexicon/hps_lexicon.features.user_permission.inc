<?php
/**
 * @file
 * hps_lexicon.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_lexicon_user_default_permissions() {
  $permissions = array();

  // Exported permission: access lexicon.
  $permissions['access lexicon'] = array(
    'name' => 'access lexicon',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'lexicon',
  );

  // Exported permission: administer lexicon.
  $permissions['administer lexicon'] = array(
    'name' => 'administer lexicon',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'lexicon',
  );

  return $permissions;
}
