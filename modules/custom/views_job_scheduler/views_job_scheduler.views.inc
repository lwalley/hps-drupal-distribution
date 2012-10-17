<?php

/**
 * @file
 * Defines default views data for job_schedule table.
 */

/**
 * Implements hook_views_data().
 */
function views_job_scheduler_views_data() {
  $data = array();

  // Base table.
  $data['job_schedule']['table']['group'] = t('Job Schedule');
  $data['job_schedule']['table']['base'] = array(
    'field' => 'item_id',
    'title' => t('Job Schedule'),
    'help' => t('The Job Scheduler schedule table.'),
  );

  // Fields.
  $data['job_schedule']['item_id'] = array(
    'title' => t('Item ID'),
    'help' => t('Schedule item ID.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['job_schedule']['name'] = array(
    'title' => t('Name'),
    'help' => t('Schedule name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['job_schedule']['type'] = array(
    'title' => t('Type'),
    'help' => t('Job type.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['job_schedule']['id'] = array(
    'title' => t('ID'),
    'help' => t('Job ID.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['job_schedule']['period'] = array(
    'title' => t('Period'),
    'help' => t('Time period after which job is to be executed.'),
    'field' => array(
      'handler' => 'views_handler_field_time_interval',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['job_schedule']['crontab'] = array(
    'title' => t('Crontab'),
    'help' => t('Crontab line in *NIX format.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['job_schedule']['data'] = array(
    'title' => t('Data'),
    'help' => t('Arbitrary data for the item.'),
    'field' => array(
      'handler' => 'views_handler_field_serialized',
      'click sortable' => FALSE,
    ),
  );
  $data['job_schedule']['expire'] = array(
    'title' => t('Expire'),
    'help' => t('Timestamp when job expires.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
  $data['job_schedule']['created'] = array(
    'title' => t('Created'),
    'help' => t('Timestamp when schedule item was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
  $data['job_schedule']['last'] = array(
    'title' => t('Last'),
    'help' => t('Timestamp when a job was last executed.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
  $data['job_schedule']['periodic'] = array(
    'title' => t('Periodic'),
    'help' => t('If true job will be automatically rescheduled.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'active-disabled' => array(t('True'), t('False')),
      ),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Periodic'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['job_schedule']['next'] = array(
    'title' => t('Next'),
    'help' => t('Timestamp when a job is to be executed (next = last + period), used for fast ordering.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
  $data['job_schedule']['scheduled'] = array(
    'title' => t('Scheduled'),
    'help' => t('Timestamp when a job was scheduled. 0 if a job is currently not scheduled.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
  return $data;
}
