<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Index page with facets'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_index.png',
  'theme' => 'hpszen_index',
  'regions' => array(
    'introduction' => t('Introduction'),
    'operations' => t('Operations'),
    'results' => t('Results')
  ),
);
