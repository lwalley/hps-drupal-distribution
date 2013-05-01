<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Landing (triple) page'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_triple_landing.png',
  'theme' => 'hpszen_triple_landing',
  'regions' => array(
    'introduction' => t('Introduction'),
    'featured' => t('Featured'),
    'content' => t('Content'),
    'aside' => t('Aside'),
    'arside' => t('Another aside')
  ),
);
