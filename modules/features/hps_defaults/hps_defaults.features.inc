<?php
/**
 * @file
 * hps_defaults.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function hps_defaults_image_default_styles() {
  $styles = array();

  // Exported image style: hps_large_adaptive.
  $styles['hps_large_adaptive'] = array(
    'name' => 'hps_large_adaptive',
    'effects' => array(
      1 => array(
        'label' => 'Adaptive',
        'help' => 'Adaptive image scale according to client resolution.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'adaptive_image_scale_form',
        'summary theme' => 'adaptive_image_scale_summary',
        'module' => 'adaptive_image',
        'name' => 'adaptive_image',
        'data' => array(
          'resolutions' => '1382, 992, 768, 480',
          'mobile_first' => 1,
          'height' => '',
          'width' => '1382',
          'upscale' => '',
        ),
        'weight' => '0',
      ),
    ),
  );

  return $styles;
}

