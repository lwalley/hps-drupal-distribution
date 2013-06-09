<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Basic page'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_basic.png',
  'theme' => 'hpszen_basic',
  'regions' => array(
    'content' => t('Content')
  ),
);
