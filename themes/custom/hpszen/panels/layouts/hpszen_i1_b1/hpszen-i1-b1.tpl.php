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
  </div>
</div>
