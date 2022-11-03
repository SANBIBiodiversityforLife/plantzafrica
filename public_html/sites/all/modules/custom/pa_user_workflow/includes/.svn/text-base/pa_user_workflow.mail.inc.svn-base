<?php
/*
 * @file pa_user_workflow.mail.inc
 * Mail callback and definitions goes here.
 */

/**
 * Implements hook_mail().
 */
function pa_user_workflow_mail($key, &$message, $params){

  switch($key){

    case 'verification_email':

      //generate URL for verification mail
      $account = $params['account'];
      $timestamp = REQUEST_TIME;
      $clickURL = url("signup/verify/" . $params['account']->uid . "/" . $timestamp . "/" . user_pass_rehash($account->pass, $timestamp, $account->login), array(
          'absolute' => TRUE,
          'query' => array('destination' => $params['destination']),
        )
      );

      //theme link for use within email
      $link = l(t('here'), $clickURL, array('fragment' => 'loginmodal'));

      $message['subject'] = t('Verify your account with Plantz Africa');
      $message['body'][] = t('Hi there!');
      $message['body'][] = t('You are one step away from enabling your Plantz Africa account.');
      $message['body'][] = 'Click ' . $link . ' to verify your account and login.';
      $message['body'][] = t('Kind regards');
      $message['body'][] = '<strong>The Plantz Africa team</strong>';

      watchdog('pa_user_workflow', $link);

      break;
  }
}

/**
 * Implements hook_mail_send().
 */
function pa_user_workflow_mail_send($account, $destination){

  // All system mails need to specify the module and template key (mirrored from
  // hook_mail()) that the message they want to send comes from.
  $module = 'pa_user_workflow';
  $key = 'verification_email';

  //use form values as mail params
  $params['account'] = $account;
  $params['destination'] = $destination;

  // Specify 'to' and 'from' addresses.
  $to = $account->mail;
  $from = variable_get('site_mail', 'admin@example.com');

  $language = language_default();
  $send = TRUE;

  //send mail using drupal_mail
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);

  //return result of mail send
  return $result;
}