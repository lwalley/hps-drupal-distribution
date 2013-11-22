<?php
/**
 * @file
 * Template for the HPS Zen responsive basic 3 layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - b1
 *   - b2
 *   - b3
 */
?>
<div id="basic" class="basic">
  <div class="bucket basic__bucket">
    <div id="basic__one" class="basic__one panel basic__panel">
      <?php print $content['b1']; ?>
    </div>
    <div id="basic__two" class="basic__two panel basic__panel">
      <?php print $content['b2']; ?>
    </div>
    <div id="basic__three" class="basic__three panel basic__panel">
      <?php print $content['b3']; ?>
    </div>
  </div>
</div>
