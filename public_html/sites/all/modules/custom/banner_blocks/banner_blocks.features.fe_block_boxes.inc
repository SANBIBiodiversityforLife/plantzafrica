<?php
/**
 * @file
 * banner_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function banner_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Banner Description - About';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'banner_description_about';
  $fe_block_boxes->body = '<p>The South African National Biodiversity Institute is responsible for exploring, revealing, <br>celebrating and championing biodiversity for the benefit and enjoyment of all South Africans.</p>';

  $export['banner_description_about'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Banner Description - Contact Us';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'banner_description_contact_us';
  $fe_block_boxes->body = '<p>Please dont hesitate to get in touch with us</p>';

  $export['banner_description_contact_us'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Banner Description - Information Library';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'banner_description_info_library';
  $fe_block_boxes->body = '<p>Our collection of all documents and articles about South African plants</p>';

  $export['banner_description_info_library'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Banner Description - Vegetation of SA';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'banner_description_vegetation';
  $fe_block_boxes->body = '<p>The South African National Biodiversity Institute is responsible for exploring, revealing, celebrating and championing biodiversity for the benefit and enjoyment of all South Africans.</p>';

  $export['banner_description_vegetation'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Banner Description - Welcome';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'banner_description_welcome';
  $fe_block_boxes->body = '<p>The South African National Biodiversity Institute is responsible for exploring, revealing, celebrating and championing biodiversity for the benefit and enjoyment of all South Africans. Read More</p>';

  $export['banner_description_welcome'] = $fe_block_boxes;

  return $export;
}
