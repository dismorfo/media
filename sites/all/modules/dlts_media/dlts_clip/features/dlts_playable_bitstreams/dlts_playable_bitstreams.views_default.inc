<?php
/**
 * @file
 * dlts_playable_bitstreams.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dlts_playable_bitstreams_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'audio_clips';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Audio clips';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Audio clips';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_identifier_1' => 'field_identifier_1',
    'field_bitstream_ref' => 'field_bitstream_ref',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'field_identifier_1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_identifier_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Bitstream Reference (field_bitstream_ref) */
  $handler->display->display_options['relationships']['field_bitstream_ref_nid']['id'] = 'field_bitstream_ref_nid';
  $handler->display->display_options['relationships']['field_bitstream_ref_nid']['table'] = 'field_data_field_bitstream_ref';
  $handler->display->display_options['relationships']['field_bitstream_ref_nid']['field'] = 'field_bitstream_ref_nid';
  $handler->display->display_options['relationships']['field_bitstream_ref_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_bitstream_ref_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier_1']['id'] = 'field_identifier_1';
  $handler->display->display_options['fields']['field_identifier_1']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier_1']['field'] = 'field_identifier';
  /* Field: Content: Bitstream Reference */
  $handler->display->display_options['fields']['field_bitstream_ref']['id'] = 'field_bitstream_ref';
  $handler->display->display_options['fields']['field_bitstream_ref']['table'] = 'field_data_field_bitstream_ref';
  $handler->display->display_options['fields']['field_bitstream_ref']['field'] = 'field_bitstream_ref';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Identifier (field_identifier) */
  $handler->display->display_options['sorts']['field_identifier_value']['id'] = 'field_identifier_value';
  $handler->display->display_options['sorts']['field_identifier_value']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['sorts']['field_identifier_value']['field'] = 'field_identifier_value';
  /* Contextual filter: Content: Media type (field_media_type) */
  $handler->display->display_options['arguments']['field_media_type_value']['id'] = 'field_media_type_value';
  $handler->display->display_options['arguments']['field_media_type_value']['table'] = 'field_data_field_media_type';
  $handler->display->display_options['arguments']['field_media_type_value']['field'] = 'field_media_type_value';
  $handler->display->display_options['arguments']['field_media_type_value']['relationship'] = 'field_bitstream_ref_nid';
  $handler->display->display_options['arguments']['field_media_type_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_media_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_media_type_value']['default_argument_options']['argument'] = 'audio';
  $handler->display->display_options['arguments']['field_media_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_media_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_media_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_media_type_value']['limit'] = '0';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_clip' => 'dlts_clip',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'audio-clip';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'clip';
  $export['audio_clips'] = $view;

  $view = new view();
  $view->name = 'bitstream_sets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bitstream Sets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bitstream Set';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_bitstream_set' => 'dlts_bitstream_set',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'bitstream-sets';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['bitstream_sets'] = $view;

  $view = new view();
  $view->name = 'clips';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clips';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Clips';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_identifier_1' => 'field_identifier_1',
    'field_bitstream_ref' => 'field_bitstream_ref',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'field_identifier_1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_identifier_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier_1']['id'] = 'field_identifier_1';
  $handler->display->display_options['fields']['field_identifier_1']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier_1']['field'] = 'field_identifier';
  /* Field: Content: Bitstream Reference */
  $handler->display->display_options['fields']['field_bitstream_ref']['id'] = 'field_bitstream_ref';
  $handler->display->display_options['fields']['field_bitstream_ref']['table'] = 'field_data_field_bitstream_ref';
  $handler->display->display_options['fields']['field_bitstream_ref']['field'] = 'field_bitstream_ref';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Identifier (field_identifier) */
  $handler->display->display_options['sorts']['field_identifier_value']['id'] = 'field_identifier_value';
  $handler->display->display_options['sorts']['field_identifier_value']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['sorts']['field_identifier_value']['field'] = 'field_identifier_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_clip' => 'dlts_clip',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'clip';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'clip';
  $export['clips'] = $view;

  $view = new view();
  $view->name = 'collections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Collections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Collections';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['label'] = 'UUID';
  $handler->display->display_options['fields']['field_identifier']['exclude'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['text'] = '<a href="[path]" title="[field_identifier]">[field_name-value]</a>';
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_partner']['id'] = 'field_partner';
  $handler->display->display_options['fields']['field_partner']['table'] = 'field_data_field_partner';
  $handler->display->display_options['fields']['field_partner']['field'] = 'field_partner';
  $handler->display->display_options['fields']['field_partner']['label'] = 'Partner';
  $handler->display->display_options['fields']['field_partner']['delta_offset'] = '0';
  /* Field: Content: Code */
  $handler->display->display_options['fields']['field_code']['id'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['table'] = 'field_data_field_code';
  $handler->display->display_options['fields']['field_code']['field'] = 'field_code';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_collection' => 'dlts_collection',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'collections';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['collections'] = $view;

  $view = new view();
  $view->name = 'creative_works';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Creative Works';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Creative Works';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_mediaobject' => 'field_mediaobject',
    'field_partner' => 'field_partner',
    'field_collection' => 'field_collection',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'status';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mediaobject' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_partner' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_collection' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Media Object */
  $handler->display->display_options['fields']['field_mediaobject']['id'] = 'field_mediaobject';
  $handler->display->display_options['fields']['field_mediaobject']['table'] = 'field_data_field_mediaobject';
  $handler->display->display_options['fields']['field_mediaobject']['field'] = 'field_mediaobject';
  $handler->display->display_options['fields']['field_mediaobject']['label'] = 'Media';
  $handler->display->display_options['fields']['field_mediaobject']['delta_offset'] = '0';
  /* Field: Content: Collection */
  $handler->display->display_options['fields']['field_collection']['id'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['table'] = 'field_data_field_collection';
  $handler->display->display_options['fields']['field_collection']['field'] = 'field_collection';
  $handler->display->display_options['fields']['field_collection']['delta_offset'] = '0';
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_partner']['id'] = 'field_partner';
  $handler->display->display_options['fields']['field_partner']['table'] = 'field_data_field_partner';
  $handler->display->display_options['fields']['field_partner']['field'] = 'field_partner';
  $handler->display->display_options['fields']['field_partner']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Collection (field_collection) */
  $handler->display->display_options['sorts']['field_collection_nid']['id'] = 'field_collection_nid';
  $handler->display->display_options['sorts']['field_collection_nid']['table'] = 'field_data_field_collection';
  $handler->display->display_options['sorts']['field_collection_nid']['field'] = 'field_collection_nid';
  $handler->display->display_options['sorts']['field_collection_nid']['expose']['label'] = 'Collection (field_collection)';
  /* Contextual filter: Content: Collection (field_collection) */
  $handler->display->display_options['arguments']['field_collection_nid']['id'] = 'field_collection_nid';
  $handler->display->display_options['arguments']['field_collection_nid']['table'] = 'field_data_field_collection';
  $handler->display->display_options['arguments']['field_collection_nid']['field'] = 'field_collection_nid';
  $handler->display->display_options['arguments']['field_collection_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_collection_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_collection_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_collection_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_creativework' => 'dlts_creativework',
  );
  /* Filter criterion: Content: Collection (field_collection) */
  $handler->display->display_options['filters']['field_collection_nid']['id'] = 'field_collection_nid';
  $handler->display->display_options['filters']['field_collection_nid']['table'] = 'field_data_field_collection';
  $handler->display->display_options['filters']['field_collection_nid']['field'] = 'field_collection_nid';
  $handler->display->display_options['filters']['field_collection_nid']['value'] = array(
    'all' => 'all',
    11 => '11',
    12 => '12',
    3 => '3',
    14 => '14',
  );
  $handler->display->display_options['filters']['field_collection_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_collection_nid']['expose']['operator_id'] = 'field_collection_nid_op';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['label'] = 'Collection';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['operator'] = 'field_collection_nid_op';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['identifier'] = 'field_collection_nid';
  $handler->display->display_options['filters']['field_collection_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_collection_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_collection_nid']['group_info']['label'] = 'Collection (field_collection)';
  $handler->display->display_options['filters']['field_collection_nid']['group_info']['identifier'] = 'field_collection_nid';
  $handler->display->display_options['filters']['field_collection_nid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_collection_nid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'creative-work';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['creative_works'] = $view;

  $view = new view();
  $view->name = 'partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partners';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Identifier */
  $handler->display->display_options['fields']['field_identifier']['id'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['table'] = 'field_data_field_identifier';
  $handler->display->display_options['fields']['field_identifier']['field'] = 'field_identifier';
  $handler->display->display_options['fields']['field_identifier']['label'] = 'UUID';
  $handler->display->display_options['fields']['field_identifier']['exclude'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['text'] = '<a href="[path]" title="[field_identifier]">[field_name-value]</a>';
  /* Field: Content: Code */
  $handler->display->display_options['fields']['field_code']['id'] = 'field_code';
  $handler->display->display_options['fields']['field_code']['table'] = 'field_data_field_code';
  $handler->display->display_options['fields']['field_code']['field'] = 'field_code';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_partner' => 'dlts_partner',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'partners';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['partners'] = $view;

  $view = new view();
  $view->name = 'playlists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Playlists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Playlists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Clip */
  $handler->display->display_options['fields']['field_clip_ref']['id'] = 'field_clip_ref';
  $handler->display->display_options['fields']['field_clip_ref']['table'] = 'field_data_field_clip_ref';
  $handler->display->display_options['fields']['field_clip_ref']['field'] = 'field_clip_ref';
  $handler->display->display_options['fields']['field_clip_ref']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dlts_playlist' => 'dlts_playlist',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'playlists';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['playlists'] = $view;

  return $export;
}
