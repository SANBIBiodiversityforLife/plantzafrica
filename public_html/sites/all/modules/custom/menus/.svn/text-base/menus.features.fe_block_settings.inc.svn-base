<?php
/**
 * @file
 * menus.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function menus_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-vegetation-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-vegetation-menu',
    'module' => 'menu',
    'node_types' => array(
      0 => 'page',
      1 => 'vegetation',
    ),
    'pages' => 'vegetation/*
vegetation',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'greenbox',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'greenbox' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'greenbox',
        'weight' => -6,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
