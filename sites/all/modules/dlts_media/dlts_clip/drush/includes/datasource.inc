<?php

/**
 * List of all Bitstream nid
 */
function bitstream_nids () {
  $query = new EntityFieldQuery;
  $bundle = 'dlts_bitstream_set';
  $result = $query->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', $bundle)
                  ->execute();
  if (!empty($result['node'])) {
    return array_keys($result['node']);
  }
}

function dlts_clip_DLPAS227 () {
  $query = db_query("SELECT nid FROM {bitstream_node_map} WHERE processed = 0 LIMIT 25");
  if ($query->rowCount() > 0) {
    return $query->fetchAll();
  }
  return false;
}
