<?php
/*
 * @file pa_user_workflow.json.inc
 * Provides all the JSON / AJAX callback functions for login / registration forms
 */

/**
 * Callback function to login via AJAX.
 */
function pa_user_workflow_login(){
  $data = $_POST;

  //initialize JSON reponse array
  $response = array('success' => FALSE, 'message' => NULL);

  //get username and password values from form POST array
  $username = trim($data['name']);
  $pass = $data['pass'];

  //attempt login procedure
  if(user_authenticate($username, $pass)){

    $user_obj = user_load_by_name($username);
    $form_state = array();
    $form_state['uid'] = $user_obj->uid;

    user_login_submit(array(), $form_state);

    //update json status array
    $response['success'] = TRUE;
  }

  //return our JSON response back to the frontend
  return drupal_json_output($response);
  drupal_exit();
}

/**
 * Callback function to register via AJAX.
 */
function pa_user_workflow_register(){
  $data = $_POST;

  //initialize JSON reponse array
  $response = array('success' => FALSE, 'message' => NULL);

  //loop through roles to ensure we have correct IDs (staging -> live bug)
  $roles = user_roles();
  $pKey = array_search('processing', $roles);

  //split name
  $names = explode(' ', $data['name'], 2);

  //set up the user fields in array format for user_save()
  $details = array(
    'name' => trim($data['email']),
    'mail' => trim($data['email']),
    'pass' => $data['pass1'],
    'status' => 0,
    'init' => 'email address',
    'roles' => array(
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
      $pKey => 'processing',
    ),
    'field_first_name' => array(
      LANGUAGE_NONE => array(
        0 => array('value' => $names[0])
      )
    ),
    'field_last_name' => array(
      LANGUAGE_NONE => array(
        0 => array('value' => $names[1])
      )
    ),
    'field_country' => array(
      LANGUAGE_NONE => array(
        0 => array('iso2' => $data['country'])
      )
    ),
  );

  //first we need to see if username and email already exists in database to avoid duplicate SQL error
  $uid = db_query("SELECT uid FROM {users} WHERE name = :name limit 1", array(":name" => $data['email']))->fetchField();
  $username = db_query("SELECT name FROM {users} WHERE mail = :mail limit 1", array(":mail" => $data['email']))->fetchField();

  //if no UID or username returned from queries then create user
  if(!is_numeric($uid) && $username == ''){
    //if there was an error creating the user account
    if($account = user_save('', $details)){
      $response['success'] = TRUE;
      //send verfication email containing token
      $mail = pa_user_workflow_mail_send($account, $data['destination']);
    }
  }

  //return our JSON response back to the frontend
  return drupal_json_output($response);
  drupal_exit();
}