<?php
/**
 * @file
 * general_search.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function general_search_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Banner Description - General site search results';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'banner_general_search';
  $fe_block_boxes->body = '<p>Please use the Information library search or the Plant of the Week search<br />if you want to refine your search.</p>';

  $export['banner_general_search'] = $fe_block_boxes;

  return $export;
}
