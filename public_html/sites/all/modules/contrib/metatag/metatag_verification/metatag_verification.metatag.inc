<?php

/**
 * @file
 * Metatag integration for the Metatag: Verification module.
 */

/**
 * Implements hook_metatag_info().
 */
function metatag_verification_metatag_info() {
  $info['groups']['verification'] = array(
    'label' => t('Site verification'),
    'description' => t('These meta tags are used to confirm site ownership with search engines and other services.'),
    'form' => array(
      '#weight' => 110,
    ),
  );

  // Stack the verification codes after most others.
  $weight = 100;

  // Defaults used for all meta tags.
  $defaults = array(
    'class' => 'DrupalTextMetaTag',
    'context' => array('global'),
    'group' => 'verification',
  );

  $info['tags']['msvalidate.01'] = array(
    'label' => t('Bing'),
    'description' => t('A string provided by <a href="@bing">Bing</a>, full details are available from the <a href="@verify_url">Bing online help</a>.', array('@bing' => 'https://www.bing.com/', '@verify_url' => 'https://www.bing.com/webmaster/help/how-to-verify-ownership-of-your-site-afcfefc6')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['baidu-site-verification'] = array(
    'label' => t('Baidu'),
    'description' => t('A string provided by <a href="@baidu">Baidu</a>.', array('@baidu' => 'https://www.baidu.com/')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['facebook-domain-verification'] = array(
    'label' => t('Facebook'),
    'description' => t('A string provided by <a href="@facebook">Facebook</a>, full details are available from the <a href="@verify_url">Facebook online help</a>.', array('@facebook' => 'https://facebook.com/', '@verify_url' => 'https://developers.facebook.com/docs/sharing/domain-verification/verifying-your-domain/#meta-tags')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['google-site-verification'] = array(
    'label' => t('Google'),
    'description' => t('A string provided by <a href="@google">Google</a>, full details are available from the <a href="@verify_url">Google online help</a>.', array('@google' => 'https://www.google.com/', '@verify_url' => 'https://support.google.com/webmasters/answer/35179?hl=en')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['norton-safeweb-site-verification'] = array(
    'label' => t('Norton Safe Web'),
    'description' => t('A string provided by <a href="@norton">Norton Safe Web</a>, full details are available from the <a href="@verify_url">Norton Safe Web online help</a>.', array('@norton' => 'https://safeweb.norton.com/', '@verify_url' => 'https://safeweb.norton.com/help/site_owners')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['p:domain_verify'] = array(
    'label' => t('Pinterest'),
    'description' => t('A string provided by <a href="@pinterest">Pinterest</a>, full details are available from the <a href="@verify_url">Pinterest online help</a>.', array('@pinterest' => 'https://www.pinterest.com/', '@verify_url' => 'https://help.pinterest.com/en/articles/verify-your-website')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['pocket-site-verification'] = array(
    'label' => t('Pocket'),
    'description' => t('A string provided by <a href="@pocket">Pocket</a>, full details are available from the <a href="@verify_url">Pocket online help</a>.', array('@pocket' => 'https://getpocket.com/', '@verify_url' => 'https://support.google.com/webmasters/answer/9008080')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['yandex-verification'] = array(
    'label' => t('Yandex'),
    'description' => t('A string provided by <a href="@yandex">Yandex</a>, full details are available from the <a href="@verify_url">Yandex online help</a>.', array('@yandex' => 'https://www.yandex.com/', '@verify_url' => 'https://api.yandex.com/webmaster/doc/dg/reference/hosts-type.xml')),
    'weight' => ++$weight,
  ) + $defaults;

  $info['tags']['zoom-domain-verification'] = array(
    'label' => t('Zoom'),
    'description' => t('A string provided by <a href="@zoom">Zoom</a>, full details are available from the <a href="@help">Zoom online help</a>.', array('@zoom' => 'https://zoom.us/', '@help' => 'https://support.zoom.us/hc/en-us/articles/203395207-What-is-Managed-Domain')),
    'weight' => ++$weight,
  ) + $defaults;

  return $info;
}
