<?php

/**
 * @file
 */

/**
 * Implements hook_views_default().
 */
function dspaced_ui_views_default_views() {

  $views = array();
  $views['dspaced_ui_job_schedule'] = _dspaced_ui_job_schedule_default();
  $views['dspaced_ui_queue'] = _dspaced_ui_queue_default();
  $views['dspaced_ui_feeds_log'] = _dspaced_ui_feeds_log_default();
  return $views;

}

/**
 * Helper function to define dspaced_ui_job_schedule view.
 */
function _dspaced_ui_job_schedule_default() {
  $view = new view();
  $view->name = 'dspaced_ui_job_schedule';
  $view->description = 'Displays scheduled jobs for DSpaced imports.';
  $view->tag = 'DSpaced';
  $view->base_table = 'job_schedule';
  $view->human_name = 'DSpaced Job Schedule';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Import schedule';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer dspaced';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Job Schedule: Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  /* Field: Job Schedule: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Source node ID';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'node/[id]';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Job Schedule: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Job Schedule: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Job Schedule: Last */
  $handler->display->display_options['fields']['last']['id'] = 'last';
  $handler->display->display_options['fields']['last']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['last']['field'] = 'last';
  $handler->display->display_options['fields']['last']['label'] = 'Last executed';
  $handler->display->display_options['fields']['last']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['last']['date_format'] = 'time ago';
  /* Field: Job Schedule: Next */
  $handler->display->display_options['fields']['next']['id'] = 'next';
  $handler->display->display_options['fields']['next']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['next']['field'] = 'next';
  $handler->display->display_options['fields']['next']['label'] = 'Next execution';
  $handler->display->display_options['fields']['next']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['next']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['next']['date_format'] = 'time hence';
  /* Field: Job Schedule: Periodic */
  $handler->display->display_options['fields']['periodic']['id'] = 'periodic';
  $handler->display->display_options['fields']['periodic']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['periodic']['field'] = 'periodic';
  $handler->display->display_options['fields']['periodic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['periodic']['type'] = 'on-off';
  $handler->display->display_options['fields']['periodic']['not'] = 0;
  /* Field: Job Schedule: Period */
  $handler->display->display_options['fields']['period']['id'] = 'period';
  $handler->display->display_options['fields']['period']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['period']['field'] = 'period';
  $handler->display->display_options['fields']['period']['label'] = 'Time between execution';
  $handler->display->display_options['fields']['period']['element_label_colon'] = FALSE;
  /* Field: Job Schedule: Expire */
  $handler->display->display_options['fields']['expire']['id'] = 'expire';
  $handler->display->display_options['fields']['expire']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['expire']['field'] = 'expire';
  $handler->display->display_options['fields']['expire']['label'] = 'Expires';
  $handler->display->display_options['fields']['expire']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['expire']['empty'] = 'Never';
  $handler->display->display_options['fields']['expire']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['expire']['date_format'] = 'time hence';
  /* Contextual filter: Job Schedule: ID */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'job_schedule';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Job Schedule: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'job_schedule';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'starts';
  $handler->display->display_options['filters']['type']['value'] = 'dspaced';

  /* Display: Summary */
  $handler = $view->new_display('attachment', 'Summary', 'attachment_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Job Schedule: Last */
  $handler->display->display_options['fields']['last']['id'] = 'last';
  $handler->display->display_options['fields']['last']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['last']['field'] = 'last';
  $handler->display->display_options['fields']['last']['label'] = 'Last executed';
  $handler->display->display_options['fields']['last']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['last']['date_format'] = 'time ago';
  /* Field: Job Schedule: Next */
  $handler->display->display_options['fields']['next']['id'] = 'next';
  $handler->display->display_options['fields']['next']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['next']['field'] = 'next';
  $handler->display->display_options['fields']['next']['label'] = 'Next execution';
  $handler->display->display_options['fields']['next']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['next']['date_format'] = 'time hence';
  /* Field: Job Schedule: Periodic */
  $handler->display->display_options['fields']['periodic']['id'] = 'periodic';
  $handler->display->display_options['fields']['periodic']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['periodic']['field'] = 'periodic';
  $handler->display->display_options['fields']['periodic']['type'] = 'on-off';
  $handler->display->display_options['fields']['periodic']['not'] = 0;
  /* Field: Job Schedule: Period */
  $handler->display->display_options['fields']['period']['id'] = 'period';
  $handler->display->display_options['fields']['period']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['period']['field'] = 'period';
  $handler->display->display_options['fields']['period']['label'] = 'Time between execution';
  $handler->display->display_options['fields']['period']['granularity'] = '2';
  /* Field: Job Schedule: Expire */
  $handler->display->display_options['fields']['expire']['id'] = 'expire';
  $handler->display->display_options['fields']['expire']['table'] = 'job_schedule';
  $handler->display->display_options['fields']['expire']['field'] = 'expire';
  $handler->display->display_options['fields']['expire']['label'] = 'Expires';
  $handler->display->display_options['fields']['expire']['empty'] = 'Never';
  $handler->display->display_options['fields']['expire']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['expire']['date_format'] = 'time hence';

  return $view;
}

/**
 * Helper function to define dspaced_ui_queue view.
 */
function _dspaced_ui_queue_default() {
  $view = new view();
  $view->name = 'dspaced_ui_queue';
  $view->description = 'Lists DSpace entities queued for update.';
  $view->tag = 'DSpaced';
  $view->base_table = 'queue';
  $view->human_name = 'DSpaced Queue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Queue';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer dspaced';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'item_id' => 'item_id',
    'created' => 'created',
    'data' => 'data',
    'expire' => 'expire',
  );
  $handler->display->display_options['style_options']['default'] = 'item_id';
  $handler->display->display_options['style_options']['info'] = array(
    'item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'data' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expire' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty';
  $handler->display->display_options['empty']['area']['content'] = '<p>There are no items in the queue.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: SystemQueue: Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'queue';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Field: SystemQueue: Data */
  $handler->display->display_options['fields']['data']['id'] = 'data';
  $handler->display->display_options['fields']['data']['table'] = 'queue';
  $handler->display->display_options['fields']['data']['field'] = 'data';
  /* Field: SystemQueue: Creation */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'queue';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Filter criterion: SystemQueue: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'queue';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = 'feeds_source_import';

  return $view;
}

/**
 * Helper function to define dspaced_ui_feeds_log view.
 */
function _dspaced_ui_feeds_log_default() {

  $view = new view();
  $view->name = 'dspaced_ui_feeds_log';
  $view->description = 'DSpaced feeds log displays.';
  $view->tag = 'DSpaced';
  $view->base_table = 'feeds_log';
  $view->human_name = 'DSpaced Feeds Log';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer feeds';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'log_time' => 'log_time',
    'request_time' => 'request_time',
    'message' => 'message',
    'severity' => 'severity',
  );
  $handler->display->display_options['style_options']['default'] = 'log_time';
  $handler->display->display_options['style_options']['info'] = array(
    'log_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'request_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'severity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There are no log messages.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  /* Field: Feeds log: Log time */
  $handler->display->display_options['fields']['log_time']['id'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['log_time']['field'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['log_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Feeds log: Request time */
  $handler->display->display_options['fields']['request_time']['id'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['request_time']['field'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['request_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Feeds log: Log message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = 'Message';
  /* Field: Feeds log: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  /* Sort criterion: Feeds log: Log time */
  $handler->display->display_options['sorts']['log_time']['id'] = 'log_time';
  $handler->display->display_options['sorts']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['sorts']['log_time']['field'] = 'log_time';
  $handler->display->display_options['sorts']['log_time']['order'] = 'DESC';
  /* Contextual filter: Feeds log: Importer id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'feeds_log';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['id']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['id']['limit'] = '0';
  /* Filter criterion: Feeds log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['group'] = 1;
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator_id'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  /* Filter criterion: Feeds log: Importer id */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['operator'] = 'starts';
  $handler->display->display_options['filters']['id']['value'] = 'dspaced';

  return $view;
}

