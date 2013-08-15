; Drupal core project requirements.
; Includes patches against Drupal core.

api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = 7.23

; Use vocabulary machine name for permissions
; @see http://drupal.org/node/995156
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch

; Fix for node_access integrity constraint violation
; @note To recreate issue: enable OG Access module, enable HPS Exhibit After
;       Create rule, create a new exhibit. Without patch error is returned:
;       PDOException: SQLSTATE[23000]: Integrity constraint violation:
;       1062 Duplicate entry '...og_access:node' for key 'PRIMARY':
;       INSERT INTO {node_access} (nid, realm, gid, grant_view...
; @see https://drupal.org/node/1146244
projects[drupal][patch][1146244] = https://drupal.org/files/node-access-records-1146244-110.patch
