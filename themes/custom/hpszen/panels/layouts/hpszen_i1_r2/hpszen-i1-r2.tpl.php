<?php
/**
 * @file
 * Template for the HPS Zen responsive introduction 1, results 2 layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - i1
 *   - r1
 *   - r2
 */
?>
<div id="introduction">
  <div class="section">
    <div id="panel-hpszen-i1" class="panel">
      <?php print $content['i1']; ?>
    </div>
  </div>
</div>
<div id="results">
  <div class="section">
    <div id="panel-hpszen-r1" class="panel">
      <?php print $content['r1']; ?>
    </div>
    <div id="panel-hpszen-r2" class="panel">
      <?php print $content['r2']; ?>
    </div>
  </div>
</div>
