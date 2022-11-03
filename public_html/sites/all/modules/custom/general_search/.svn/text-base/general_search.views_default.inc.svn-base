<?php
/**
 * @file
 * general_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function general_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'general_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_general_search';
  $view->human_name = 'General search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'General search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Unfortunately there are no results matching you search terms.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['preserve_tags'] = '<strong>';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Field: Info lib - file upload */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['ui_name'] = 'Info lib - file upload';
  $handler->display->display_options['fields']['field_file']['label'] = '';
  $handler->display->display_options['fields']['field_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'file_url_plain';
  /* Field: Info lib - date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['ui_name'] = 'Info lib - date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'search_results',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Info lib - author */
  $handler->display->display_options['fields']['field_author_name']['id'] = 'field_author_name';
  $handler->display->display_options['fields']['field_author_name']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_author_name']['field'] = 'field_author_name';
  $handler->display->display_options['fields']['field_author_name']['ui_name'] = 'Info lib - author';
  $handler->display->display_options['fields']['field_author_name']['label'] = '';
  $handler->display->display_options['fields']['field_author_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author_name']['link_to_entity'] = 0;
  /* Field: Info lib - source */
  $handler->display->display_options['fields']['field_source']['id'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_source']['field'] = 'field_source';
  $handler->display->display_options['fields']['field_source']['ui_name'] = 'Info lib - source';
  $handler->display->display_options['fields']['field_source']['label'] = '';
  $handler->display->display_options['fields']['field_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_source']['type'] = 'text_plain';
  /* Field: Info lib - keywords */
  $handler->display->display_options['fields']['field_keywords_name']['id'] = 'field_keywords_name';
  $handler->display->display_options['fields']['field_keywords_name']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_keywords_name']['field'] = 'field_keywords_name';
  $handler->display->display_options['fields']['field_keywords_name']['ui_name'] = 'Info lib - keywords';
  $handler->display->display_options['fields']['field_keywords_name']['label'] = '';
  $handler->display->display_options['fields']['field_keywords_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_keywords_name']['link_to_entity'] = 0;
  /* Field: Info lib - Copyright */
  $handler->display->display_options['fields']['field_publisher_copyright_name']['id'] = 'field_publisher_copyright_name';
  $handler->display->display_options['fields']['field_publisher_copyright_name']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_publisher_copyright_name']['field'] = 'field_publisher_copyright_name';
  $handler->display->display_options['fields']['field_publisher_copyright_name']['ui_name'] = 'Info lib - Copyright';
  $handler->display->display_options['fields']['field_publisher_copyright_name']['label'] = '';
  $handler->display->display_options['fields']['field_publisher_copyright_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publisher_copyright_name']['link_to_entity'] = 0;
  /* Field: POW - common names */
  $handler->display->display_options['fields']['field_common_names']['id'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_common_names']['field'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['ui_name'] = 'POW - common names';
  $handler->display->display_options['fields']['field_common_names']['label'] = '';
  $handler->display->display_options['fields']['field_common_names']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_common_names']['type'] = 'text_plain';
  /* Field: POW - family */
  $handler->display->display_options['fields']['field_family_name']['id'] = 'field_family_name';
  $handler->display->display_options['fields']['field_family_name']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_family_name']['field'] = 'field_family_name';
  $handler->display->display_options['fields']['field_family_name']['ui_name'] = 'POW - family';
  $handler->display->display_options['fields']['field_family_name']['label'] = '';
  $handler->display->display_options['fields']['field_family_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_family_name']['link_to_entity'] = 0;
  /* Field: POW - location */
  $handler->display->display_options['fields']['field_cost_center_name']['id'] = 'field_cost_center_name';
  $handler->display->display_options['fields']['field_cost_center_name']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_cost_center_name']['field'] = 'field_cost_center_name';
  $handler->display->display_options['fields']['field_cost_center_name']['ui_name'] = 'POW - location';
  $handler->display->display_options['fields']['field_cost_center_name']['label'] = '';
  $handler->display->display_options['fields']['field_cost_center_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cost_center_name']['link_to_entity'] = 0;
  /* Field: POW - week */
  $handler->display->display_options['fields']['field_week']['id'] = 'field_week';
  $handler->display->display_options['fields']['field_week']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_week']['field'] = 'field_week';
  $handler->display->display_options['fields']['field_week']['ui_name'] = 'POW - week';
  $handler->display->display_options['fields']['field_week']['label'] = '';
  $handler->display->display_options['fields']['field_week']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_week']['settings'] = array(
    'format_type' => 'search_results',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: POW - author fname */
  $handler->display->display_options['fields']['field_authors_field_first_name']['id'] = 'field_authors_field_first_name';
  $handler->display->display_options['fields']['field_authors_field_first_name']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_authors_field_first_name']['field'] = 'field_authors_field_first_name';
  $handler->display->display_options['fields']['field_authors_field_first_name']['ui_name'] = 'POW - author fname';
  $handler->display->display_options['fields']['field_authors_field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_authors_field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_authors_field_first_name']['type'] = 'text_plain';
  /* Field: POW - author surname */
  $handler->display->display_options['fields']['field_authors_field_last_name']['id'] = 'field_authors_field_last_name';
  $handler->display->display_options['fields']['field_authors_field_last_name']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['fields']['field_authors_field_last_name']['field'] = 'field_authors_field_last_name';
  $handler->display->display_options['fields']['field_authors_field_last_name']['ui_name'] = 'POW - author surname';
  $handler->display->display_options['fields']['field_authors_field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_authors_field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_authors_field_last_name']['type'] = 'text_plain';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 's';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = '<>';
  $handler->display->display_options['filters']['type']['value'] = array(
    'webform' => 'webform',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_general_search';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: General search page */
  $handler = $view->new_display('page', 'General search page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search';
  $export['general_search'] = $view;

  return $export;
}
