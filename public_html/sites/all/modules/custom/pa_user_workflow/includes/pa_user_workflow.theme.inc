<?php
/*
 * @file pa_user_workflow.theme.inc
 * Contains all theme layer hooks and overrides.
 */

/**
 * Implements hook_theme().
 */
function pa_user_workflow_theme($existing, $type, $theme, $path) {
  return array(
    'pa_modal' => array(
      'variables' => array(
        'modal_id' => NULL,
        'class'=> NULL,
        'title' => NULL,
        'content' => NULL,
      ),
      'template' => 'templates/pa_modal_window'
    ),
  );
}

/**
 * Implementation of hook_preprocess_page.
 */
function pa_user_workflow_page_alter(&$page){

  if(!user_is_logged_in()){

    //add our bootstrap modal css and js
    drupal_add_css(drupal_get_path('module', 'pa_user_workflow') . '/css/bootstrap-modal.css');
    drupal_add_js(drupal_get_path('module', 'pa_user_workflow') . '/scripts/bootstrap.min.js', array('weight' => JS_LIBRARY));

    //add our custom JS files
    drupal_add_js(drupal_get_path('module', 'pa_user_workflow') . '/scripts/pa_user_workflow.login.js');
    drupal_add_js(drupal_get_path('module', 'pa_user_workflow') . '/scripts/pa_user_workflow.register.js');

    //login modal render array
    $page['bottom']['modal-login'] = array(
      '#modal_id' => 'pa_login_modal',
      '#class' => 'login-modal',
      '#title' => 'Please login to your account',
      '#content' => drupal_get_form('pa_user_workflow_login_form'),
      '#theme' => 'pa_modal'
    );

    //register modal render array
    $page['bottom']['modal-register'] = array(
      '#modal_id' => 'pa_register_modal',
      '#class' => 'modal-class-here',
      '#title' => 'Please fill in form below to register.',
      '#content' => drupal_get_form('pa_user_workflow_register_form'),
      '#theme' => 'pa_modal'
    );
  }
}