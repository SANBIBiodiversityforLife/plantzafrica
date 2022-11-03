<?php
/**
 * @file pa_advanced_search.blocks.inc
 * Provides all our block definitions for our serach form
 */

/**
 * Implements hook_block_info().
 */
function pa_advanced_search_block_info(){

  //Advanced search form block
  $blocks['pa_advanced_search_form_block'] = array(
    'info' => t('Plants Africa advanced search form'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'plants/search/advanced',
  );

  //active search filters for search results.
  $blocks['pa_active_search_filters'] = array(
    'info' => t('Plants Africa active filters'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'plants/search/advanced',
  );

  //basic search block for homepage
  $blocks['pa_pow_basic_search_block'] = array(
    'info' => t('POW basic search block'),
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function pa_advanced_search_block_view($delta = '') {

  switch ($delta) {

    case 'pa_advanced_search_form_block':
      $block['subject'] = '<none>';
      $block['content'] = drupal_get_form('pa_advanced_search_form');
      break;

    case 'pa_active_search_filters':
      $block['subject'] = '<none>';
      $block['content'] = pa_advanced_search_get_active_filters();
      break;

    case 'pa_pow_basic_search_block':
      $block['subject'] = '<none>';
      $block['content'] = drupal_get_form('pa_advanced_search_basic_form');
      break;

  }

  return $block;
}