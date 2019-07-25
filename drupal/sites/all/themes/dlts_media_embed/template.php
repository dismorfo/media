<?php

/**
 * Implements function hook_js_alter.
 * https://api.drupal.org/api/drupal/modules!system!system.api.php/function/hook_js_alter/7
 */
// function dlts_embed_js_alter ( &$javascript ) { }

/**
 * Implements hook_css_alter().
 * https://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_css_alter/7
 */
// function dlts_embed_css_alter(&$css) { }

/**
 * Implementation of hook_theme().
 */
function dlts_embed_theme() {

  $items = array();

  // Content theming.
  $items['node'] = array(
    'path' => drupal_get_path('theme', 'dlts_embed') .'/templates',
    'template' => 'object',
  );

  $items['node']['template'] = 'node';

  return $items;

}
