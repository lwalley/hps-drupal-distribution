<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Primary Box'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_primary_box.png',
  'theme' => 'hpszen_primary_box',
  'regions' => array(
    'primary-box' => t('Primary Box')
  ),
);
