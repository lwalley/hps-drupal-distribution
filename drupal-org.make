api = 2
core = 7.x

; Contributed modules
projects[advanced_help][subdir] = contributed
projects[advanced_help][version] = 1.0

projects[pathauto][subdir] = contributed
projects[pathauto][version] = 1.2

projects[ctools][subdir] = contributed
projects[ctools][version] = 1.2

projects[features][subdir] = contributed
projects[features][version] = 1.0

projects[strongarm][subdir] = contributed
projects[strongarm][version] = 2.0

projects[date][subdir] = contributed
projects[date][version] = 2.6

projects[link][subdir] = contributed
projects[link][version] = 1.0

projects[libraries][subdir] = contributed
projects[libraries][version] = 2.0

projects[wysiwyg][subdir] = contributed
projects[wysiwyg][version] = 2.2

projects[imce][subdir] = contributed
projects[imce][version] = 1.5

projects[imce_wysiwyg][subdir] = contributed
projects[imce_wysiwyg][version] = 1.0

projects[transliteration][subdir] = contributed
projects[transliteration][version] = 3.1

projects[job_scheduler][subdir] = contributed
projects[job_scheduler][version] = 2.0-alpha3

projects[feeds][subdir] = contributed
projects[feeds][version] = 2.0-alpha6
projects[feeds][patch][] = http://drupal.org/files/feeds-getfile_replace_behaviour_alter-1171114-19.patch

projects[feeds_xpathparser][subdir] = contributed
projects[feeds_xpathparser][version] = 1.0-beta3

projects[feeds_selfnode_processor][subdir] = contributed
projects[feeds_selfnode_processor][version] = 1.0-beta3+3-dev
projects[feeds_selfnode_processor][download][type] = git
projects[feeds_selfnode_processor][download][url] = http://git.drupal.org/project/feeds_selfnode_processor.git
projects[feeds_selfnode_processor][download][revision] = 802826d2787e6547b505deb9da5d965fdb15875b
projects[feeds_selfnode_processor][patch][] = http://drupal.org/files/feeds_selfnode_processor-refactored_processor_to_include_feeds_hooks-1815768-1.patch

projects[views][subdir] = contributed
projects[views][version] = 3.5

projects[views_ui][subdir] = contributed
projects[views_ui][version] = 3.5

projects[views_queue][subdir] = contributed
projects[views_queue][version] = 1.x-dev
projects[views_queue][download][type] = git
projects[views_queue][download][url] = http://git.drupal.org/project/views_queue.git
projects[views_queue][download][revision] = 0d661bcd22f0cafdb0942c5efd612de7cc408d48

projects[entity][subdir] = contributed
projects[entity][version] = 1.0-rc3

projects[facetapi][subdir] = contributed
projects[facetapi][version] = 1.2

projects[facetapi_bonus][subdir] = contributed
projects[facetapi_bonus][version] = 1.1

projects[search_api][subdir] = contributed
projects[search_api][version] = 1.2

projects[search_api_facetapi][subdir] = contributed
projects[search_api_facetapi][version] = 1.2

projects[search_api_solr][subdir] = contributed
projects[search_api_solr][version] = 1.0-rc2


; Custom unversioned modules
projects[views_job_scheduler][subdir] = custom
projects[dspaced_entities][subdir] = custom
projects[dspaced][subdir] = custom
projects[dspaced_ui][subdir] = custom


; Libraries
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor%20for%20Drupal/CKEditor%203.6.2%20for%20Drupal/ckeditor_3.6.2_for_drupal_7.zip

libraries[SolrPhpClient][download][type] = get
libraries[SolrPhpClient][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.zip
