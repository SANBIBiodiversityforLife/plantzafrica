<?php
/*
 * @file pa_user_workflow.forms.inc
 * Provides all form definitions for our login / registration modals
 */

/**
 * Login form builder.
 */
function pa_user_workflow_login_form($form, &$form_state) {

  //validation attributes
  $form = array(
    '#attributes' => array(
      'data-validate' => 'parsley',
      'novalidate' => 'novalidate'
    )
  );

  //email address
  $form['name'] = array(
    '#type' => 'textfield',
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#size' => 25,
    '#attributes' => array(
      'required' => 'required',
      'data-type' => 'email',
      'data-trigger' => 'change',
      'placeholder' => 'Email address',
      'class' => array('txtfield'),
    ),
  );

  //password
  $form['pass'] = array(
    '#type' => 'password',
    '#maxlength' => 60,
    '#size' => 25,
    '#attributes' => array(
      'required' => 'required',
      'data-trigger' => 'change',
      'placeholder' => 'Password',
      'class' => array('txtfield'),
    ),
  );

  //login button
  $form['login'] = array(
    '#type' => 'submit',
    '#value' => 'Login',
    '#attributes' => array(
      'class' => array('login-btn', 'submit-btn')
    ),
    '#prefix' => '<div class="submit-row">',
  );

  //reset link
  $form['reset'] = array(
    '#markup' => l('Forgotten your password? Click here.', 'user/password'),
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Register form builder.
 */
function pa_user_workflow_register_form($form, &$form_state) {

  //validation attributes
  $form = array(
    '#attributes' => array(
      'data-validate' => 'parsley',
      'novalidate' => 'novalidate'
    )
  );

  //full name
  $form['name'] = array(
    '#type' => 'textfield',
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#size' => 25,
    '#attributes' => array(
      'required' => 'required',
      'data-trigger' => 'change',
      'placeholder' => 'Name',
      'class' => array('txtfield'),
    ),
  );

  //email address
  $form['email'] = array(
    '#type' => 'textfield',
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#size' => 25,
    '#attributes' => array(
      'required' => 'required',
      'data-type' => 'email',
      'data-trigger' => 'change',
      'placeholder' => 'Email address',
      'class' => array('txtfield'),
    ),
  );

  //first password field
  $form['pass1'] = array(
    '#type' => 'password',
    '#required' => TRUE,
    '#size' => 25,
    '#attributes' => array(
      'required' => 'required',
      'data-trigger' => 'change',
      'placeholder' => 'Password',
      'data-error-message' => 'Please enter a password',
      'class' => array('txtfield'),
    ),
  );

  //second password field
  $form['pass2'] = array(
    '#type' => 'password',
    '#required' => TRUE,
    '#size' => 25,
    '#attributes' => array(
      'required' => 'required',
      'data-trigger' => 'change',
      'placeholder' => 'Confirm password',
      'data-equalto' => '#edit-pass1',
      'data-error-message' => 'Your passwords do not match',
      'class' => array('txtfield'),
    ),
  );

  //country
  include_once DRUPAL_ROOT . '/includes/iso.inc';
  $form['country'] = array(
    '#type' => 'select',
    '#default_value' => 'ZA',
    '#options' => _country_get_predefined_list(),
    '#attributes' => array(
      'required' => 'required',
    ),
  );

  //destination page hidden value
  $form['destination'] = array(
    '#type' => 'hidden',
    '#value' => $_GET['q'],
  );

  //login button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Register',
    '#attributes' => array(
      'class' => array('login-btn', 'submit-btn')
    ),
  );

  return $form;
}