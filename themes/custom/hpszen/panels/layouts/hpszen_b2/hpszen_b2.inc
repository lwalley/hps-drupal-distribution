<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Basic 2'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_b2.png',
  'theme' => 'hpszen_b2',
  'regions' => array(
    'b1' => t('Basic 1'),
    'b2' => t('Basic 2')
  ),
);
