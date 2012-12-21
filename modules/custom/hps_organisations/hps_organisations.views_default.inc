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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>This web site is supported by:</p>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['hps_organisation_url']['id'] = 'hps_organisation_url';
  $handler->display->display_options['fields']['hps_organisation_url']['table'] = 'field_data_hps_organisation_url';
  $handler->display->display_options['fields']['hps_organisation_url']['field'] = 'hps_organisation_url';
  $handler->display->display_options['fields']['hps_organisation_url']['label'] = '';
  $handler->display->display_options['fields']['hps_organisation_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_url']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['hps_organisation_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['hps_organisation_url']['field_api_classes'] = TRUE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['hps_organisation_logo']['id'] = 'hps_organisation_logo';
  $handler->display->display_options['fields']['hps_organisation_logo']['table'] = 'field_data_hps_organisation_logo';
  $handler->display->display_options['fields']['hps_organisation_logo']['field'] = 'hps_organisation_logo';
  $handler->display->display_options['fields']['hps_organisation_logo']['label'] = '';
  $handler->display->display_options['fields']['hps_organisation_logo']['alter']['make_link'] = TRUE;
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
  $handler->display->display_options['fields']['hps_organisation_logo']['field_api_classes'] = TRUE;
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
  /* Filter criterion: Promoted to footer */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['ui_name'] = 'Promoted to footer';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Supporting Organisations */
  $handler = $view->new_display('block', 'Supporting Organisations', 'block_supporting_organisations');
  $handler->display->display_options['display_description'] = 'Provides a block containing a list of organisations that support the site, e.g. for display in a site wide footer.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['block_description'] = 'Supporting Organisations';

  /* Display: Principal Organisation */
  $handler = $view->new_display('block', 'Principal Organisation', 'block_principal_organisation');
  $handler->display->display_options['display_description'] = 'Provides block containing contact details for principal organisation.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Contact and Copyright';
  $handler->display->display_options['header']['area']['content'] = '<p>See an error? <a href="/contact">Contact us</a></p>
<p>&copy;</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['prefix'] = 'The site at ';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'p';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['hps_organisation_address']['id'] = 'hps_organisation_address';
  $handler->display->display_options['fields']['hps_organisation_address']['table'] = 'field_data_hps_organisation_address';
  $handler->display->display_options['fields']['hps_organisation_address']['field'] = 'hps_organisation_address';
  $handler->display->display_options['fields']['hps_organisation_address']['label'] = '';
  $handler->display->display_options['fields']['hps_organisation_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_address']['alter']['text'] = '<address>[hps_organisation_address]</address>';
  $handler->display->display_options['fields']['hps_organisation_address']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_address']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_address']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['hps_organisation_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['hps_organisation_address']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['hps_organisation_fax']['id'] = 'hps_organisation_fax';
  $handler->display->display_options['fields']['hps_organisation_fax']['table'] = 'field_data_hps_organisation_fax';
  $handler->display->display_options['fields']['hps_organisation_fax']['field'] = 'hps_organisation_fax';
  $handler->display->display_options['fields']['hps_organisation_fax']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_fax']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_fax']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['hps_organisation_fax']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_fax']['hide_empty'] = TRUE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['hps_organisation_phone']['id'] = 'hps_organisation_phone';
  $handler->display->display_options['fields']['hps_organisation_phone']['table'] = 'field_data_hps_organisation_phone';
  $handler->display->display_options['fields']['hps_organisation_phone']['field'] = 'hps_organisation_phone';
  $handler->display->display_options['fields']['hps_organisation_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_phone']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_organisation_phone']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['hps_organisation_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_organisation_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Promoted to footer */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['ui_name'] = 'Promoted to footer';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '1535';
  $handler->display->display_options['block_description'] = 'Principal Organisation';

  /* Display: Supporting Organisations Logos */
  $handler = $view->new_display('block', 'Supporting Organisations Logos', 'block_supporting_organisations_logos');
  $handler->display->display_options['display_description'] = 'Provides block containing logos for supporting organisations.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Promoted to footer */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['ui_name'] = 'Promoted to footer';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Logo (hps_organisation_logo:fid) */
  $handler->display->display_options['filters']['hps_organisation_logo_fid']['id'] = 'hps_organisation_logo_fid';
  $handler->display->display_options['filters']['hps_organisation_logo_fid']['table'] = 'field_data_hps_organisation_logo';
  $handler->display->display_options['filters']['hps_organisation_logo_fid']['field'] = 'hps_organisation_logo_fid';
  $handler->display->display_options['filters']['hps_organisation_logo_fid']['operator'] = 'not empty';
  $handler->display->display_options['block_description'] = 'Supporting Organisations Logos';
  $export['hps_organisations'] = $view;

  return $export;
}
