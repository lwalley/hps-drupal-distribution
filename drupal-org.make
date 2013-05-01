api = 2
core = 7.x

; Set projects defaults for modules
defaults[projects][subdir] = "contributed"

; Themes
projects[zen][version] = 5.1

; Contributed modules
projects[libraries][version] = 2.1

projects[transliteration][version] = 3.1

projects[ctools][version] = 1.3

projects[diff][version] = 3.2

projects[advanced_help][version] = 1.0

projects[administerusersbyrole][version] = 1.x-dev
projects[administerusersbyrole][download][type] = git
projects[administerusersbyrole][download][url] = http://git.drupal.org/project/administerusersbyrole.git
projects[administerusersbyrole][download][revision] = f8671526da1e97ef7740368f7a0ad25474d4d9a9
; http://drupalcode.org/project/administerusersbyrole.git/commit/f867152
; Addresses install error "You do not have permission to unblock <uid 1>" which
; breaks Aegir site install.
; @see http://drupal.org/node/923882

projects[token][version] = 1.5

projects[pathauto][version] = 1.2

projects[subpathauto][version] = 1.3

projects[redirect][version] = 1.0-rc1

projects[date][version] = 2.6
; includes date_views

projects[link][version] = 1.1

projects[field_group][version] = 1.1

projects[entity][version] = 1.0

projects[entityreference][version] = 1.0-rc5
; Foregin key information defaulting to node on field create and not being
; udpated. This is a core bug but for now patching entityreference until core
; fixed.
; @see http://drupal.org/node/1340748#comment-5806046
; @see http://drupal.org/node/1416506
;projects[entityreference][patch][1340748] = http://drupal.org/files/entity_reference-add-cTools-relationship-1340748-33.patch
; Patch provided could not be applied, re-rolled for HPS
projects[entityreference][patch][1340748] = https://raw.github.com/mbl-cli/hps-drupal-distribution/master/patches/entity_reference-add-cTools-relationship-1340748.patch

projects[jquery_update][version] = 2.3

projects[adaptive_image][version] = 1.4

projects[wysiwyg][version] = 2.2
; HPSR-158 Patch to remove file_create_url and prevent absolute URLs being used
; with drupal_add_js instead of relative paths.
; @see http://drupal.org/node/1802394
projects[wysiwyg][patch][1802394] = http://drupal.org/files/wysiwyg-1802394-4.patch

projects[imce][version] = 1.7

projects[imce_wysiwyg][version] = 1.0

projects[wysiwyg_filter][version] = 1.6-rc2

projects[fences][version] = 1.0

projects[features][version] = 1.0

projects[strongarm][version] = 2.0

projects[panels][version] = 3.3

projects[job_scheduler][version] = 2.0-alpha3

; @todo update to Feeds 2.0-alpha7
; Modules/patches will need to be tested/recreated for feeds,
; feeds_selfnode_processor and feeds_xpathparser
projects[feeds][version] = 2.0-alpha7
projects[feeds][patch][1171114] = http://drupal.org/files/feeds-getfile_replace_behaviour_alter-1171114-19.patch

projects[feeds_xpathparser][version] = 1.x-dev
projects[feeds_xpathparser][download][type] = git
projects[feeds_xpathparser][download][url] = http://git.drupal.org/project/feeds_xpathparser.git
projects[feeds_xpathparser][download][revision] = 4b1f1a40bfc5754f7fc04164ea33e37d21312f4b
; http://drupalcode.org/project/feeds_xpathparser.git/commit/4b1f1a4

projects[feeds_selfnode_processor][version] = 1.x-dev
projects[feeds_selfnode_processor][download][type] = git
projects[feeds_selfnode_processor][download][url] = http://git.drupal.org/project/feeds_selfnode_processor.git
projects[feeds_selfnode_processor][download][revision] = 802826d2787e6547b505deb9da5d965fdb15875b
projects[feeds_selfnode_processor][patch][1815768] = http://drupal.org/files/feeds_selfnode_processor-refactored_processor_to_include_feeds_hooks-1815768-1.patch

projects[views][version] = 3.7
; includes view_ui

projects[views_queue][version] = 1.x-dev
projects[views_queue][download][type] = git
projects[views_queue][download][url] = http://git.drupal.org/project/views_queue.git
projects[views_queue][download][revision] = 0d661bcd22f0cafdb0942c5efd612de7cc408d48

projects[facetapi][version] = 1.3

projects[facetapi_bonus][version] = 1.1

projects[search_api][version] = 1.4
projects[search_api][patch][1925114] = http://drupal.org/files/search_api-views_panels_facets_compatibility-1925114-2.patch
; includes search_facet_api

projects[search_api_solr][version] = 1.0-rc3

projects[taxonomy_menu][version] = 1.4

projects[addressfield][version] = 1.0-beta3

projects[geophp][version] = 1.7
; includes the geoPHP library
; recommends installing the GEOS PHP extension
; @see https://github.com/phayes/geoPHP/wiki/GEOS

projects[geofield][version] = 1.1

projects[geocoder][version] = 1.2

projects[lexicon][version] = 1.10

projects[taxonomy_csv][version] = 5.10

projects[print][version] = 1.2

projects[sharethis][version] = 2.5

projects[google_analytics][version] = 1.3

projects[views_rss][version] = 2.0-rc3

projects[override_node_options][version] = 1.12

projects[field_collection][version] = 1.0-beta5
projects[field_collection][patch][1063434] = http://drupal.org/files/field_collection-feeds_integration.patch

projects[rules][version] = 2.3

projects[views_bulk_operations][version] = 3.1

projects[field_validation][version] = 2.3

projects[behavior_weights][version] = 1.0

; @note some custom unversioned modules are included with this profile, others
;       we download from sandbox
projects[dspaced][type] = module
projects[dspaced][subdir] = custom
projects[dspaced][download][type] = git
projects[dspaced][download][url] = http://git.drupal.org/sandbox/lwalley/1911858.git
projects[dspaced][download][revision] = b6d545eaa1701e4a4a09f4922ffe2060fc6ffd5c

projects[views_job_scheduler][type] = module
projects[views_job_scheduler][subdir] = custom
projects[views_job_scheduler][download][type] = git
projects[views_job_scheduler][download][url] = http://git.drupal.org/sandbox/lwalley/1911890.git
projects[views_job_scheduler][download][revision] = 4a4bc165735d6381169094125f666710365149de

projects[feeds_xlsx][type] = module
projects[feeds_xlsx][subdir] = custom
projects[feeds_xlsx][download][type] = git
projects[feeds_xlsx][download][url] = http://git.drupal.org/sandbox/lwalley/1960440.git
projects[feeds_xlsx][download][revision] = 80864fc6b05a509f99993e36e5fdbad5b369d8cb

; Libraries
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url]  = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.5/ckeditor_3.6.5.zip

libraries[SolrPhpClient][download][type] = get
libraries[SolrPhpClient][download][url]  = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.zip

;libraries[geoPHP][download][type] = get
;libraries[geoPHP][download][url]  = https://github.com/phayes/geoPHP/archive/1.1.zip
; geoPHP library is bundled with the geophp module

; Fixing jquery.cycle version to 2.9999.8 (26-OCT-2012) and downloading from
; GitHub instead of http://malsup.github.com/jquery.cycle.all.js because
; starting Version: 2.9999.81 (15-JAN-2013) jquery.cycle requires jquery 1.7.1
; or above. We are currently using 1.5 because of Ctools and Views compatibility.
; @see http://drupal.org/node/1494860
libraries[jquery.cycle][download][type] = get
libraries[jquery.cycle][download][url]  = https://raw.github.com/malsup/cycle/4fffa1d366e964267ca433db9f8bfc83723f04a4/jquery.cycle.all.js
libraries[jquery.cycle][directory_name] = jquery.cycle

libraries[jwplayer][download][type] = get
libraries[jwplayer][download][url]  = http://www.longtailvideo.com/download/jwplayer-free-6-0-2813.zip

;libraries[jquery.jplayer][download][type] = get
;libraries[jquery.jplayer][download][url]  = http://www.jplayer.org/latest/jQuery.jPlayer.2.2.0.zip

libraries[dompdf][download][type] = get
libraries[dompdf][download][url]  = http://dompdf.googlecode.com/files/dompdf_0-6-0_beta3.zip

libraries[PHPExcel][download][type] = get
libraries[PHPExcel][download][url]  = https://github.com/PHPOffice/PHPExcel/archive/PHPExcel_1.7.8.tar.gz
libraries[PHPExcel][directory_name] = PHPExcel
libraries[PHPExcel][patch][1] = https://raw.github.com/mbl-cli/hps-drupal-distribution/master/patches/PHPExcel-zoomscale-fix.patch
