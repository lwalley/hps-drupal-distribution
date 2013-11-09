<?php

/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 *
 * @note Preprocess functions for theme suggestions do not work. You have to
 *       either declare the theme in hook_theme or call a preprocess
 *       suggestion function from a generic preprocess function i.e. generate
 *       function name from $variables properties and then call it
 *       dynamically.
 * @see http://drupal.org/node/939462
 */

/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function hpszen_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  hpszen_preprocess_html($variables, $hook);
  hpszen_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function hpszen_preprocess_html(&$variables, $hook) {

  // Add classes for page names and panels layouts.
  // @note Zen theme uses page_callback on menu_item for determining if this is
  //       a panels page, but that assumes the page has a matching variant that
  //       invokes panels, which is not always the case.
  if ($panels_display = panels_get_current_page_display()) {
    $variables['classes_array'][] = drupal_clean_css_identifier($panels_display->layout);
  }
  else {
    $variables['classes_array'][] = 'no-panels';
  }
  if ($current_page = page_manager_get_current_page()) {
    $variables['classes_array'][] = drupal_clean_css_identifier($current_page['name']);
  }

  // Strip html from head title
  if ($variables['head_title']) {
    $variables['head_title'] = strip_tags(htmlspecialchars_decode($variables['head_title']));
  }

  // Pass behaviour settings to javascript
  drupal_add_js(array('hpszen' => array(
    'toggleSubNavigation'     => theme_get_setting('hpszen_navigation_dropdown'),
    'toggleRelatedItemDetail' => theme_get_setting('hpszen_exhibits_js'),
  )), 'setting');


  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function hpszen_preprocess_page(&$variables, $hook) {

  // Add theme wrapper for HTTP error pages
  $status = drupal_get_http_header('status');
  switch ($status) {
    case '404 Not Found':
    case '403 Forbidden':
      if (isset($variables['page']['content']['system_main']['main']['#markup'])
        && !preg_match('/^<div/', $variables['page']['content']['system_main']['main']['#markup'])) {
        $variables['page']['content']['system_main']['main']['#prefix'] = '<div class="section"><div class="section-inner"><p>';
        $variables['page']['content']['system_main']['main']['#suffix'] = '</p></div></div>';
      }
      break;
  }


  // @note Removed log in link that was being added to secondary menu here
  //       programmatically. Instead add login and logout links to menus
  //       through GUI and use user/login? as path to avoid access issues
  //       when creating the menu item. Alternatively use path alias.
  // @see http://drupal.stackexchange.com/questions/75824/user-login-page-no-access-to-it
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function hpszen_preprocess_node(&$variables, $hook) {
  if ($variables['view_mode'] == 'hps_featured_content') {
    $variables['theme_hook_suggestions'][] = 'node__hps_featured_content';
  }

  $variables['submitted'] = t('By !username &mdash; <time datetime="!datetime">!shortdate</time>',
    array(
      '!username' => $variables['name'],
      '!datetime' => format_date($variables['node']->created, 'custom', 'c'),
      '!shortdate' => format_date($variables['node']->created, 'short'
    )
  ));

  // Remove empty print-link span
  if (empty($variables['elements']['print_links']['#markup'])) {
    $variables['elements']['print_links']['#access'] = FALSE;
    $variables['content']['print_links']['#access'] = FALSE;
  }

  // Optionally, run node-type-specific preprocess functions, like
  // hpszen_preprocess_node_page() or hpszen_preprocess_node_story().
  //$function = __FUNCTION__ . '_' . $variables['node']->type;
  //if (function_exists($function)) {
    //$function($variables, $hook);
  //}
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function hpszen_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function hpszen_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function hpszen_preprocess_block(&$variables, $hook) {
  if ($variables['block_html_id'] == 'block-system-main-menu') {
    // Add navigation behaviour state depending on theme settings.
    $variables['classes_array'][] = 'navigation__block';
    if (theme_get_setting('hpszen_navigation_dropdown')) {
      $variables['classes_array'][] = 'navigation__block--dropdown';
    }
  }
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
//*/

/**
 * Implements hook_preprocess_field().
 *
 * Override or insert variables into a field template.
 */
/* -- Delete this line to use this function
function hpszen_preprocess_field(&$variables, $hook) {
}
//*/


/**
 * Implements hook_preprocess_views_view().
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("views_view" in this case.)
 */
function hpszen_preprocess_views_view(&$variables, $hook) {
  // Include jQuery Cycle Javascript plugin for slideshows
  if ($variables['css_class'] == 'hps-slideshow' && module_exists('libraries')) {
    if ($library_path = libraries_get_path('jquery.cycle')) {
      foreach (array('jquery.cycle.all.min.js', 'jquery.cycle.all.js') as $file_name) {
        $file_path = "$library_path/$file_name";
        if (file_exists($file_path)) {
          drupal_add_js($file_path);
          break;
        }
      }
    }
  }
}

/**
 * Implements hook_preprocess_views_view_fields().
 */
function hpszen_preprocess_views_view_fields(&$variables) {
  if ($variables['view']->name == 'hps_browse_by' && array_key_exists('description', $variables['fields'])) {
    // Re-render term description content without the container div element
    // added by template_preprocess_views_view_fields.
    // @see http://api.drupal.org/api/views/theme%21theme.inc/function/template_preprocess_views_view_fields/7
    $variables['fields']['description']->content = $variables['view']->style_plugin->get_field($variables['view']->row_index, 'description');
  }
}
/**
 * Implements hook_preprocess_views_view_field().
 */
function hpszen_preprocess_views_view_field(&$variables) {
  if ($variables['view']->name == 'hps_browse' && $variables['view']->current_display == 'panel_pane_gallery') {
    if ($variables['field']->field == 'dspace_bitstream_url') {
      // @todo This is a total hack, preferably do this pre-render or with theme
      // suggestion if we can figure out how to get the context
      $pattern = "/'width':.*?,/";
      $replace = "'width': 230,";
      $variables['output'] = preg_replace($pattern, $replace, $variables['output']);
      $pattern = "/'height':.*?,/";
      $replace = "'height': 130,";
      $variables['output'] = preg_replace($pattern, $replace, $variables['output']);
    }
  }
}

/**
 * Implements preprocess_panels_pane().
 */
function hpszen_preprocess_panels_pane(&$variables) {
  if ($variables['pane']->subtype == 'hps_courses_search') {
    // @note Browsing by facets using Views Facets Blocks and Panels is made
    //       possible with patch. However, view is missing a more link, and
    //       doesn't use views styles, sorts or paging. So we override e.g.
    //       more link and sort, as needed here. This is quick and dirty fix.
    // @see  http://drupal.org/node/1925114#comment-7107040
    // @todo Make Facets Blocks in Panels adhere to views or panel settings or
    //       find better plan for overriding Views render.
    //$variables['more'] = l(t('more'), 'courses');
    $data = array();
    foreach ($variables['content']['facets']['#items'] as $key => &$item) {
      $data[$key] = $item['data'];
      unset($item['class']);
      $item['data'] .= ', ';
    }
    $sort_direction = SORT_ASC;
    $limit = 10;
    if ($variables['pane']->configuration['display'] == 'search_api_views_facets_block_course_year') {
      $sort_direction = SORT_DESC;
      $limit = 30;
    }
    array_multisort($data, $sort_direction, $variables['content']['facets']['#items']);
    // Truncate number of items displayed... alternative would be to show all and hide with client-side behaviour.
    $variables['content']['facets']['#items'] = array_splice($variables['content']['facets']['#items'], 0, $limit);
    // Remove comma from last item.
    $last = array_pop($variables['content']['facets']['#items']);
    $last['data'] = rtrim($last['data'], ", ");
    $variables['content']['facets']['#items'][] = $last;
    $variables['content']['facets']['#items'][] = array(
      'data' => t('... <a href="!url">all courses</a>', array('!url' => '/courses'))
    );
  }
}

/**
 * Implements hook_preprocess_menu_link().
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("menu_link" in this case.)
 */
function hpszen_preprocess_menu_link(&$variables, $hook) {
  if (!empty($variables['element']['#below'])) {
    // For expanded menu items replace theme wrapper for submenu tree.
    // @see hpszen_menu_tree__main_menu__submenu().
    $custom_theme_wrapper = "menu_tree";
    if (isset($variables['element']['#original_link'])) {
      $menu_name = strtr($variables['element']['#original_link']['menu_name'], array('-' => '_'));
      $custom_theme_wrapper .= "__{$menu_name}";
    }
    $custom_theme_wrapper .= "__submenu";
    $variables['element']['#below']['#theme_wrappers'] = array($custom_theme_wrapper);
  }
}

/**
 * Implements hook_menu_tree__main_menu__submenu().
 *
 * Custom theme wrapper for main menu's expanded submenus.
 *
 * @note Unfortunately we have very little context to go on with the menu_tree
 *       theme, so we added a custom theme wrapper in menu_link preprocess, to
 *       target just the submenus.
 */
function hpszen_menu_tree__main_menu__submenu($variables) {
  return '<ul class="menu element-invisible">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_image().
 *
 * Adds a wrapper to img element with style name for use with responsive layouts.
 *
 */
function hpszen_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);
  foreach (array('width', 'height', 'alt', 'title') as $key) {
    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }
  $style_name_css = '';
  if (isset($variables['style_name']) && !empty($variables['style_name'])) {
    $style_name_css = ' ' . drupal_clean_css_identifier($variables['style_name']);
  }
  $element = array(
    '#prefix' => '<span class="hpszen-responsive' . $style_name_css . '">',
    '#markup' => '<img' . drupal_attributes($attributes) . ' />',
    '#suffix' => '</span>',
  );
  return render($element);
}

