<?php
/**
 * @file
 * hps_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hps_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hps_news_image|node|hps_news|default';
  $field_group->group_name = 'group_hps_news_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hps_news';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '1',
    'children' => array(
      0 => 'field_hps_news_image',
      1 => 'field_hps_news_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_hps_news_image|node|hps_news|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hps_news_image|node|hps_news|form';
  $field_group->group_name = 'group_hps_news_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hps_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '2',
    'children' => array(
      0 => 'field_hps_news_image',
      1 => 'field_hps_news_image_caption',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hps_news_image|node|hps_news|form'] = $field_group;

  return $export;
}
