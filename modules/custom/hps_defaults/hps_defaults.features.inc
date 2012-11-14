<?php
/**
 * @file
 * hps_defaults.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_defaults_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

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

  // Exported image style: hps_thumbnail.
  $styles['hps_thumbnail'] = array(
    'name' => 'hps_thumbnail',
    'effects' => array(
      25 => array(
        'label' => 'HPS Scale and Crop',
        'help' => 'Scales image so that one dimension fits and the other is larger than desired, then crops the remaining dimension. If the remainin dimension is width the crop will be even, if the remaining dimension is height then the top is favoured depending on how drastic the crop is.',
        'effect callback' => '_hps_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'hps_media',
        'name' => 'hps_scale_and_crop',
        'data' => array(
          'width' => '360',
          'height' => '300',
        ),
        'weight' => '-10',
      ),
      24 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => '300',
          'height' => '300',
          'anchor' => 'center-top',
        ),
        'weight' => '-9',
      ),
    ),
  );

  return $styles;
}
