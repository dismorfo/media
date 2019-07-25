<?php

/**
 * @file
 * media_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function media_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clip_by_identifier';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clip by identifier';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['text'] = '[path]/mode/embed';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Contextual filter: Content: Identifier (field_identifier) */
  $handler->display->display_options['arguments']['field_identifier_value']['id'] = 'field_identifier_value';
  $handler->display->display_options['arguments']['field_identifier_value']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['arguments']['field_identifier_value']['field'] = 'field_identifier_value';
  $handler->display->display_options['arguments']['field_identifier_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_identifier_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_identifier_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_identifier_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_identifier_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_clip' => 'dlts_clip',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'api/clip/%';
  $export['clip_by_identifier'] = $view;

  $view = new view();
  $view->name = 'clips_by_collection';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clips by collection';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Clips by collection';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_identifier' => 'field_identifier',
    'field_collection' => 'field_collection',
    'field_bitstream_ref' => 'field_bitstream_ref',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_identifier' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collection' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bitstream_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['delta_offset'] = '0';
  /* Field: Content: Bitstream Reference */
  $handler->display->display_options['fields']['field_bitstream_ref']['id'] = 'field_bitstream_ref';
  $handler->display->display_options['fields']['field_bitstream_ref']['table'] = 'field_data_field_bitstream_ref';
  $handler->display->display_options['fields']['field_bitstream_ref']['field'] = 'field_bitstream_ref';
  $handler->display->display_options['fields']['field_bitstream_ref']['label'] = 'Bitstream';
  $handler->display->display_options['fields']['field_bitstream_ref']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bitstream_ref']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['field_bitstream_ref']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_bitstream_ref']['alter']['path'] = 'node/[field_bitstream_ref-nid]/edit';
  /* Sort criterion: Content: Collection (field_collection) */
  $handler->display->display_options['sorts']['field_collection_nid']['id'] = 'field_collection_nid';
  $handler->display->display_options['sorts']['field_collection_nid']['table'] = 'field_data_field_collection';
  $handler->display->display_options['sorts']['field_collection_nid']['field'] = 'field_collection_nid';
  $handler->display->display_options['sorts']['field_collection_nid']['expose']['label'] = 'Collection (field_collection)';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Collection (field_collection) */
  $handler->display->display_options['arguments']['field_collection_nid']['id'] = 'field_collection_nid';
  $handler->display->display_options['arguments']['field_collection_nid']['table'] = 'field_data_field_collection';
  $handler->display->display_options['arguments']['field_collection_nid']['field'] = 'field_collection_nid';
  $handler->display->display_options['arguments']['field_collection_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_collection_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_collection_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_collection_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_clip' => 'dlts_clip',
  );
  /* Filter criterion: Content: Collection (field_collection) */
  $handler->display->display_options['filters']['field_collection_nid']['id'] = 'field_collection_nid';
  $handler->display->display_options['filters']['field_collection_nid']['table'] = 'field_data_field_collection';
  $handler->display->display_options['filters']['field_collection_nid']['field'] = 'field_collection_nid';
  $handler->display->display_options['filters']['field_collection_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_collection_nid']['expose']['operator_id'] = 'field_collection_nid_op';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['label'] = 'Collection';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['operator'] = 'field_collection_nid_op';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['identifier'] = 'field_collection_nid';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_collection_nid']['expose']['remember_roles'] = array(
    2 => 0,
    3 => '3',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/clips-by-collection';
  $export['clips_by_collection'] = $view;

  $view = new view();
  $view->name = 'collection_playlist';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'collection-playlist';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Clips by collection';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '500';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_collection' => 'field_collection',
    'field_identifier' => 'field_identifier',
    'field_partner' => 'field_partner',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collection' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_identifier' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_partner' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Collection (field_collection) */
  $handler->display->display_options['relationships']['field_collection_nid']['id'] = 'field_collection_nid';
  $handler->display->display_options['relationships']['field_collection_nid']['table'] = 'field_data_field_collection';
  $handler->display->display_options['relationships']['field_collection_nid']['field'] = 'field_collection_nid';
  $handler->display->display_options['relationships']['field_collection_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Code (field_code) */
  $handler->display->display_options['arguments']['field_code_value']['id'] = 'field_code_value';
  $handler->display->display_options['arguments']['field_code_value']['table'] = 'field_data_field_code';
  $handler->display->display_options['arguments']['field_code_value']['field'] = 'field_code_value';
  $handler->display->display_options['arguments']['field_code_value']['relationship'] = 'field_collection_nid';
  $handler->display->display_options['arguments']['field_code_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_code_value']['title'] = 'Clips by collection: "%1"';
  $handler->display->display_options['arguments']['field_code_value']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_code_value']['breadcrumb'] = 'Clips by collection: "%1"';
  $handler->display->display_options['arguments']['field_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_code_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_clip' => 'dlts_clip',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Playlists by collection';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Code (field_code) */
  $handler->display->display_options['arguments']['field_code_value']['id'] = 'field_code_value';
  $handler->display->display_options['arguments']['field_code_value']['table'] = 'field_data_field_code';
  $handler->display->display_options['arguments']['field_code_value']['field'] = 'field_code_value';
  $handler->display->display_options['arguments']['field_code_value']['relationship'] = 'field_collection_nid';
  $handler->display->display_options['arguments']['field_code_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_code_value']['title'] = 'Playlists by collection: %1';
  $handler->display->display_options['arguments']['field_code_value']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_code_value']['breadcrumb'] = 'Playlists by collection: %1';
  $handler->display->display_options['arguments']['field_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_code_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_playlist' => 'dlts_playlist',
  );
  $handler->display->display_options['path'] = 'admin/collection/%/playlist';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'admin/collection/%/clips';
  $export['collection_playlist'] = $view;

  return $export;
}
