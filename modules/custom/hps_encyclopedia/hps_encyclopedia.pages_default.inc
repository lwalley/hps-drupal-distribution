<?php
/**
 * @file
 * hps_encyclopedia.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hps_encyclopedia_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Encyclopedia Item',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: HPS Encyclopedia Items',
        'keyword' => 'view',
        'name' => 'view_from_argument:hps_encyclopedia_items-ctools_context_encyclopedia_item',
        'context' => array(
          0 => 'argument_entity_id:node_1',
        ),
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'dspaced_entities_item' => 'dspaced_entities_item',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_i1_b1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'i1' => NULL,
      'b1' => NULL,
    ),
    'i1' => array(
      'style' => 'naked',
    ),
    'b1' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'b1';
    $pane->type = 'views_row';
    $pane->subtype = 'views_row';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'rows' => array(),
      'use_fields' => 0,
      'fields' => array(),
      'context' => 'relationship_view_from_argument:hps_encyclopedia_items-ctools_context_encyclopedia_item_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['b1'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'b1';
    $pane->type = 'block';
    $pane->subtype = 'print-print-links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['b1'][1] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hps_encyclopedia_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hps_encyclopedia_items';
  $page->task = 'page';
  $page->admin_title = 'HPS Encyclopedia Items';
  $page->admin_description = 'Lists all encyclopedia (DSpace) items.';
  $page->path = 'pages';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hps_encyclopedia_items_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hps_encyclopedia_items';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Items',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: HPS Encyclopedia Items: Items',
        'keyword' => 'view',
        'name' => 'view:hps_encyclopedia_items-ctools_context_encyclopedia_items',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_i1_b1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'i1' => NULL,
      'b1' => NULL,
    ),
    'i1' => array(
      'style' => 'naked',
    ),
    'b1' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'b1';
    $pane->type = 'views_pager';
    $pane->subtype = 'views_pager';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:hps_encyclopedia_items-ctools_context_encyclopedia_items_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['b1'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'b1';
    $pane->type = 'views_row';
    $pane->subtype = 'views_row';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'rows' => array(),
      'use_fields' => 0,
      'fields' => array(),
      'context' => 'context_view:hps_encyclopedia_items-ctools_context_encyclopedia_items_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['b1'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'b1';
    $pane->type = 'views_pager';
    $pane->subtype = 'views_pager';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:hps_encyclopedia_items-ctools_context_encyclopedia_items_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['b1'][2] = 'new-3';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hps_encyclopedia_items'] = $page;

  return $pages;

}
