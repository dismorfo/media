<style><?php print $style ?></style>
<div 
  id="<?php print $identifier ?>"
  class="dlts_playlist flowplayer is-splash"
  data-title="<?php print $identifier ?>"
  data-duration="<?php print $duration ?>" 
  data-start="<?php print $start ?>" 
  data-fullscreen="true"
  data-type="<?php print $type ?>"
  data-share="<?php print $share ?>"
  data-key="<?php print $key ?>"  
  <?php if ($type == 'audio') : ?>data-audio-only="true"<?php endif ?>
  >
 <!-- initial clip -->
  <video poster="<?php print $poster ?>">
    <source type="application/x-mpegurl" src="<?php print $m3u ?>">
  </video>
  <!-- playlist root -->
  <div class="fp-playlist">
    <?php print $links ?>
  </div>
  <!-- optional prev/next buttons -->
  <a class="fp-prev" title="prev"></a>
  <a class="fp-next" title="next"></a> 
</div>
