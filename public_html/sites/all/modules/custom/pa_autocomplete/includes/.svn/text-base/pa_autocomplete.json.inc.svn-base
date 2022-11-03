<?php
/**
 * @file pa_autocomplete.json.inc
 * Contains all our AJAX callbacks returning JSON to our autocomplete enabled inputs.
 */

/**
 * Returns JSON autocomplete data for Plant searches.
 */
function pa_autocomplete_get_plants(){

  //get user autocomplete input
  $term = $_GET['term'];

  //load Search API index and instantiate query object
  //$index = search_api_index_load('plants'); /* RR changed to below */
  $index = search_api_index_load('plant_names');
  $query = new SearchApiQuery($index);

  //set our query options
  $query->setOption('search id', 'pa:search:plants:autocomplete');
  $query->setOption('skip result count', FALSE);
  $query->setOption('limit', '7');
  $query->setOption('offset', 0);

  //define our search filters
  $filter = $query->createFilter('OR');
  //$filter->condition('field_common_names', $term, '='); /* RR removed */
  //$filter->condition('field_short_scientific_name', $term, '='); /* RR removed */
  $filter->condition('field_genus:name', $term, '='); /* RR added */
  $query->filter($filter);

  //Node type is "Plant" and published sanity check
  $filter = $query->createFilter('AND');
  $filter->condition('type', 'plant');
  $filter->condition('status', 1);

  //sort by SOLR relevance
  $query->sort('search_api_relevance', 'DESC');

  //execute query
  $data = $query->execute();
  $ids = $data['results'];
  $ids = array_keys($ids);

  //load plant entities
  $plants = entity_load('node', $ids);

  //loop through plants and define search result strings
  $results = array();
  foreach($plants as $nid => $p){
    $results[$nid] = $p->field_short_scientific_name[LANGUAGE_NONE][0]['value'];
    $results[$nid] = substr($results[$nid], 0, 128);
  }

  return drupal_json_output($results);
  drupal_exit();
}

/**
 * Returns JSON autocomplete data for General searches.
 */
function pa_autocomplete_get_general(){

  //get user autocomplete input
  $term = $_GET['term'];

  //load Search API index and instantiate query object
  $index = search_api_index_load('general_search');
  $query = new SearchApiQuery($index);

  //set our query options
  $query->setOption('search id', 'pa:search:general:autocomplete');
  $query->setOption('skip result count', FALSE);
  $query->setOption('limit', '5');
  $query->setOption('offset', 0);

  //define our search filters
  $filter = $query->createFilter('OR');
  $filter->condition('title', $term, '=');
  $filter->condition('field_common_names', $term, '=');
  $filter->condition('field_short_scientific_name', $term, '=');
  $filter->condition('body:value', $term, '=');
  $filter->condition('field_description:value', $term, '=');
  $filter->condition('field_ecology:value', $term, '=');
  $filter->condition('field_family:name', $term, '=');
  $filter->condition('field_history:value', $term, '=');
  $filter->condition('field_long_scientific_name:value', $term, '=');
  $filter->condition('field_use:value', $term, '=');
  $query->filter($filter);

  //Node type is "Plant" and published sanity check
  $filter = $query->createFilter('AND');
  $filter->condition('status', 1);

  //sort by SOLR relevance
  $query->sort('search_api_relevance', 'DESC');

  //execute query
  $data = $query->execute();

  $ids = $data['results'];
  $ids = array_keys($ids);

  //load plant entities
  $plants = entity_load('node', $ids);

  //loop through plants and define search result strings
  $results = array();
  foreach($plants as $nid => $p){
    $results[$nid] = $p->title;
  }

  return drupal_json_output($results);
  drupal_exit();
}