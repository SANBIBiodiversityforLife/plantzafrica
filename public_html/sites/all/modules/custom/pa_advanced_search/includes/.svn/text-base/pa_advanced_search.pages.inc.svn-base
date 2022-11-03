<?php
/**
 * @file pa_advanced_search.pages.inc
 * Page callback function for displaying our advanced search pages
 */

//include our form builder functions here so that they not loaded on every page load but only during routing.
//module_load_include('inc', 'pa_advanced_search', '/includes/pa_advanced_search.forms');

/*
 * Page callback function to display our Advanced POW Search page.
 */
function pa_advanced_search_page(){

  //include out autocomplete JS scripts
  drupal_add_js(drupal_get_path('module', 'pa_advanced_search') . '/scripts/pa_advanced_search.js');

  $page = array();

  //declare default theme function variables
  $results['plants'] = FALSE;
  $pager = FALSE;

  //get our parameters from GET variable
  $params = drupal_get_query_parameters();

  //check if advanced landing page (form only)
  $form_only = (empty($params) && arg(2) != 'list')? TRUE : FALSE;

  if(!$form_only){

    $tab_urls = pa_advanced_search_tab_urls($params);

    //get out date sort links
    $sort['date'] = pa_advanced_search_sort_links($params, $type = 'date');

    //build our sort links for date sort (ASC OR DESC)
    $sort['title'] = pa_advanced_search_sort_links($params, $type = 'title');

    //build our glossary nav links
    $glossary_nav = pa_advanced_search_build_glossary_nav($params);

    //execute search query
    $results = pa_advanced_search_execute($params);

    //grab some result stats to display
    $stats['viewing'] = ($results['count'] < 20)? $results['count'] : 20;
    $stats['total'] = $results['count'];
    $stats['page'] = (!isset($_GET['page']))? 1 : $_GET['page'];

    //pager logic using count values returned from SOLR in submit handler
    $current = pager_default_initialize($results['count'], 20);
    $pager = theme('pager', array('parameters' => $params, 'quantity' => count($results['plants'])));

    //theme the results using our custom template
    $page = array(
      '#date_form' => drupal_get_form('pa_advanced_search_date_range_form'),
      '#tab_url' => $tab_urls,
      '#sort' => $sort,
      '#glossary_nav' => $glossary_nav,
      '#results' => $results['plants'],
      '#stats' => $stats,
      '#pager' => $pager,
      '#theme' => 'pa_advanced_search_listings'
    );

  }

  return $page;
}