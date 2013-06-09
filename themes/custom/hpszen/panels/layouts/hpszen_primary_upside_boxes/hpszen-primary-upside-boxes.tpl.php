<?php
/**
 * @file
 * Template for the HPS Zen responsive two boxes layout with aside first.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - primary-box: The primary content.
 *   - upside-box: The aside content. Note appears first in document flow.
 */
?>
<div class="panel-hpszen-upside-box">
  <?php print $content['upside-box']; ?>
</div>
<div class="panel-hpszen-primary-box">
  <?php print $content['primary-box']; ?>
</div>
