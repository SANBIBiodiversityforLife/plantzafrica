<?php
/**
 * @file
 * views_plant_of_the_week_searches.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_plant_of_the_week_searches_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pow_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_plants';
  $view->human_name = 'POW search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Basic POW search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_plants';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 's';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
  );

  /* Display: Basic POW Search */
  $handler = $view->new_display('page', 'Basic POW Search', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'plants/test-search';

  /* Display: Facet: Plant type */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Plant type', 'facet_plant_type');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Plant type';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Plant Type';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_plant_type:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Flower colour */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Flower colour', 'facet_flower_colour');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Flower colour';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Flower colour';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_flower_colour:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Flowering season */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Flowering season', 'facet_flowering_season');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Flowering season';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Flowering season';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_flowering_season:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Gardening skill */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Gardening skill', 'facet_gardening_skill');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Gardening skill';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Gardening skill';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_gardening_skill:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: SA Distro */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: SA Distro', 'facet_SA_distros');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: SA Distro';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: SA Distro';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_distribution:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Special features */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Special features', 'facet_special_features');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Special features';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Special features';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_special_features:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Hort zone */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Hort zone', 'facet_hort_zone');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Hort zone';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Hort zone';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_hort_zone:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Soil type */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Soil type', 'facet_soil_type');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Soil type';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Soil type';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_soil_type:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Soil PH */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Soil PH', 'facet_soil_ph');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Soil PH';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Soil PH';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_ph:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Facet: Exposure */
  $handler = $view->new_display('search_api_views_facets_block', 'Facet: Exposure', 'facet_exposure');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Facet: Exposure';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Facet View: Exposure';
  $handler->display->display_options['linked_path'] = 'plants/search/advanced';
  $handler->display->display_options['facet_field'] = 'field_exposure:name';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Plants home page */
  $handler = $view->new_display('block', 'Plants home page', 'homepage');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Plants home page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Primary Image */
  $handler->display->display_options['fields']['field_primary_image']['id'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['field_primary_image']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['label'] = '';
  $handler->display->display_options['fields']['field_primary_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_primary_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_primary_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_primary_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_primary_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image']['settings'] = array(
    'image_style' => 'plant_listing',
    'image_link' => 'content',
  );
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Introduction */
  $handler->display->display_options['fields']['field_introduction']['id'] = 'field_introduction';
  $handler->display->display_options['fields']['field_introduction']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['field_introduction']['field'] = 'field_introduction';
  $handler->display->display_options['fields']['field_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_introduction']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_introduction']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_introduction']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_introduction']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_introduction']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_introduction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_introduction']['type'] = 'text_plain';
  /* Field: Indexed Node: Common names */
  $handler->display->display_options['fields']['field_common_names']['id'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['field_common_names']['field'] = 'field_common_names';
  $handler->display->display_options['fields']['field_common_names']['label'] = '';
  $handler->display->display_options['fields']['field_common_names']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_common_names']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_common_names']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_common_names']['type'] = 'text_plain';
  /* Field: Cost center: Name (indexed) */
  $handler->display->display_options['fields']['field_cost_center_name']['id'] = 'field_cost_center_name';
  $handler->display->display_options['fields']['field_cost_center_name']['table'] = 'search_api_index_plants';
  $handler->display->display_options['fields']['field_cost_center_name']['field'] = 'field_cost_center_name';
  $handler->display->display_options['fields']['field_cost_center_name']['label'] = '';
  $handler->display->display_options['fields']['field_cost_center_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cost_center_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cost_center_name']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Promoted to frontpage */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'search_api_index_plants';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_plants';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Plants home page';
  $export['pow_search'] = $view;

  return $export;
}
