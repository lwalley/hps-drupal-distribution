<?php

/**
 * @file
 * GD Image Toolkit implementation of HPS Media image effects.
 */

/**
 * Scales an image to the exact width and height given.
 *
 * This function achieves the target aspect ratio by scaling so that one
 * dimension fits and the remaining is larger than desired, then it crops the
 * remaining dimension. If the remaining dimension is the width then the crop is
 * even on both sides, if it is height then the top of the image is favoured
 * depeneding on how drastic the crop is.
 *
 * The resulting image always has the exact target dimensions.
 *
 * @param $image
 *   An image object returned by image_load().
 * @param $width
 *   The target width, in pixels.
 * @param $height
 *   The target height, in pixels.
 *
 * @return
 *   TRUE on success, FALSE on failure.
 *
 * @see image_load()
 * @see image_resize()
 * @see image_crop()
 */
function image_gd_hps_scale_and_crop(stdClass $image, $width, $height) {
  $scale = max($width / $image->info['width'], $height / $image->info['height']);

  $x = _calculate_x_coordinate_point($image->info['width'] * $scale, $width);
  $y = _calculate_y_coordinate_point($image->info['height'] * $scale, $height);

  if (image_resize($image, $image->info['width'] * $scale, $image->info['height'] * $scale)) {
    return image_crop($image, $x, $y, $width, $height);
  }
  return FALSE;
}

/**
 * Crop an image using different offset depending on how much of the image
 * is being chopped off.
 *
 * @param $image
 *   An image object returned by image_load().
 * @param $width
 *   The target width, in pixels.
 * @param $height
 *   The target height, in pixels.
 *
 * @return
 *   TRUE on success, FALSE on failure.
 *
 * @see image_crop()
 * @see image_gd_crop()
 */
function image_gd_hps_crop(stdClass $image, $width, $height) {

  $aspect = $image->info['height'] / $image->info['width'];
  if (empty($height)) $height = $width / $aspect;
  if (empty($width)) $width = $height * $aspect;

  $width = (int) round($width);
  $height = (int) round($height);

  $x = _calculate_x_coordinate_point($image->info['width'], $width);
  $y = _calculate_y_coordinate_point($image->info['height'], $height);

  return image_toolkit_invoke('crop', $image, array($x, $y, $width, $height));
}

/**
 * Relatively scales an image while maintaining aspect ratio.
 *
 * The resulting image can be smaller for one or both target dimensions.
 *
 * @param $image
 *   An image object returned by image_load().
 * @param $width
 *   The target width, as a percentage integer of the existing width. If this
 *   value is omitted then the scaling will based only on the height value.
 * @param $height
 *   The target height, as a percentage integer of the existing height. If this
 *   value is omitted then the scaling will based only on the width value.
 * @param $minimum_width
 *   Minimum target width, in pixels. Width will not be scaled less than this
 *   value. If value is omitted then the scaling will not be restricted.
 * @param $minimum_height
 *   Minimum target height, in pixels. Height will not be scaled less than this
 *   value. If value is omitted then the scaling will not be restricted.
 *
 * @return
 *   TRUE on success, FALSE on failure.
 *
 * @see image_dimensions_scale()
 * @see image_load()
 * @see image_scale_and_crop()
 */
function image_gd_hps_relative_scale(stdClass $image, $width = NULL, $height = NULL, $minimum_width = NULL, $minimum_height = NULL) {
  // Form validation ensures we have width and height values between and
  // including 1 and 99 so no need to check here.
  // @see _hps_relative_scale_validate()

  $dimensions = $image->info;

  $target_width = NULL;
  if ($width) {
    $target_width = $dimensions['width'] * ($width / 100);
    if ($target_width < $minimum_width) {
      $target_width = $minimum_width;
    }
  }

  $target_height = NULL;
  if ($height) {
    $target_height = $dimensions['height'] * ($height / 100);
    if ($target_height < $minimum_height) {
      $target_height = $minimum_height;
    }
  }

  // Scale the dimensions - if they don't change then just return success.
  if (!image_dimensions_scale($dimensions, $target_width, $target_height)) {
    return TRUE;
  }

  return image_resize($image, $dimensions['width'], $dimensions['height']);
}

/**
 * Helper function to determine the x coordinate point for top left crop
 * area.
 *
 * @param int $image_width
 *   Width in pixels of the original image.
 * @param int $crop_width
 *   Width of the requested crop.
 * @return int
 *   Top left x coordinate point for the crop area in pixels.
 */
function _calculate_x_coordinate_point($image_width, $crop_width) {
  // Crop width evenly since it's difficult to guess which side is important
  return (int) round(($image_width - $crop_width) / 2);
}

/**
 * Helper function to determine the y coordinate point for top left crop
 * area.
 *
 * Assumes the most important bit of the image is towards the top.
 *
 * @param int $image_height
 *   Height in pixels of the original image.
 * @param int $crop_height
 *   Height of the requested crop.
 * @return int
 *   Top left y coordinate point for the crop area in pixels.
 */
function _calculate_y_coordinate_point($image_height, $crop_height) {
  $crop_ratio = $crop_height / $image_height;
  if ($crop_ratio > 0.7) {
    // Chopping nothing or less than 30% off the original image favour the top
    // as a ratio of the difference
    $y = (int) round(($image_height - $crop_height) / 4);
  } elseif ($crop_ratio > 0.5 ) {
    // Chopping off between 20% and 50% of the image
    // Favour the top area of the image for the crop as a fixed percentage of
    // the original dimension.
    $y = (int) round(0.1 * $image_height);
  } else {
    // Chopping off more than 50% of the image
    // Favour the top area of the image for the crop as a fixed percentage of
    // the original dimension.
    $y = (int) round(0.2 * $image_height);
  }

  return $y;
}
