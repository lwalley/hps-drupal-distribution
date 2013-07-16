<?php
/**
 * @file
 * hps_exhibits.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hps_exhibits_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_hps_exhibit';
  $strongarm->value = 'edit-print';
  $export['additional_settings__active_tab_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_hps_exhibit_information_page';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_hps_exhibit_narrative';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_allowed_types';
  $strongarm->value = array(
    0 => 'book',
    1 => 'hps_exhibit',
    2 => 'hps_exhibit_narrative',
  );
  $export['book_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_child_type';
  $strongarm->value = 'book';
  $export['book_child_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_hps_exhibit';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_hps_exhibit_information_page';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_hps_exhibit_narrative';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hps_exhibit';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'hps_featured_content' => array(
        'custom_settings' => FALSE,
      ),
      'hps_search_results' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hps_exhibit_information_page';
  $strongarm->value = array();
  $export['field_bundle_settings_node__hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hps_exhibit_narrative';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '40',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hps_exhibit';
  $strongarm->value = array();
  $export['menu_options_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hps_exhibit_information_page';
  $strongarm->value = array();
  $export['menu_options_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hps_exhibit_narrative';
  $strongarm->value = array();
  $export['menu_options_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hps_exhibit';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hps_exhibit_information_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hps_exhibit_narrative';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hps_exhibit';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hps_exhibit_information_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hps_exhibit_narrative';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hps_exhibit';
  $strongarm->value = '1';
  $export['node_preview_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hps_exhibit_information_page';
  $strongarm->value = '1';
  $export['node_preview_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hps_exhibit_narrative';
  $strongarm->value = '1';
  $export['node_preview_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hps_exhibit';
  $strongarm->value = 0;
  $export['node_submitted_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hps_exhibit_information_page';
  $strongarm->value = 0;
  $export['node_submitted_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hps_exhibit_narrative';
  $strongarm->value = 0;
  $export['node_submitted_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_manager_default_rids_node_hps_exhibit';
  $strongarm->value = array(
    3 => '3',
  );
  $export['og_group_manager_default_rids_node_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_manager_full_access';
  $strongarm->value = 0;
  $export['og_group_manager_full_access'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_node_access_strict';
  $strongarm->value = 0;
  $export['og_node_access_strict'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hps_exhibit_information_page_pattern';
  $strongarm->value = 'exploring/exhibits/[node:og-group-ref:title]/info/[node:title]';
  $export['pathauto_node_hps_exhibit_information_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hps_exhibit_narrative_pattern';
  $strongarm->value = 'exploring/exhibits/[node:og-group-ref:title]/narrative/[node:title]';
  $export['pathauto_node_hps_exhibit_narrative_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hps_exhibit_pattern';
  $strongarm->value = 'exploring/exhibits/[node:title]';
  $export['pathauto_node_hps_exhibit_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_hps_exhibit';
  $strongarm->value = 0;
  $export['print_display_comment_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_hps_exhibit_information_page';
  $strongarm->value = 0;
  $export['print_display_comment_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_hps_exhibit_narrative';
  $strongarm->value = 0;
  $export['print_display_comment_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_hps_exhibit';
  $strongarm->value = 0;
  $export['print_display_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_hps_exhibit_information_page';
  $strongarm->value = 1;
  $export['print_display_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_hps_exhibit_narrative';
  $strongarm->value = 1;
  $export['print_display_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_hps_exhibit';
  $strongarm->value = 0;
  $export['print_display_urllist_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_hps_exhibit_information_page';
  $strongarm->value = 1;
  $export['print_display_urllist_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_hps_exhibit_narrative';
  $strongarm->value = 1;
  $export['print_display_urllist_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_comment_hps_exhibit';
  $strongarm->value = 0;
  $export['print_mail_display_comment_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_comment_hps_exhibit_information_page';
  $strongarm->value = 0;
  $export['print_mail_display_comment_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_comment_hps_exhibit_narrative';
  $strongarm->value = 0;
  $export['print_mail_display_comment_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_hps_exhibit';
  $strongarm->value = 0;
  $export['print_mail_display_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_hps_exhibit_information_page';
  $strongarm->value = 1;
  $export['print_mail_display_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_hps_exhibit_narrative';
  $strongarm->value = 1;
  $export['print_mail_display_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_urllist_hps_exhibit';
  $strongarm->value = 0;
  $export['print_mail_display_urllist_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_urllist_hps_exhibit_information_page';
  $strongarm->value = 1;
  $export['print_mail_display_urllist_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_mail_display_urllist_hps_exhibit_narrative';
  $strongarm->value = 1;
  $export['print_mail_display_urllist_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_comment_hps_exhibit';
  $strongarm->value = 0;
  $export['print_pdf_display_comment_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_comment_hps_exhibit_information_page';
  $strongarm->value = 0;
  $export['print_pdf_display_comment_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_comment_hps_exhibit_narrative';
  $strongarm->value = 0;
  $export['print_pdf_display_comment_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_hps_exhibit';
  $strongarm->value = 0;
  $export['print_pdf_display_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_hps_exhibit_information_page';
  $strongarm->value = 1;
  $export['print_pdf_display_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_hps_exhibit_narrative';
  $strongarm->value = 1;
  $export['print_pdf_display_hps_exhibit_narrative'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_urllist_hps_exhibit';
  $strongarm->value = 0;
  $export['print_pdf_display_urllist_hps_exhibit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_urllist_hps_exhibit_information_page';
  $strongarm->value = 1;
  $export['print_pdf_display_urllist_hps_exhibit_information_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_pdf_display_urllist_hps_exhibit_narrative';
  $strongarm->value = 1;
  $export['print_pdf_display_urllist_hps_exhibit_narrative'] = $strongarm;

  return $export;
}
