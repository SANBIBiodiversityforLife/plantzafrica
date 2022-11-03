<?php
/**
 * @file pa_advanced_search.blocks.inc
 * Provides all our block definitions for our serach form
 */

/**
 * Implements hook_block_info().
 */
function pa_forms_block_info(){

  $blocks['pa_forms_general_search'] = array(
    'info' => t('General search form'),
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function pa_forms_block_view($delta = '') {

  switch ($delta) {
    case 'pa_forms_general_search':
      $block['subject'] = '<none>';
      $block['content'] = pa_forms_get_general_search_form();
      break;
  }
  return $block;
}

/**
 * Content callback for the block.
 */
function pa_forms_get_general_search_form(){
  $view = views_get_view('general_search');
  $view->set_display('page');
  $view->init_handlers();
  $exposed_form = $view->display_handler->get_plugin('exposed_form');
  $content = $exposed_form->render_exposed_form(true);
  return $content;
}