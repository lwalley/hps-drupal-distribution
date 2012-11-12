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

  1. Contains an Entity Reference field to a vocabulary*.
  2. Can be assigned a menu item to act as the parent menu item for the vocabulary's
     Taxonomy Menu settings.
  3. Behaves as a landing page which can list all of the browse by categories in the
     vocabulary.

* The vocabulary should contain all the terms that you want to browse by, and should be
  configured using the Taxonomy Menu to create a menu item for each term. By default this
  feature provides all of this configuration for the 'DC Description Type' vocabulary
  imported from DSpace.

Provides a node override using Page Manager/Panels which renders the vocabulary terms automatically**
on the browse by node landing page.

** Passing the vocabulary vid as a context argument from Panels to Views is a little quirky
   @see http://drupal.org/node/1831872

Provides a taxonomy term override using Page Manager/Panels which contains variants for
category pages (i.e. sub-landing pages), and specifc to this feature, variants for specific
DC Description Type terms i.e. formats such as Audio, Video etc. so that different formats
can dsiplay node listings in different ways.


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

3. Edit 'HPS Browse' View at /admin/structure/views.

   By default there are a set of content panes configured to list 'DSpace Item' nodes that are
   linked to specific terms in the 'DC Description Types' vocabulary. Each term has its own content
   pane and uses a different view mode (teaser) or fields for its listing.

   Edit the Filter Criteria of each content pane to select the term you want to list nodes for
   e.g. for 'Articles' pane edit (or re-add) the 'Content: DC Description Type (= Articles)'
   Filter Criteria to select the 'Articles' term from your vocabulary.

   Once you're done don't forget to enable the View and the individual content panes you want to use.

4. Configure content type view modes (teasers) /admin/structure/types/manage/dspaced-entities-item/display.

   By default the 'HPS Browse' View uses the render entity format with teaser view modes to display
   DSpace Items in the browse by listings. Custom view modes e.g. 'Audio Teaser' are provided by the
   'HPS Defaults' Feature. You can configure which DSpace Item fields should be shown in each teaser
   mode using the DSpace Item content type display manager interface.

5. Edit the 'Taxonomy term template' in Page Manager /admin/structure/pages or Panels
   /admin/structure/panels.

   For each variant you want to use you will need to edit the 'Selection Rules' and reselect the
   'DC Description Type' vocabulary and the specific term that variant is for e.g. for the 'Audio'
   variant you'll need to reselect the 'Audio' term in the selection rule to update the vid and tid.

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

6. Create a 'HPS Browse By' node, choose the 'DC Description Types' vocabulary and create a menu item
   for the node.

7. Configure the 'DC Description Types' vocabulary's Taxonomy Menu Settings to use the new node's menu
   item as the parent menu item.

8. Enable the Page Manager node override and Browse By variant /admin/structure/pages.
