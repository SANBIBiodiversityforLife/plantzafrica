<?php
/**
 * @file
 * views_information_library.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function views_information_library_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Information Library Landing Block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'info_library_landing_block';
  $fe_block_boxes->body = 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis justo risus, malesuada ac egestas ut, aliquam id quam. Nulla pulvinar est diam, quis posuere enim porta quis. Aenean tincidunt tristique orci. Aenean in tellus sit amet tortor iaculis gravida. Sed aliquet elit a velit iaculis efficitur. Etiam dictum vel turpis et cursus. Integer sit amet mollis enim. Quisque sed ante ut ante fermentum viverra. Vestibulum consequat ac eros rutrum luctus. Vestibulum vehicula enim libero, iaculis vehicula sapien pretium at.';

  $export['info_library_landing_block'] = $fe_block_boxes;

  return $export;
}
