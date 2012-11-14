<?php
/**
 * @file
 * hps_defaults.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hps_defaults_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access statistics.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: access toolbar.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer advanced pane settings.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer dspaced.
  $permissions['administer dspaced'] = array(
    'name' => 'administer dspaced',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'dspaced',
  );

  // Exported permission: administer facets.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: administer feeds.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: administer fieldgroups.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: administer imce.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'imce',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer page manager.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: administer pane access.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer panels layouts.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer panels styles.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer search_api.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer statistics.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: cancel users with no custom roles.
  $permissions['cancel users with no custom roles'] = array(
    'name' => 'cancel users with no custom roles',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role administrator.
  $permissions['cancel users with role administrator'] = array(
    'name' => 'cancel users with role administrator',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role administrator and other roles.
  $permissions['cancel users with role administrator and other roles'] = array(
    'name' => 'cancel users with role administrator and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role anonymoususer.
  $permissions['cancel users with role anonymoususer'] = array(
    'name' => 'cancel users with role anonymoususer',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role anonymoususer and other roles.
  $permissions['cancel users with role anonymoususer and other roles'] = array(
    'name' => 'cancel users with role anonymoususer and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role authenticateduser.
  $permissions['cancel users with role authenticateduser'] = array(
    'name' => 'cancel users with role authenticateduser',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role authenticateduser and other roles.
  $permissions['cancel users with role authenticateduser and other roles'] = array(
    'name' => 'cancel users with role authenticateduser and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role editor.
  $permissions['cancel users with role editor'] = array(
    'name' => 'cancel users with role editor',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role editor and other roles.
  $permissions['cancel users with role editor and other roles'] = array(
    'name' => 'cancel users with role editor and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role manager.
  $permissions['cancel users with role manager'] = array(
    'name' => 'cancel users with role manager',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: cancel users with role manager and other roles.
  $permissions['cancel users with role manager and other roles'] = array(
    'name' => 'cancel users with role manager and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: change layouts in place editing.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: create article content.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dspaced_entities_community content.
  $permissions['create dspaced_entities_community content'] = array(
    'name' => 'create dspaced_entities_community content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create dspaced_entities_item content.
  $permissions['create dspaced_entities_item content'] = array(
    'name' => 'create dspaced_entities_item content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: create users.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: delete any article content.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dspaced_entities_community content.
  $permissions['delete any dspaced_entities_community content'] = array(
    'name' => 'delete any dspaced_entities_community content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any dspaced_entities_item content.
  $permissions['delete any dspaced_entities_item content'] = array(
    'name' => 'delete any dspaced_entities_item content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own article content.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dspaced_entities_community content.
  $permissions['delete own dspaced_entities_community content'] = array(
    'name' => 'delete own dspaced_entities_community content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own dspaced_entities_item content.
  $permissions['delete own dspaced_entities_item content'] = array(
    'name' => 'delete own dspaced_entities_item content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in dc_description_type.
  $permissions['delete terms in dc_description_type'] = array(
    'name' => 'delete terms in dc_description_type',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in dc_relation_ispartof.
  $permissions['delete terms in dc_relation_ispartof'] = array(
    'name' => 'delete terms in dc_relation_ispartof',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in dc_subject.
  $permissions['delete terms in dc_subject'] = array(
    'name' => 'delete terms in dc_subject',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in dc_subject_lcsh.
  $permissions['delete terms in dc_subject_lcsh'] = array(
    'name' => 'delete terms in dc_subject_lcsh',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in dc_subject_mesh.
  $permissions['delete terms in dc_subject_mesh'] = array(
    'name' => 'delete terms in dc_subject_mesh',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in dc_subject_tag.
  $permissions['delete terms in dc_subject_tag'] = array(
    'name' => 'delete terms in dc_subject_tag',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in dc_type.
  $permissions['delete terms in dc_type'] = array(
    'name' => 'delete terms in dc_type',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in tags.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any article content.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dspaced_entities_community content.
  $permissions['edit any dspaced_entities_community content'] = array(
    'name' => 'edit any dspaced_entities_community content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any dspaced_entities_item content.
  $permissions['edit any dspaced_entities_item content'] = array(
    'name' => 'edit any dspaced_entities_item content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own article content.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dspaced_entities_community content.
  $permissions['edit own dspaced_entities_community content'] = array(
    'name' => 'edit own dspaced_entities_community content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own dspaced_entities_item content.
  $permissions['edit own dspaced_entities_item content'] = array(
    'name' => 'edit own dspaced_entities_item content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in dc_description_type.
  $permissions['edit terms in dc_description_type'] = array(
    'name' => 'edit terms in dc_description_type',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in dc_relation_ispartof.
  $permissions['edit terms in dc_relation_ispartof'] = array(
    'name' => 'edit terms in dc_relation_ispartof',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in dc_subject.
  $permissions['edit terms in dc_subject'] = array(
    'name' => 'edit terms in dc_subject',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in dc_subject_lcsh.
  $permissions['edit terms in dc_subject_lcsh'] = array(
    'name' => 'edit terms in dc_subject_lcsh',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in dc_subject_mesh.
  $permissions['edit terms in dc_subject_mesh'] = array(
    'name' => 'edit terms in dc_subject_mesh',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in dc_subject_tag.
  $permissions['edit terms in dc_subject_tag'] = array(
    'name' => 'edit terms in dc_subject_tag',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in dc_type.
  $permissions['edit terms in dc_type'] = array(
    'name' => 'edit terms in dc_type',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in tags.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit users with no custom roles.
  $permissions['edit users with no custom roles'] = array(
    'name' => 'edit users with no custom roles',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role administrator.
  $permissions['edit users with role administrator'] = array(
    'name' => 'edit users with role administrator',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role administrator and other roles.
  $permissions['edit users with role administrator and other roles'] = array(
    'name' => 'edit users with role administrator and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role anonymoususer.
  $permissions['edit users with role anonymoususer'] = array(
    'name' => 'edit users with role anonymoususer',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role anonymoususer and other roles.
  $permissions['edit users with role anonymoususer and other roles'] = array(
    'name' => 'edit users with role anonymoususer and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role authenticateduser.
  $permissions['edit users with role authenticateduser'] = array(
    'name' => 'edit users with role authenticateduser',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role authenticateduser and other roles.
  $permissions['edit users with role authenticateduser and other roles'] = array(
    'name' => 'edit users with role authenticateduser and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role editor.
  $permissions['edit users with role editor'] = array(
    'name' => 'edit users with role editor',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role editor and other roles.
  $permissions['edit users with role editor and other roles'] = array(
    'name' => 'edit users with role editor and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role manager.
  $permissions['edit users with role manager'] = array(
    'name' => 'edit users with role manager',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: edit users with role manager and other roles.
  $permissions['edit users with role manager and other roles'] = array(
    'name' => 'edit users with role manager and other roles',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: geocoder_service_all_handlers.
  $permissions['geocoder_service_all_handlers'] = array(
    'name' => 'geocoder_service_all_handlers',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_exif.
  $permissions['geocoder_service_handler_exif'] = array(
    'name' => 'geocoder_service_handler_exif',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_google.
  $permissions['geocoder_service_handler_google'] = array(
    'name' => 'geocoder_service_handler_google',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_gpx.
  $permissions['geocoder_service_handler_gpx'] = array(
    'name' => 'geocoder_service_handler_gpx',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_json.
  $permissions['geocoder_service_handler_json'] = array(
    'name' => 'geocoder_service_handler_json',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_kml.
  $permissions['geocoder_service_handler_kml'] = array(
    'name' => 'geocoder_service_handler_kml',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_latlon.
  $permissions['geocoder_service_handler_latlon'] = array(
    'name' => 'geocoder_service_handler_latlon',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_mapquest_nominatim.
  $permissions['geocoder_service_handler_mapquest_nominatim'] = array(
    'name' => 'geocoder_service_handler_mapquest_nominatim',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_wkt.
  $permissions['geocoder_service_handler_wkt'] = array(
    'name' => 'geocoder_service_handler_wkt',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_yahoo.
  $permissions['geocoder_service_handler_yahoo'] = array(
    'name' => 'geocoder_service_handler_yahoo',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: geocoder_service_handler_yandex.
  $permissions['geocoder_service_handler_yandex'] = array(
    'name' => 'geocoder_service_handler_yandex',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: use page manager.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: use panels caching features.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels dashboard.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels in place editing.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels locks.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format hps_standard_html.
  $permissions['use text format hps_standard_html'] = array(
    'name' => 'use text format hps_standard_html',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: view advanced help index.
  $permissions['view advanced help index'] = array(
    'name' => 'view advanced help index',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: view advanced help popup.
  $permissions['view advanced help popup'] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: view advanced help topic.
  $permissions['view advanced help topic'] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: view pane admin links.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: view post access counter.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
