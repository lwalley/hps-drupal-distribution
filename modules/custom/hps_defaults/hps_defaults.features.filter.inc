<?php
/**
 * @file
 * hps_defaults.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function hps_defaults_filter_default_formats() {
  $formats = array();

  // Exported format: Standard HTML.
  $formats['hps_standard_html'] = array(
    'format' => 'hps_standard_html',
    'name' => 'Standard HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <table> <p> <img> <address> <h3> <h4> <h5> <h6> <dt> <dd>',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '50',
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
