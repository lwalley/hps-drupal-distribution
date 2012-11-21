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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Introduction */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['ui_name'] = 'Introduction';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'This web site is supported by';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['hps_organisation_url']['id'] = 'hps_organisation_url';
  $handler->display->display_options['fields']['hps_organisation_url']['table'] = 'field_data_hps_organisation_url';
  $handler->display->display_options['fields']['hps_organisation_url']['field'] = 'hps_organisation_url';
  $handler->display->display_options['fields']['hps_organisation_url']['label'] = '';
  $handler->display->display_options['fields']['hps_organisation_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_url']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_url']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_url']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['hps_organisation_url']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[hps_organisation_url]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'hps-organisation-title';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['hps_organisation_logo']['id'] = 'hps_organisation_logo';
  $handler->display->display_options['fields']['hps_organisation_logo']['table'] = 'field_data_hps_organisation_logo';
  $handler->display->display_options['fields']['hps_organisation_logo']['field'] = 'hps_organisation_logo';
  $handler->display->display_options['fields']['hps_organisation_logo']['label'] = '';
  $handler->display->display_options['fields']['hps_organisation_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_logo']['alter']['path'] = '[hps_organisation_url]';
  $handler->display->display_options['fields']['hps_organisation_logo']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_logo']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_logo']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_logo']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['hps_organisation_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_logo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_logo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['hps_organisation_logo']['settings'] = array(
    'image_style' => 'hps_minor',
    'image_link' => '',
  );
  /* Sort criterion: Content: Rank (hps_organisation_rank) */
  $handler->display->display_options['sorts']['hps_organisation_rank_value']['id'] = 'hps_organisation_rank_value';
  $handler->display->display_options['sorts']['hps_organisation_rank_value']['table'] = 'field_data_hps_organisation_rank';
  $handler->display->display_options['sorts']['hps_organisation_rank_value']['field'] = 'hps_organisation_rank_value';
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
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Supporting Organisations */
  $handler = $view->new_display('block', 'Supporting Organisations', 'block_supporting_organisations');
  $handler->display->display_options['display_description'] = 'Provides a block containing a list of organisations that support the site, e.g. for display in a site wide footer.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Supporting organisations';
  $export['hps_organisations'] = $view;

  return $export;
}
