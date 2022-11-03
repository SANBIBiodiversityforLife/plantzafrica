<?php
/**
 * @file
 * views_information_library.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function views_information_library_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'info_lib_current_search';
  $item->label = 'Info lib search count';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Your search results for \'[facetapi_results:keys]\' (displaying 10 of [facetapi_results:result-count] on page [facetapi_results:page-number])',
        'plural' => 0,
        'text_plural' => 'Search found [facetapi_results:result-count] items',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h2',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '0',
    ),
  );
  $export['info_lib_current_search'] = $item;

  return $export;
}
