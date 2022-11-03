<?php
/**
 * @file pa_advanced_search.forms.inc
 * Contains all our form builder, validation and submission callbacks for our Advanced Search forms.
 */

/**
 * Implements hook_form().
 */
function pa_advanced_search_form($form, &$form_state) {

  //Add in jQuery UI lib for our autocomplete functionality
  $path = drupal_get_path('module', 'pa_jquery_update') . '/scripts/jquery-ui-1.10.4.custom.min.js';
  drupal_add_js($path, array('weight' => -18));

  $form['name'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($_GET['name'])? $_GET['name'] : '',
    '#required' => FALSE,
    '#attributes' => array(
      'class' => array('autocomplete-pa-advanced', 'txtfield'),
      'placeholder' => 'Enter your search terms'
    )
  );

  $form['top_submit'] = array(
    '#type' => 'submit',
    '#value' => 'Search',
    '#attributes' => array(
      'class' => array('search-btn'),
    )
  );

  //build facet render arrays to access select options for custom form if form not in cache
  $searcher = 'search_api@plants';
  $realm_name = 'block';
  $build = facetapi_build_realm($searcher, $realm_name);

  /* ### define and group the facet fields we wish to include on our form BEGIN ### */
  $facets = pa_advanced_search_build_facet_groups();

  //TODO: temp grouping logic, group using proper theming
  $form['facets'] = array(
    '#tree' => TRUE,
  );

  //loop through facets and check if they exist on page
  foreach($facets as $gkey => $group){

    //TODO: temp grouping logic, group using proper theming
    $form['facets'][$gkey] = array(
      '#tree' => TRUE,
    );

    //loop through facets and add to our form
    foreach($group as $f => $facet){
      if(isset($build[$f][$f]['facets'])){

        //clean up our GET param key first
        $param_key = pa_advanced_search_clean_facet_element_name($f);

        //populate form element with the facet built for the block realm
        $form['facets'][$gkey][$param_key] = array(
          '#type' => $facet['type'],
          '#options' => $build[$f][$f]['facets']['#options'],
          '#default_value' => (isset($_GET[$param_key]))? pa_advanced_search_get_element_default_value($param_key, $_GET[$param_key]) : array(),
        );

        //add select box classes and attributes
        if($form['facets'][$gkey][$param_key]['#type'] == 'select'){
          $form['facets'][$gkey][$param_key]['#multiple'] = TRUE;
          $form['facets'][$gkey][$param_key]['#attributes'] = array(
           'data-placeholder' => 'Any',
           'class' => array('select-box')
          );
        }

        //if the facet widget is a select list then enable multiple attribute
        if($form['facets'][$gkey][$param_key]['#type'] == 'select'){
          $form['facets'][$gkey][$param_key]['#multiple'] = TRUE;
        }
      }
    }
  }
  /* ### define and group the facet fields we wish to include on our form END ### */

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Search',
    '#attributes' => array(
      'class' => array('yellow-btn'),
    )
  );

  //use our custom form template
  $form['#theme'] = 'pa_advanced_search_form';
  
  return $form;
}

/**
 * Submit callback function for our advanced search form.
 */
function pa_advanced_search_form_submit($form, &$form_state) {

  //allows us to postback to the same page where the form resides and retain input values.
  $form_state['rebuild'] = TRUE;

  //build GET params using postback values
  $input = $form_state['input'];
  unset($input['form_build_id'], $input['form_id'], $input['form_token'], $input['op']);

  //check if doing freetext search or attribute search
  // RR to recombine searches
  //if(isset($input['name']) && $input['name'] != ''){
  //  unset($input['facets']);
  //}

  //clean up facet values (if there are any active ones) for our URL params
  if(isset($input['facets'])){
    $facets = pa_advanced_search_extract_facet_value($input['facets']);
    unset($input['facets']);
    if(!empty($facets)){
      $input += $facets;
    }
  }

  //declare which parameters we need to retain
  $retain = array(
    'date_sort',
    'glossary',
    'page'
  );

  //get our parameters from GET variable
  $params = drupal_get_query_parameters();

  //loop through paramters and remove those which we shouldn't be retaining
  foreach($params as $key => $value){
    if(!in_array($key, $params)){
      unset($params[$key]);
    }
  }

  $input += $params;

  //redirect to our search results listings route
  drupal_goto('plants/search/advanced', array('query' => $input));
}

/**
 * Form builder function for simple search form.
 */
function pa_advanced_search_basic_form($form, &$form_state){

  //add our autocomplete scripts and CSS
  drupal_add_js(drupal_get_path('module', 'pa_autocomplete') . '/scripts/pa_autocomplete.plants.js');
  drupal_add_css(drupal_get_path('module', 'pa_autocomplete') . '/css/pa_autocomplete.css');

  //validation attributes
  $form = array(
    '#attributes' => array(
      'data-validate' => 'parsley',
      'novalidate' => 'novalidate'
    ),
  );

  //intro copy
  $form['intro'] = array(
    '#markup' => '<p>This searches all Plant of the Week articles that have been transferred. To search all the content on the website, use the General Site Search above.</p>'
  );

  //plant name input
  $form['name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('autocomplete-pa-basic txtfield'),
      'required' => 'required',
      'data-trigger' => 'change',
    ),
    '#prefix' => '<div class="field">',
  );

  //submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Search',
    '#attributes' => array(
      'class' => array('search-btn'),
    ),
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Submit handler for our basic search form.
 */
function pa_advanced_search_basic_form_submit($form, &$form_state){

  //grab user input
  $input['name'] = $form_state['input']['name'];

  //redirect to our search results listings route
  drupal_goto('plants/search/advanced', array('query' => $input));
}

/**
 * Form builder function for our date range form.
 */
function pa_advanced_search_date_range_form(){

  //add in our javascript for validation and utils
  drupal_add_js(drupal_get_path('module', 'pa_advanced_search') . '/scripts/pa_pow_date_range.js');

  $min_date = date('Y') - 2000;

  $form['date_start'] = array(
    '#type' => 'date_popup',
    '#title' => t('From'),
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '-' . $min_date . ':+0',
    '#default_value' => isset($_GET['date_start'])? date('Y-m-d H:i:s', $_GET['date_start']) : '',
    '#attributes' => array(
      'placeholder' => 'Start date'
    ),
  );

  $form['date_end'] = array(
    '#type' => 'date_popup',
    '#title' => t('Until'),
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '-' . $min_date . ':+0',
    '#default_value' => isset($_GET['date_end'])? date('Y-m-d H:i:s', $_GET['date_end']) : '',
    '#attributes' => array(
      'placeholder' => 'End date'
    ),
  );

  $form['reset'] = array(
    '#type' => 'button',
    '#value' => 'Reset',
    '#attributes' => array(
      'class' => array('search-btton')
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Apply',
    '#attributes' => array(
      'class' => array('search-btton')
    ),
  );

  return $form;
}

/**
 * Submit handler function for our date range form.
 */
function pa_advanced_search_date_range_form_submit($form, $form_state){

  $input = array();

  /*krumo($form_state['input']); exit();*/

  if($form_state['input']['date_start']['date'] != '' && $form_state['input']['date_end']['date'] != ''){
    //manipulate date format for our query
    $tmp['start'] = $form_state['input']['date_start']['date'];
    $tmp['end'] = $form_state['input']['date_end']['date'];

    //split up dd mm yy
    $tmp['start'] = explode('/', $tmp['start']);
    $tmp['end'] = explode('/', $tmp['end']);

    $input = array(
      'name' => '',
      'date_start' => strtotime($tmp['start'][2] . '/' . $tmp['start'][1] . '/' . $tmp['start'][0]),
      'date_end' => strtotime($tmp['end'][2] . '/' . $tmp['end'][1] . '/' . $tmp['end'][0])
    );
  }

  //redirect to our search results listings route
  drupal_goto('plants/search/list', array('query' => $input));
}

/**
 * Utility function which returns facet grouping, key and label array.
 */
function pa_advanced_search_build_facet_groups(){

  //facets for plant criteria
  $facets['plant'] = array(
    'field_plant_type:name' => array(
      'label' => 'Type of plant',
      'type' => 'select'
    ),
    'field_flower_colour:name' => array(
      'label' => 'Flower colour',
      'type' => 'select'
    ),
    'field_flowering_season:name' => array(
      'label' => 'Flowering season',
      'type' => 'select'
    ),
    'field_gardening_skill:name' => array(
      'label' => 'Gardening skill',
      'type' => 'select'
    ),
    'field_distribution:name' => array(
      'label' => 'SA distribution',
      'type' => 'select'
    ),
  );

  //special features
  $facets['features'] = array(
    'field_special_features:name' => array(
      'label' => 'Special features',
      'type' => 'checkboxes',
    ),
  );

  //special features
  $facets['gardening'] = array(
    'field_hort_zone:name' => array(
      'label' => 'Horticultural zones',
      'type' => 'checkboxes',
    ),
    'field_soil_type:name' => array(
      'label' => 'Soil type',
      'type' => 'select',
    ),
    'field_ph:name' => array(
      'label' => 'Soil PH',
      'type' => 'select',
    ),
    'field_exposure:name' => array(
      'label' => 'Exposure',
      'type' => 'select',
    ),
  );

  return $facets;
}

/**
 * Util function which cleans up our facet keys to look a little prettier.
 */
function pa_advanced_search_clean_facet_element_name($key){

  $key = str_replace('field_', '', $key);
  $key = str_replace(':name', '', $key);

  return $key;
}

/**
 * Util function to extract facet value from form submission variable.
 */
function pa_advanced_search_extract_facet_value($input){

  $facet_params = array();

  //loop through our received facet input and extra clean value for processing
  foreach($input as $gKey => $group){
    foreach($group as $fKey => $facet){
      if(is_array($facet)){
        $count = 0;
        foreach($facet as $delta => $value){
          if($value){
            $tmp = explode(':', $value);
            $facet_params[$fKey][$count++] = $tmp[1];
          }
        }
      }
    }
  }

  return $facet_params;
}

/**
 * Util function to set default value for search form elements
 */
function pa_advanced_search_get_element_default_value($key, $value){

  $default_values = array();

  //URL params should always be multiple
  if(is_array($value)){
    //loop through param values and generate default values for facet element
    foreach($value as $val){
      $delta = $facet_key = 'field_' . $key . '%3Aname:' . $val;
      $default_values[] = $delta;
    }
  }

  return drupal_map_assoc($default_values);
}
