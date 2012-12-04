<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
  'title' => t('Primary, Downsides Boxes'),
  'category' => t('HPS Zen Responsive'),
  'icon' => 'hpszen_primary_downsides_boxes.png',
  'theme' => 'hpszen_primary_downsides_boxes',
  'regions' => array(
    'primary-box' => t('Primary Box'),
    'aside-box' => t('Aside Box'),
    'downside-box' => t('Downside Box'),
  ),
);
