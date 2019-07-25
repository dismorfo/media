<?php

function dlts_clip_initialize_schema($module, &$schema) {
  // Set the name and module key for all tables.
  foreach ($schema as $name => $table) {
    if (empty($table['module'])) {
      $schema[$name]['module'] = $module;
    }
    if (!isset($table['name'])) {
      $schema[$name]['name'] = $name;
    }
  }
}

function dlts_clip_list_schemas() {
  $schema = array();
  $schema['bitstream_node_map'] = array(
    'description' => 'Stores a record of Bitstreams.',
    'fields' => array(
      'nid' => array(
        'description' => 'The primary identifier for the node.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
      ),
      'processed' => array(
        'description' => 'Process information',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
      ),
    ),
    'indexes' => array(
      'nid' => array('nid'),
    ),
    'primary key' => array('nid'),
  );
  return $schema;
}
