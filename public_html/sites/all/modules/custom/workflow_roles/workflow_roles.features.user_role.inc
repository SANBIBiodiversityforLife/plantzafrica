<?php
/**
 * @file
 * workflow_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function workflow_roles_user_default_roles() {
  $roles = array();

  // Exported role: contributor.
  $roles['contributor'] = array(
    'name' => 'contributor',
    'weight' => 4,
  );

  // Exported role: processing.
  $roles['processing'] = array(
    'name' => 'processing',
    'weight' => 6,
  );

  // Exported role: public user.
  $roles['public user'] = array(
    'name' => 'public user',
    'weight' => 5,
  );

  // Exported role: web admin.
  $roles['web admin'] = array(
    'name' => 'web admin',
    'weight' => 3,
  );

  return $roles;
}
