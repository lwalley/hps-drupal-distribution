<?php
/**
 * @file
 * hps_organisations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hps_organisations_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hps_organisations';
  $view->description = 'Lists organisation nodes.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'HPS Organisations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_hps_organisation_url']['id'] = 'field_hps_organisation_url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['table'] = 'field_data_field_hps_organisation_url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['field'] = 'field_hps_organisation_url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['label'] = '';
  $handler->display->display_options['fields']['field_hps_organisation_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_hps_organisation_url']['field_api_classes'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_hps_organisation_logo']['id'] = 'field_hps_organisation_logo';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['table'] = 'field_data_field_hps_organisation_logo';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['field'] = 'field_hps_organisation_logo';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['label'] = '';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['settings'] = array(
    'image_style' => 'hps_minor',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_hps_organisation_logo']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_organisation' => 'hps_organisation',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['display_description'] = 'Supporting organisations, appears in footer.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_hps_organisation_url']['id'] = 'field_hps_organisation_url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['table'] = 'field_data_field_hps_organisation_url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['field'] = 'field_hps_organisation_url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['label'] = '';
  $handler->display->display_options['fields']['field_hps_organisation_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_hps_organisation_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_hps_organisation_url']['field_api_classes'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_hps_organisation_logo']['id'] = 'field_hps_organisation_logo';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['table'] = 'field_data_field_hps_organisation_logo';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['field'] = 'field_hps_organisation_logo';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['label'] = '';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['alter']['path'] = '[field_hps_organisation_url]';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_organisation_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hps_organisation_logo']['settings'] = array(
    'image_style' => 'hps_minor',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_hps_organisation_logo']['field_api_classes'] = TRUE;
  $export['hps_organisations'] = $view;

  return $export;
}
