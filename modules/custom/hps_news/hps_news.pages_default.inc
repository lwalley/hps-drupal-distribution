<?php
/**
 * @file
 * hps_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hps_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hps_news';
  $page->task = 'page';
  $page->admin_title = 'HPS News';
  $page->admin_description = 'Landing page for news.';
  $page->path = 'news';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hps_news_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hps_news';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'News',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: HPS News: News',
        'keyword' => 'view',
        'name' => 'view:hps_news-ctools_context_news',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_primary_aside_boxes';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'primary-box' => NULL,
      'aside-box' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'News';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'primary-box';
    $pane->type = 'views_exposed';
    $pane->subtype = 'views_exposed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:hps_news-ctools_context_news_1',
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
    $display->panels['primary-box'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'primary-box';
    $pane->type = 'views_pager';
    $pane->subtype = 'views_pager';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:hps_news-ctools_context_news_1',
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
    $display->panels['primary-box'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'primary-box';
    $pane->type = 'views_empty';
    $pane->subtype = 'views_empty';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:hps_news-ctools_context_news_1',
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
    $display->panels['primary-box'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'primary-box';
    $pane->type = 'views_row';
    $pane->subtype = 'views_row';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'rows' => array(),
      'use_fields' => 0,
      'fields' => array(),
      'context' => 'context_view:hps_news-ctools_context_news_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['primary-box'][3] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hps_news'] = $page;

  return $pages;

}
