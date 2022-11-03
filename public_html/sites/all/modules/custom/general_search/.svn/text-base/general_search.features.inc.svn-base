<?php
/**
 * @file
 * general_search.features.inc
 */

/**
 * Implements hook_views_api().
 */
function general_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function general_search_default_search_api_index() {
  $items = array();
  $items['general_search'] = entity_import('search_api_index', '{
    "name" : "General search",
    "machine_name" : "general_search",
    "description" : "Index storing fields only used in our general search",
    "server" : "database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "100",
      "fields" : {
        "body:value" : { "type" : "text" },
        "field_abstract" : { "type" : "text" },
        "field_author:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_authors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_authors:field_first_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_authors:field_last_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_common_names" : { "type" : "text" },
        "field_cost_center:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_description:value" : { "type" : "text" },
        "field_ecology:value" : { "type" : "text" },
        "field_family:name" : { "type" : "text" },
        "field_grow:value" : { "type" : "text" },
        "field_history:value" : { "type" : "text" },
        "field_keywords:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_long_scientific_name:value" : { "type" : "text" },
        "field_publisher_copyright:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_short_scientific_name" : { "type" : "text" },
        "field_use:value" : { "type" : "text" },
        "field_week" : { "type" : "date" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "pa_advanced_search_alter_add_first_letter_title" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_common_names" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_common_names" : true },
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_common_names" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_common_names" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
