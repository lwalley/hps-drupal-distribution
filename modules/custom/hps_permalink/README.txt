Summary
-------

Intercepts paths in the format handle/1234/1234 and loads their corresponding
DSpace Archive Item node. If multiple nodes are found with the same handle it
will load the smallest nid, and record an error in the background to watchdog.

Recommendations
---------------

Use Metatag (https://drupal.org/project/metatag) module to add canonical URL to
node view, indicating to search engines that the handle URL node view is a copy
of the node page view.


