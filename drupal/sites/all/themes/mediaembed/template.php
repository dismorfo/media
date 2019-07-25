<?php

/**
 * Implements function hook_js_alter.
 * https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_js_alter/7
 */
// function mediaembed_js_alter ( &$javascript ) { }

/**
 * Implements hook_css_alter().
 * https://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_css_alter/7
 */
// function mediaembed_css_alter(&$css) { }

/**
 * Implementation of hook_theme().
 */
function mediaembed_theme() {

  $items = array();

  // Content theming.
  $items['node'] = array(
    'path' => drupal_get_path('theme', 'mediaembed') .'/templates',
    'template' => 'object',
  );

  $items['node']['template'] = 'node';

  return $items;

}
