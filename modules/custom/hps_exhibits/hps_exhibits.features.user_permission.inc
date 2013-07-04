<?php
/**
 * @file
 * hps_exhibits.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_exhibits_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer hps exhibits.
  $permissions['administer hps exhibits'] = array(
    'name' => 'administer hps exhibits',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'hps_exhibits',
  );

  // Exported permission: create hps_exhibit content.
  $permissions['create hps_exhibit content'] = array(
    'name' => 'create hps_exhibit content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create hps_exhibit_information_page content.
  $permissions['create hps_exhibit_information_page content'] = array(
    'name' => 'create hps_exhibit_information_page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create hps_exhibit_narrative content.
  $permissions['create hps_exhibit_narrative content'] = array(
    'name' => 'create hps_exhibit_narrative content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_exhibit content.
  $permissions['delete any hps_exhibit content'] = array(
    'name' => 'delete any hps_exhibit content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_exhibit_information_page content.
  $permissions['delete any hps_exhibit_information_page content'] = array(
    'name' => 'delete any hps_exhibit_information_page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hps_exhibit_narrative content.
  $permissions['delete any hps_exhibit_narrative content'] = array(
    'name' => 'delete any hps_exhibit_narrative content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_exhibit content.
  $permissions['delete own hps_exhibit content'] = array(
    'name' => 'delete own hps_exhibit content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_exhibit_information_page content.
  $permissions['delete own hps_exhibit_information_page content'] = array(
    'name' => 'delete own hps_exhibit_information_page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hps_exhibit_narrative content.
  $permissions['delete own hps_exhibit_narrative content'] = array(
    'name' => 'delete own hps_exhibit_narrative content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_exhibit content.
  $permissions['edit any hps_exhibit content'] = array(
    'name' => 'edit any hps_exhibit content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_exhibit_information_page content.
  $permissions['edit any hps_exhibit_information_page content'] = array(
    'name' => 'edit any hps_exhibit_information_page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hps_exhibit_narrative content.
  $permissions['edit any hps_exhibit_narrative content'] = array(
    'name' => 'edit any hps_exhibit_narrative content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_exhibit content.
  $permissions['edit own hps_exhibit content'] = array(
    'name' => 'edit own hps_exhibit content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_exhibit_information_page content.
  $permissions['edit own hps_exhibit_information_page content'] = array(
    'name' => 'edit own hps_exhibit_information_page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hps_exhibit_narrative content.
  $permissions['edit own hps_exhibit_narrative content'] = array(
    'name' => 'edit own hps_exhibit_narrative content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: enter hps_exhibit revision log entry.
  $permissions['enter hps_exhibit revision log entry'] = array(
    'name' => 'enter hps_exhibit revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: enter hps_exhibit_information_page revision log entry.
  $permissions['enter hps_exhibit_information_page revision log entry'] = array(
    'name' => 'enter hps_exhibit_information_page revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: enter hps_exhibit_narrative revision log entry.
  $permissions['enter hps_exhibit_narrative revision log entry'] = array(
    'name' => 'enter hps_exhibit_narrative revision log entry',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit authored by option.
  $permissions['override hps_exhibit authored by option'] = array(
    'name' => 'override hps_exhibit authored by option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit authored on option.
  $permissions['override hps_exhibit authored on option'] = array(
    'name' => 'override hps_exhibit authored on option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit promote to front page option.
  $permissions['override hps_exhibit promote to front page option'] = array(
    'name' => 'override hps_exhibit promote to front page option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit published option.
  $permissions['override hps_exhibit published option'] = array(
    'name' => 'override hps_exhibit published option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit revision option.
  $permissions['override hps_exhibit revision option'] = array(
    'name' => 'override hps_exhibit revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit sticky option.
  $permissions['override hps_exhibit sticky option'] = array(
    'name' => 'override hps_exhibit sticky option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_information_page authored by option.
  $permissions['override hps_exhibit_information_page authored by option'] = array(
    'name' => 'override hps_exhibit_information_page authored by option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_information_page authored on option.
  $permissions['override hps_exhibit_information_page authored on option'] = array(
    'name' => 'override hps_exhibit_information_page authored on option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_information_page promote to front page option.
  $permissions['override hps_exhibit_information_page promote to front page option'] = array(
    'name' => 'override hps_exhibit_information_page promote to front page option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_information_page published option.
  $permissions['override hps_exhibit_information_page published option'] = array(
    'name' => 'override hps_exhibit_information_page published option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_information_page revision option.
  $permissions['override hps_exhibit_information_page revision option'] = array(
    'name' => 'override hps_exhibit_information_page revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_information_page sticky option.
  $permissions['override hps_exhibit_information_page sticky option'] = array(
    'name' => 'override hps_exhibit_information_page sticky option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_narrative authored by option.
  $permissions['override hps_exhibit_narrative authored by option'] = array(
    'name' => 'override hps_exhibit_narrative authored by option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_narrative authored on option.
  $permissions['override hps_exhibit_narrative authored on option'] = array(
    'name' => 'override hps_exhibit_narrative authored on option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_narrative promote to front page option.
  $permissions['override hps_exhibit_narrative promote to front page option'] = array(
    'name' => 'override hps_exhibit_narrative promote to front page option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_narrative published option.
  $permissions['override hps_exhibit_narrative published option'] = array(
    'name' => 'override hps_exhibit_narrative published option',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_narrative revision option.
  $permissions['override hps_exhibit_narrative revision option'] = array(
    'name' => 'override hps_exhibit_narrative revision option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: override hps_exhibit_narrative sticky option.
  $permissions['override hps_exhibit_narrative sticky option'] = array(
    'name' => 'override hps_exhibit_narrative sticky option',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}
