<?php
/**
 * @file
 * hps_sharing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_sharing_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
