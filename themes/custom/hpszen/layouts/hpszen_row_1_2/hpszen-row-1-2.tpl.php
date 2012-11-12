<?php
/**
 * @file
 * Template for the HPS Zen responsive single column panel layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - row-1-1: The first column's content.
 *   - row-1-2: The second column's content.
 */
?>
<div class="panel-hpszen-row-1-1">
  <?php print $content['row-1-1']; ?>
</div>
<div class="panel-hpszen-row-1-2">
  <?php print $content['row-1-2']; ?>
</div>

