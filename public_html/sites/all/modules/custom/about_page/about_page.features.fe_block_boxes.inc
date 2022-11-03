<?php
/**
 * @file
 * about_page.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function about_page_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'About SANBI Sidebar';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'about_sanbi_sidebar';
  $fe_block_boxes->body = '<div class="right-sidebar"><div class="title"><h3>About SANBI</h3></div><div class="updates-news"><p>There are more than 22 000 different species of seed plants indigenous to southern Africa. These are arranged into about 2 180 genera, which in turn form part of 227 families.</p><div class="sanbi-logo"><img alt="" src="sites/all/themes/greenbox/images/sanbi-logo.jpg" style="width: 182px; height: 48px;" /></div><a class="sanbi-link" href="#">www.sanbi.org</a></div><div class="updates-news"><h4>Advertise on PlantZAfrica ?</h4><p>If you would like to advertise on PlantZAfrica please contact us at <a href="mailto:webmaster@sanbi.org.za">webmaster@sanbi.org.za</a></p></div></div><p>&nbsp;</p>';

  $export['about_sanbi_sidebar'] = $fe_block_boxes;

  return $export;
}
