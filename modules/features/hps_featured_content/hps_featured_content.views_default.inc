<?php
/**
 * @file
 * hps_featured_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hps_featured_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hps_featured_content';
  $view->description = 'Entities to reference (defaults to DSpace items with images) and displays for featured content.';
  $view->tag = 'HPS';
  $view->base_table = 'node';
  $view->human_name = 'HPS Featured Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Featured Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['empty'] = 'Missing image!';
  $handler->display->display_options['fields']['dspace_image']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'page' => 'page',
    'dspaced_entities_item' => 'dspaced_entities_item',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Displays a list of entities for the entity reference field autocomplete in the HPS Featured Content node edit form.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'dspace_image' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['dspace_image']['id'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['table'] = 'field_data_dspace_image';
  $handler->display->display_options['fields']['dspace_image']['field'] = 'dspace_image';
  $handler->display->display_options['fields']['dspace_image']['label'] = '';
  $handler->display->display_options['fields']['dspace_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['dspace_image']['empty'] = '[no image]';
  $handler->display->display_options['fields']['dspace_image']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['dspace_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['dspace_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;

  /* Display: Featured Content Slides */
  $handler = $view->new_display('panel_pane', 'Featured Content Slides', 'panel_pane_featured_content_slides');
  $handler->display->display_options['display_description'] = 'Lists limited number of featured content nodes with \'slides\' CSS class added to convert list to slideshow in theme.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'slides';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Featured entity */
  $handler->display->display_options['fields']['hps_featured_entity']['id'] = 'hps_featured_entity';
  $handler->display->display_options['fields']['hps_featured_entity']['table'] = 'field_data_hps_featured_entity';
  $handler->display->display_options['fields']['hps_featured_entity']['field'] = 'hps_featured_entity';
  $handler->display->display_options['fields']['hps_featured_entity']['label'] = '';
  $handler->display->display_options['fields']['hps_featured_entity']['element_type'] = '0';
  $handler->display->display_options['fields']['hps_featured_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['hps_featured_entity']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['hps_featured_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['hps_featured_entity']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['hps_featured_entity']['settings'] = array(
    'view_mode' => 'hps_featured_content',
    'links' => 1,
  );
  /* Field: Content: Alternative image */
  $handler->display->display_options['fields']['field_hps_featured_content_image']['id'] = 'field_hps_featured_content_image';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['table'] = 'field_data_field_hps_featured_content_image';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['field'] = 'field_hps_featured_content_image';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['label'] = '';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hps_featured_content_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_hps_featured_content_image']['alter']['path'] = '[hps_featured_entity]';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hps_featured_content_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hps_featured_content_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_hps_featured_content_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hps_featured_content_image']['settings'] = array(
    'image_style' => 'hps_large_adaptive',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<em> <i> <strong> <b> <p>';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hps_featured_content' => 'hps_featured_content',
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
  $handler->display->display_options['inherit_panels_path'] = '0';
  $export['hps_featured_content'] = $view;

  return $export;
}
