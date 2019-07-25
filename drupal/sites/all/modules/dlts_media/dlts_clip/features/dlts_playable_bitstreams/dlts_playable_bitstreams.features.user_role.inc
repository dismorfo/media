<?php
/**
 * @file
 * dlts_playable_bitstreams.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dlts_playable_bitstreams_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
