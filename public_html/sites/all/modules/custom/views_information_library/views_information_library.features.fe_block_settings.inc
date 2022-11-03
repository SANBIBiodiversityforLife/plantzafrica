<?php
/**
 * @file
 * views_information_library.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function views_information_library_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-info_library_landing_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'info_library_landing_block',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'information-library',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => 0,
      ),
      'tmp' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tmp',
        'weight' => 0,
      ),
    ),
    'title' => 'Information Library',
    'visibility' => 1,
  );

  $export['current_search-info_lib_current_search'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'info_lib_current_search',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => -29,
      ),
      'tmp' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tmp',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-a5dad4a547bae092a090950d55156d5c'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'a5dad4a547bae092a090950d55156d5c',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'information-library
information-library/*',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => -29,
      ),
      'tmp' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'tmp',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
