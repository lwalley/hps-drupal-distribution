; Drush make file for HPS distribution

api = 2
core = 7.x

;includes[] = drupal-org-core.make
includes[] = https://raw.github.com/mbl-cli/hps-drupal-distribution/master/drupal-org-core.make

; Install profile
projects[hps][type] = profile
projects[hps][download][type] = git
projects[hps][download][url] = git@github.com:mbl-cli/hps-drupal-distribution.git
projects[hps][download][branch] = master


