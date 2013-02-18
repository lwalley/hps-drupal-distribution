<?php
/**
 * @file
 * hps_encyclopedia.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hps_encyclopedia_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hps_encyclopedia_items';
  $view->description = 'Alternative DSpace item node view as content pane for use with Panels.';
  $view->tag = 'HPS';
  $view->base_table = 'node';
  $view->human_name = 'HPS Encyclopedia Items';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Item */
  $handler = $view->new_display('ctools_context', 'Item', 'ctools_context_encyclopedia_item');
  $handler->display->display_options['display_description'] = 'Context for a single encyclopedia item.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['style_options']['row_class'] = 'node-[nid]';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nid']['empty_zero'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: DC Creator */
  $handler->display->display_options['fields']['dc_creator']['id'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['fields']['dc_creator']['field'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['label'] = 'by';
  $handler->display->display_options['fields']['dc_creator']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_creator']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_creator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_creator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['type'] = 'text_plain';
  /* Field: Content: DC Subject Tag */
  $handler->display->display_options['fields']['dc_subject_tag']['id'] = 'dc_subject_tag';
  $handler->display->display_options['fields']['dc_subject_tag']['table'] = 'field_data_dc_subject_tag';
  $handler->display->display_options['fields']['dc_subject_tag']['field'] = 'dc_subject_tag';
  $handler->display->display_options['fields']['dc_subject_tag']['label'] = 'Keywords';
  $handler->display->display_options['fields']['dc_subject_tag']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_tag']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_tag']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['dc_subject_tag']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_tag']['delta_offset'] = '0';
  /* Field: Content: Bitstreams */
  $handler->display->display_options['fields']['dspace_bitstream_url']['id'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['table'] = 'field_data_dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['field'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['label'] = '';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['dspace_bitstream_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['separator'] = ' ';
  $handler->display->display_options['fields']['dspace_bitstream_url']['field_api_classes'] = TRUE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'hps_supplemental',
    'image_link' => '',
  );
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['alter']['text'] = '[dc_description] [dc_description_abstract]';
  $handler->display->display_options['fields']['dc_description']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description']['separator'] = ' ';
  /* Field: Content: DC Description Abstract */
  $handler->display->display_options['fields']['dc_description_abstract']['id'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['table'] = 'field_data_dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['field'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['label'] = '';
  $handler->display->display_options['fields']['dc_description_abstract']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['empty'] = '[dc_description]';
  $handler->display->display_options['fields']['dc_description_abstract']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['separator'] = ' ';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['empty'] = '[dc_description_abstract]';
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1000',
  );
  /* Field: Content: DC Subject LCSH */
  $handler->display->display_options['fields']['dc_subject_lcsh']['id'] = 'dc_subject_lcsh';
  $handler->display->display_options['fields']['dc_subject_lcsh']['table'] = 'field_data_dc_subject_lcsh';
  $handler->display->display_options['fields']['dc_subject_lcsh']['field'] = 'dc_subject_lcsh';
  $handler->display->display_options['fields']['dc_subject_lcsh']['label'] = '';
  $handler->display->display_options['fields']['dc_subject_lcsh']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['alter']['text'] = '[dc_subject_lcsh]; ';
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_subject_lcsh']['field_api_classes'] = TRUE;
  /* Field: Content: DC Subject Mesh */
  $handler->display->display_options['fields']['dc_subject_mesh']['id'] = 'dc_subject_mesh';
  $handler->display->display_options['fields']['dc_subject_mesh']['table'] = 'field_data_dc_subject_mesh';
  $handler->display->display_options['fields']['dc_subject_mesh']['field'] = 'dc_subject_mesh';
  $handler->display->display_options['fields']['dc_subject_mesh']['label'] = 'Subject';
  $handler->display->display_options['fields']['dc_subject_mesh']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_mesh']['alter']['text'] = '[dc_subject_lcsh] [dc_subject_mesh] ';
  $handler->display->display_options['fields']['dc_subject_mesh']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_mesh']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_subject_mesh']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_subject_mesh']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_subject_mesh']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_mesh']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_mesh']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_mesh']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_subject_mesh']['field_api_classes'] = TRUE;
  /* Field: Content: DC Subject */
  $handler->display->display_options['fields']['dc_subject']['id'] = 'dc_subject';
  $handler->display->display_options['fields']['dc_subject']['table'] = 'field_data_dc_subject';
  $handler->display->display_options['fields']['dc_subject']['field'] = 'dc_subject';
  $handler->display->display_options['fields']['dc_subject']['label'] = '';
  $handler->display->display_options['fields']['dc_subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_subject']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_subject']['alter']['text'] = '[dc_subject_mesh] [dc_subject_lcsh] [dc_subject]';
  $handler->display->display_options['fields']['dc_subject']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_subject']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_subject']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['dc_subject']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_subject']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_subject']['delta_offset'] = '0';
  /* Field: Content: Handle as URL */
  $handler->display->display_options['fields']['dspace_handle']['id'] = 'dspace_handle';
  $handler->display->display_options['fields']['dspace_handle']['table'] = 'field_data_dspace_handle';
  $handler->display->display_options['fields']['dspace_handle']['field'] = 'dspace_handle';
  $handler->display->display_options['fields']['dspace_handle']['ui_name'] = 'Content: Handle as URL';
  $handler->display->display_options['fields']['dspace_handle']['label'] = '';
  $handler->display->display_options['fields']['dspace_handle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_handle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dspace_handle']['alter']['text'] = '[dspace_handle]';
  $handler->display->display_options['fields']['dspace_handle']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_handle']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dspace_handle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_handle']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_handle']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_handle']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_handle']['type'] = 'text_plain';
  /* Field: Content: DC Creator for How to Cite */
  $handler->display->display_options['fields']['dc_creator_1']['id'] = 'dc_creator_1';
  $handler->display->display_options['fields']['dc_creator_1']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['fields']['dc_creator_1']['field'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator_1']['ui_name'] = 'Content: DC Creator for How to Cite';
  $handler->display->display_options['fields']['dc_creator_1']['label'] = '';
  $handler->display->display_options['fields']['dc_creator_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_creator_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_creator_1']['alter']['text'] = '[dc_creator_1],';
  $handler->display->display_options['fields']['dc_creator_1']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_creator_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_creator_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_creator_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_creator_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_creator_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_creator_1']['type'] = 'text_plain';
  /* Field: Content: DC Date Created */
  $handler->display->display_options['fields']['dc_date_created']['id'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['field'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['label'] = '';
  $handler->display->display_options['fields']['dc_date_created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_date_created']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_date_created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_date_created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'How to Cite';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[dc_creator_1] "[title]". [dspace_handle]. [dc_date_created]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'p';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Last Modified */
  $handler->display->display_options['fields']['dspace_lastmodified']['id'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['table'] = 'field_data_dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['field'] = 'dspace_lastmodified';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_type'] = 'p';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dspace_lastmodified']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_lastmodified']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_lastmodified']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: DC Publisher Original */
  $handler->display->display_options['fields']['dc_publisher_original']['id'] = 'dc_publisher_original';
  $handler->display->display_options['fields']['dc_publisher_original']['table'] = 'field_data_dc_publisher_original';
  $handler->display->display_options['fields']['dc_publisher_original']['field'] = 'dc_publisher_original';
  $handler->display->display_options['fields']['dc_publisher_original']['label'] = '';
  $handler->display->display_options['fields']['dc_publisher_original']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_original']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_original']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_publisher_original']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_publisher_original']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_original']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_publisher_original']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_original']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_original']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_original']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_publisher_original']['separator'] = ' ';
  /* Field: Content: DC Publisher Digital */
  $handler->display->display_options['fields']['dc_publisher_digital']['id'] = 'dc_publisher_digital';
  $handler->display->display_options['fields']['dc_publisher_digital']['table'] = 'field_data_dc_publisher_digital';
  $handler->display->display_options['fields']['dc_publisher_digital']['field'] = 'dc_publisher_digital';
  $handler->display->display_options['fields']['dc_publisher_digital']['label'] = '';
  $handler->display->display_options['fields']['dc_publisher_digital']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_digital']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_digital']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_publisher_digital']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_publisher_digital']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_digital']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_publisher_digital']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_digital']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_digital']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_digital']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_publisher_digital']['separator'] = ' ';
  /* Field: Content: DC Publisher */
  $handler->display->display_options['fields']['dc_publisher']['id'] = 'dc_publisher';
  $handler->display->display_options['fields']['dc_publisher']['table'] = 'field_data_dc_publisher';
  $handler->display->display_options['fields']['dc_publisher']['field'] = 'dc_publisher';
  $handler->display->display_options['fields']['dc_publisher']['label'] = 'Publisher';
  $handler->display->display_options['fields']['dc_publisher']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher']['alter']['text'] = '[dc_publisher] [dc_publisher_original] [dc_publisher_digital]';
  $handler->display->display_options['fields']['dc_publisher']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_publisher']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_publisher']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_publisher']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_publisher']['separator'] = ' ';
  /* Field: Content: DC Rights Copyright */
  $handler->display->display_options['fields']['dc_rights_copyright']['id'] = 'dc_rights_copyright';
  $handler->display->display_options['fields']['dc_rights_copyright']['table'] = 'field_data_dc_rights_copyright';
  $handler->display->display_options['fields']['dc_rights_copyright']['field'] = 'dc_rights_copyright';
  $handler->display->display_options['fields']['dc_rights_copyright']['label'] = '';
  $handler->display->display_options['fields']['dc_rights_copyright']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_copyright']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_copyright']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_copyright']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_copyright']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_copyright']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_copyright']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_copyright']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_copyright']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_copyright']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_rights_copyright']['separator'] = ' ';
  /* Field: Content: DC Rights Holder */
  $handler->display->display_options['fields']['dc_rights_holder']['id'] = 'dc_rights_holder';
  $handler->display->display_options['fields']['dc_rights_holder']['table'] = 'field_data_dc_rights_holder';
  $handler->display->display_options['fields']['dc_rights_holder']['field'] = 'dc_rights_holder';
  $handler->display->display_options['fields']['dc_rights_holder']['label'] = '';
  $handler->display->display_options['fields']['dc_rights_holder']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_holder']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_holder']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_holder']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_holder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_holder']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_holder']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_holder']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_holder']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_holder']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_rights_holder']['separator'] = ' ';
  /* Field: Content: DC Rights License */
  $handler->display->display_options['fields']['dc_rights_license']['id'] = 'dc_rights_license';
  $handler->display->display_options['fields']['dc_rights_license']['table'] = 'field_data_dc_rights_license';
  $handler->display->display_options['fields']['dc_rights_license']['field'] = 'dc_rights_license';
  $handler->display->display_options['fields']['dc_rights_license']['label'] = '';
  $handler->display->display_options['fields']['dc_rights_license']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_license']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_license']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_license']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_license']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_license']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_license']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_license']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_license']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_license']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_rights_license']['separator'] = ' ';
  /* Field: Content: DC Rights URI */
  $handler->display->display_options['fields']['dc_rights_uri']['id'] = 'dc_rights_uri';
  $handler->display->display_options['fields']['dc_rights_uri']['table'] = 'field_data_dc_rights_uri';
  $handler->display->display_options['fields']['dc_rights_uri']['field'] = 'dc_rights_uri';
  $handler->display->display_options['fields']['dc_rights_uri']['label'] = '';
  $handler->display->display_options['fields']['dc_rights_uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_uri']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_uri']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_uri']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_uri']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_rights_uri']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_uri']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_uri']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_uri']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['dc_rights_uri']['type'] = 'link_url';
  $handler->display->display_options['fields']['dc_rights_uri']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_rights_uri']['separator'] = ' ';
  /* Field: Content: DC Rights */
  $handler->display->display_options['fields']['dc_rights']['id'] = 'dc_rights';
  $handler->display->display_options['fields']['dc_rights']['table'] = 'field_data_dc_rights';
  $handler->display->display_options['fields']['dc_rights']['field'] = 'dc_rights';
  $handler->display->display_options['fields']['dc_rights']['label'] = 'Rights';
  $handler->display->display_options['fields']['dc_rights']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_rights']['alter']['text'] = '[dc_rights] [dc_rights_copyright] [dc_rights_holder] [dc_rights_license] [dc_rights_uri]';
  $handler->display->display_options['fields']['dc_rights']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['dc_rights']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_rights']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_rights']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_rights']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_rights']['separator'] = ' ';
  /* Field: Full Item Record Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Item Record Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Show full item record';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = '[dspace_handle]';
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'p';
  $handler->display->display_options['fields']['nothing_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
    ),
  );

  /* Display: Items */
  $handler = $view->new_display('ctools_context', 'Items', 'ctools_context_encyclopedia_items');
  $handler->display->display_options['display_description'] = 'Lists all encyclopedia items.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: DC Description Abstract */
  $handler->display->display_options['fields']['dc_description_abstract']['id'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['table'] = 'field_data_dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['field'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['label'] = '';
  $handler->display->display_options['fields']['dc_description_abstract']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['alter']['preserve_tags'] = '<em> <i> <strong> <b> <a>';
  $handler->display->display_options['fields']['dc_description_abstract']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description_abstract']['settings'] = array(
    'trim_length' => '1000',
  );
  $handler->display->display_options['fields']['dc_description_abstract']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['separator'] = ' ';
  $handler->display->display_options['fields']['dc_description_abstract']['field_api_classes'] = TRUE;
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['alter']['preserve_tags'] = '<em> <i> <strong> <b> <a>';
  $handler->display->display_options['fields']['dc_description']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['empty'] = '[dc_description_abstract]';
  $handler->display->display_options['fields']['dc_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['dc_description']['settings'] = array(
    'trim_length' => '1000',
  );
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description']['separator'] = ' ';
  $handler->display->display_options['fields']['dc_description']['field_api_classes'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<em> <i> <strong> <b> <a>';
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['empty'] = '[dc_description]';
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1000',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Recent Items */
  $handler = $view->new_display('panel_pane', 'Recent Items', 'panel_pane_encyclopedia_recent_items');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'What\'s New?';
  $handler->display->display_options['display_description'] = 'Lists most recently added items.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'All Recent Content';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: More Link To Custom Page */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['ui_name'] = 'More Link To Custom Page';
  $handler->display->display_options['footer']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="more-link"><a href="/pages">All Recent Content</a></div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_encyclopedia_items');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest additions.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => 'Latest additions.',
        'language' => 'en',
        'category' => '',
        'image' => '',
        'copyright' => 'Copyright',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'title',
        'link' => 'path',
        'description' => 'body',
        'author' => 'dc_creator',
        'category' => 'dc_description_type',
        'comments' => '',
        'enclosure' => '',
        'guid' => '',
        'pubDate' => 'created',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 1,
    'feed_in_links' => 1,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description']['separator'] = ' ';
  /* Field: Content: DC Description Abstract */
  $handler->display->display_options['fields']['dc_description_abstract']['id'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['table'] = 'field_data_dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['field'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['label'] = '';
  $handler->display->display_options['fields']['dc_description_abstract']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['separator'] = ' ';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['empty'] = '[dc_description] [dc_description_abstract]';
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  /* Field: Content: DC Creator */
  $handler->display->display_options['fields']['dc_creator']['id'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['fields']['dc_creator']['field'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['label'] = '';
  $handler->display->display_options['fields']['dc_creator']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_creator']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_creator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_creator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_creator']['type'] = 'text_plain';
  /* Field: Content: DC Description Type */
  $handler->display->display_options['fields']['dc_description_type']['id'] = 'dc_description_type';
  $handler->display->display_options['fields']['dc_description_type']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['fields']['dc_description_type']['field'] = 'dc_description_type';
  $handler->display->display_options['fields']['dc_description_type']['label'] = '';
  $handler->display->display_options['fields']['dc_description_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['dc_description_type']['alter']['text'] = '[dc_description_type]';
  $handler->display->display_options['fields']['dc_description_type']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description_type']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_description_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['dc_description_type']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_type'] = '0';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['path']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['created']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'pages/feed';
  $handler->display->display_options['displays'] = array(
    'ctools_context_encyclopedia_items' => 'ctools_context_encyclopedia_items',
    'default' => 0,
    'ctools_context_encyclopedia_item' => 0,
    'panel_pane_encyclopedia_recent_items' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['hps_encyclopedia_items'] = $view;

  return $export;
}
