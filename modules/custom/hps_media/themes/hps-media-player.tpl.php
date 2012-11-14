<?php
/**
 * @file
 * hps-media-player.tpl.php
 *
 * Available variables:
 * - $element: hps_media_player element
 *
 * .. and some others
 *
 */
?>
<div id="<?php print $element['#id']; ?>" class="<?php print $classes ?>"></div>
<script type="text/javascript">
  jwplayer('<?php print $element['#id']; ?>').setup({
    'file':        '<?php print $element['#url']; ?>',
  });
</script>
