<?php
/**
 * @file
 * Template for the HPS Zen responsive introduction 1, featured 1, basic 3 layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - i1
 *   - f1
 *   - b1
 *   - b2
 *   - b3
 */
?>
<div id="introduction" class="introduction">
  <div class="bucket introduction__bucket">
    <div id="introduction__one" class="introduction__one panel introduction__panel">
      <?php print $content['i1']; ?>
    </div>
  </div>
</div>
<div id="featured" class="featured">
  <div class="bucket featured__bucket">
    <div id="featured__one" class="featured__one panel featured__panel">
      <?php print $content['f1']; ?>
    </div>
  </div>
</div>
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
