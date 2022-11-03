<?php
/**
 * @file
 * views_plant_of_the_week_searches.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function views_plant_of_the_week_searches_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function views_plant_of_the_week_searches_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
