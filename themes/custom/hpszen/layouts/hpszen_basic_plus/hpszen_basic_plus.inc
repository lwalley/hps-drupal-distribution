<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Basic page plus'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_basic_plus.png',
  'theme' => 'hpszen_basic_plus',
  'regions' => array(
    'introduction' => t('Introduction'),
    'content' => t('Content')
  ),
);
