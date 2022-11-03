<?php
/**
 * @file
 * plant_settings.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function plant_settings_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_1|node|plant|form';
  $field_group->group_name = 'group_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'plant';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_plant';
  $field_group->data = array(
    'label' => 'Attributes',
    'weight' => '1',
    'children' => array(
      0 => 'field_plant_type',
      1 => 'field_hort_zone',
      2 => 'field_soil_type',
      3 => 'field_ph',
      4 => 'field_flowering_season',
      5 => 'field_flower_colour',
      6 => 'field_distribution',
      7 => 'field_exposure',
      8 => 'field_special_features',
      9 => 'field_gardening_skill',
      10 => 'field_sa_tree_number',
      11 => 'metatags',
      12 => 'title',
      13 => 'path',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Attributes',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_1|node|plant|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_2|node|plant|form';
  $field_group->group_name = 'group_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'plant';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_plant';
  $field_group->data = array(
    'label' => 'Content Fields',
    'weight' => '2',
    'children' => array(
      0 => 'field_short_scientific_name',
      1 => 'field_distribution_description',
      2 => 'field_description',
      3 => 'field_grow',
      4 => 'field_history',
      5 => 'field_use',
      6 => 'field_status',
      7 => 'field_ecology',
      8 => 'field_week',
      9 => 'field_primary_image',
      10 => 'field_synched_scientific_name',
      11 => 'field_family',
      12 => 'field_cost_center',
      13 => 'field_long_scientific_name',
      14 => 'field_common_names',
      15 => 'field_secondary_images',
      16 => 'field_introduction',
      17 => 'field_authors',
      18 => 'field_credits',
      19 => 'field_genus',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Content Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_2|node|plant|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_plant|node|plant|form';
  $field_group->group_name = 'group_plant';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'plant';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Plant',
    'weight' => '0',
    'children' => array(
      0 => 'group_1',
      1 => 'group_2',
      2 => 'group_references',
      3 => 'group_species',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-plant field-group-htabs',
      ),
    ),
  );
  $export['group_plant|node|plant|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rating|node|plant|form';
  $field_group->group_name = 'group_rating';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'plant';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_plant';
  $field_group->data = array(
    'label' => 'Rating',
    'weight' => '5',
    'children' => array(
      0 => 'field_rating_article',
      1 => 'field_rating_plant',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-rating field-group-htabs',
      ),
    ),
  );
  $export['group_rating|node|plant|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_references|node|plant|form';
  $field_group->group_name = 'group_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'plant';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_plant';
  $field_group->data = array(
    'label' => 'References',
    'weight' => '4',
    'children' => array(
      0 => 'field_references',
      1 => 'field_references_taxonomy',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-references field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_references|node|plant|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_species|node|plant|form';
  $field_group->group_name = 'group_species';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'plant';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_plant';
  $field_group->data = array(
    'label' => 'Species',
    'weight' => '3',
    'children' => array(
      0 => 'field_species',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Species',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-species field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_species|node|plant|form'] = $field_group;

  return $export;
}
