<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Primary, Aside Boxes'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_primary_aside_boxes.png',
  'theme' => 'hpszen_primary_aside_boxes',
  'regions' => array(
    'primary-box' => t('Primary Box'),
    'aside-box' => t('Aside Box')
  ),
);
