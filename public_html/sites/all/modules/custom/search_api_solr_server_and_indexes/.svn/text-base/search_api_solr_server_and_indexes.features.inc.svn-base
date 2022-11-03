<?php
/**
 * @file
 * search_api_solr_server_and_indexes.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function search_api_solr_server_and_indexes_default_search_api_index() {
  $items = array();
  $items['info_library'] = entity_import('search_api_index', '{
    "name" : "Info library",
    "machine_name" : "info_library",
    "description" : "Contains indexed \\u0022Info Lib\\u0022 node data for search.",
    "server" : "database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "100",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_abstract" : { "type" : "text" },
        "field_author:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_category:name" : { "type" : "text" },
        "field_category:tid" : { "type" : "integer" },
        "field_date" : { "type" : "date" },
        "field_file:file" : { "type" : "integer", "entity_type" : "file" },
        "field_keywords:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_publisher_copyright:name" : { "type" : "list\\u003Ctext\\u003E" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "info_library_entry" : "info_library_entry" }
          }
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
          "settings" : { "fields" : { "title" : true, "field_abstract" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_abstract" : true },
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_abstract" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_abstract" : true },
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
  $items['plants'] = entity_import('search_api_index', '{
    "name" : "Plants",
    "machine_name" : "plants",
    "description" : "Index of all Plants and their fields",
    "server" : "database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "100",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_authors:field_first_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_authors:field_last_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_common_names" : { "type" : "text" },
        "field_cost_center:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_credits:value" : { "type" : "text" },
        "field_description:value" : { "type" : "text" },
        "field_distribution:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_distribution_description:value" : { "type" : "text" },
        "field_ecology:value" : { "type" : "text" },
        "field_exposure:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_family:name" : { "type" : "text" },
        "field_flower_colour:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_flowering_season:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_gardening_skill:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_genus:name" : { "type" : "text" },
        "field_grow:value" : { "type" : "text" },
        "field_history:value" : { "type" : "text" },
        "field_hort_zone:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_introduction:value" : { "type" : "text" },
        "field_long_scientific_name:value" : { "type" : "text" },
        "field_ph:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_plant_type:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_sa_tree_number" : { "type" : "text" },
        "field_short_scientific_name" : { "type" : "text" },
        "field_soil_type:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_source" : { "type" : "text" },
        "field_special_features:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_status:value" : { "type" : "text" },
        "field_synched_scientific_name" : { "type" : "text" },
        "field_use:value" : { "type" : "text" },
        "field_week" : { "type" : "date" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "search_api_title_first_letter" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "string" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-49",
          "settings" : { "default" : "0", "bundles" : { "plant" : "plant" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-47", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-46", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "pa_advanced_search_alter_add_first_letter_title" : { "status" : 1, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-43", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_short_scientific_name" : true,
              "field_synched_scientific_name" : true,
              "field_common_names" : true,
              "field_sa_tree_number" : true,
              "field_source" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_short_scientific_name" : true,
              "field_synched_scientific_name" : true,
              "field_common_names" : true,
              "field_sa_tree_number" : true,
              "field_source" : true
            },
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_short_scientific_name" : true,
              "field_synched_scientific_name" : true,
              "field_common_names" : true,
              "field_sa_tree_number" : true,
              "field_source" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_short_scientific_name" : true,
              "field_synched_scientific_name" : true,
              "field_common_names" : true,
              "field_sa_tree_number" : true,
              "field_source" : true
            },
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

/**
 * Implements hook_default_search_api_server().
 */
function search_api_solr_server_and_indexes_default_search_api_server() {
  $items = array();
  $items['apache_solr'] = entity_import('search_api_server', '{
    "name" : "Apache Solr",
    "machine_name" : "apache_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "0",
    "rdf_mapping" : []
  }');
  $items['database'] = entity_import('search_api_server', '{
    "name" : "MySQL DB",
    "machine_name" : "database",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "indexes" : {
        "plants" : {
          "type" : {
            "table" : "search_api_db_plants",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_plants",
            "type" : "string",
            "boost" : "1.0",
            "column" : "title"
          },
          "url" : {
            "table" : "search_api_db_plants",
            "column" : "url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_plants",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "promote" : {
            "table" : "search_api_db_plants",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_plants",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_plants",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_short_scientific_name" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_week" : {
            "table" : "search_api_db_plants",
            "column" : "field_week",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_synched_scientific_name" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_common_names" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_sa_tree_number" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_source" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_plants",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_title_first_letter" : {
            "table" : "search_api_db_plants",
            "column" : "search_api_title_first_letter",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_plant_type:name" : {
            "table" : "search_api_db_plants_field_plant_type_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_hort_zone:name" : {
            "table" : "search_api_db_plants_field_hort_zone_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_soil_type:name" : {
            "table" : "search_api_db_plants_field_soil_type_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_ph:name" : {
            "table" : "search_api_db_plants_field_ph_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_flowering_season:name" : {
            "table" : "search_api_db_plants_field_flowering_season_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_flower_colour:name" : {
            "table" : "search_api_db_plants_field_flower_colour_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_distribution:name" : {
            "table" : "search_api_db_plants_field_distribution_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_exposure:name" : {
            "table" : "search_api_db_plants_field_exposure_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_distribution_description:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_description:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_grow:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_history:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_use:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_status:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_ecology:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_special_features:name" : {
            "table" : "search_api_db_plants_field_special_features_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_gardening_skill:name" : {
            "table" : "search_api_db_plants_field_gardening_skill_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_family:name" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_long_scientific_name:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_introduction:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_credits:value" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_genus:name" : {
            "table" : "search_api_db_plants_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cost_center:name" : {
            "table" : "search_api_db_plants_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_authors:field_first_name" : {
            "table" : "search_api_db_plants_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_authors:field_last_name" : {
            "table" : "search_api_db_plants_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        },
        "general_search" : {
          "nid" : {
            "table" : "search_api_db_general_search",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_general_search",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "url" : {
            "table" : "search_api_db_general_search",
            "column" : "url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_general_search",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_short_scientific_name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_week" : {
            "table" : "search_api_db_general_search",
            "column" : "field_week",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_common_names" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_authors" : {
            "table" : "search_api_db_general_search_field_authors",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_general_search",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_description:value" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_history:value" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_use:value" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_ecology:value" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_family:name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cost_center:name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_long_scientific_name:value" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_authors:field_first_name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_authors:field_last_name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_author:name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_keywords:name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_publisher_copyright:name" : {
            "table" : "search_api_db_general_search_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_grow:value" : {
            "table" : "search_api_db_general_search_text",
            "type" : "text",
            "boost" : "1.0"
          }
        },
        "info_library" : {
          "nid" : {
            "table" : "search_api_db_info_library",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_info_library",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_info_library_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_info_library",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_info_library",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_info_library",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_info_library",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_abstract" : {
            "table" : "search_api_db_info_library_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_date" : {
            "table" : "search_api_db_info_library",
            "column" : "field_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_info_library",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_author:name" : {
            "table" : "search_api_db_info_library_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_category:tid" : {
            "table" : "search_api_db_info_library",
            "column" : "field_category_tid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_category:name" : {
            "table" : "search_api_db_info_library_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_file:file" : {
            "table" : "search_api_db_info_library",
            "column" : "field_file_file",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_keywords:name" : {
            "table" : "search_api_db_info_library_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_publisher_copyright:name" : {
            "table" : "search_api_db_info_library_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
