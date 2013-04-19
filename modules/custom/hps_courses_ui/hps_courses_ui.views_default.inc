<?php
/**
 * @file
 * hps_courses_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hps_courses_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hps_courses';
  $view->description = 'Courses lists and course page view panes.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'HPS Courses';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Course name (hps_course_name) */
  $handler->display->display_options['sorts']['hps_course_name_value']['id'] = 'hps_course_name_value';
  $handler->display->display_options['sorts']['hps_course_name_value']['table'] = 'field_data_hps_course_name';
  $handler->display->display_options['sorts']['hps_course_name_value']['field'] = 'hps_course_name_value';
  $handler->display->display_options['sorts']['hps_course_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['hps_course_name_value']['expose']['label'] = 'Course name (hps_course_name)';
  /* Sort criterion: Content: Course year (hps_course_year) */
  $handler->display->display_options['sorts']['hps_course_year_value']['id'] = 'hps_course_year_value';
  $handler->display->display_options['sorts']['hps_course_year_value']['table'] = 'field_data_hps_course_year';
  $handler->display->display_options['sorts']['hps_course_year_value']['field'] = 'hps_course_year_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_course' => 'hps_course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Courses */
  $handler = $view->new_display('ctools_context', 'Courses', 'ctools_context_hps_courses');
  $handler->display->display_options['display_description'] = 'Lists course pages.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Course year (hps_course_year) */
  $handler->display->display_options['sorts']['hps_course_year_value']['id'] = 'hps_course_year_value';
  $handler->display->display_options['sorts']['hps_course_year_value']['table'] = 'field_data_hps_course_year';
  $handler->display->display_options['sorts']['hps_course_year_value']['field'] = 'hps_course_year_value';
  $handler->display->display_options['sorts']['hps_course_year_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['hps_course_year_value']['expose']['label'] = 'Course year';
  /* Sort criterion: Content: Course name (hps_course_name) */
  $handler->display->display_options['sorts']['hps_course_name_value']['id'] = 'hps_course_name_value';
  $handler->display->display_options['sorts']['hps_course_name_value']['table'] = 'field_data_hps_course_name';
  $handler->display->display_options['sorts']['hps_course_name_value']['field'] = 'hps_course_name_value';
  $handler->display->display_options['sorts']['hps_course_name_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['hps_course_name_value']['expose']['label'] = 'Course name';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_course' => 'hps_course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Course name (hps_course_name) */
  $handler->display->display_options['filters']['hps_course_name_value']['id'] = 'hps_course_name_value';
  $handler->display->display_options['filters']['hps_course_name_value']['table'] = 'field_data_hps_course_name';
  $handler->display->display_options['filters']['hps_course_name_value']['field'] = 'hps_course_name_value';
  $handler->display->display_options['filters']['hps_course_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['operator_id'] = 'hps_course_name_value_op';
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['label'] = 'Course name';
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['operator'] = 'hps_course_name_value_op';
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['identifier'] = 'hps_course_name_value';
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['hps_course_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['hps_course_name_value']['group_info']['label'] = 'Course name';
  $handler->display->display_options['filters']['hps_course_name_value']['group_info']['identifier'] = 'hps_course_name_value';
  $handler->display->display_options['filters']['hps_course_name_value']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['hps_course_name_value']['group_info']['remember'] = 1;
  $handler->display->display_options['filters']['hps_course_name_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Course year (hps_course_year) */
  $handler->display->display_options['filters']['hps_course_year_value']['id'] = 'hps_course_year_value';
  $handler->display->display_options['filters']['hps_course_year_value']['table'] = 'field_data_hps_course_year';
  $handler->display->display_options['filters']['hps_course_year_value']['field'] = 'hps_course_year_value';
  $handler->display->display_options['filters']['hps_course_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hps_course_year_value']['expose']['operator_id'] = 'hps_course_year_value_op';
  $handler->display->display_options['filters']['hps_course_year_value']['expose']['label'] = 'Course year';
  $handler->display->display_options['filters']['hps_course_year_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['hps_course_year_value']['expose']['operator'] = 'hps_course_year_value_op';
  $handler->display->display_options['filters']['hps_course_year_value']['expose']['identifier'] = 'hps_course_year_value';
  $handler->display->display_options['filters']['hps_course_year_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hps_course_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['hps_course_year_value']['group_info']['label'] = 'Course year (hps_course_year)';
  $handler->display->display_options['filters']['hps_course_year_value']['group_info']['identifier'] = 'hps_course_year_value';
  $handler->display->display_options['filters']['hps_course_year_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['hps_course_year_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Course photo */
  $handler = $view->new_display('panel_pane', 'Course photo', 'panel_pane_course_photo');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Items (hps_course_items) */
  $handler->display->display_options['relationships']['hps_course_items_value']['id'] = 'hps_course_items_value';
  $handler->display->display_options['relationships']['hps_course_items_value']['table'] = 'field_data_hps_course_items';
  $handler->display->display_options['relationships']['hps_course_items_value']['field'] = 'hps_course_items_value';
  $handler->display->display_options['relationships']['hps_course_items_value']['label'] = 'field_collection_item_hps_course_items';
  $handler->display->display_options['relationships']['hps_course_items_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['hps_course_item_entity_target_id']['id'] = 'hps_course_item_entity_target_id';
  $handler->display->display_options['relationships']['hps_course_item_entity_target_id']['table'] = 'field_data_hps_course_item_entity';
  $handler->display->display_options['relationships']['hps_course_item_entity_target_id']['field'] = 'hps_course_item_entity_target_id';
  $handler->display->display_options['relationships']['hps_course_item_entity_target_id']['relationship'] = 'hps_course_items_value';
  $handler->display->display_options['relationships']['hps_course_item_entity_target_id']['label'] = 'entity_referenced_from_hps_course_item_entity';
  $handler->display->display_options['relationships']['hps_course_item_entity_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['relationship'] = 'hps_course_item_entity_target_id';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'hps_principal',
    'image_link' => '',
  );
  /* Field: Content: DC Description */
  $handler->display->display_options['fields']['dc_description']['id'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['table'] = 'field_data_dc_description';
  $handler->display->display_options['fields']['dc_description']['field'] = 'dc_description';
  $handler->display->display_options['fields']['dc_description']['relationship'] = 'hps_course_item_entity_target_id';
  $handler->display->display_options['fields']['dc_description']['label'] = '';
  $handler->display->display_options['fields']['dc_description']['element_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['dc_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['dc_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dc_description']['type'] = 'text_plain';
  $handler->display->display_options['fields']['dc_description']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_course' => 'hps_course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field collection item: Type (hps_course_item_type) */
  $handler->display->display_options['filters']['hps_course_item_type_tid']['id'] = 'hps_course_item_type_tid';
  $handler->display->display_options['filters']['hps_course_item_type_tid']['table'] = 'field_data_hps_course_item_type';
  $handler->display->display_options['filters']['hps_course_item_type_tid']['field'] = 'hps_course_item_type_tid';
  $handler->display->display_options['filters']['hps_course_item_type_tid']['relationship'] = 'hps_course_items_value';
  $handler->display->display_options['filters']['hps_course_item_type_tid']['value'] = array(
    409 => '409',
  );
  $handler->display->display_options['filters']['hps_course_item_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['hps_course_item_type_tid']['vocabulary'] = 'hps_course_item_type';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Course participants */
  $handler = $view->new_display('panel_pane', 'Course participants', 'panel_pane_course_participants');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'hps_participant_role',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Participants (hps_course_participants) */
  $handler->display->display_options['relationships']['hps_course_participants_value']['id'] = 'hps_course_participants_value';
  $handler->display->display_options['relationships']['hps_course_participants_value']['table'] = 'field_data_hps_course_participants';
  $handler->display->display_options['relationships']['hps_course_participants_value']['field'] = 'hps_course_participants_value';
  $handler->display->display_options['relationships']['hps_course_participants_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Participant first name */
  $handler->display->display_options['fields']['hps_participant_first_name']['id'] = 'hps_participant_first_name';
  $handler->display->display_options['fields']['hps_participant_first_name']['table'] = 'field_data_hps_participant_first_name';
  $handler->display->display_options['fields']['hps_participant_first_name']['field'] = 'hps_participant_first_name';
  $handler->display->display_options['fields']['hps_participant_first_name']['relationship'] = 'hps_course_participants_value';
  $handler->display->display_options['fields']['hps_participant_first_name']['label'] = '';
  $handler->display->display_options['fields']['hps_participant_first_name']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_first_name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_participant_first_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_first_name']['element_default_classes'] = FALSE;
  /* Field: Field collection item: Participant last name */
  $handler->display->display_options['fields']['hps_participant_last_name']['id'] = 'hps_participant_last_name';
  $handler->display->display_options['fields']['hps_participant_last_name']['table'] = 'field_data_hps_participant_last_name';
  $handler->display->display_options['fields']['hps_participant_last_name']['field'] = 'hps_participant_last_name';
  $handler->display->display_options['fields']['hps_participant_last_name']['relationship'] = 'hps_course_participants_value';
  $handler->display->display_options['fields']['hps_participant_last_name']['label'] = '';
  $handler->display->display_options['fields']['hps_participant_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_last_name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_participant_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_participant_last_name']['type'] = 'text_plain';
  /* Field: Field collection item: Role */
  $handler->display->display_options['fields']['hps_participant_role']['id'] = 'hps_participant_role';
  $handler->display->display_options['fields']['hps_participant_role']['table'] = 'field_data_hps_participant_role';
  $handler->display->display_options['fields']['hps_participant_role']['field'] = 'hps_participant_role';
  $handler->display->display_options['fields']['hps_participant_role']['relationship'] = 'hps_course_participants_value';
  $handler->display->display_options['fields']['hps_participant_role']['label'] = '';
  $handler->display->display_options['fields']['hps_participant_role']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hps_participant_role']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_role']['element_label_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_participant_role']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_participant_role']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_participant_role']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Participant first name (hps_participant_first_name) */
  $handler->display->display_options['sorts']['hps_participant_first_name_value']['id'] = 'hps_participant_first_name_value';
  $handler->display->display_options['sorts']['hps_participant_first_name_value']['table'] = 'field_data_hps_participant_first_name';
  $handler->display->display_options['sorts']['hps_participant_first_name_value']['field'] = 'hps_participant_first_name_value';
  $handler->display->display_options['sorts']['hps_participant_first_name_value']['relationship'] = 'hps_course_participants_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['hps_courses'] = $view;

  return $export;
}
