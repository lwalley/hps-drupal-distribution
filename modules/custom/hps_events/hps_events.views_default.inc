<?php
/**
 * @file
 * hps_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hps_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hps_events';
  $view->description = 'Upcoming events and full listings for events landing page.';
  $view->tag = 'HPS';
  $view->base_table = 'node';
  $view->human_name = 'HPS Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More events';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'No results message';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No events found.';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_event' => 'hps_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Upcoming Events */
  $handler = $view->new_display('panel_pane', 'Upcoming Events', 'panel_pane_upcoming_events');
  $handler->display->display_options['display_description'] = 'Lists all upcoming events.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'All Events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_hps_event_date) */
  $handler->display->display_options['sorts']['field_hps_event_date_value']['id'] = 'field_hps_event_date_value';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['field'] = 'field_hps_event_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_event' => 'hps_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Content: Date -  start date (field_hps_event_date) */
  $handler->display->display_options['filters']['field_hps_event_date_value']['id'] = 'field_hps_event_date_value';
  $handler->display->display_options['filters']['field_hps_event_date_value']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['filters']['field_hps_event_date_value']['field'] = 'field_hps_event_date_value';
  $handler->display->display_options['filters']['field_hps_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_hps_event_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_hps_event_date_value']['default_date'] = 'today';
  $handler->display->display_options['filters']['field_hps_event_date_value']['year_range'] = '-0:+3';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Events */
  $handler = $view->new_display('ctools_context', 'Events', 'ctools_context_events');
  $handler->display->display_options['display_description'] = 'Lists all published events providing context for events landing page.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['pager_position'] = 'both';
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_hps_event_date']['id'] = 'field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['field'] = 'field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['label'] = 'Event Date';
  $handler->display->display_options['fields']['field_hps_event_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_hps_event_location']['id'] = 'field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['table'] = 'field_data_field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['field'] = 'field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_hps_event_location']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_hps_event_date) */
  $handler->display->display_options['sorts']['field_hps_event_date_value']['id'] = 'field_hps_event_date_value';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['field'] = 'field_hps_event_date_value';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_hps_event_date_value']['expose']['label'] = 'Date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Date -  start date (field_hps_event_date) */
  $handler->display->display_options['arguments']['field_hps_event_date_value']['id'] = 'field_hps_event_date_value';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['field'] = 'field_hps_event_date_value';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_hps_event_date_value']['use_fromto'] = 'no';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Upcoming and Latest Past Events */
  $handler = $view->new_display('panel_pane', 'Upcoming and Latest Past Events', 'panel_pane_upcoming_or_latest_events');
  $handler->display->display_options['display_description'] = 'Lists upcoming events or latest past events.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'All Events';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_hps_event_date']['id'] = 'field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['field'] = 'field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_date']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_hps_event_date']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_hps_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_hps_event_date']['field_api_classes'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_hps_event_location']['id'] = 'field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['table'] = 'field_data_field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['field'] = 'field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_location']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_hps_event_location']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_hps_event_location']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_hps_event_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_hps_event_location']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'organisation' => 'organisation',
    ),
  );
  $handler->display->display_options['fields']['field_hps_event_location']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_hps_event_date) */
  $handler->display->display_options['sorts']['field_hps_event_date_value']['id'] = 'field_hps_event_date_value';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['field'] = 'field_hps_event_date_value';
  $handler->display->display_options['sorts']['field_hps_event_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_event' => 'hps_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Date -  start date (field_hps_event_date) */
  $handler->display->display_options['filters']['field_hps_event_date_value_1']['id'] = 'field_hps_event_date_value_1';
  $handler->display->display_options['filters']['field_hps_event_date_value_1']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['filters']['field_hps_event_date_value_1']['field'] = 'field_hps_event_date_value';
  $handler->display->display_options['filters']['field_hps_event_date_value_1']['operator'] = 'between';
  $handler->display->display_options['filters']['field_hps_event_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_hps_event_date_value_1']['default_date'] = 'today -1 year';
  $handler->display->display_options['filters']['field_hps_event_date_value_1']['default_to_date'] = 'today + 6 months';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest events';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => 'Latest events',
        'language' => 'en',
        'category' => 'events',
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
        'author' => '',
        'category' => '',
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
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_hps_event_date']['id'] = 'field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['table'] = 'field_data_field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['field'] = 'field_hps_event_date';
  $handler->display->display_options['fields']['field_hps_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_hps_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_date']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_hps_event_location']['id'] = 'field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['table'] = 'field_data_field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['field'] = 'field_hps_event_location';
  $handler->display->display_options['fields']['field_hps_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_location']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_location']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_hps_event_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_event_location']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_event_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_event_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_hps_event_location']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[field_hps_event_date] [body] [field_hps_event_location]';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
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
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['path'] = 'events/feed';
  $handler->display->display_options['displays'] = array(
    'ctools_context_events' => 'ctools_context_events',
    'default' => 0,
    'panel_pane_upcoming_events' => 0,
    'panel_pane_upcoming_or_latest_events' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['hps_events'] = $view;

  return $export;
}
