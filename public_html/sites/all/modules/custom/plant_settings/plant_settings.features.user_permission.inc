<?php
/**
 * @file
 * plant_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function plant_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  return $permissions;
}
