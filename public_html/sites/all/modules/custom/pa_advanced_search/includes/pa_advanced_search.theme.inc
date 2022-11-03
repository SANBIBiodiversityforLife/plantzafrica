<?php
/**
 * @file: pa_advanced_search.theme.inc
 * theme declarations for PA advanced search
 */

/**
 * Implements hook_theme().
 */
function pa_advanced_search_theme($existing, $type, $theme, $path) {
  return array(
    'pa_advanced_search_listings' => array(
      'variables' => array(
        'date_form' => array(),
        'tab_url' => array(),
        'sort' => array(),
        'glossary_nav' => array(),
        'stats' => array(),
        'results' => array(),
        'pager' => array(),
      ),
      'template' => 'templates/pa-advanced-search--listings'
    ),
    'pa_advanced_search_form' => array(
      'render element' => 'form',
      'template' => 'templates/pa-advanced-search--form'
    ),
    'pa_search_pager' => array(
      'variables' => array(
        'tags' => array(),
        'element' => 0,
        'parameters' => array(),
        'quantity' => 7,
      ),
    ),
    'pa_pager_first' => array(
      'variables' => array(
        'text' => array(),
        'element' => 0,
        'parameters' => array(),
      ),
    ),
    'pa_pager_link' => array(
      'variables' => array(
        'text' => array(),
        'element' => 0,
        'parameters' => array(),
        'page_new' => array(),
        'attributes' => array(),
      ),
    )
  );
}

/**
 * Alter theme registry to use custom theme function for our pager link bugs
 */
function pa_advanced_search_theme_registry_alter(&$theme_registry) {
  if (isset($theme_registry['pager_link'])) {
    $theme_registry['pager_link']['function'] = 'theme_pa_pager_link';
  }
}

/**
 * Custom pager link theme callback to fix pagiung buig
 */
function theme_pa_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  /*incoming hack to fix "first" and "1" links to go to proper query param*/

  //check that we're on POWAS page
  $powas = (arg(0) == 'plants' && arg(1) == 'search')? TRUE : FALSE;

  //check POWAS state and text
  if($powas && ($text == '« first' || $text == '1')){
    unset($query['page']);
    $attributes['href'] = url('plants/search/' . arg(2), array('query' => $query));
    return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
  }else{
    $attributes['href'] = url($_GET['q'], array('query' => $query));
    return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
  }
}