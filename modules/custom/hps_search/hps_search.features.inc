<?php
/**
 * @file
 * hps_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hps_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hps_search_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function hps_search_default_search_api_index() {
  $items = array();
  $items['hps_node_index'] = entity_import('search_api_index', '{
    "name" : "HPS Node Index",
    "machine_name" : "hps_node_index",
    "description" : "Index of node data, primarily configured to index DSpace Items but can be modified or added to, e.g. add index for extended DSpace fields unique to the community e.g. extended DC Subject qualifiers.",
    "server" : "hps_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "1",
      "fields" : {
        "title" : { "type" : "text", "boost" : "5.0" },
        "status" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "dspace_handle" : { "type" : "text" },
        "dspace_entity_id" : { "type" : "integer" },
        "dspace_lastmodified" : { "type" : "date" },
        "dc_contributor" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_editor" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_illustrator" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_interviewee" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_interviewer" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_narrator" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_photographer" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_correspondent" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_speaker" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_translator" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_contributor_videographer" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_coverage" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_coverage_spatial" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_coverage_temporal" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_creator" : { "type" : "text" },
        "dc_date" : { "type" : "list\u003Ctext\u003E" },
        "dc_date_accessioned" : { "type" : "date" },
        "dc_date_available" : { "type" : "date" },
        "dc_date_created" : { "type" : "list\u003Ctext\u003E" },
        "dc_date_issued" : { "type" : "date" },
        "dc_description_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "dc_format" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_format_extent" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_format_medium" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_identifier" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_identifier_citation" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_identifier_issn" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_language" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_language_iso" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_publisher" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_publisher_digital" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_publisher_original" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_relation_hasformat" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_relation_haspart" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_relation_hasversion" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_relation_isformatof" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_relation_ispartof" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_relation_isversionof" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_rights" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_rights_copyright" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_rights_holder" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_rights_license" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_source" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_title" : { "type" : "text" },
        "dc_title_alternative" : { "type" : "list\\u003Ctext\\u003E" },
        "dspace_pdf_text" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text", "boost" : "2.0" },
        "dc_description:value" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "dc_description_abstract:value" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "dc_description_provenance:value" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_description_tableofcontents:value" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_description_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_subject:name" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_subject_lcsh:name" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_subject_mesh:name" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_subject_tag:name" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "dc_description_type:parent:name" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "dspaced_entities_item" : "dspaced_entities_item" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "dc_description_type:parents_all" : "dc_description_type:parents_all",
              "dc_subject:parents_all" : "dc_subject:parents_all",
              "dc_subject_lcsh:parents_all" : "dc_subject_lcsh:parents_all",
              "dc_subject_mesh:parents_all" : "dc_subject_mesh:parents_all",
              "dc_subject_tag:parents_all" : "dc_subject_tag:parents_all",
              "dc_type:parents_all" : "dc_type:parents_all",
              "field_tags:parents_all" : "field_tags:parents_all"
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "dc_contributor" : true,
              "dc_contributor_editor" : true,
              "dc_contributor_illustrator" : true,
              "dc_contributor_interviewee" : true,
              "dc_contributor_interviewer" : true,
              "dc_contributor_narrator" : true,
              "dc_contributor_photographer" : true,
              "dc_contributor_correspondent" : true,
              "dc_contributor_speaker" : true,
              "dc_contributor_translator" : true,
              "dc_contributor_videographer" : true,
              "dc_coverage" : true,
              "dc_coverage_spatial" : true,
              "dc_coverage_temporal" : true,
              "dc_creator" : true,
              "dc_format" : true,
              "dc_format_extent" : true,
              "dc_format_medium" : true,
              "dc_identifier" : true,
              "dc_identifier_citation" : true,
              "dc_identifier_issn" : true,
              "dc_language" : true,
              "dc_language_iso" : true,
              "dc_publisher" : true,
              "dc_publisher_digital" : true,
              "dc_publisher_original" : true,
              "dc_relation_hasformat" : true,
              "dc_relation_haspart" : true,
              "dc_relation_hasversion" : true,
              "dc_relation_isformatof" : true,
              "dc_relation_ispartof" : true,
              "dc_relation_isversionof" : true,
              "dc_rights" : true,
              "dc_rights_copyright" : true,
              "dc_rights_holder" : true,
              "dc_rights_license" : true,
              "dc_source" : true,
              "dc_title" : true,
              "dc_title_alternative" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "dc_contributor" : true,
              "dc_contributor_editor" : true,
              "dc_contributor_illustrator" : true,
              "dc_contributor_interviewee" : true,
              "dc_contributor_interviewer" : true,
              "dc_contributor_narrator" : true,
              "dc_contributor_photographer" : true,
              "dc_contributor_correspondent" : true,
              "dc_contributor_speaker" : true,
              "dc_contributor_translator" : true,
              "dc_contributor_videographer" : true,
              "dc_coverage" : true,
              "dc_coverage_spatial" : true,
              "dc_coverage_temporal" : true,
              "dc_creator" : true,
              "dc_format" : true,
              "dc_format_extent" : true,
              "dc_format_medium" : true,
              "dc_identifier" : true,
              "dc_identifier_citation" : true,
              "dc_identifier_issn" : true,
              "dc_language" : true,
              "dc_language_iso" : true,
              "dc_publisher" : true,
              "dc_publisher_digital" : true,
              "dc_publisher_original" : true,
              "dc_relation_hasformat" : true,
              "dc_relation_haspart" : true,
              "dc_relation_hasversion" : true,
              "dc_relation_isformatof" : true,
              "dc_relation_ispartof" : true,
              "dc_relation_isversionof" : true,
              "dc_rights" : true,
              "dc_rights_copyright" : true,
              "dc_rights_holder" : true,
              "dc_rights_license" : true,
              "dc_source" : true,
              "dc_title" : true,
              "dc_title_alternative" : true,
              "body:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "dspace_handle" : true,
              "dc_contributor" : true,
              "dc_contributor_editor" : true,
              "dc_contributor_illustrator" : true,
              "dc_contributor_interviewee" : true,
              "dc_contributor_interviewer" : true,
              "dc_contributor_narrator" : true,
              "dc_contributor_photographer" : true,
              "dc_contributor_correspondent" : true,
              "dc_contributor_speaker" : true,
              "dc_contributor_translator" : true,
              "dc_contributor_videographer" : true,
              "dc_coverage" : true,
              "dc_coverage_spatial" : true,
              "dc_coverage_temporal" : true,
              "dc_creator" : true,
              "dc_format" : true,
              "dc_format_extent" : true,
              "dc_format_medium" : true,
              "dc_identifier" : true,
              "dc_identifier_citation" : true,
              "dc_identifier_issn" : true,
              "dc_language" : true,
              "dc_language_iso" : true,
              "dc_publisher" : true,
              "dc_publisher_digital" : true,
              "dc_publisher_original" : true,
              "dc_relation_hasformat" : true,
              "dc_relation_haspart" : true,
              "dc_relation_hasversion" : true,
              "dc_relation_isformatof" : true,
              "dc_relation_ispartof" : true,
              "dc_relation_isversionof" : true,
              "dc_rights" : true,
              "dc_rights_copyright" : true,
              "dc_rights_holder" : true,
              "dc_rights_license" : true,
              "dc_source" : true,
              "dc_title" : true,
              "dc_title_alternative" : true,
              "body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
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
function hps_search_default_search_api_server() {
  $items = array();
  $items['hps_solr'] = entity_import('search_api_server', '{
    "name" : "HPS Solr",
    "machine_name" : "hps_solr",
    "description" : "Solr server for this site. For multicores be sure to enter the path to the correct Solr instance for this site e.g. \\/solr\\/\\u003Creplaceme\\u003E.",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/replaceme",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
