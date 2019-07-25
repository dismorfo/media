<div
  id="<?php print $identifier ?>"
  class="flowplayer"
  data-title="<?php print $identifier ?>"
  data-duration="<?php print $duration ?>"
  data-start="<?php print $start ?>"
  data-share="<?php print $share ?>"
  data-key="<?php print $key ?>"
  <?php if ($type == 'audio') : ?>data-audio-only="true"<?php endif ?>
  data-fullscreen="true">
  <video poster="<?php print $poster ?>">
    <source type="application/x-mpegurl" src="<?php print $m3u ?>">
    <?php if (isset($captions)) : ?>
      <?php foreach ($captions as $caption) : ?>
        <track kind="<?php print $caption['kind'] ?>" srclang="<?php print $caption['srclang'] ?>" label="<?php print $caption['label'] ?>" src="<?php print $caption['src'] ?>" <?php if (isset($caption['kind']) && ($caption['default'])) : ?>default<?php endif ?>>
      <?php endforeach ?>
    <?php endif ?>
  </video>
</div>
