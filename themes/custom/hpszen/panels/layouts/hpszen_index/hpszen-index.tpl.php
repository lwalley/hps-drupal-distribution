<?php
/**
 * @file
 * Template for the HPS Zen responsive index layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - introduction
 *   - content
 *   - aside
 */
?>
<div class="panel-hpszen-introduction">
  <div class="section">
    <?php print $content['introduction']; ?>
  </div>
</div>
<div class="section">
  <div class="panel-hpszen-operations">
    <?php print $content['operations']; ?>
  </div>
  <div class="panel-hpszen-results">
    <?php print $content['results']; ?>
  </div>
</div>
