<?php
/**
 * @file
 * Template for the HPS Zen responsive basic 2 layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - b1
 *   - b2
 */
?>
<div id="basic" class="basic">
  <div class="bucket basic__bucket">
    <div id="basic__one" class="panel basic__panel">
      <?php print $content['b1']; ?>
    </div>
    <div id="basic__two" class="panel basic__panel">
      <?php print $content['b2']; ?>
    </div>
  </div>
</div>
