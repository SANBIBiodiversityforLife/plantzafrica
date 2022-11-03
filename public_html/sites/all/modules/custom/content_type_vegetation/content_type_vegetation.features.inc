<?php
/**
 * @file
 * content_type_vegetation.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function content_type_vegetation_image_default_styles() {
  $styles = array();

  // Exported image style: vegetation_thumbnail.
  $styles['vegetation_thumbnail'] = array(
    'name' => 'vegetation_thumbnail',
    'label' => 'Vegetation Thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 116,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function content_type_vegetation_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'vegetation' => array(
      'name' => t('Vegetation'),
      'base' => 'node_content',
      'description' => t('Vegetation'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
