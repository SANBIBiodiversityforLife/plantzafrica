<?php
/**
 * @file
 * search_api_solr_server_and_indexes.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function search_api_solr_server_and_indexes_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['pa_advanced_search-pa_active_search_filters'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'pa_active_search_filters',
    'module' => 'pa_advanced_search',
    'node_types' => array(),
    'pages' => 'plants/search/advanced',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => -29,
      ),
      'tmp' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'tmp',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['pa_advanced_search-pa_advanced_search_form_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'pa_advanced_search_form_block',
    'module' => 'pa_advanced_search',
    'node_types' => array(),
    'pages' => 'plants/search/advanced',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'highlighted',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => -19,
      ),
      'tmp' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'tmp',
        'weight' => -24,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
