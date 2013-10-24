<?php
/**
 * Implements hook_form_system_theme_settings_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function hpszen_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL)  {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  $form['hpszen_behaviours'] = array(
    '#type' => 'fieldset',
    '#title' => t('Behaviours'),
  );
  $form['hpszen_behaviours']['hpszen_navigation_dropdown'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Use dropdown navigation'),
    '#default_value' => theme_get_setting('hpszen_navigation_dropdown'),
    '#description'   => t('Check here if you want the main navigation to use a drop-down design pattern for sub items.'),
  );

  // Remove some of the base theme's settings.
  /* -- Delete this line if you want to turn off this setting.
  unset($form['themedev']['zen_wireframes']); // We don't need to toggle wireframes on this site.
  // */

  // We are editing the $form in place, so we don't need to return anything.
}
