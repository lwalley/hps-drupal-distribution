<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Home page'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_home.png',
  'theme' => 'hpszen_home',
  'regions' => array(
    'introduction' => t('Introduction'),
    'featured' => t('Featured'),
    'content' => t('Content'),
    'aside' => t('Aside'),
  ),
);
