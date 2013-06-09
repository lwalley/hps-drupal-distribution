<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Introduction 1, Results 2'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_i1_r2.png',
  'theme' => 'hpszen_i1_r2',
  'regions' => array(
    'i1' => t('Introduction 1'),
    'r1' => t('Results 1'),
    'r2' => t('Results 2')
  ),
);
