<?php
/**
 * @file
 * general_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function general_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-banner_general_search'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'banner_general_search',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'search',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'banner',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => -31,
      ),
      'tmp' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tmp',
        'weight' => 0,
      ),
    ),
    'title' => 'General site search results',
    'visibility' => 1,
  );

  $export['current_search-standard'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'standard',
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

  $export['pa_forms-pa_forms_general_search'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'pa_forms_general_search',
    'module' => 'pa_forms',
    'node_types' => array(),
    'pages' => 'search',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'banner',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => -30,
      ),
      'tmp' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tmp',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views--exp-general_search-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-general_search-page',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => 0,
      ),
      'tmp' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'tmp',
        'weight' => -25,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
