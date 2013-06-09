<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Landing page'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_landing.png',
  'theme' => 'hpszen_landing',
  'regions' => array(
    'introduction' => t('Introduction'),
    'featured' => t('Featured'),
    'content' => t('Content')
  ),
);
