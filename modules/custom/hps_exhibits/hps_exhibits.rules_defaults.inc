<?php
/**
 * @file
 * hps_exhibits.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function hps_exhibits_default_rules_configuration() {
  $items = array();
  $items['rules_hps_exhibit_after_create'] = entity_import('rules_config', '{ "rules_hps_exhibit_after_create" : {
      "LABEL" : "HPS Exhibit After Create",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "HPS" ],
      "REQUIRES" : [ "rules", "rules_book" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "hps_exhibit" : "hps_exhibit" } }
          }
        }
      ],
      "DO" : [
        { "rules_book_action_convert_node_to_book" : { "rules_book_parameter_node" : [ "node" ] } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  return $items;
}
