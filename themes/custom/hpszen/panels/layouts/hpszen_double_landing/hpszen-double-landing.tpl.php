<?php
/**
 * @file
 * Template for the HPS Zen responsive double landing layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - introduction
 *   - featured
 *   - content
 *   - aside
 */
?>
<div class="panel-hpszen-introduction">
  <div class="section">
    <?php print $content['introduction']; ?>
  </div>
</div>
<div class="panel-hpszen-featured">
  <div class="section">
    <?php print $content['featured']; ?>
  </div>
</div>
<div class="section">
  <div class="panel-hpszen-content">
    <?php print $content['content']; ?>
  </div>
  <div class="panel-hpszen-aside">
    <?php print $content['aside']; ?>
  </div>
</div>

