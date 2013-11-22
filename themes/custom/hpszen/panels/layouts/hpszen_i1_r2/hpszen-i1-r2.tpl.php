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
<div id="introduction" class="introduction">
  <div class="bucket introduction__bucket">
    <div id="introduction__one" class="introduction__one panel introduction__panel">
      <?php print $content['i1']; ?>
    </div>
  </div>
</div>
<div id="results" class="results">
  <div class="bucket results__bucket">
    <div id="results__one" class="results__one panel panel__results">
      <?php print $content['r1']; ?>
    </div>
    <div id="results__two" class="results__two panel panel__results">
      <?php print $content['r2']; ?>
    </div>
  </div>
</div>
