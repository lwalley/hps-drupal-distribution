<?php
/**
 * @file
 * hps_courses.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function hps_courses_default_rules_configuration() {
  $items = array();
  $items['rules_hps_courses_component_import_course'] = entity_import('rules_config', '{ "rules_hps_courses_component_import_course" : {
      "LABEL" : "Import Course Node",
      "PLUGIN" : "action set",
      "TAGS" : [ "HPS" ],
      "REQUIRES" : [ "hps_courses" ],
      "USES VARIABLES" : { "hps_course_node" : { "label" : "Course Node", "type" : "node" } },
      "ACTION SET" : [
        { "hps_courses_action_import_course" : { "hps_courses_parameter_course_node" : [ "hps-course-node" ] } }
      ]
    }
  }');
  return $items;
}
