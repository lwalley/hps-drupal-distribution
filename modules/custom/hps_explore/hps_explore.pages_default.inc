<?php
/**
 * @file
 * hps_explore.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hps_explore_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hps_explore';
  $page->task = 'page';
  $page->admin_title = 'HPS Explore';
  $page->admin_description = 'Explore landing page.';
  $page->path = 'explore';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Explore the archive',
    'name' => 'main-menu',
    'weight' => '10',
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
  $handler->name = 'page_hps_explore_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hps_explore';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'DC Subject MBL History vocabulary',
        'keyword' => 'dc_subject_mblhistory_vocabulary',
        'name' => 'entity:taxonomy_vocabulary',
        'entity_id' => '9',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'DC Description Type vocabulary',
        'keyword' => 'dc_description_type_vocabulary',
        'name' => 'entity:taxonomy_vocabulary',
        'entity_id' => '1',
        'id' => 2,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_landing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'primary-box' => NULL,
      'aside-box' => NULL,
      'downside-box' => NULL,
      'introduction' => NULL,
      'featured' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'featured';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-hps_search-page_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 1,
      'override_title_text' => 'Quick search',
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
    $display->panels['featured'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'featured';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_browse_by-panel_pane_browse_by';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'context_entity:taxonomy_vocabulary_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Browse by topic',
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
    $display->panels['featured'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'featured';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_browse_by-panel_pane_browse_by';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'context_entity:taxonomy_vocabulary_2',
      ),
      'override_title' => 1,
      'override_title_text' => 'Browse by format',
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
    $display->panels['featured'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'introduction';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_explore-panel_pane_explore_introduction';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['introduction'][0] = 'new-4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hps_explore'] = $page;

  return $pages;

}
