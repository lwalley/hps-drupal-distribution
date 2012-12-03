<?php

/**
 * @file dspaced.admin.inc
 * Menu callbacks for DSpaced administration settings.
 */

/**
 * Page callback for /admin/config/dspaced/settings.
 */
function dspaced_admin_settings() {

  module_load_include('inc', 'dspaced', 'dspaced.feeds');

  $rest_baseurl = _dspaced_repository_rest_baseurl();

  $form = array();
  $form['dspaced_repository'] = array(
    '#type' => 'fieldset',
    '#title' => t('Repository')
  );
  $form['dspaced_repository']['dspaced_repository_rest_baseurl'] = array(
    '#type' => 'textfield',
    '#title' => t('REST base URL'),
    '#default_value' => $rest_baseurl,
    '#description' => t("Enter the address of your DSpace repository's " .
                        "REST API base path, for example http://repository.edu/rest."),
    '#maxlength' => 100,
  );
  // Check status of repository connections, and build community list.
  $ping = _dspaced_ping_repository();
  if ($ping === DSPACED_PING_MISSING_REST_BASEURL) {
    $status = array(
      'class' => 'tip',
      'description' => "Enter the base URL of your DSpace repository's REST API to " .
        "get started. We'll then check the connection and show you which communities " .
        "we find. Once we've found your communities you'll be able to select which ones " .
        "you'd like to import items from."
    );
  }
  elseif ($ping === DSPACED_PING_REQUEST_ERROR) {
    $status = array(
      'class' => 'error',
      'description' => "Connection not established. Check that !rest_baseurl points " .
        "to your repository's REST API path e.g. http://repository.edu/rest and that " .
        "your repository is online and accessible to this Drupal application."
    );
  }
  elseif ($ping === DSPACED_PING_RESPONSE_ERROR) {
    $status = array(
      'class' => 'error',
      'description' => "Invalid response from REST API. Check that !rest_baseurl points " .
        "to your repository's REST API path e.g. http://repository.edu/rest."
    );
  }
  elseif (is_array($ping) && ($community_ids_options = $ping)) {
    $status = array(
      'class' => 'connected',
      'description' => "Connected to !rest_baseurl."
    );
  }
  else {
    $status = array(
      'class' => 'error',
      'description' => "There is a problem with the connection to !rest_baseurl but " .
        "we're not sure what it is."
    );
  }

  $form['dspaced_repository']['connection_status'] = array(
    '#prefix' => '<p class="' . $status['class'] . '">',
    '#markup' => t($status['description'], array('!rest_baseurl' => $rest_baseurl)),
    '#suffix' => '</p>',
  );
  if (isset($community_ids_options) && $community_ids_options) {
    $form['dspaced_communities'] = array(
      '#type' => 'fieldset',
      '#title' => t('Communities'),
      '#description' => t('%communities found in your repository.',
        array('%communities' => format_plural(count($community_ids_options),
        '1 community', '@count communities'))),
    );
    $form['dspaced_communities']['dspaced_community_dspace_entity_ids'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Import source'),
      '#default_value' => _dspaced_selected_community_dspace_entity_ids(),
      '#options' => $community_ids_options,
      '#description' => t('Select which communities items should be imported from. ' .
                          'Please note that if you deselect a community, all data ' .
                          'imported from that community, including images, will be deleted.'),
    );
    $form['#submit'][] = 'dspaced_admin_settings_submit';
  }
  return system_settings_form($form);
}
/**
 * Validation callback for /admin/config/dspaced/settings.
 */
function dspaced_admin_settings_validate($form, &$form_state) {
}

/**
 * Submit callback for /admin/config/dspaced/settings.
 */
function dspaced_admin_settings_submit($form, &$form_state) {
  $community_dspace_entity_ids = $form_state['values']['dspaced_community_dspace_entity_ids'];
  $import = array();
  $clear= array();
  foreach ($community_dspace_entity_ids as $id => $selected) {
    if ($selected) {
      $import[] = $id;
    }
    else {
      $clear[] = $id;
    }
  }
  if ($import) {
    _dspaced_import_communities($import);
  }
  if ($clear) {
    drupal_set_message(t('Hey, why are you trying to delete stuff? I totally ' .
                         'commented out the delete functionality because I haven\'t ' .
                         'added a confirmation step to the form yet. If you really want ' .
                         'to delete it go to the dspaced.admin.inc file and uncomment the ' .
                         'function call to _dspaced_clear_communities().'), 'warning');
    // @todo commented delete out needs a confirmation step... yikes
    // @see http://drupal.org/node/470834
    //_dspaced_clear_communities($clear);
  }
}
