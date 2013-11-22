<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Basic 3'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_b3.png',
  'theme' => 'hpszen_b3',
  'regions' => array(
    'b1' => t('Basic 1'),
    'b2' => t('Basic 2'),
    'b3' => t('Basic 3')
  ),
);
