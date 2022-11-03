<?php
/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can modify or override Drupal's theme
 *   functions, intercept or make additional variables available to your theme,
 *   and create custom PHP logic. For more information, please visit the Theme
 *   Developer's Guide on Drupal.org: http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to greenbox_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: greenbox_breadcrumb()
 *
 *   where STARTERKIT is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override either of the two theme functions used in Zen
 *   core, you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function greenbox_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function greenbox_preprocess_page(&$variables, $hook) {

  // addtoany additional header and footer js
  // global $_addtoany_init;
  // $_addtoany_init = TRUE;
  // addtoany_page_alter($variables['page']);

  //QR code suggestion handling
  if (isset($_GET['qr']) && ($_GET['qr'] == 1)){
    $variables['theme_hook_suggestions'] = array('page__qr');
  }

  //Disable the second sidebar from the plant node
  if (isset($variables['node']) && $variables['node']->type == 'plant'){
    $variables['page']['sidebar_second'] = array();
  }

  //template suggestion based on path
  $alias = explode('/',drupal_get_path_alias(request_uri()));

  //add template suggestions based on path
  $path = drupal_get_path_alias($_GET['q']);
  if ($path != $_GET['q']) {
    $template_filename = 'page';
    //Break it down for each piece of the alias path
    foreach (explode('/', $path) as $path_part) {
      $template_filename = $template_filename . '__' . str_replace('-', '_', $path_part);
      $variables['theme_hook_suggestions'][] = $template_filename;
    }
  }

  //adding special main content wrapper class for CSS targeting
  switch(arg(0)){
    case 'search':
      $variables['main_class'] = 'search-results';
      break;
  }

  //krumo($variables['theme_hook_suggestions']);
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function greenbox_preprocess_node(&$variables, $hook) {

  // Optionally, run node-type-specific preprocess functions, like
  // greenbox_preprocess_node_page() or greenbox_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }

  // Get a list of all the regions for this theme
  foreach (system_region_list($GLOBALS['theme']) as $region_key => $region_name) {

    // Get the content for each region and add it to the $region variable
    if ($blocks = block_get_blocks_by_region($region_key)) {
      $variables['region'][$region_key] = $blocks;
    }
    else {
      $variables['region'][$region_key] = array();
    }
  }
}

/**
 * Override or insert variables into the node PLANT templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function greenbox_preprocess_node_plant(&$variables, $hook) {

  // Get node
  $node = $variables['node'];

  // Get the correct zone image overlay (Only for plant nodes)
  // Check for taxonomy term
  if (isset($node->field_hort_zone['und'][0]['taxonomy_term'])){
    foreach($node->field_hort_zone['und'] as $delta => $hort){

      // Get name
      $name = $hort['taxonomy_term']->name;

      // Pattern
      $pattern = '/Zone\s+(\d{1})/i';

      // Find pattern
      if (preg_match($pattern, $name, $matches)){

        // Get number
        $number = $matches[1];

        // Array of number words
        $words = array(1 => 'one', 2 => 'two', 3 => 'three', 4 => 'four', 5 => 'five');

        // Word
        $word = $words[$number];

        $variables['hort_overlay'][$delta] = array(
          'image_name' => 'zone-' . $word . '-hover.png',
          'class' => $word,
        );
      }
    }
  }

  // Get some formatted taxonomy terms for certain fields
  $variables['attr']['sa_distribution'] = greenbox_format_taxonomy_terms($node->field_distribution); // SA distribution
  $variables['attr']['flowering_season'] = greenbox_format_taxonomy_terms($node->field_flowering_season); // Flowering season
  $variables['attr']['gardening_skill'] = greenbox_format_taxonomy_terms($node->field_gardening_skill); // Gardening skill
  $variables['attr']['plant_type'] = greenbox_format_taxonomy_terms($node->field_plant_type); // Plant type
  $variables['attr']['soil_type'] = greenbox_format_taxonomy_terms($node->field_soil_type); // Soil type
  $variables['attr']['soil_ph'] = greenbox_format_taxonomy_terms($node->field_ph); // Soil PH
  $variables['attr']['flower_colour'] = greenbox_format_taxonomy_terms($node->field_flower_colour); // Flower colour
  $variables['attr']['exposure'] = greenbox_format_taxonomy_terms($node->field_exposure); // Field exposure

  // Species table stuff which JJ forgot
  $variables['species'] = array();
  if(isset($node->field_species[LANGUAGE_NONE])){
    foreach ($node->field_species[LANGUAGE_NONE] as $delta => $entity_id) {

      //load our field collection item
      $entity = entity_load('field_collection_item', array($entity_id['value']));
      $entity = reset($entity);

      //assign image and description for species table
      if(!empty($entity)){
        $variables['species'][$delta]['description'] = $entity->field_description[LANGUAGE_NONE][0]['value'];  
        // RR amended below
        // theme('image_style', array('path' => $entity->field_primary_image[LANGUAGE_NONE][0]['uri'], 'style_name' => 'plant_listing'));
        $image = theme('image_style', array(
                    'style_name' => '', // was 'plant_listing' but rather want unmodified image
                    'path' => $entity->field_primary_image[LANGUAGE_NONE][0]['uri'],
                    'alt' => $entity->field_primary_image[LANGUAGE_NONE][0]['alt'],
                    'title' => $entity->field_primary_image[LANGUAGE_NONE][0]['title'],                    
                  )
                );
        $image = str_replace('styles//public/','',$image); //HACK refer to root image, not (broken) path
        $variables['species'][$delta]['img'] = $image;         
      }
    }
  }

  // Check if we need to build legacy reference list or use the new re-usable field
  if (isset($node->field_references_taxonomy) || isset($node->field_references)){

    $items = array();

    // Loop through newer taxonomy references if they exist
    if (isset($node->field_references_taxonomy['und']) && !empty($node->field_references_taxonomy['und'])){
      $items = array();
      foreach($node->field_references_taxonomy['und'] as $telta => $term){
        $items[$telta]['data'] = $term['taxonomy_term']->name;
      }
    }elseif (isset($node->field_references['und']) && $node->field_references['und'][0]['value'] != ''){

      $tmp = strip_tags($node->field_references['und'][0]['value']);
      $tmp = explode('|', $tmp);

      if(!empty($tmp)){
        foreach($tmp as $telta => $ref){
          $items[$telta]['data'] = $ref;
        }
      }
    }

    //theme into list
    $variables['references'] = theme_item_list(array('items' => $items, 'title' => '', 'type' => 'ul', 'attributes' => array()));
  }
}

/**
 * Override or insert variables into the node PLANT templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function greenbox_preprocess_node_info_library_entry(&$variables, $hook) {
  if(isset($variables['field_file'][0]['uri'])){
    $variables['download_path'] = file_create_url($variables['field_file'][0]['uri']);
  }
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function greenbox_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function greenbox_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  $variables['classes_array'][] = 'count-' . $variables['block_id'];
}
// */

/**
 * Get category path for the info library
 *
 * @param $tid
 *   term id
 *
 */
function greenbox_get_category_path($tid){

  // Get term alias
  $term_alias = drupal_lookup_path('alias', 'taxonomy/term/' . $tid);

  // Get parts of alias
  $alias_parts = pathinfo($term_alias);

  // Return the last part of the path
  return base_path() . 'information-library/' . $alias_parts['basename'] . '/' . $tid;
}

/**
 * Format list of a taxonomy field's terms
 *
 * @param $field
 *
 */
function greenbox_format_taxonomy_terms($field){

  // Check for value
  if (isset($field['und'])){

    // Loop
    foreach ($field['und'] as $key => $term) {
      $terms[] = $term['taxonomy_term']->name;
    }
    return implode(', ', $terms);
  }else{

    // Return blank
    return "";
  }
}