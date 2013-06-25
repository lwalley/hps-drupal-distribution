<?php
/**
 * @file
 * Template for the HPS Zen responsive introduction 1, basic 3 layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - i1
 *   - b1
 *   - b2
 *   - b3
 */
?>
<div id="introduction">
  <div class="section">
    <div id="panel-hpszen-i1" class="panel">
      <?php print $content['i1']; ?>
    </div>
  </div>
</div>
<div id="basic">
  <div class="section">
    <div id="panel-hpszen-b1" class="panel">
      <?php print $content['b1']; ?>
    </div>
    <div id="panel-hpszen-b2" class="panel">
      <?php print $content['b2']; ?>
    </div>
    <div id="panel-hpszen-b3" class="panel">
      <?php print $content['b3']; ?>
    </div>
  </div>
</div>
