<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Index page'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_index.png',
  'theme' => 'hpszen_index',
  'regions' => array(
    'introduction' => t('Introduction'),
    'content' => t('Content'),
    'aside' => t('Aside'),
  ),
);
