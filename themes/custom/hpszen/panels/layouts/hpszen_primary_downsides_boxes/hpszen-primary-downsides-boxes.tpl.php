<?php
/**
 * @file
 * Template for the HPS Zen responsive two boxes layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - primary-box: The primary content.
 *   - aside-box: The aside content.
 *   - downside-box: Another aside content.
 */
?>
<div class="panel-hpszen-primary-box">
  <?php print $content['primary-box']; ?>
</div>
<div class="panel-hpszen-aside-box">
  <?php print $content['aside-box']; ?>
</div>
<div class="panel-hpszen-downside-box">
  <?php print $content['downside-box']; ?>
</div>
