<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Landing (double) page'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_double_landing.png',
  'theme' => 'hpszen_double_landing',
  'regions' => array(
    'introduction' => t('Introduction'),
    'featured' => t('Featured'),
    'content' => t('Content'),
    'aside' => t('Aside'),
  ),
);
