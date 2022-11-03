<?php
/*
 * @file pa_user_workflow.blocks.inc
 * Contains all block hooks and definitions for our user registration / login workflow
 */

/**
 * Implements hook_block_info().
 */
function pa_user_workflow_block_info(){

  $blocks['pa_workflow_links'] = array(
    'info' => t('Plants Africa login / register links'),
    'cache' => DRUPAL_NO_CACHE,
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function pa_user_workflow_block_view($delta = '') {

  switch ($delta) {
    case 'pa_workflow_links':
      $block['subject'] = '<none>';
      $block['content'] = pa_user_workflow_block_links($logged_in = user_is_logged_in());
      break;
  }
  return $block;
}

/**
 * Block content callback function.
 */
function pa_user_workflow_block_links($logged_in){

  if(!$logged_in){
    $links = '<a href="#" class="login">Login</a> | <a href="#" class="register">Register</a>';
  }else{
    $links = '<a href="/pzauser/logout" class="logout">Logout</a>'; /* RR note new path */
  }

  return array(
    '#prefix' => '<div class="link-text">',
    '#markup' => $links,
    '#suffix' => '</div>',
 );
}