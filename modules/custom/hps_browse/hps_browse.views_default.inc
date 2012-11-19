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
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
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
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'dc_description_type' => 'dc_description_type',
  );
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'empty';
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

  /* Display: List */
  $handler = $view->new_display('panel_pane', 'List', 'panel_pane_list');
  $handler->display->display_options['display_description'] = 'Content pane for displaying items as a list.';
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
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'hps_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Bitstreams */
  $handler->display->display_options['fields']['dspace_bitstream_url']['id'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['table'] = 'field_data_dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['field'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['label'] = '';
  $handler->display->display_options['fields']['dspace_bitstream_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['dspace_bitstream_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['multi_type'] = 'ul';
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
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Index */
  $handler = $view->new_display('panel_pane', 'Index', 'panel_pane_index');
  $handler->display->display_options['display_description'] = 'Content pane for displaying items as an index.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'dc_creator' => 'dc_creator',
    'dc_description' => 'dc_description',
    'dc_description_abstract' => 'dc_description',
    'dc_date_created' => 'dc_date_created',
    'dspace_lastmodified' => 'dspace_lastmodified',
  );
  $handler->display->display_options['style_options']['default'] = 'dspace_lastmodified';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dc_creator' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dc_description' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dc_description_abstract' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dc_date_created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dspace_lastmodified' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  $handler->display->display_options['fields']['dc_description']['label'] = 'Description';
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
  $handler->display->display_options['sorts']['dspace_lastmodified_value']['expose']['label'] = 'Last Modified';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: DC Creator (dc_creator) */
  $handler->display->display_options['sorts']['dc_creator_value']['id'] = 'dc_creator_value';
  $handler->display->display_options['sorts']['dc_creator_value']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['sorts']['dc_creator_value']['field'] = 'dc_creator_value';
  /* Sort criterion: Content: DC Date Created (dc_date_created) */
  $handler->display->display_options['sorts']['dc_date_created_value']['id'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['sorts']['dc_date_created_value']['field'] = 'dc_date_created_value';
  $handler->display->display_options['sorts']['dc_date_created_value']['order'] = 'DESC';
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
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Gallery */
  $handler = $view->new_display('panel_pane', 'Gallery', 'panel_pane_gallery');
  $handler->display->display_options['display_description'] = 'Content pane for displaying items as a gallery.';
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
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'hps_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Bitstreams */
  $handler->display->display_options['fields']['dspace_bitstream_url']['id'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['table'] = 'field_data_dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['field'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['label'] = '';
  $handler->display->display_options['fields']['dspace_bitstream_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['dspace_bitstream_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['multi_type'] = 'ul';
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
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['hps_browse'] = $view;

  $view = new view();
  $view->name = 'hps_browse_by';
  $view->description = 'List vocabulary terms for browse by landing page.';
  $view->tag = 'HPS';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'HPS Browse By';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_type'] = '0';
  $handler->display->display_options['fields']['name_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['preserve_tags'] = '<em> <strong> <b> <i> <a>';
  $handler->display->display_options['fields']['description']['element_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['description']['hide_empty'] = TRUE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Contextual filter: Taxonomy vocabulary: Vocabulary ID */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['operator'] = '>';
  $handler->display->display_options['filters']['parent']['value']['value'] = '0';

  /* Display: Browse by terms */
  $handler = $view->new_display('panel_pane', 'Browse by terms', 'panel_pane_browse_by');
  $handler->display->display_options['display_description'] = 'Lists terms from a browse by vocabulary.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'vid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_vocabulary.vid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy vocabulary: Vocabulary ID',
    ),
  );

  /* Display: Children of the root */
  $handler = $view->new_display('panel_pane', 'Children of the root', 'panel_pane_child_terms');
  $handler->display->display_options['display_description'] = 'Display a list of children for a root term.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['preserve_tags'] = '<em> <strong> <b> <i> <a>';
  $handler->display->display_options['fields']['description']['element_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['description']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Parent term */
  $handler->display->display_options['arguments']['parent']['id'] = 'parent';
  $handler->display->display_options['arguments']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['arguments']['parent']['field'] = 'parent';
  $handler->display->display_options['arguments']['parent']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['parent']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['parent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['parent']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['parent']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'HPS Browse Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'parent' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy term: Parent term',
    ),
  );
  $export['hps_browse_by'] = $view;

  return $export;
}
