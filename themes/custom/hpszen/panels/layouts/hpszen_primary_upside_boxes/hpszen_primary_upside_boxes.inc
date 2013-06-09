<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  // Upside is just an aside that comes before primary content in document flow.
  'title' => t('Primary, Upside Boxes'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_primary_upside_boxes.png',
  'theme' => 'hpszen_primary_upside_boxes',
  'regions' => array(
    'primary-box' => t('Primary Box'),
    'upside-box' => t('Upside Box')
  ),
);
