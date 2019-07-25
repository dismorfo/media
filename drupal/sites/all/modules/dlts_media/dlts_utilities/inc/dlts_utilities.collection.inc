<?php

/*
 * collection getters. If you need any of this functionalities load with module_load_include
 * e.g., module_load_include('inc', 'dlts_utilities', 'inc/dlts_utilities.collection');
 */

/** Returns book identifier */
function dlts_utilities_collection_get_identifier($node) {

  $ewrapper = entity_metadata_wrapper('node', $node);
  
  return $ewrapper->field_identifier->value();
  
}