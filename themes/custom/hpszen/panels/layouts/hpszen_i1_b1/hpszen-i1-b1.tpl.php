<?php
/**
 * @file
 * Template for the HPS Zen responsive introduction 1, basic 1 layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - i1
 *   - b1
 */
?>
<div id="introduction" class="introduction">
  <div class="bucket" class="introduction__bucket">
    <div id="introduction__one" class="panel introduction__panel">
      <?php print $content['i1']; ?>
    </div>
  </div>
</div>
<div id="basic" class="basic">
  <div class="bucket basic__bucket">
    <div id="basic__one" class="panel basic__panel">
      <?php print $content['b1']; ?>
    </div>
  </div>
</div>
