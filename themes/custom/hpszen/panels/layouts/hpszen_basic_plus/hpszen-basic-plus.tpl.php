<?php
/**
 * @file
 * Template for the HPS Zen responsive basic layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - introduction
 *   - content
 */
?>
<div class="panel-hpszen-introduction">
  <div class="section">
    <?php print $content['introduction']; ?>
  </div>
</div>
<div class="panel-hpszen-content">
  <div class="section">
    <?php print $content['content']; ?>
  </div>
</div>

