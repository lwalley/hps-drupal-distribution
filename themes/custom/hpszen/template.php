<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   hpszen_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: hpszen_field()
 *
 *   where hpszen is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 *
 *
 *   @note Preprocess functions for theme suggestions do not work. You have to
 *         either declare the theme in hook_theme or call a preprocess
 *         suggestion function from a generic preprocess function i.e. generate
 *         function name from $variables properties and then call it
 *         dynamically.
 *   @see http://drupal.org/node/939462
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

  if ($variables['menu_item']) {
    switch ($variables['menu_item']['page_callback']) {
      case 'page_manager_page_execute':
      case 'page_manager_term_view_page':
      case 'page_manager_node_view_page':
      case 'page_manager_contact_site':
        // Add panels layout name to body class attribute.
        $page = page_manager_get_current_page();
        if (isset($page['name'])) {
          $variables['classes_array'][] = drupal_clean_css_identifier($page['name']);
        }
        if (isset($page['handler'])) {
          $variables['classes_array'][] = drupal_clean_css_identifier($page['handler']->conf['display']->layout);
        }
        break;
    }
  }
  // Strip html from head title
  if ($variables['head_title']) {
    $variables['head_title'] = strip_tags(htmlspecialchars_decode($variables['head_title']));
  }

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
  // Add log in menu item to secondary menu for anonymous users.
  if (!user_is_logged_in()) {
    $variables['secondary_menu']['menu-login'] = array(
      'href' => 'user/login',
      'title' => t('Log in'),
    );
  }
  // URL Redirect module adds action link direct to $content, here we move it
  // to $action_links
  // @see templates/pages.tpl.php
  if (isset($variables['page']['content']['system_main']['actions']) &&
      $actions = $variables['page']['content']['system_main']['actions']) {
    $variables['action_links'][] = $actions;
    unset($variables['page']['content']['system_main']['actions']);
    unset($actions);
  }
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
  // Optionally, run node-type-specific preprocess functions, like
  // hpszen_preprocess_node_page() or STARTERKIT_preprocess_node_story().
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
/* -- Delete this line to use this function
function hpszen_preprocess_block(&$variables, $hook) {
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
