HPS Search Feature
------------------

What does it do?
----------------

Provides base configuration for Solr server and DSpace Items node index
including custom search results page with exposed filter (search form)
for full text keyword search, and facet filters for 'DC Description Types'.

How does it do it?
------------------

Provides a base configuration for Solr Search and Facet API modules to
connect to a Solr core instance 'HPS Solr Server', index DSpace Item nodes
with 'HPS Node Index' and provide a facet block (check box filters) for
'DC Description Types'.

Custom search results page 'HPS Search' is provided by Page Manager and Panels,
and uses a custom 'HPS Search' Views Context display to render the keyword
search form (exposed filter), along with the Facet API block for 'DC Description
Types', results summary, pagination and search results (DSpace Item node listing).

This feature also includes a custom node view mode 'Search Results' which is
used when rendering the DSpace Item nodes in the Views rows on the results page.

How to get it working?
----------------------

Assumes you have imported DSpace Items, see DSpaced module.

1. Import the DSpace Items you want to use with this Feature, see
   the DSpaced module for instructions on importing items from DSpace.

2. Install/enable this Feature /admin/structure/features.

3. Edit the 'HPS Solr Server' configuration to match your Solr server path
   /admin/config/search/search_api.

4. Edit the 'HPS Node Index' configuration as required, e.g. you may want to
   include additional fields or node types /admin/config/search/search_api.

   Note: Facet API block for 'DC Description Types' is configured with the
   HPS Node Index e.g. /admin/config/search/search_api/index/hps_node_index/facets

   Run cron, or manually index items.

5. Configure which fields should be displayed in DSpace Item content type's
   custom 'Search Results' node view (display) mode e.g.
   /admin/structure/types/manage/dspaced-entities-item/display/search_results

6. Enable the 'HPS Search' View and context display /admin/structure/views.

7. Enable the 'HPS Search' Page /admin/structure/pages and 'Search' variant.

   Note: The variants 'Contexts' includes the the 'HPS Search' Views Context
         display which allows different Views elements to be added separately
         as Content to the page e.g. pagination, views rows (results), empty
         text area, views header etc.

         The Facet API block is not part of the Views configuration, it is
         configured in 'HPS Node Index' and added as a seperate Content item
         in the Panel.

8. Test search results page at /search.

