<?php
/**
 * @file
 * plant_voting.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function plant_voting_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  return $permissions;
}
