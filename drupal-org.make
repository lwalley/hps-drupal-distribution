api = 2
core = 7.x

; Set projects defaults for modules
defaults[projects][subdir] = "contributed"

; Themes
projects[zen][version] = 5.1

; Contributed modules
projects[fences][version] = 1.0

projects[jquery_update][version] = 2.2

projects[adaptive_image][version] = 1.4

projects[date][version] = 2.6

projects[link][version] = 1.0

projects[field_group][version] = 1.1

projects[entityreference][version] = 1.0-rc5

projects[advanced_help][version] = 1.0

projects[administerusersbyrole][version] = 1.0-beta1

projects[token][version] = 1.4

projects[pathauto][version] = 1.2

projects[ctools][version] = 1.2

projects[features][version] = 1.0

projects[strongarm][version] = 2.0

projects[libraries][version] = 2.0

projects[wysiwyg][version] = 2.2

projects[imce][version] = 1.5

projects[imce_wysiwyg][version] = 1.0

projects[transliteration][version] = 3.1

projects[job_scheduler][version] = 2.0-alpha3

projects[feeds][version] = 2.0-alpha6
projects[feeds][patch][1171114] = http://drupal.org/files/feeds-getfile_replace_behaviour_alter-1171114-19.patch

projects[feeds_xpathparser][version] = 1.x-dev
projects[feeds_selfnode_processor][download][type] = git
projects[feeds_selfnode_processor][download][url] = http://git.drupal.org/project/feeds_xpathparser.git
projects[feeds_selfnode_processor][download][revision] = 4b1f1a40bfc5754f7fc04164ea33e37d21312f4b
; http://drupalcode.org/project/feeds_xpathparser.git/commit/4b1f1a4

projects[feeds_selfnode_processor][version] = 1.x-dev
projects[feeds_selfnode_processor][download][type] = git
projects[feeds_selfnode_processor][download][url] = http://git.drupal.org/project/feeds_selfnode_processor.git
projects[feeds_selfnode_processor][download][revision] = 802826d2787e6547b505deb9da5d965fdb15875b
projects[feeds_selfnode_processor][patch][1815768] = http://drupal.org/files/feeds_selfnode_processor-refactored_processor_to_include_feeds_hooks-1815768-1.patch

projects[views][version] = 3.5
; includes view_ui

projects[views_queue][version] = 1.x-dev
projects[views_queue][download][type] = git
projects[views_queue][download][url] = http://git.drupal.org/project/views_queue.git
projects[views_queue][download][revision] = 0d661bcd22f0cafdb0942c5efd612de7cc408d48

projects[entity][version] = 1.0-rc3

projects[facetapi][version] = 1.2

projects[facetapi_bonus][version] = 1.1

projects[search_api][version] = 1.3
; includes search_facet_api

projects[search_api_solr][version] = 1.0-rc2


; @note Custom unversioned modules are included in profile tar.gz

; Libraries
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.5/ckeditor_3.6.5.zip

libraries[SolrPhpClient][download][type] = get
libraries[SolrPhpClient][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.zip

; @todo jquery cycle
