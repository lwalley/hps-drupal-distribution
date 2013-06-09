<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Introduction 1, Featured 1, Basic 1'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_i1_f1_b1.png',
  'theme' => 'hpszen_i1_f1_b1',
  'regions' => array(
    'i1' => t('Introduction 1'),
    'f1' => t('Featured 1'),
    'b1' => t('Basic 1')
  ),
);
