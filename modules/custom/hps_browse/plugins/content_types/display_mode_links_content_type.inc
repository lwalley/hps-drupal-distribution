<?php

/**
 * @file
 *
 * Plugin to generate a list of links to different display modes of current
 * taxonomy term page e.g. gallery, list etc.
 *
 */

$plugin = array(
  'title' => t('Display Mode Links'),
  'content_types' => 'display_mode_links_content_type',
  'single' => TRUE,
  'render callback' => '_display_mode_links_content_type_render',
  'description' => t('Displays a list of links which append display modes to the current path alias.'),
  'required context' => array(
    new ctools_context_required(t('Term'), array('term', 'taxonomy_term')),
    new ctools_context_optional(t('Active Display Mode'), 'string'),
  ),
  'edit form' => '_display_mode_links_content_type_edit_form',
  'admin title' => '_display_mode_links_content_type_admin_title',
  'admin info' => '_display_mode_links_content_type_admin_info',
  'category' => array(t('HPS Widgets'), -9),
);

/**
 * Callback to define default administrative title for the pane when building
 * the pane in panels.
 */
function _display_mode_links_content_type_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Display Mode Links');
  if ($conf['override_title'] && !empty($conf['override_title_text'])) {
    $output = filter_xss_admin($conf['override_title_text']);
  }
  return $output;
}

/**
 * Callback to display a preview of the content and other administrative
 * information when building the pane in panels.
 *
 * In this case we'll render the links but with dummy paths since we don't have
 * the term and mode contexts during previews.
 */
function _display_mode_links_content_type_admin_info($subtype, $conf, $context = NULL) {

  $block = _display_mode_links_content_type_render($subtype, $conf, array(), $context);

  if (empty($block->content)) {
    // Content will be empty in preview because we didn't pass any context into
    // the rendererer
    $block->content = t('<h4>Notes for administrators</h4><p>If you have correctly configured ' .
                        'your display modes you will see a list of links below, otherwise add ' .
                        'your display modes in the settings form for the content pane.</p>' .
                        '<p>Since we do not have the required taxonomy term or optional ' .
                        'active display mode contexts during preview the links contain dummy ' .
                        'paths.</p>');
    if (empty($conf['display_modes'])) {
      $block->content .= t('No display modes found, add display modes in the settings form.');
    }
    else {
      // Render links with dummy term and mode contexts
      $block->content .= theme('hps_browse_display_mode_links', array(
        'term' => new stdClass,
        'term_path_alias' => 'dummy/path',
        'display_modes' => $conf['display_modes'],
        'active_mode' => '',
      ));
    }
  }
  return $block;
}

/**
 * Render callback for the body of the Display Mode Links content type.
 *
 * @param string $subtype
 *   Machine name for the content type (pane).
 * @param array $conf
 *   Contains content type (pane) settings from edit form.
 * @param array $args
 *   Array of URL arguments e.g. %term or %mode from taxonomy/term/%term/%mode
 * @param array $context
 *   Array of context objects, in this case we require a taxonomy term context.
 *
 * @return
 *   An object with title and content.
 */
function _display_mode_links_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();

  $block->title = 'Display as';
  if ($conf['override_title']) {
    $block->title = filter_xss_admin($conf['override_title_text']);
  }

  $term = NULL; // Required context.
  $active_mode = NULL; // Optional context.
  foreach ($context as $argument) {
    // @todo figure out if there is a more robust way to identify each context
    if (!isset($argument->plugin)) {
      // If there isn't a plugin property its pobably a 'no context' context
      continue;
    }
    if ($argument->plugin == 'entity:taxonomy_term' && !$argument->empty) {
      $term = clone($argument->data);
    }
    elseif ($argument->plugin == 'string' && !$argument->empty) {
      // We assume the string context is the mode.
      $active_mode = $argument->data;
    }
  }

  if (!isset($term->tid)) {
    // If we don't have the term context, we can't show the display mode links
    // so we return an empty block.
    return $block;
  }

  $term_uri = taxonomy_term_uri($term);
  $term_path_alias = drupal_get_path_alias($term_uri['path']);

  $block->title = t('Display results as');
  $block->delta = $term->tid;
  $block->content = array(
    '#theme' => 'hps_browse_display_mode_links',
    '#term' => $term,
    '#term_path_alias' => $term_path_alias,
    '#display_modes' => $conf['display_modes'],
    '#active_mode' => $active_mode,
  );

  return $block;
}

/**
 * Callback for the Display Mode Links content type edit form.
 *
 * @note Selection box for the taxonomy term context is automatically added to
 *       the top of the form, along with the override title option.
 */
function _display_mode_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $contexts = $form_state['contexts'];
  $form['display_modes'] = array(
    '#type' => 'textfield',
    '#title' => t('Display modes'),
    '#size' => 50,
    '#description' => t('<p>Comma separated list of display modes. For each mode provide a label ' .
                        'and the suffix you want appended to the taxonomy term path. Each suffix ' .
                        'must match a path that Drupal recognises, for example the HPS Browse module ' .
                        'includes a custom page with the path /taxonomy/term/%term/%mode and variants ' .
                        'that use selection rules on %mode to determine which views pane to display.</p>' .
                        '<p>Use the syntax [Label](suffix). For example, if you have a gallery display ' .
                        'and a list display (the default display) for the matching taxonomy term ' .
                        'then you would enter [Gallery](gallery),[List]() note list display suffix ' .
                        'is empty indicating this is the default display that is shown when users ' .
                        'go to taxonomy/term/%term, whereas the gallery display link becomes ' .
                        'taxonomy/term/%term/gallery.</p>'),
    '#default_value' => !empty($conf['display_modes']) ? $conf['display_modes'] : '',
    '#prefix' => '',
    '#suffix' => '',
  );

  return $form;
}

/**
 * Submit callback for Display Mode Links content type edit form.
 */
function _display_mode_links_content_type_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

