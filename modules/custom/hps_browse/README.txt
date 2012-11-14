HPS Browse Feature
------------------

WARNING: The vocabulary vid and terms tids used to create this Feature will not exist or will be
different than taxonomies in your application. You will need to reconfigure the Panel/Page
Manager selection rules, the Views/View Content pane filters and the Taxonomy menu settings
before using this Feature.

@see Issue "Exporting a taxonomy term page manager variant with vocabulary selection rules
     exports vid instead of machine_name" http://drupal.org/node/1586324


What does it do?
----------------

Provides base configuration for converting a taxonomy vocabulary into a 'Browse by ...' menu with
node listings pages. By default this Feature uses the 'DC Description Types' vocabulary as an
example configuration for a 'Browse By Format' menu and listings.


How does it do it?
------------------

Provides a custom content type 'HPS Browse By' that:

  1. Contains an Entity Reference field to a vocabulary [1].
  2. Can be assigned a menu item to act as the parent menu item for the vocabulary's
     Taxonomy Menu settings.
  3. Behaves as a landing page which can list all of the browse by categories in the
     vocabulary.

[1] The vocabulary should contain all the terms that you want to browse by, and should be
  configured using the Taxonomy Menu to create a menu item for each term. By default this
  feature provides all of this configuration for the 'DC Description Type' vocabulary
  imported from DSpace.


Provides a node override using Page Manager/Panels which renders the vocabulary terms
automatically on the browse by node landing page. It does this by passing the vocabulary
referenced in the current browse by node through a Choas Tools context relationship [2]
configured in Panels/Page Manager, to the Views content pane.

[2] Passing the vocabulary vid as a context argument from Panels to Views is problematic
    due to core bug with foreign keys. Temporarily solved with entityreference patch.
    @see http://drupal.org/node/1831872


Provides taxonomy term override using Page Manager/Panels which contains variants for
category pages (i.e. sub-landing pages 'Root' variant) and default listing display
('List' view) for terms in the DC Description Type vocabulary.


Provides an additional custom page for taxonomy terms with a sub-path wildcard
(taxonomy/term/%term/%mode) to capture the display mode. Thus allowing different display
types e.g. gallery, index for term listings. By default the variants 'Gallery' and 'Index'
have been added for the DC Description Type vocabulary.


Provides a ctools content type (pane) that allows display mode links to be added to a
panels page. By default the taxonomy term and taxonomy term display mode pages have display
mode links for 'List' (default), 'Gallery' and 'Index'.


Provides views panes for the different display modes, list, gallery and index. The term ID
is passed in to the views contextual filters from the panel page so it would be possible to
add more variants to the panels pages for specific terms or groups of terms if the view results
needed to be different.


How to get it working?
----------------------

1. Import or create the taxonomy vocabulary and terms you want to use with this Feature, see
   the DSpaced module for instructions on importing items from DSpace.

   The Feature assumes you are have imported items from DSpace and that the import created a
   vocabulary 'DC Description Types' which has a list of terms without any hierarchy. If you
   want to group terms you can manually add root terms to the vocabulary and organise the child
   terms under these manually added root terms. You can then add a description to this root term
   which will be displayed as a 'category' page, see the 'Root' variant in Page Manager/Panels
   term view configuration.

2. Enable this Feature at /admin/structure/features.

3. Enable 'HPS Browse' View at /admin/structure/views.

   By default there are a set of content panes configured to list 'DSpace Item' nodes that are
   linked to terms in the 'DC Description Types' vocabulary. Each content pane represents a different
   display mode for the node listing 'List' (default), 'Gallery' and 'Index'.

4. Enable 'HPS Browse By' View at /admin/structure/views

   By default this view provides a content pane that lists a complete hierarchy of terms for a
   single vocabulary. The vocabulary vid is passed to the view from the panel page with a ctools
   context relationship configured in page manager/panels.

5. Edit the 'Taxonomy term template' in Page Manager /admin/structure/pages or Panels
   /admin/structure/panels.

   For each variant you want to use you will need to edit the 'Selection Rules' and reselect the
   'DC Description Type' vocabulary to update the vid.

   The 'Root' variant is a special case and assumes you have manually added some root terms to your
   'DC Description Types' vocabulary that you want to use as category pages. This variant has two
   selection rules, one that checks the term is in the 'DC Description Types' vocabulary and one
   that checks it is a root term in that vocabulary, i.e. it does not have a parent term. You will
   need reselect your vocabulary for both of these selection rules to update the vid.

   The 'Root' Variant does not use a Views pane from the 'HPS Browse Panes' selection, instead the
   content to display is configured directly in the Page Manager/Panels 'Content' section. It is
   configured to display the Term description and then a list of child terms for that term, you
   don't need to modify this configuration unless you want to change what content is displayed.

   Once you're done don't forget to enable the page and the variants you want to use.

6. Edit the 'HPS Browse By... Alternative Display Modes' in Page Manager /admin/structure/pages
   or Panels /admin/structure/panels.

    For each variant you want to use you will need to edit the 'Selection Rules' and reselect the
   'DC Description Type' vocabulary to update the vid. Note the additional selection rule for the
   display mode, by default two alternative display variants are included 'Gallery' and 'Index'.

   Note in the variant's content settings that there is an additional content pane 'Display Mode Links',
   this is the custom content pane that takes the URL arguments as context and a manually set string
   of links in the form [Link label](suffix) where suffix is the sub path, and converts these values
   to a list of appropriate links for the available display modes.

   Once you're done don't forget to enable the page and the variants you want to use.

7. Create a 'HPS Browse By' node, choose the 'DC Description Types' vocabulary and create a menu item
   for the node.

8. Configure the 'DC Description Types' vocabulary's Taxonomy Menu Settings to use the new node's menu
   item as the parent menu item.

9. Enable the Page Manager node override and 'Browse By' variant /admin/structure/pages.
