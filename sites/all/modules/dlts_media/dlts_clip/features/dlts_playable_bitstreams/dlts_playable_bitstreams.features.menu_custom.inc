<?php
/**
 * @file
 * dlts_playable_bitstreams.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dlts_playable_bitstreams_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-content.
  $menus['menu-content'] = array(
    'menu_name' => 'menu-content',
    'title' => 'Content links',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Content links');

  return $menus;
}
