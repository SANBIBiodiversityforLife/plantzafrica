<?php
/**
 * @file
 * home_page_content.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function home_page_content_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'News & Updates home page';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_page_news';
  $fe_block_boxes->body = '<div class="updates-news"><h4>Orchids in southern Africa</h4><p>We are pleased to anounce that we have a new plant series adedd to our information library. <a class="readmore-btn" href="#">Read More</a></p></div><div class="updates-news"><h4>New search terms added to our search</h4><p>We are pleased to anounce that we have added more searching terms to our search tool box <a class="readmore-btn" href="#">Read More</a></p></div>';

  $export['home_page_news'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Search tool call-to-action';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_page_search_cta';
  $fe_block_boxes->body = '<div class="search-info"><div class="img-figure"><a href="/plants/search/advanced"><img alt="" src="/sites/all/themes/greenbox/images/Instruction-img.jpg" /></a></div><p>Try the <a href="/plants/search/advanced">Advanced Search</a> to refine your Plants of the Week search and find plants suited to your garden or for a specific purpose.</p></div><p>&nbsp;</p>';

  $export['home_page_search_cta'] = $fe_block_boxes;

  return $export;
}
