<?php

/*
 * Book getters. If you need any of this functionalities load with module_load_include
 * e.g., module_load_include('inc', 'dlts_utilities', 'inc/dlts_utilities.book');
 */

/** Returns book identifier */
function dlts_utilities_book_get_identifier($node) {
  $field = dlts_utilities_field_get_first_item('node', $node, 'field_identifier');
  
  if (isset($field['safe_value']) && !empty($field['safe_value'])) {
    return $field['safe_value'];
  }
  else {
    return FALSE;
  }
}

function dlts_utilities_book_get_multivol_book($node) {

  $query = new EntityFieldQuery;
  
  $result_multivol_identifier = $query
                  ->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', 'dlts_multivol_book')
                  ->fieldCondition('field_book', 'nid', array($node->nid))
                  ->execute();
  
  if (!empty($result_multivol_identifier['node'])) {

    $keys = array_keys($result_multivol_identifier['node']);

    return node_load(array_pop($keys));

  }
  
  else {
  	return FALSE;
  }

}

/**
 * Returns book is part of collection
 */
function dlts_utilities_book_get_collection_identifier($node) {
  
  $field = dlts_utilities_field_get_first_item('node', $node, 'field_collection');
  
  if (isset($field['nid'])) {
    
    // Load the node by NID

    $entity = node_load($field['nid']);
    
    // Wrap it with Entity API
    $ewrapper = entity_metadata_wrapper('node', $entity);
    
    return $ewrapper->field_identifier->value();
    
  }

}

/**
 * Returns book page sequence number
 */
function dlts_utilities_book_get_sequence_count($node) {
  $field = dlts_utilities_field_get_first_item('node', $node, 'field_sequence_count');
  return $field['value'];
}

/**
 * Returns book volume field
 */
function dlts_utilities_book_get_volume($node) {
	$field = dlts_utilities_field_get_first_item('node', $node, 'field_volume');
	return $field['value'];
}

/**
 * Returns book number field
 */
function dlts_utilities_book_get_number($node) {
	$field = dlts_utilities_field_get_first_item('node', $node, 'field_number');
	return $field['value'];
}

/**
 * Returns book pub date
 */
function dlts_utilities_book_get_publication_date($node) {
	$field = dlts_utilities_field_get_first_item('node', $node, 'field_publication_date');
	return $field['value'];
}

function dlts_utilities_book_get_description($node) {
  $field = dlts_utilities_field_get_first_item('node', $node, 'field_description');
  
  if (isset($field['safe_value']) && !empty($field['safe_value'])) {
    return $field['safe_value'];
  }
  else {
    return FALSE;
  }
}

function dlts_utilities_book_get_title($node) {
  $field = dlts_utilities_field_get_first_item('node', $node, 'field_title');
  
  if (isset($field['safe_value']) && !empty($field['safe_value'])) {
    return $field['safe_value'];
  }
  else {
    return t('Untitled');
  }
}

/*
 * 0 | Left to right
 * 1 | Right to left
 */

function dlts_utilities_book_get_read_order($node) {
  $field = dlts_utilities_field_get_first_item('node', $node, 'field_read_order');
  
  return (isset($field['value']) && !empty($field['value'])) ? $field['value'] : 0;
  
}

/**
 * Returns book representative image
 */
function dlts_utilities_book_get_representative_image($node, $image_style = 'medium') {

	$field = dlts_utilities_field_get_first_item('node', $node, 'field_representative_image');
	
	// book does not have a representative image; assume sequence number 1 is "visible" and have a service copy image
    if (!$field) {

      $query = new EntityFieldQuery;

      $result = $query
                  ->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', 'dlts_book_page')
                  ->propertyCondition('status', 1)
                  ->fieldCondition('field_is_part_of', 'value', dlts_utilities_book_get_identifier($node), '=')
				  ->fieldCondition('field_visible', 'value', TRUE, '=')
				  ->fieldCondition('field_sequence_number', 'value', 1, '=')
                  ->execute();

      if (!empty($result['node'])) {
        $keys = array_keys($result['node']);

        $page_node = node_load(
          array_pop($keys)
	    );
		
		$field = dlts_utilities_field_get_first_item('node', $page_node, 'field_service_copy');

      } 
      else {
        return FALSE;
      }

    }
	
    $field['path'] = image_style_path($image_style, $field['uri']);
		
	$field['style_name'] = $image_style;
		
	return theme('image_style', $field);

}

/**
 * Returns book representative image
 */
function dlts_utilities_book_get_representative_image_uri($entity, $image_style = 'medium') {

    // Wrap it with Entity API
    $ewrapper = entity_metadata_wrapper('node', $entity);
    
    $field = $ewrapper->field_representative_image->value();
    
    if (!$field) {

      $query = new EntityFieldQuery;

      $result = $query
                  ->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', 'dlts_book_page')
                  ->propertyCondition('status', 1)
                  ->fieldCondition('field_is_part_of', 'value', dlts_utilities_book_get_identifier($node), '=')
				  ->fieldCondition('field_visible', 'value', TRUE, '=')
				  ->fieldCondition('field_sequence_number', 'value', 1, '=')
                  ->execute();

      if (!empty($result['node'])) {
        $keys = array_keys($result['node']);

        $page_node = node_load(
          array_pop($keys)
	    );
		
		$field = dlts_utilities_field_get_first_item('node', $page_node, 'field_service_copy');

      } 
      else {
        return FALSE;
      }

    }
	
    $field['path'] = image_style_path($image_style, $field['uri']);
		
	$field['style_name'] = $image_style;

    // Drupal is not generating the images
	//print_r(file_create_url($field['path']));
		
	return file_create_url($field['uri']);

}



/**
 * Returns book first page
 */
function dlts_utilities_book_get_first_page($node) {
      	
  $query = new EntityFieldQuery;
	  
  $result = $query
              ->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'dlts_book_page')
              ->propertyCondition('status', 1)
              ->fieldCondition('field_is_part_of', 'value', dlts_utilities_book_get_identifier($node), '=')
			  ->fieldCondition('field_visible', 'value', TRUE, '=')
			  ->fieldCondition('field_sequence_number', 'value', 1, '=')
              ->execute();

  if (!empty($result['node'])) {
    $keys = array_keys($result['node']);

    $page_node = node_load( array_pop($keys) );
		
    return url('node/'. $page_node->nid);
  } 
  else {
    return FALSE;
  }

  return $field['value'];
}
