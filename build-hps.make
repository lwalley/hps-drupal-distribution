; Drush make file for HPS distribution

api = 2
core = 7.x

includes[] = drupal-org-core.make

; Install profile
projects[hps][type] = profile
projects[hps][download][type] = file
projects[hps][download][url] = ../hps.tar.gz


