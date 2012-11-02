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

Provides a 'Browse by Format' menu item with child menu items automatically synched to taxonomy
terms in a selected vocabulary 'DC Description Types'. The term pages in the vocabulary are
customised to allow different view modes for each format, e.g. an audio teaser for 'Audio' listings,
image teaser for 'Photographs', regular teaser for 'Essays' etc.


How does it do it?
------------------

Overrides Drupal's core taxonomy term view if certain criteria are met using a combination of
Views Content and Page Manager, both provided by Chaos Tools, and the Panels and Views modules.
The parent 'Browse by format' menu item is created with Drupal core's menu system and it's child
menu items are created by synching with the 'DC Description Types' vocabulary terms using the
Taxonomy Menu module.


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

4. If using teaser view modes, select the fields you want to display in them
   /admin/structure/types/manage/dspaced-entities-item/display.

   Teaser view modes are provided by the 'HPS Defaults' Feature and what fields you display in
   them can be configured in the content type display manager.

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

