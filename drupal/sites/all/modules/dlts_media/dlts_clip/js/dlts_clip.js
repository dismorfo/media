(function($) {
  function attach() {
    if (window.flowplayer) {
      /* eslint-disable-next-line no-undef */
      flowplayer.conf = {
        share: false,
        // See https://jira.nyu.edu/jira/browse/DLTSVIDEO-120
        // See https://flowplayer.com/help/player/flowplayer-7/setup#splash
        // Splash contradicts autoplay and takes precendence if
        // you configure both.
        splash: true
      };
      // https://flowplayer.com/help/player/flowplayer-7/api.html
      /* eslint-disable-next-line no-undef */
      flowplayer(function(api, root) {
        var parent = $(root);
        var controls = parent.find('.fp-controls');
        parent
          .find('.fp-next')
          .clone()
          .appendTo(controls);
        parent
          .find('.fp-prev')
          .clone()
          .appendTo(controls);

        $('.fp-playlist a').click(function() {
          parent.attr({
            'data-start': $(this).attr('data-start'),
            'data-duration': $(this).attr('data-duration')
          });
        });

        api.on('finish', function(e, api) {
          // all players go to splash state on finish
          // https://demos.flowplayer.com/lookandfeel/splash-on-finish.html
          api.unload();
        });

        // When the video is fully loaded and video metadata (such as duration) becomes
        // available from the video object which is provided by the 3rd argument.
        api.on('ready', function(e, api, media) {
          // find the playlist element in the DOM
          var isPlaylist = $('.fp-playlist');
          // placeholder for the clip that fire "load" event
          var clipElement = undefined;
          // the start  position in (seconds) of the video
          var currentItemStartPosition = 0;
          // check if we have a playlist
          if (isPlaylist.length) {
            // See https://flowplayer.com/help/player/flowplayer-7/playlists
            // information about the current clip available in the playlist array
            // we can find the item using ${media.index}
            clipElement = $(isPlaylist.find('a').get(media.index));
          } else {
            // Single item (clip)
            clipElement = $('.flowplayer');
          }
          // test if we have a clip
          if (clipElement.length) {
            // make sure we don't set start at a incoherent position
            currentItemStartPosition =
              Math.round(parseFloat(clipElement.attr('data-start')) * 10) / 10;
          }
          if (currentItemStartPosition < media.duration) {
            api.seek(currentItemStartPosition);
          }
        });

        api.on('load', function(e, api, media) {
          // find the playlist element in the DOM
          var isPlaylist = $('.fp-playlist');
          // placeholder for the clip that fire "load" event
          var clipElement = undefined;
          // Check if we have a playlist
          if (isPlaylist.length) {
            // See https://flowplayer.com/help/player/flowplayer-7/playlists
            // information about the current clip available in the playlist array
            // we can find the item using ${media.index}
            clipElement = $(isPlaylist.find('a').get(media.index));
            if (clipElement) {
              // set media.subtitles attribute (close captions) if available.
              media.subtitles = JSON.parse(clipElement.attr('data-captions'));
            }
          }
          // Single item (clip)
          else {
            clipElement = $('.flowplayer');
            if (clipElement.length) {
              try {
                // set media.subtitles attribute (close captions) if available.
                media.subtitles = JSON.parse(clipElement.attr('data-captions'));
              } catch (error) {
                console.error(error); /* eslint-disable-line no-console */
              }
            }
          }
        });

        api.on('beforeseek', function(e, api, target) {
          var start = $(parent).attr('data-start');
          var duration = $(parent).attr('data-duration');
          // console.log(`beforeseek start at ${start} and the duration ${duration}`)
          // prevent seeking before start position
          if (target < start) {
            // console.log(`Prevent seeking before start position at ${start}`)
            e.preventDefault();
          }
          // prevent seeking after duration position
          if (duration > 0 && target > duration) {
            // console.log(`Prevent seeking after duration ${duration}`)
            e.preventDefault();
          }
        });
      });
    }
  }

  Drupal.behaviors.dlts_clip = { attach: attach }; /* eslint-disable-line no-undef */
})(jQuery); /* eslint-disable-line no-undef */
