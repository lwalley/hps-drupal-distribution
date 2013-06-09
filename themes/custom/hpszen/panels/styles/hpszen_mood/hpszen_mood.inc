<?php

/**
 * @file hpszen_mood.inc
 */

$plugin =  array(
  'title' => t('HPS Zen Mood'),
  'description'   => t('Select whether the panel should appear neutral or accented.'),
  'render region' => 'hpszen_mood_render_region',
  'render pane' => 'hpszen_mood_render_pane',
  'settings form' => 'hpszen_mood_settings_form',
  // @todo theme or preprocess to add mood classes to panels
  // @note this style does nothing at the moment
);

/**
 * Implements hook_render_region().
 */
function hpszen_hpszen_mood_render_region($vars) {
  // @todo add theme or preprocess to add mood classes to panels
  return implode($vars['panes']);
}

/**
 * Implements hook_render_pane().
 */
function hpszen_hpszen_mood_render_pane($vars) {
  return render($vars['content']->content);
}

/**
 * Implements hook_settings_form().
 */
function hpszen_mood_settings_form($style_settings) {
  $form['hpszen_mood'] = array(
    '#type' => 'select',
    '#title' => t('Mood'),
    '#options' => array(
      'hpszen-default' => t('Default'),
      'hpszen-neutral' => t('Neutral'),
      'hpszen-accented' => t('Accented'),
    ),
    '#default_value' => (isset($style_settings['hpszen_mood'])) ? $style_settings['hpszen_mood'] : 'hpszen-default',
  );

  return $form;
}

