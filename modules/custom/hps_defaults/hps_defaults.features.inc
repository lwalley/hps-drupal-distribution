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

  // Exported image style: hps_minor.
  $styles['hps_minor'] = array(
    'name' => 'hps_minor',
    'effects' => array(
      18 => array(
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
        'weight' => '2',
      ),
      19 => array(
        'label' => 'HPS Relative Scale',
        'help' => 'Scales image to a percentage of its existing dimensions. Relative scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated. If both dimensions are specified then the dimension used is the one that would not be calculated, when maintaining aspect ratio, to be bigger than its target. If a minimum dimension is provided it will be used to adjust the target dimension, as needed, prior to scaling. If both dimensions are provided then one of the dimensions may be smaller than its minimum value.',
        'effect callback' => '_hps_relative_scale_effect',
        'form callback' => '_hps_relative_scale_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'hps_media',
        'name' => 'hps_relative_scale',
        'data' => array(
          'width' => '30',
          'height' => '',
          'minimum_width' => '100',
          'minimum_height' => '',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: hps_original.
  $styles['hps_original'] = array(
    'name' => 'hps_original',
    'effects' => array(
      13 => array(
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
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: hps_principal.
  $styles['hps_principal'] = array(
    'name' => 'hps_principal',
    'effects' => array(
      14 => array(
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
        'weight' => '2',
      ),
      15 => array(
        'label' => 'HPS Relative Scale',
        'help' => 'Scales image to a percentage of its existing dimensions. Relative scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated. If both dimensions are specified then the dimension used is the one that would not be calculated, when maintaining aspect ratio, to be bigger than its target. If a minimum dimension is provided it will be used to adjust the target dimension, as needed, prior to scaling. If both dimensions are provided then one of the dimensions may be smaller than its minimum value.',
        'effect callback' => '_hps_relative_scale_effect',
        'form callback' => '_hps_relative_scale_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'hps_media',
        'name' => 'hps_relative_scale',
        'data' => array(
          'width' => '80',
          'height' => '80',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: hps_supplemental.
  $styles['hps_supplemental'] = array(
    'name' => 'hps_supplemental',
    'effects' => array(
      16 => array(
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
        'weight' => '2',
      ),
      17 => array(
        'label' => 'HPS Relative Scale',
        'help' => 'Scales image to a percentage of its existing dimensions. Relative scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated. If both dimensions are specified then the dimension used is the one that would not be calculated, when maintaining aspect ratio, to be bigger than its target. If a minimum dimension is provided it will be used to adjust the target dimension, as needed, prior to scaling. If both dimensions are provided then one of the dimensions may be smaller than its minimum value.',
        'effect callback' => '_hps_relative_scale_effect',
        'form callback' => '_hps_relative_scale_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'hps_media',
        'name' => 'hps_relative_scale',
        'data' => array(
          'width' => '50',
          'height' => '',
          'minimum_width' => '200',
          'minimum_height' => '',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: hps_uniform.
  $styles['hps_uniform'] = array(
    'name' => 'hps_uniform',
    'effects' => array(
      10 => array(
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
        'weight' => '1',
      ),
      11 => array(
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
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}
