<?php
/**
 * @file
 * hps_browse.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hps_browse_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hps_browse';
  $view->description = 'Content panes for browse by listings.';
  $view->tag = 'HPS';
  $view->base_table = 'node';
  $view->human_name = 'HPS Browse';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = TRUE;

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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';

  /* Sort criterion: Content: Last Modified (dspace_lastmodified) */
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['id'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['field'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['expose']['label'] = 'Last Modified';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
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
    'dspaced_entities_item' => 'dspaced_entities_item',
  );

  /* Display: Articles */
  $handler = $view->new_display('panel_pane', 'Articles', 'panel_pane_articles');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Content pane for listing articles.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: DC Creator */
  $handler->display->display_options['fields']['dc_creator']['id'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['fields']['dc_creator']['field'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['label'] = 'By';
  $handler->display->display_options['fields']['dc_creator']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['element_type'] = 'em';
  $handler->display->display_options['fields']['dc_creator']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dc_creator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dc_creator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['type'] = 'text_plain';
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description']['separator'] = '';
  /* Field: Content: DC Description Abstract */
  $handler->display->display_options['fields']['dc_description_abstract']['id'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['table'] = 'field_data_dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['field'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['label'] = '';
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description_abstract']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['dc_description_abstract']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['separator'] = '';
  /* Field: Content: DC Date Created */
  $handler->display->display_options['fields']['dc_date_created']['id'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['field'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['label'] = 'Created';
  $handler->display->display_options['fields']['dc_date_created']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['element_type'] = 'em';
  $handler->display->display_options['fields']['dc_date_created']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dc_date_created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dc_date_created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Last Modified */
  $handler->display->display_options['fields']['dspace_lastmodified']['id'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['field'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['label'] = 'Last modified';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_type'] = 'em';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_lastmodified']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_lastmodified']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_lastmodified']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dspace_lastmodified']['type'] = 'format_interval';
  $handler->display->display_options['fields']['dspace_lastmodified']['settings'] = array(
    'interval' => '2',
    'interval_display' => 'time ago',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Modified (dspace_lastmodified) */
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['id'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['field'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['expose']['label'] = 'Last Modified';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: DC Creator (dc_creator) */
  $handler->display->display_options['sorts']['dc_creator_value']['id'] = 'dc_creator_value';
  $handler->display->display_options['sorts']['dc_creator_value']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['sorts']['dc_creator_value']['field'] = 'dc_creator_value';
  $handler->display->display_options['sorts']['dc_creator_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dc_creator_value']['expose']['label'] = 'Creator';
  /* Sort criterion: Content: DC Date Created (dc_date_created) */
  $handler->display->display_options['sorts']['dc_date_created_value']['id'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['sorts']['dc_date_created_value']['field'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dc_date_created_value']['expose']['label'] = 'Created';
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
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: DC Description Type (dc_description_type) */
  $handler->display->display_options['filters']['dc_description_type_tid']['id'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['field'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['value'] = array(
    73 => '73',
  );
  $handler->display->display_options['filters']['dc_description_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['dc_description_type_tid']['vocabulary'] = 'dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Audio */
  $handler = $view->new_display('panel_pane', 'Audio', 'panel_pane_audio');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Content pane for listing audio files.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'audio_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: DC Description Type (dc_description_type) */
  $handler->display->display_options['filters']['dc_description_type_tid']['id'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['field'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['value'] = array(
    27 => '27',
  );
  $handler->display->display_options['filters']['dc_description_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['dc_description_type_tid']['vocabulary'] = 'dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Essays */
  $handler = $view->new_display('panel_pane', 'Essays', 'panel_pane_essays');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Content pane for listing essays.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: DC Creator */
  $handler->display->display_options['fields']['dc_creator']['id'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['fields']['dc_creator']['field'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['label'] = 'By';
  $handler->display->display_options['fields']['dc_creator']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['element_type'] = 'em';
  $handler->display->display_options['fields']['dc_creator']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dc_creator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dc_creator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['type'] = 'text_plain';
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description']['separator'] = '';
  /* Field: Content: DC Description Abstract */
  $handler->display->display_options['fields']['dc_description_abstract']['id'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['table'] = 'field_data_dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['field'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['label'] = '';
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description_abstract']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['dc_description_abstract']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['separator'] = '';
  /* Field: Content: DC Date Created */
  $handler->display->display_options['fields']['dc_date_created']['id'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['field'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['label'] = 'Created';
  $handler->display->display_options['fields']['dc_date_created']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['element_type'] = 'em';
  $handler->display->display_options['fields']['dc_date_created']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dc_date_created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dc_date_created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Last Modified */
  $handler->display->display_options['fields']['dspace_lastmodified']['id'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['field'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['label'] = 'Last modified';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_type'] = 'em';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_lastmodified']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_lastmodified']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_lastmodified']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dspace_lastmodified']['type'] = 'format_interval';
  $handler->display->display_options['fields']['dspace_lastmodified']['settings'] = array(
    'interval' => '2',
    'interval_display' => 'time ago',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Modified (dspace_lastmodified) */
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['id'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['field'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['expose']['label'] = 'Last Modified';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: DC Creator (dc_creator) */
  $handler->display->display_options['sorts']['dc_creator_value']['id'] = 'dc_creator_value';
  $handler->display->display_options['sorts']['dc_creator_value']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['sorts']['dc_creator_value']['field'] = 'dc_creator_value';
  $handler->display->display_options['sorts']['dc_creator_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dc_creator_value']['expose']['label'] = 'Creator';
  /* Sort criterion: Content: DC Date Created (dc_date_created) */
  $handler->display->display_options['sorts']['dc_date_created_value']['id'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['sorts']['dc_date_created_value']['field'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dc_date_created_value']['expose']['label'] = 'Created';
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
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: DC Description Type (dc_description_type) */
  $handler->display->display_options['filters']['dc_description_type_tid']['id'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['field'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['value'] = array(
    428 => '428',
  );
  $handler->display->display_options['filters']['dc_description_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['dc_description_type_tid']['vocabulary'] = 'dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Images */
  $handler = $view->new_display('panel_pane', 'Images', 'panel_pane_images');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Content pane for displaying list of photographs.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'image_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: DC Description Type (dc_description_type) */
  $handler->display->display_options['filters']['dc_description_type_tid']['id'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['field'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['dc_description_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['dc_description_type_tid']['vocabulary'] = 'dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Publications */
  $handler = $view->new_display('panel_pane', 'Publications', 'panel_pane_publications');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Content pane for listing publications.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description']['separator'] = '';
  /* Field: Content: DC Description Abstract */
  $handler->display->display_options['fields']['dc_description_abstract']['id'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['table'] = 'field_data_dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['field'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['label'] = '';
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description_abstract']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['dc_description_abstract']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['separator'] = '';
  /* Field: Content: DC Date Created */
  $handler->display->display_options['fields']['dc_date_created']['id'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['field'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['label'] = 'Created';
  $handler->display->display_options['fields']['dc_date_created']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['element_type'] = 'em';
  $handler->display->display_options['fields']['dc_date_created']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dc_date_created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dc_date_created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Last Modified */
  $handler->display->display_options['fields']['dspace_lastmodified']['id'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['field'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['label'] = 'Last modified';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_type'] = 'em';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_lastmodified']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_lastmodified']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_lastmodified']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dspace_lastmodified']['type'] = 'format_interval';
  $handler->display->display_options['fields']['dspace_lastmodified']['settings'] = array(
    'interval' => '2',
    'interval_display' => 'time ago',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last Modified (dspace_lastmodified) */
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['id'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['field'] = 'dspace_lastmodified_value';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['expose']['label'] = 'Last Modified';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: DC Date Created (dc_date_created) */
  $handler->display->display_options['sorts']['dc_date_created_value']['id'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['sorts']['dc_date_created_value']['field'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['dc_date_created_value']['expose']['label'] = 'Created';
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
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: DC Description Type (dc_description_type) */
  $handler->display->display_options['filters']['dc_description_type_tid']['id'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['field'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['value'] = array(
    33 => '33',
  );
  $handler->display->display_options['filters']['dc_description_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['dc_description_type_tid']['vocabulary'] = 'dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Video */
  $handler = $view->new_display('panel_pane', 'Video', 'panel_pane_video');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Content pane for listing videos.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'video_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  /* Filter criterion: Content: DC Description Type (dc_description_type) */
  $handler->display->display_options['filters']['dc_description_type_tid']['id'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['field'] = 'dc_description_type_tid';
  $handler->display->display_options['filters']['dc_description_type_tid']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['filters']['dc_description_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['dc_description_type_tid']['vocabulary'] = 'dc_description_type';
  $handler->display->display_options['filters']['dc_description_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['hps_browse'] = $view;

  return $export;
}
