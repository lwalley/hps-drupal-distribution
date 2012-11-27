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

  /* Display: Context */
  $handler = $view->new_display('ctools_context', 'Context', 'ctools_context_encyclopedia_item');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'panels_fields';
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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  /* Field: Content: Bitstreams */
  $handler->display->display_options['fields']['dspace_bitstream_url']['id'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['table'] = 'field_data_dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['field'] = 'dspace_bitstream_url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['label'] = '';
  $handler->display->display_options['fields']['dspace_bitstream_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_bitstream_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['dspace_bitstream_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['dspace_bitstream_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dspace_bitstream_url']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['dspace_bitstream_url']['field_api_classes'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['label'] = 'Description';
  $handler->display->display_options['fields']['dc_description']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  /* Field: Content: DC Description Abstract */
  $handler->display->display_options['fields']['dc_description_abstract']['id'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['table'] = 'field_data_dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['field'] = 'dc_description_abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['label'] = 'Abstract';
  $handler->display->display_options['fields']['dc_description_abstract']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description_abstract']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description_abstract']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_description_abstract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_abstract']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_abstract']['delta_offset'] = '0';
  /* Field: Content: DC Contributor */
  $handler->display->display_options['fields']['dc_contributor']['id'] = 'dc_contributor';
  $handler->display->display_options['fields']['dc_contributor']['table'] = 'field_data_dc_contributor';
  $handler->display->display_options['fields']['dc_contributor']['field'] = 'dc_contributor';
  $handler->display->display_options['fields']['dc_contributor']['label'] = 'Contributor';
  $handler->display->display_options['fields']['dc_contributor']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Correspondent */
  $handler->display->display_options['fields']['dc_contributor_correspondent']['id'] = 'dc_contributor_correspondent';
  $handler->display->display_options['fields']['dc_contributor_correspondent']['table'] = 'field_data_dc_contributor_correspondent';
  $handler->display->display_options['fields']['dc_contributor_correspondent']['field'] = 'dc_contributor_correspondent';
  $handler->display->display_options['fields']['dc_contributor_correspondent']['label'] = 'Contributor Correspondent';
  $handler->display->display_options['fields']['dc_contributor_correspondent']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_correspondent']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_correspondent']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_correspondent']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_correspondent']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_correspondent']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Editor */
  $handler->display->display_options['fields']['dc_contributor_editor']['id'] = 'dc_contributor_editor';
  $handler->display->display_options['fields']['dc_contributor_editor']['table'] = 'field_data_dc_contributor_editor';
  $handler->display->display_options['fields']['dc_contributor_editor']['field'] = 'dc_contributor_editor';
  $handler->display->display_options['fields']['dc_contributor_editor']['label'] = 'Contributor Editor';
  $handler->display->display_options['fields']['dc_contributor_editor']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_editor']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_editor']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_editor']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_editor']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_editor']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Illustrator */
  $handler->display->display_options['fields']['dc_contributor_illustrator']['id'] = 'dc_contributor_illustrator';
  $handler->display->display_options['fields']['dc_contributor_illustrator']['table'] = 'field_data_dc_contributor_illustrator';
  $handler->display->display_options['fields']['dc_contributor_illustrator']['field'] = 'dc_contributor_illustrator';
  $handler->display->display_options['fields']['dc_contributor_illustrator']['label'] = 'Contributor Illustrator';
  $handler->display->display_options['fields']['dc_contributor_illustrator']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_illustrator']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_illustrator']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_illustrator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_illustrator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_illustrator']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Interviewee */
  $handler->display->display_options['fields']['dc_contributor_interviewee']['id'] = 'dc_contributor_interviewee';
  $handler->display->display_options['fields']['dc_contributor_interviewee']['table'] = 'field_data_dc_contributor_interviewee';
  $handler->display->display_options['fields']['dc_contributor_interviewee']['field'] = 'dc_contributor_interviewee';
  $handler->display->display_options['fields']['dc_contributor_interviewee']['label'] = 'Contributor Interviewee';
  $handler->display->display_options['fields']['dc_contributor_interviewee']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_interviewee']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_interviewee']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_interviewee']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_interviewee']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_interviewee']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Interviewer */
  $handler->display->display_options['fields']['dc_contributor_interviewer']['id'] = 'dc_contributor_interviewer';
  $handler->display->display_options['fields']['dc_contributor_interviewer']['table'] = 'field_data_dc_contributor_interviewer';
  $handler->display->display_options['fields']['dc_contributor_interviewer']['field'] = 'dc_contributor_interviewer';
  $handler->display->display_options['fields']['dc_contributor_interviewer']['label'] = 'Contributor Interviewer';
  $handler->display->display_options['fields']['dc_contributor_interviewer']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_interviewer']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_interviewer']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_interviewer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_interviewer']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_interviewer']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Narrator */
  $handler->display->display_options['fields']['dc_contributor_narrator']['id'] = 'dc_contributor_narrator';
  $handler->display->display_options['fields']['dc_contributor_narrator']['table'] = 'field_data_dc_contributor_narrator';
  $handler->display->display_options['fields']['dc_contributor_narrator']['field'] = 'dc_contributor_narrator';
  $handler->display->display_options['fields']['dc_contributor_narrator']['label'] = 'Contributor Narrator';
  $handler->display->display_options['fields']['dc_contributor_narrator']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_narrator']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_narrator']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_narrator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_narrator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_narrator']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Photographer */
  $handler->display->display_options['fields']['dc_contributor_photographer']['id'] = 'dc_contributor_photographer';
  $handler->display->display_options['fields']['dc_contributor_photographer']['table'] = 'field_data_dc_contributor_photographer';
  $handler->display->display_options['fields']['dc_contributor_photographer']['field'] = 'dc_contributor_photographer';
  $handler->display->display_options['fields']['dc_contributor_photographer']['label'] = 'Contributor Photographer';
  $handler->display->display_options['fields']['dc_contributor_photographer']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_photographer']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_photographer']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_photographer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_photographer']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_photographer']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_contributor_photographer']['field_api_classes'] = TRUE;
  /* Field: Content: DC Contributor Speaker */
  $handler->display->display_options['fields']['dc_contributor_speaker']['id'] = 'dc_contributor_speaker';
  $handler->display->display_options['fields']['dc_contributor_speaker']['table'] = 'field_data_dc_contributor_speaker';
  $handler->display->display_options['fields']['dc_contributor_speaker']['field'] = 'dc_contributor_speaker';
  $handler->display->display_options['fields']['dc_contributor_speaker']['label'] = 'Contributor Speaker';
  $handler->display->display_options['fields']['dc_contributor_speaker']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_speaker']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_speaker']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_speaker']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_speaker']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_speaker']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Translator */
  $handler->display->display_options['fields']['dc_contributor_translator']['id'] = 'dc_contributor_translator';
  $handler->display->display_options['fields']['dc_contributor_translator']['table'] = 'field_data_dc_contributor_translator';
  $handler->display->display_options['fields']['dc_contributor_translator']['field'] = 'dc_contributor_translator';
  $handler->display->display_options['fields']['dc_contributor_translator']['label'] = 'Contributor Translator';
  $handler->display->display_options['fields']['dc_contributor_translator']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_translator']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_translator']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_translator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_translator']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_translator']['delta_offset'] = '0';
  /* Field: Content: DC Contributor Videographer */
  $handler->display->display_options['fields']['dc_contributor_videographer']['id'] = 'dc_contributor_videographer';
  $handler->display->display_options['fields']['dc_contributor_videographer']['table'] = 'field_data_dc_contributor_videographer';
  $handler->display->display_options['fields']['dc_contributor_videographer']['field'] = 'dc_contributor_videographer';
  $handler->display->display_options['fields']['dc_contributor_videographer']['label'] = 'Videographer';
  $handler->display->display_options['fields']['dc_contributor_videographer']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_contributor_videographer']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_contributor_videographer']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_contributor_videographer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_contributor_videographer']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_contributor_videographer']['delta_offset'] = '0';
  /* Field: Content: DC Coverage */
  $handler->display->display_options['fields']['dc_coverage']['id'] = 'dc_coverage';
  $handler->display->display_options['fields']['dc_coverage']['table'] = 'field_data_dc_coverage';
  $handler->display->display_options['fields']['dc_coverage']['field'] = 'dc_coverage';
  $handler->display->display_options['fields']['dc_coverage']['label'] = 'Coverage';
  $handler->display->display_options['fields']['dc_coverage']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_coverage']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_coverage']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_coverage']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_coverage']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_coverage']['delta_offset'] = '0';
  /* Field: Content: DC Coverage Spatial */
  $handler->display->display_options['fields']['dc_coverage_spatial']['id'] = 'dc_coverage_spatial';
  $handler->display->display_options['fields']['dc_coverage_spatial']['table'] = 'field_data_dc_coverage_spatial';
  $handler->display->display_options['fields']['dc_coverage_spatial']['field'] = 'dc_coverage_spatial';
  $handler->display->display_options['fields']['dc_coverage_spatial']['label'] = 'Spatial Coverage';
  $handler->display->display_options['fields']['dc_coverage_spatial']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_coverage_spatial']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_coverage_spatial']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_coverage_spatial']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_coverage_spatial']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_coverage_spatial']['delta_offset'] = '0';
  /* Field: Content: DC Coverage Temporal */
  $handler->display->display_options['fields']['dc_coverage_temporal']['id'] = 'dc_coverage_temporal';
  $handler->display->display_options['fields']['dc_coverage_temporal']['table'] = 'field_data_dc_coverage_temporal';
  $handler->display->display_options['fields']['dc_coverage_temporal']['field'] = 'dc_coverage_temporal';
  $handler->display->display_options['fields']['dc_coverage_temporal']['label'] = 'Temporal Coverage';
  $handler->display->display_options['fields']['dc_coverage_temporal']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_coverage_temporal']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_coverage_temporal']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_coverage_temporal']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_coverage_temporal']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_coverage_temporal']['delta_offset'] = '0';
  /* Field: Content: DC Creator */
  $handler->display->display_options['fields']['dc_creator']['id'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['table'] = 'field_data_dc_creator';
  $handler->display->display_options['fields']['dc_creator']['field'] = 'dc_creator';
  $handler->display->display_options['fields']['dc_creator']['label'] = 'Creator';
  $handler->display->display_options['fields']['dc_creator']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_creator']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_creator']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_creator']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_creator']['hide_empty'] = TRUE;
  /* Field: Content: DC Date */
  $handler->display->display_options['fields']['dc_date']['id'] = 'dc_date';
  $handler->display->display_options['fields']['dc_date']['table'] = 'field_data_dc_date';
  $handler->display->display_options['fields']['dc_date']['field'] = 'dc_date';
  $handler->display->display_options['fields']['dc_date']['label'] = 'Date';
  $handler->display->display_options['fields']['dc_date']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_date']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['dc_date']['delta_offset'] = '0';
  /* Field: Content: DC Date Accessioned */
  $handler->display->display_options['fields']['dc_date_accessioned']['id'] = 'dc_date_accessioned';
  $handler->display->display_options['fields']['dc_date_accessioned']['table'] = 'field_data_dc_date_accessioned';
  $handler->display->display_options['fields']['dc_date_accessioned']['field'] = 'dc_date_accessioned';
  $handler->display->display_options['fields']['dc_date_accessioned']['label'] = 'Date Accessioned';
  $handler->display->display_options['fields']['dc_date_accessioned']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_date_accessioned']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_date_accessioned']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_date_accessioned']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_accessioned']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_accessioned']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: DC Date Available */
  $handler->display->display_options['fields']['dc_date_available']['id'] = 'dc_date_available';
  $handler->display->display_options['fields']['dc_date_available']['table'] = 'field_data_dc_date_available';
  $handler->display->display_options['fields']['dc_date_available']['field'] = 'dc_date_available';
  $handler->display->display_options['fields']['dc_date_available']['label'] = 'Date Available';
  $handler->display->display_options['fields']['dc_date_available']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_date_available']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_date_available']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_date_available']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_available']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_available']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: DC Date Created */
  $handler->display->display_options['fields']['dc_date_created']['id'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['table'] = 'field_data_dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['field'] = 'dc_date_created';
  $handler->display->display_options['fields']['dc_date_created']['label'] = 'Date Created';
  $handler->display->display_options['fields']['dc_date_created']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_date_created']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_date_created']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_date_created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_created']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: DC Date Issued */
  $handler->display->display_options['fields']['dc_date_issued']['id'] = 'dc_date_issued';
  $handler->display->display_options['fields']['dc_date_issued']['table'] = 'field_data_dc_date_issued';
  $handler->display->display_options['fields']['dc_date_issued']['field'] = 'dc_date_issued';
  $handler->display->display_options['fields']['dc_date_issued']['label'] = 'Date Issued';
  $handler->display->display_options['fields']['dc_date_issued']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_date_issued']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_date_issued']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_date_issued']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_date_issued']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_date_issued']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: DC Description Provenance */
  $handler->display->display_options['fields']['dc_description_provenance']['id'] = 'dc_description_provenance';
  $handler->display->display_options['fields']['dc_description_provenance']['table'] = 'field_data_dc_description_provenance';
  $handler->display->display_options['fields']['dc_description_provenance']['field'] = 'dc_description_provenance';
  $handler->display->display_options['fields']['dc_description_provenance']['label'] = 'Provenance';
  $handler->display->display_options['fields']['dc_description_provenance']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description_provenance']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description_provenance']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_description_provenance']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_provenance']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_provenance']['delta_offset'] = '0';
  /* Field: Content: DC Description Table of Contents */
  $handler->display->display_options['fields']['dc_description_tableofcontents']['id'] = 'dc_description_tableofcontents';
  $handler->display->display_options['fields']['dc_description_tableofcontents']['table'] = 'field_data_dc_description_tableofcontents';
  $handler->display->display_options['fields']['dc_description_tableofcontents']['field'] = 'dc_description_tableofcontents';
  $handler->display->display_options['fields']['dc_description_tableofcontents']['label'] = 'Table of Contents';
  $handler->display->display_options['fields']['dc_description_tableofcontents']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description_tableofcontents']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description_tableofcontents']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_description_tableofcontents']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_tableofcontents']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_tableofcontents']['delta_offset'] = '0';
  /* Field: Content: DC Description Type */
  $handler->display->display_options['fields']['dc_description_type']['id'] = 'dc_description_type';
  $handler->display->display_options['fields']['dc_description_type']['table'] = 'field_data_dc_description_type';
  $handler->display->display_options['fields']['dc_description_type']['field'] = 'dc_description_type';
  $handler->display->display_options['fields']['dc_description_type']['label'] = 'Format';
  $handler->display->display_options['fields']['dc_description_type']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_description_type']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_description_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_description_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_description_type']['delta_offset'] = '0';
  /* Field: Content: DC Format */
  $handler->display->display_options['fields']['dc_format']['id'] = 'dc_format';
  $handler->display->display_options['fields']['dc_format']['table'] = 'field_data_dc_format';
  $handler->display->display_options['fields']['dc_format']['field'] = 'dc_format';
  $handler->display->display_options['fields']['dc_format']['label'] = '';
  $handler->display->display_options['fields']['dc_format']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_format']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_format']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_format']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_format']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_format']['field_api_classes'] = TRUE;
  /* Field: Content: DC Format Extent */
  $handler->display->display_options['fields']['dc_format_extent']['id'] = 'dc_format_extent';
  $handler->display->display_options['fields']['dc_format_extent']['table'] = 'field_data_dc_format_extent';
  $handler->display->display_options['fields']['dc_format_extent']['field'] = 'dc_format_extent';
  $handler->display->display_options['fields']['dc_format_extent']['label'] = '';
  $handler->display->display_options['fields']['dc_format_extent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_format_extent']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_format_extent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_format_extent']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_format_extent']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_format_extent']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_format_extent']['field_api_classes'] = TRUE;
  /* Field: Content: DC Format Medium */
  $handler->display->display_options['fields']['dc_format_medium']['id'] = 'dc_format_medium';
  $handler->display->display_options['fields']['dc_format_medium']['table'] = 'field_data_dc_format_medium';
  $handler->display->display_options['fields']['dc_format_medium']['field'] = 'dc_format_medium';
  $handler->display->display_options['fields']['dc_format_medium']['label'] = '';
  $handler->display->display_options['fields']['dc_format_medium']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_format_medium']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_format_medium']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_format_medium']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_format_medium']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_format_medium']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_format_medium']['field_api_classes'] = TRUE;
  /* Field: Content: DC Identifier */
  $handler->display->display_options['fields']['dc_identifier']['id'] = 'dc_identifier';
  $handler->display->display_options['fields']['dc_identifier']['table'] = 'field_data_dc_identifier';
  $handler->display->display_options['fields']['dc_identifier']['field'] = 'dc_identifier';
  $handler->display->display_options['fields']['dc_identifier']['label'] = '';
  $handler->display->display_options['fields']['dc_identifier']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_identifier']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_identifier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_identifier']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_identifier']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_identifier']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_identifier']['field_api_classes'] = TRUE;
  /* Field: Content: DC Identifier Citation */
  $handler->display->display_options['fields']['dc_identifier_citation']['id'] = 'dc_identifier_citation';
  $handler->display->display_options['fields']['dc_identifier_citation']['table'] = 'field_data_dc_identifier_citation';
  $handler->display->display_options['fields']['dc_identifier_citation']['field'] = 'dc_identifier_citation';
  $handler->display->display_options['fields']['dc_identifier_citation']['label'] = 'Citation';
  $handler->display->display_options['fields']['dc_identifier_citation']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_identifier_citation']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_identifier_citation']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_identifier_citation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_identifier_citation']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_identifier_citation']['delta_offset'] = '0';
  /* Field: Content: DC Identifier ISSN */
  $handler->display->display_options['fields']['dc_identifier_issn']['id'] = 'dc_identifier_issn';
  $handler->display->display_options['fields']['dc_identifier_issn']['table'] = 'field_data_dc_identifier_issn';
  $handler->display->display_options['fields']['dc_identifier_issn']['field'] = 'dc_identifier_issn';
  $handler->display->display_options['fields']['dc_identifier_issn']['label'] = 'ISSN';
  $handler->display->display_options['fields']['dc_identifier_issn']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_identifier_issn']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_identifier_issn']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_identifier_issn']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_identifier_issn']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_identifier_issn']['delta_offset'] = '0';
  /* Field: Content: DC Identifier URI */
  $handler->display->display_options['fields']['dc_identifier_uri']['id'] = 'dc_identifier_uri';
  $handler->display->display_options['fields']['dc_identifier_uri']['table'] = 'field_data_dc_identifier_uri';
  $handler->display->display_options['fields']['dc_identifier_uri']['field'] = 'dc_identifier_uri';
  $handler->display->display_options['fields']['dc_identifier_uri']['label'] = '';
  $handler->display->display_options['fields']['dc_identifier_uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_identifier_uri']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_identifier_uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_identifier_uri']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_identifier_uri']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_identifier_uri']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['dc_identifier_uri']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_identifier_uri']['field_api_classes'] = TRUE;
  /* Field: Content: DC Language */
  $handler->display->display_options['fields']['dc_language']['id'] = 'dc_language';
  $handler->display->display_options['fields']['dc_language']['table'] = 'field_data_dc_language';
  $handler->display->display_options['fields']['dc_language']['field'] = 'dc_language';
  $handler->display->display_options['fields']['dc_language']['label'] = '';
  $handler->display->display_options['fields']['dc_language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_language']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_language']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_language']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_language']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_language']['field_api_classes'] = TRUE;
  /* Field: Content: DC Language ISO */
  $handler->display->display_options['fields']['dc_language_iso']['id'] = 'dc_language_iso';
  $handler->display->display_options['fields']['dc_language_iso']['table'] = 'field_data_dc_language_iso';
  $handler->display->display_options['fields']['dc_language_iso']['field'] = 'dc_language_iso';
  $handler->display->display_options['fields']['dc_language_iso']['label'] = '';
  $handler->display->display_options['fields']['dc_language_iso']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_language_iso']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_language_iso']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_language_iso']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_language_iso']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_language_iso']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_language_iso']['field_api_classes'] = TRUE;
  /* Field: Content: DC Publisher */
  $handler->display->display_options['fields']['dc_publisher']['id'] = 'dc_publisher';
  $handler->display->display_options['fields']['dc_publisher']['table'] = 'field_data_dc_publisher';
  $handler->display->display_options['fields']['dc_publisher']['field'] = 'dc_publisher';
  $handler->display->display_options['fields']['dc_publisher']['label'] = 'Publisher';
  $handler->display->display_options['fields']['dc_publisher']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_publisher']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_publisher']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_publisher']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher']['delta_offset'] = '0';
  /* Field: Content: DC Publisher Digital */
  $handler->display->display_options['fields']['dc_publisher_digital']['id'] = 'dc_publisher_digital';
  $handler->display->display_options['fields']['dc_publisher_digital']['table'] = 'field_data_dc_publisher_digital';
  $handler->display->display_options['fields']['dc_publisher_digital']['field'] = 'dc_publisher_digital';
  $handler->display->display_options['fields']['dc_publisher_digital']['label'] = 'Digital Publisher';
  $handler->display->display_options['fields']['dc_publisher_digital']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_publisher_digital']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_publisher_digital']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_publisher_digital']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_digital']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_digital']['delta_offset'] = '0';
  /* Field: Content: DC Publisher Original */
  $handler->display->display_options['fields']['dc_publisher_original']['id'] = 'dc_publisher_original';
  $handler->display->display_options['fields']['dc_publisher_original']['table'] = 'field_data_dc_publisher_original';
  $handler->display->display_options['fields']['dc_publisher_original']['field'] = 'dc_publisher_original';
  $handler->display->display_options['fields']['dc_publisher_original']['label'] = 'Original Publisher';
  $handler->display->display_options['fields']['dc_publisher_original']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_publisher_original']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_publisher_original']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_publisher_original']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_publisher_original']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_publisher_original']['delta_offset'] = '0';
  /* Field: Content: DC Relation Has Format */
  $handler->display->display_options['fields']['dc_relation_hasformat']['id'] = 'dc_relation_hasformat';
  $handler->display->display_options['fields']['dc_relation_hasformat']['table'] = 'field_data_dc_relation_hasformat';
  $handler->display->display_options['fields']['dc_relation_hasformat']['field'] = 'dc_relation_hasformat';
  $handler->display->display_options['fields']['dc_relation_hasformat']['label'] = '';
  $handler->display->display_options['fields']['dc_relation_hasformat']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_relation_hasformat']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_hasformat']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_hasformat']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_hasformat']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_hasformat']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_relation_hasformat']['field_api_classes'] = TRUE;
  /* Field: Content: DC Relation Has Part */
  $handler->display->display_options['fields']['dc_relation_haspart']['id'] = 'dc_relation_haspart';
  $handler->display->display_options['fields']['dc_relation_haspart']['table'] = 'field_data_dc_relation_haspart';
  $handler->display->display_options['fields']['dc_relation_haspart']['field'] = 'dc_relation_haspart';
  $handler->display->display_options['fields']['dc_relation_haspart']['label'] = '';
  $handler->display->display_options['fields']['dc_relation_haspart']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_relation_haspart']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_haspart']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_haspart']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_haspart']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_haspart']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_relation_haspart']['field_api_classes'] = TRUE;
  /* Field: Content: DC Relation Has Version */
  $handler->display->display_options['fields']['dc_relation_hasversion']['id'] = 'dc_relation_hasversion';
  $handler->display->display_options['fields']['dc_relation_hasversion']['table'] = 'field_data_dc_relation_hasversion';
  $handler->display->display_options['fields']['dc_relation_hasversion']['field'] = 'dc_relation_hasversion';
  $handler->display->display_options['fields']['dc_relation_hasversion']['label'] = '';
  $handler->display->display_options['fields']['dc_relation_hasversion']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_relation_hasversion']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_hasversion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_hasversion']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_hasversion']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_hasversion']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_relation_hasversion']['field_api_classes'] = TRUE;
  /* Field: Content: DC Relation Is Format Of */
  $handler->display->display_options['fields']['dc_relation_isformatof']['id'] = 'dc_relation_isformatof';
  $handler->display->display_options['fields']['dc_relation_isformatof']['table'] = 'field_data_dc_relation_isformatof';
  $handler->display->display_options['fields']['dc_relation_isformatof']['field'] = 'dc_relation_isformatof';
  $handler->display->display_options['fields']['dc_relation_isformatof']['label'] = '';
  $handler->display->display_options['fields']['dc_relation_isformatof']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_relation_isformatof']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_isformatof']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_isformatof']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_isformatof']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_isformatof']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_relation_isformatof']['field_api_classes'] = TRUE;
  /* Field: Content: DC Relation Is Part Of */
  $handler->display->display_options['fields']['dc_relation_ispartof']['id'] = 'dc_relation_ispartof';
  $handler->display->display_options['fields']['dc_relation_ispartof']['table'] = 'field_data_dc_relation_ispartof';
  $handler->display->display_options['fields']['dc_relation_ispartof']['field'] = 'dc_relation_ispartof';
  $handler->display->display_options['fields']['dc_relation_ispartof']['label'] = '';
  $handler->display->display_options['fields']['dc_relation_ispartof']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_relation_ispartof']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_ispartof']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_ispartof']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_ispartof']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_ispartof']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_relation_ispartof']['field_api_classes'] = TRUE;
  /* Field: Content: DC Relation Is Version Of */
  $handler->display->display_options['fields']['dc_relation_isversionof']['id'] = 'dc_relation_isversionof';
  $handler->display->display_options['fields']['dc_relation_isversionof']['table'] = 'field_data_dc_relation_isversionof';
  $handler->display->display_options['fields']['dc_relation_isversionof']['field'] = 'dc_relation_isversionof';
  $handler->display->display_options['fields']['dc_relation_isversionof']['label'] = '';
  $handler->display->display_options['fields']['dc_relation_isversionof']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_relation_isversionof']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_isversionof']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_isversionof']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_relation_isversionof']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_relation_isversionof']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_relation_isversionof']['field_api_classes'] = TRUE;
  /* Field: Content: DC Rights */
  $handler->display->display_options['fields']['dc_rights']['id'] = 'dc_rights';
  $handler->display->display_options['fields']['dc_rights']['table'] = 'field_data_dc_rights';
  $handler->display->display_options['fields']['dc_rights']['field'] = 'dc_rights';
  $handler->display->display_options['fields']['dc_rights']['label'] = 'Rights';
  $handler->display->display_options['fields']['dc_rights']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_rights']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_rights']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_rights']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights']['delta_offset'] = '0';
  /* Field: Content: DC Rights Copyright */
  $handler->display->display_options['fields']['dc_rights_copyright']['id'] = 'dc_rights_copyright';
  $handler->display->display_options['fields']['dc_rights_copyright']['table'] = 'field_data_dc_rights_copyright';
  $handler->display->display_options['fields']['dc_rights_copyright']['field'] = 'dc_rights_copyright';
  $handler->display->display_options['fields']['dc_rights_copyright']['label'] = 'Copyright';
  $handler->display->display_options['fields']['dc_rights_copyright']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_rights_copyright']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_rights_copyright']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_rights_copyright']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_copyright']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_copyright']['delta_offset'] = '0';
  /* Field: Content: DC Rights Holder */
  $handler->display->display_options['fields']['dc_rights_holder']['id'] = 'dc_rights_holder';
  $handler->display->display_options['fields']['dc_rights_holder']['table'] = 'field_data_dc_rights_holder';
  $handler->display->display_options['fields']['dc_rights_holder']['field'] = 'dc_rights_holder';
  $handler->display->display_options['fields']['dc_rights_holder']['label'] = 'Rights Holder';
  $handler->display->display_options['fields']['dc_rights_holder']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_rights_holder']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_rights_holder']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_rights_holder']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_holder']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_holder']['delta_offset'] = '0';
  /* Field: Content: DC Rights License */
  $handler->display->display_options['fields']['dc_rights_license']['id'] = 'dc_rights_license';
  $handler->display->display_options['fields']['dc_rights_license']['table'] = 'field_data_dc_rights_license';
  $handler->display->display_options['fields']['dc_rights_license']['field'] = 'dc_rights_license';
  $handler->display->display_options['fields']['dc_rights_license']['label'] = 'License';
  $handler->display->display_options['fields']['dc_rights_license']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_rights_license']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_rights_license']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_rights_license']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_license']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_license']['delta_offset'] = '0';
  /* Field: Content: DC Rights URI */
  $handler->display->display_options['fields']['dc_rights_uri']['id'] = 'dc_rights_uri';
  $handler->display->display_options['fields']['dc_rights_uri']['table'] = 'field_data_dc_rights_uri';
  $handler->display->display_options['fields']['dc_rights_uri']['field'] = 'dc_rights_uri';
  $handler->display->display_options['fields']['dc_rights_uri']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_rights_uri']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_rights_uri']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_rights_uri']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_rights_uri']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_rights_uri']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['dc_rights_uri']['type'] = 'link_url';
  $handler->display->display_options['fields']['dc_rights_uri']['delta_offset'] = '0';
  /* Field: Content: DC Source */
  $handler->display->display_options['fields']['dc_source']['id'] = 'dc_source';
  $handler->display->display_options['fields']['dc_source']['table'] = 'field_data_dc_source';
  $handler->display->display_options['fields']['dc_source']['field'] = 'dc_source';
  $handler->display->display_options['fields']['dc_source']['label'] = 'Source';
  $handler->display->display_options['fields']['dc_source']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_source']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_source']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_source']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_source']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_source']['delta_offset'] = '0';
  /* Field: Content: DC Subject */
  $handler->display->display_options['fields']['dc_subject']['id'] = 'dc_subject';
  $handler->display->display_options['fields']['dc_subject']['table'] = 'field_data_dc_subject';
  $handler->display->display_options['fields']['dc_subject']['field'] = 'dc_subject';
  $handler->display->display_options['fields']['dc_subject']['label'] = '';
  $handler->display->display_options['fields']['dc_subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_subject']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_subject']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_subject']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_subject']['field_api_classes'] = TRUE;
  /* Field: Content: DC Subject LCSH */
  $handler->display->display_options['fields']['dc_subject_lcsh']['id'] = 'dc_subject_lcsh';
  $handler->display->display_options['fields']['dc_subject_lcsh']['table'] = 'field_data_dc_subject_lcsh';
  $handler->display->display_options['fields']['dc_subject_lcsh']['field'] = 'dc_subject_lcsh';
  $handler->display->display_options['fields']['dc_subject_lcsh']['label'] = '';
  $handler->display->display_options['fields']['dc_subject_lcsh']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_lcsh']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_lcsh']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_subject_lcsh']['field_api_classes'] = TRUE;
  /* Field: Content: DC Subject MBL History */
  $handler->display->display_options['fields']['dc_subject_mblhistory']['id'] = 'dc_subject_mblhistory';
  $handler->display->display_options['fields']['dc_subject_mblhistory']['table'] = 'field_data_dc_subject_mblhistory';
  $handler->display->display_options['fields']['dc_subject_mblhistory']['field'] = 'dc_subject_mblhistory';
  $handler->display->display_options['fields']['dc_subject_mblhistory']['label'] = 'Subject';
  $handler->display->display_options['fields']['dc_subject_mblhistory']['element_type'] = 'p';
  $handler->display->display_options['fields']['dc_subject_mblhistory']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['dc_subject_mblhistory']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_subject_mblhistory']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_mblhistory']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_mblhistory']['delta_offset'] = '0';
  /* Field: Content: DC Subject Mesh */
  $handler->display->display_options['fields']['dc_subject_mesh']['id'] = 'dc_subject_mesh';
  $handler->display->display_options['fields']['dc_subject_mesh']['table'] = 'field_data_dc_subject_mesh';
  $handler->display->display_options['fields']['dc_subject_mesh']['field'] = 'dc_subject_mesh';
  $handler->display->display_options['fields']['dc_subject_mesh']['label'] = '';
  $handler->display->display_options['fields']['dc_subject_mesh']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_mesh']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_mesh']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_mesh']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_mesh']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_mesh']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_subject_mesh']['field_api_classes'] = TRUE;
  /* Field: Content: DC Subject Tag */
  $handler->display->display_options['fields']['dc_subject_tag']['id'] = 'dc_subject_tag';
  $handler->display->display_options['fields']['dc_subject_tag']['table'] = 'field_data_dc_subject_tag';
  $handler->display->display_options['fields']['dc_subject_tag']['field'] = 'dc_subject_tag';
  $handler->display->display_options['fields']['dc_subject_tag']['label'] = '';
  $handler->display->display_options['fields']['dc_subject_tag']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_subject_tag']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_tag']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_subject_tag']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_subject_tag']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_subject_tag']['field_api_classes'] = TRUE;
  /* Field: Content: DC Title */
  $handler->display->display_options['fields']['dc_title']['id'] = 'dc_title';
  $handler->display->display_options['fields']['dc_title']['table'] = 'field_data_dc_title';
  $handler->display->display_options['fields']['dc_title']['field'] = 'dc_title';
  $handler->display->display_options['fields']['dc_title']['label'] = '';
  $handler->display->display_options['fields']['dc_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_title']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_title']['field_api_classes'] = TRUE;
  /* Field: Content: DC Title Alternative */
  $handler->display->display_options['fields']['dc_title_alternative']['id'] = 'dc_title_alternative';
  $handler->display->display_options['fields']['dc_title_alternative']['table'] = 'field_data_dc_title_alternative';
  $handler->display->display_options['fields']['dc_title_alternative']['field'] = 'dc_title_alternative';
  $handler->display->display_options['fields']['dc_title_alternative']['label'] = '';
  $handler->display->display_options['fields']['dc_title_alternative']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_title_alternative']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_title_alternative']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_title_alternative']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_title_alternative']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_title_alternative']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_title_alternative']['field_api_classes'] = TRUE;
  /* Field: Content: DC Type */
  $handler->display->display_options['fields']['dc_type']['id'] = 'dc_type';
  $handler->display->display_options['fields']['dc_type']['table'] = 'field_data_dc_type';
  $handler->display->display_options['fields']['dc_type']['field'] = 'dc_type';
  $handler->display->display_options['fields']['dc_type']['label'] = '';
  $handler->display->display_options['fields']['dc_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dc_type']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dc_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['dc_type']['field_api_classes'] = TRUE;
  /* Field: Content: DSpace Entity ID */
  $handler->display->display_options['fields']['dspace_entity_id']['id'] = 'dspace_entity_id';
  $handler->display->display_options['fields']['dspace_entity_id']['table'] = 'field_data_dspace_entity_id';
  $handler->display->display_options['fields']['dspace_entity_id']['field'] = 'dspace_entity_id';
  $handler->display->display_options['fields']['dspace_entity_id']['label'] = '';
  $handler->display->display_options['fields']['dspace_entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_entity_id']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_entity_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_entity_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_entity_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['dspace_entity_id']['field_api_classes'] = TRUE;
  /* Field: Content: DSpace Type Number */
  $handler->display->display_options['fields']['dspace_type']['id'] = 'dspace_type';
  $handler->display->display_options['fields']['dspace_type']['table'] = 'field_data_dspace_type';
  $handler->display->display_options['fields']['dspace_type']['field'] = 'dspace_type';
  $handler->display->display_options['fields']['dspace_type']['label'] = '';
  $handler->display->display_options['fields']['dspace_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_type']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_type']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['dspace_type']['field_api_classes'] = TRUE;
  /* Field: Content: Handle */
  $handler->display->display_options['fields']['dspace_handle']['id'] = 'dspace_handle';
  $handler->display->display_options['fields']['dspace_handle']['table'] = 'field_data_dspace_handle';
  $handler->display->display_options['fields']['dspace_handle']['field'] = 'dspace_handle';
  $handler->display->display_options['fields']['dspace_handle']['label'] = '';
  $handler->display->display_options['fields']['dspace_handle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_handle']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_handle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_handle']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_handle']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_handle']['field_api_classes'] = TRUE;
  /* Field: Content: Withdrawn */
  $handler->display->display_options['fields']['dspace_is_withdrawn']['id'] = 'dspace_is_withdrawn';
  $handler->display->display_options['fields']['dspace_is_withdrawn']['table'] = 'field_data_dspace_is_withdrawn';
  $handler->display->display_options['fields']['dspace_is_withdrawn']['field'] = 'dspace_is_withdrawn';
  $handler->display->display_options['fields']['dspace_is_withdrawn']['label'] = '';
  $handler->display->display_options['fields']['dspace_is_withdrawn']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dspace_is_withdrawn']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_is_withdrawn']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_is_withdrawn']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_is_withdrawn']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_is_withdrawn']['field_api_classes'] = TRUE;
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
  $export['hps_encyclopedia_items'] = $view;

  return $export;
}
