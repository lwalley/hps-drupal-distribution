<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Introduction 1, Featured 3, Basic 3, After 1'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_i1_f3_b3_a1.png',
  'theme' => 'hpszen_i1_f3_b3_a1',
  'regions' => array(
    'i1' => t('Introduction 1'),
    'f1' => t('Featured 1'),
    'f2' => t('Featured 2'),
    'f3' => t('Featured 3'),
    'b1' => t('Basic 1'),
    'b2' => t('Basic 2'),
    'b3' => t('Basic 3'),
    'a1' => t('After 1')
  ),
);
