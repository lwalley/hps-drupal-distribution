<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Row 1 - 2'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_row_1_2.png',
  'theme' => 'hpszen_row_1_2',
  'regions' => array(
    'row-1-1' => t('Row 1 - 1'),
    'row-1-2' => t('Row 1 - 2')
  ),
);
