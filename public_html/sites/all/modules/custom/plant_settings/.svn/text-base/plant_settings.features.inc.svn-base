<?php
/**
 * @file
 * plant_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function plant_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function plant_settings_node_info() {
  $items = array(
    'plant' => array(
      'name' => t('Plant'),
      'base' => 'node_content',
      'description' => t('Plant'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
