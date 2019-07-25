<?php
/**
 * @file
 * dlts_playable_bitstreams.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dlts_playable_bitstreams_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dlts_playable_bitstreams_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function dlts_playable_bitstreams_image_default_styles() {
  $styles = array();

  // Exported image style: poster.
  $styles['poster'] = array(
    'label' => 'poster',
    'effects' => array(),
  );

  // Exported image style: thumbnails_playlist.
  $styles['thumbnails_playlist'] = array(
    'label' => 'thumbnails_playlist',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 165,
          'height' => 165,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dlts_playable_bitstreams_node_info() {
  $items = array(
    'dlts_bitstream_set' => array(
      'name' => t('Bitstream Set'),
      'base' => 'node_content',
      'description' => t('Node to represent a single unit of time-based media, e.g., the first 10 minutes of a particular piece of video footage. Multiple encodes (e.g., 300k, 800k) can be stored as multiple \'bitstream\' filesets.
'),
      'has_title' => '1',
      'title_label' => t('DLTS Bitstream Set'),
      'help' => '',
    ),
    'dlts_clip' => array(
      'name' => t('Clip'),
      'base' => 'node_content',
      'description' => t('Represents a segment from a physical time-based media asset. This is a logical overlay for a bitstream set.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dlts_collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dlts_creativework' => array(
      'name' => t('Creative Work'),
      'base' => 'node_content',
      'description' => t('The most generic kind of creative work, including audio, movies, etc. See: http://schema.org/CreativeWork'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dlts_partner' => array(
      'name' => t('Partner'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dlts_playlist' => array(
      'name' => t('Playlist'),
      'base' => 'node_content',
      'description' => t('An order list of clips.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
