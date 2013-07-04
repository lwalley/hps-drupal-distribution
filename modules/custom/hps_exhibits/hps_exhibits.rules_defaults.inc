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
      "REQUIRES" : [ "rules", "rules_book", "views_bulk_operations", "og" ],
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
        { "entity_save" : { "data" : [ "node" ], "immediate" : 1 } },
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "hps_exhibits_users|default" },
            "PROVIDE" : { "entity_list" : { "users_list" : "Users list" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users-list" ] },
            "ITEM" : { "current_user_item" : "Current user item" },
            "DO" : [
              { "og_subcribe_user" : { "user" : [ "current-user-item" ], "group" : [ "node" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_hps_exhibit_after_update'] = entity_import('rules_config', '{ "rules_hps_exhibit_after_update" : {
      "LABEL" : "HPS Exhibit After Update",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "HPS" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "hps_exhibit" : "hps_exhibit" } }
          }
        },
        { "NOT data_is" : {
            "data" : [ "node-unchanged:group-access" ],
            "value" : [ "node:group-access" ]
          }
        }
      ],
      "DO" : [
        { "entity_save" : { "data" : [ "node" ], "immediate" : 1 } },
        { "og_get_group_content" : {
            "USING" : { "group" : [ "node" ], "entity_type" : "node" },
            "PROVIDE" : { "group_content" : { "group_content" : "Group content" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-content" ] },
            "ITEM" : { "group_content_item" : "Group content item" },
            "DO" : [ { "entity_save" : { "data" : [ "group-content-item" ] } } ]
          }
        }
      ]
    }
  }');
  return $items;
}
