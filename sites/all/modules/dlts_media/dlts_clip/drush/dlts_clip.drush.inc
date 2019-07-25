<?php

define('STREAM_SERVER', 'https://stream.dlib.nyu.edu');

/**
 * @file
 * DLTS Clip
 */
/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * @see drush_parse_command()
 *   for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function dlts_clip_drush_command() {
  $items = array();
  $items['import-bitstream'] = array(
    'callback' => 'dlts_clip_import_bitstream',
    'description' => dt('Import bitstream from a JSON document.'),
    'options' => array(
      'source' => dt('JSON document filepath.'),
    ),
  );

  $items['update-bitstream-stream-server'] = array(
    'callback' => 'dlts_clip_update_bitstream_stream_server',
    'description' => dt('Update Media site to access videos over https. See JIRA DLPAS-227'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section(prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function dlts_clip_drush_help($section) {
  switch ($section) {
    case 'drush:import-bitstream':
      return dt("Some day someone will document this module");
      break;
  }
}

function dlts_clip_update_bitstream_stream_server_init() {
  include_once(__DIR__ . '/includes/datasource.inc');
  include_once(__DIR__ . '/includes/schema.inc');
  $list_schemas = dlts_clip_list_schemas();
  // in array because we only want this schema
  // and dlts_clip_initialize_schema expect a
  // list of schemas
  $schemas = array(
    'bitstream_node_map' => $list_schemas['bitstream_node_map'],
  );
  dlts_clip_initialize_schema('dlts_clip', $schemas);
  foreach ($schemas as $name => $schema) {
    if (!db_table_exists($name)) {
      db_create_table($name, $schema);
      foreach (bitstream_nids() as $bitstream) {
        db_insert('bitstream_node_map')->fields(array(
          'nid' => $bitstream,
          'processed' => 0,
        ))->execute();
      }
    }
  }
}

function dlts_clip_update_bitstream_stream_server() {
  // make sure we have a list of all nodes that we need to update
  if (!db_table_exists('bitstream_node_map')) {
    dlts_clip_update_bitstream_stream_server_init();
  }
  else {
    include_once(__DIR__ . '/includes/datasource.inc');
    while ($results = dlts_clip_DLPAS227()) {
      foreach ($results as $result) {
        $entity = node_load($result->nid);
        $wrapper = entity_metadata_wrapper('node', $entity);
        $field = $wrapper->field_bitstream->value();
        if (isset($field)) {
          if (!empty($field['f4m'])) {
            $f4m = parse_url($field['f4m']);
            $field['f4m'] = STREAM_SERVER . $f4m['path'];
            unset($f4m);
          }
          if (!empty($field['m3u'])) {
            $m3u = parse_url($field['m3u']);
            $field['m3u'] = STREAM_SERVER . $m3u['path'];
            unset($m3u);
          }
        }
        $wrapper->field_bitstream->set($field);
        try {
          $wrapper->save();
          db_merge('bitstream_node_map')->key(array('nid' => $result->nid))->fields(array('processed' => 1))->execute();
        }
        catch (Exception $e) {
          drush_log('Caught exception: ' . $e->getMessage(), 'error');
        }
        unset($entity);
        unset($wrapper);
        unset($field);
      }
    }
  }
}

function dlts_clip_import_bitstream($source = FALSE) {

  include_once(__DIR__ . '/includes/common.inc');

  include_once(__DIR__ . '/includes/datasource.inc');

  include_once(__DIR__ . '/includes/create.inc');

  $json = ($source) ? $source : drush_get_option('source', NULL);

  if (!$json) dlts_clip_exit('No source to import', 'error');

  $files = (is_dir($json)) ? file_scan_directory($source, '/(.*)\.json$/', array('recurse' => FALSE)) : array((object) array('uri' => $json));

  create_bitstream_from_json($files);

}

function dlts_clip_exit($message = NULL, $status) {
  drush_log($message, $status);
  die();
}
