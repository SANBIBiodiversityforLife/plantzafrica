<?php
/*
 * @file pa_user_workflow.pages.inc
 * Contains all page callback functions for registeration or login procedure
 */

/**
 * Callback function which verifies our user and redirects to confirmation page.
 */
function pa_user_workflow_verify_account($user_id, $timestamp, $hash){

  //loop through roles to ensure we have correct IDs (staging -> live bug)
  $roles = user_roles();
  $public = array_search('public user', $roles);
  $processing = array_search('processing', $roles);

  //load user account and adjust status and roles
  $account = user_load($user_id);
  $account->status = 1;
  $account->roles[$public] = 'public user'; //add user role public user
  unset($account->roles[$processing]); //remove processing role

  $account = user_save($account);

  drupal_goto('home', array('query' => array('login' => 1)));
}