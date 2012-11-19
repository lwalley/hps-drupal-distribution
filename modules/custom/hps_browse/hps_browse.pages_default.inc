<?php
/**
 * @file
 * hps_browse.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hps_browse_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = TRUE;
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_browse_by';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Browse by',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Taxonomy vocabulary from Node (on Node: Vocabulary [field_vocabulary])',
        'keyword' => 'taxonomy_vocabulary',
        'name' => 'entity_from_field:field_vocabulary-node-taxonomy_vocabulary',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'hps_browse_by' => 'hps_browse_by',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_primary_box';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'primary-box' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'primary-box';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_browse_by-panel_pane_browse_by';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'relationship_entity_from_field:field_vocabulary-node-taxonomy_vocabulary_1',
      ),
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_browse_by'] = $handler;

  $handler = new stdClass();
  $handler->disabled = TRUE;
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_list';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'List',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              1 => '1',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_primary_box';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'primary-box' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:name';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'primary-box';
    $pane->type = 'display_mode_links_content_type';
    $pane->subtype = 'display_mode_links_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
        1 => 'empty',
      ),
      'display_modes' => '[List](),[Gallery](gallery),[Index](index)',
      'form_build_id' => 'form-jOJmbsc2r0iE97dIIJW8xIsNT1pV_vRSr0aqJslFfKM',
      'form_token' => 'jD84-ba_4A5_8uQ8eyUMjTX_wXuT2faX2lKE546KzvQ',
      'form_id' => '_display_mode_links_content_type_edit_form',
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
    $display->content['new-3'] = $pane;
    $display->panels['primary-box'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'primary-box';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_browse-panel_pane_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['primary-box'][1] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_list'] = $handler;

  $handler = new stdClass();
  $handler->disabled = TRUE;
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_root';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Root',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              1 => '1',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'term_parent',
          'settings' => array(
            'vid' => '1',
          ),
          'context' => 'argument_term_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_primary_box';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'primary-box' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:name';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'primary-box';
    $pane->type = 'term_description';
    $pane->subtype = 'term_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_term_1',
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
    $display->content['new-5'] = $pane;
    $display->panels['primary-box'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'primary-box';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_browse_by-panel_pane_child_terms';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['primary-box'][1] = 'new-6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_root'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hps_browse_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = TRUE;
  $page->api_version = 1;
  $page->name = 'hps_browse_by_modes';
  $page->task = 'page';
  $page->admin_title = 'HPS Browse By ... Alternative Display Modes';
  $page->admin_description = 'Alternative display modes for browsing taxonomy term pages, see default taxonomy/term/%term page for default display mode.';
  $page->path = 'taxonomy/term/%taxonomy_term/%mode';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'Gallery',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'taxonomy_term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => '1',
          2 => 0,
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
          8 => 0,
        ),
        'breadcrumb' => 0,
        'transform' => 0,
      ),
    ),
    'mode' => array(
      'id' => 1,
      'identifier' => 'Display Mode',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = TRUE;
  $handler->api_version = 1;
  $handler->name = 'page_hps_browse_by_modes_panel_context_gallery';
  $handler->task = 'page';
  $handler->subtask = 'hps_browse_by_modes';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Gallery',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              1 => '1',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'gallery',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_primary_box';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
      'primary-box' => NULL,
    ),
    'center' => array(
      'style' => 'naked',
    ),
    'middle' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '%tid:name';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'primary-box';
    $pane->type = 'display_mode_links_content_type';
    $pane->subtype = 'display_mode_links_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'display_modes' => '[List](),[Gallery](gallery),[Index](index)',
      'form_build_id' => 'form-Alh_rg3w0ixK2RU0IXe-Tfh-39Dgef9YzRVvas_Mc8Q',
      'form_token' => 'jD84-ba_4A5_8uQ8eyUMjTX_wXuT2faX2lKE546KzvQ',
      'form_id' => '_display_mode_links_content_type_edit_form',
      'override_title' => 1,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_term_1',
        1 => 'argument_string_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['primary-box'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'primary-box';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_browse-panel_pane_gallery';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = TRUE;
  $handler->api_version = 1;
  $handler->name = 'page_hps_browse_by_modes_panel_context_index';
  $handler->task = 'page';
  $handler->subtask = 'hps_browse_by_modes';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Index',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              1 => '1',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'index',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'hpszen_primary_box';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
      'primary-box' => NULL,
    ),
    'center' => array(
      'style' => 'naked',
    ),
    'middle' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '%tid:name';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'primary-box';
    $pane->type = 'display_mode_links_content_type';
    $pane->subtype = 'display_mode_links_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'display_modes' => '[List](),[Gallery](gallery),[Index](index)',
      'form_build_id' => 'form-xeta15N9BgCjc7l9tQOVvCggsS9QP3YXyIw5pTjnPCI',
      'form_token' => 'jD84-ba_4A5_8uQ8eyUMjTX_wXuT2faX2lKE546KzvQ',
      'form_id' => '_display_mode_links_content_type_edit_form',
      'override_title' => 1,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_term_1',
        1 => 'argument_string_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['primary-box'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'primary-box';
    $pane->type = 'views_panes';
    $pane->subtype = 'hps_browse-panel_pane_index';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['primary-box'][1] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hps_browse_by_modes'] = $page;

  return $pages;

}
