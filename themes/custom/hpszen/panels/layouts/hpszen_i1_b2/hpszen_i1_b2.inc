<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Introduction 1, Basic 2'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_i1_b2.png',
  'theme' => 'hpszen_i1_b2',
  'regions' => array(
    'i1' => t('Introduction 1'),
    'b1' => t('Basic 1'),
    'b2' => t('Basic 2')
  ),
);
