<?php

/**
 * @file
 * Drush
 */
function create_clip($node) {
  global $user;
  $exists = exists_nid($node->identifier);
  if (!$exists) {
    // entity_create replaces the procedural steps in the first example of
    // creating a new object $node and setting its 'type' and uid property
    $values = array(
      'type' => 'dlts_clip',
      'uid' => $user->uid,
      'status' => 1,
      'comment' => 0,
      'promote' => 0,
      'language' => LANGUAGE_NONE, // make sure we only translate the book object
   );
    $entity = entity_create('node', $values);
  }
  else {
    $entity = node_load($exists);
  }
  $entity->exists = $exists;
  // The entity is now created, but we have not yet simplified use of it.
  // Now create an entity_metadata_wrapper around the new node entity
  // to make getting and setting values easier
  $ewrapper = entity_metadata_wrapper('node', $entity);
  // Using the wrapper, we do not have to worry about telling Drupal
  // what language we are using. The Entity API handles that for us.
  if (!empty($node->title)) {
  	// find the max for this field and trunk it
  	$ewrapper->title->set($node->title);
  }
  else {
  	$ewrapper->title->set('Untitled');
  }

  // Identifier 
  if (isset($node->identifier)) {
    $ewrapper->field_identifier->set($node->identifier);
  }
  else return;
  
  // Bitstream Reference
  if (isset($node->bitstreamref)) {
    $ewrapper->field_bitstream_ref->set($node->bitstreamref);
  }

  // Play Start
  if (isset($node->start)) {
    $ewrapper->field_start->set($node->start);
  }

  // Play Duration
  if (isset($node->duration)) {
    $ewrapper->field_duration->set($node->duration);
  }

  // Thumbnail
  if (isset($node->thumbnail)) {
    $ewrapper->field_thumbnail->set($node->thumbnail);
  }

  // Permanent Link
  if (isset($node->handle)) {
    $ewrapper->field_handle->set($node->handle);
  }

  // Collection
  if (isset($node->collection)) {
    $ewrapper->field_collection->set($node->collection);
  }

  // Access Control
  if (isset($node->accesscontrol)) {
    $ewrapper->field_access_control->set($node->accesscontrol);
  }  

  $ewrapper->save();

  return $entity;
}
