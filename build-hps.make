; Drush make file for HPS distribution

api = 2
core = 7.x

; Download Drupal core using the release branch core make file
includes[] = https://raw.github.com/mbl-cli/hps-drupal-distribution/2013.10.30/drupal-org-core.make

; Download HPS profile from the current release branch, using drupal make file
projects[hps][type] = profile
projects[hps][download][type] = git
projects[hps][download][url] = git://github.com/mbl-cli/hps-drupal-distribution.git
projects[hps][download][branch] = 2013.10.30

