<?php

/**
 * Enable/disable plugins
 * http://flowplayer.org/documentation/configuration/
 */
function dlts_clip_player_flowplayer_config($form, &$form_state) {

  module_load_include('inc', 'dlts_clip', 'inc/flowplayer');

  $available_flow_plugins_flash = dlts_clip_available_flowplayer_plugins_flash () ;

  $isCommercial = FALSE;

  $versions = array();

  $flowplayer_javascript_api = array();

  $default = dlts_clip_default_flowplayer_configuration();

  $saved_config = variable_get( 'dlts_bitstream_globals_flowplayer');

  $config = unserialize ( $saved_config );

  $selected_flowplayer_version = ( isset( $config['flowplayer']['player']['version'])) ? $config['flowplayer']['player']['version'] : $default['flowplayer']['player']['version'];

  $selected_flowplayer_javascript_api = ( isset( $config['flowplayer']['player']['js_api'])) ? $config['flowplayer']['player']['js_api'] : $default['flowplayer']['player']['js_api'];

  foreach ( dlts_clip_flowplayer_available_flowplayer() as $value ) {
    $versions += array( $value['url'] => $value['filename']);
  	if ( isset( $value['type'] ) && $value['type'] == 'commercial' && ( $value['url'] == $selected_flowplayer_version ) ) $isCommercial = TRUE;
  }

  foreach ( dlts_clip_flowplayer_available_flowplayer_javascript_api() as $file => $value ) $flowplayer_javascript_api += array ( $value['url'] => $file );

  $form['dlts_bitstream_globals_flowplayer'] = array('#type' => 'hidden', '#value' => $saved_config );

  $form['flowplayer'] = array(
    '#type' => 'fieldset',
    '#title' => t('Flowplayer'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );

  $form['flowplayer']['dlts_bitstream_flowplayer_version'] = array(
    '#type' => 'radios',
    '#title' => t('Player'),
    '#default_value' => (isset($config['flowplayer']['player']['version'])) ? $config['flowplayer']['player']['version'] : $default['flowplayer']['player']['version'],
    '#options' => $versions,
  );

  $form['flowplayer']['dlts_bitstream_flowplayer_js_api'] = array(
    '#type' => 'radios',
    '#title' => t('Javascript API'),
    '#default_value' => (isset($config['flowplayer']['player']['js_api'])) ? $config['flowplayer']['player']['js_api'] : $default['flowplayer']['player']['js_api'],
    '#options' => $flowplayer_javascript_api,
  );

  $form['flowplayer']['dlts_bitstream_flowplayer_commercial_key'] = array (
    '#type' => ( ( $isCommercial ? FALSE : TRUE ) ? 'hidden' : 'textfield' ),
    '#title' => t('Commercial Key'),
    '#default_value' => ( ( $isCommercial ? FALSE : TRUE ) ? '' : ( isset ( $config['flowplayer']['player']['commercial_key'] ) ) ? $config['flowplayer']['player']['commercial_key'] :  '#$623666ca2f667514416' ),
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('The key to enable the use of the commercial version of the player'),
  );

  /**
   * Plugins
   */

  $form['flowplayer']['plugins'] = array(
    '#type' => 'item',
    '#title' => t('Plugins'),
  );

  $form['flowplayer']['dlts_bitstream_flowplayer_plugins_audio'] = array(
    '#type' => 'checkbox',
    '#title' => t('Audio'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['audio']['enabled'])) ? $config['flowplayer']['player']['plugins']['audio']['enabled'] : $default['flowplayer']['player']['plugins']['audio']['enabled'],
  );

  $form['flowplayer']['dlts_bitstream_flowplayer_plugins_bwcheck'] = array(
    '#type' => 'checkbox',
    '#title' => t('Bandwidth detection'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['enabled'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['enabled'] : $default['flowplayer']['player']['plugins']['bwcheck']['enabled'],
  );

  $form['flowplayer']['dlts_bitstream_flowplayer_plugins_controls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Controlbar'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['enabled'])) ? $config['flowplayer']['player']['plugins']['controls']['enabled'] : $default['flowplayer']['player']['plugins']['controls']['enabled'],
  );

  $form['flowplayer']['dlts_bitstream_flowplayer_plugins_rtmp'] = array(
    '#type' => 'checkbox',
    '#title' => t('Streaming RTMP'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['enabled'])) ? $config['flowplayer']['player']['plugins']['rtmp']['enabled'] : $default['flowplayer']['player']['plugins']['rtmp']['enabled'],
  );

  /**
   * Audio plugin options
   * http://flowplayer.org/plugins/streaming/audio.html
   */
  $form['audio'] = array(
    '#type' => 'fieldset',
    '#title' => t('Audio'),
    '#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['audio']['enabled'])) ? $config['flowplayer']['player']['plugins']['audio']['enabled'] : $default['flowplayer']['player']['plugins']['audio']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
    '#collapsible' => TRUE,
  );

  /**
   * Bandwidth Detection plugin options
   * http://flowplayer.org/plugins/streaming/bwcheck.html
   */
  $form['bwcheck'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bandwidth Detection'),
    '#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['bwcheck']['enabled'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['enabled'] : $default['flowplayer']['player']['plugins']['bwcheck']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
    '#collapsible' => TRUE,
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_bitrateProfileName'] = array(
    '#type' => 'textfield',
    '#title' => t('Bitrate Profile Name'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['bitrateProfileName'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['bitrateProfileName'] : $default['flowplayer']['player']['plugins']['bwcheck']['bitrateProfileName'],
    '#size' => 20,
    '#maxlength' => 100,
    '#description' => t('Used when detected bandwidth values are remembered (see the rememberBitrate setting). This is the name of the Shared Object where the bitrates are saved. You might want to change this if you have different sets of files and you want to keep the detected bandwidths separate for those sets.'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_checkOnStart'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check on Start'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['checkOnStart'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['checkOnStart'] : $default['flowplayer']['player']['plugins']['bwcheck']['checkOnStart'],
    '#description' => t('Set this to true if you want to perform an initial bwcheck with RTMP. This way the playback can be started automatically with a bitrate based on this initial check. Relying completely on bitrate monitoring and dynamic bitrate switching might be a bit slower to adjust to the best bitrate. If you set this to true, make sure your RTMP server has the bwchecker application installed (Wowza does not have it installed by default).'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_dynamic'] = array(
    '#type' => 'checkbox',
    '#title' => t('Dynamic'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['dynamic'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['dynamic'] : $default['flowplayer']['player']['plugins']['bwcheck']['dynamic'],
    '#description' => t('Enables dynamic stream switching (Quality Of Service monitoring) for Adobe Flash Media Server 3 and Wowza Media Server 2.'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_dynamicBuffer'] = array(
    '#type' => 'checkbox',
    '#title' => t('Dynamic buffer'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['dynamicBuffer'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['dynamicBuffer'] : $default['flowplayer']['player']['plugins']['bwcheck']['dynamicBuffer'],
    '#description' => t('When enabled, this feature will dynamically calculate the best buffer time to suit the available bandwidth.'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_live'] = array(
    '#type' => 'checkbox',
    '#title' => t('Live'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['live'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['live'] : $default['flowplayer']['player']['plugins']['bwcheck']['live'],
    '#description' => t('Set this to true with live streams.'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_netConnectionUrl'] = array(
    '#type' => 'textfield',
    '#title' => t('Net Connection Url'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['netConnectionUrl'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['netConnectionUrl'] : $default['flowplayer']['player']['plugins']['bwcheck']['netConnectionUrl'],
    '#size' => 50,
    '#maxlength' => 256,
    '#description' => t('The URL used to check the bandwidth. For HTTP-based checking, this should point to a reference file that is loaded as part of the check. The file should reside on the same host as the plugin, or it will require domain context policies for remote loading of the file to prevent sandbox issues. For RTMP this should be a RMTP url pointing to a streaming server.'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_rememberBitrate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remember bitrate'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['rememberBitrate'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['rememberBitrate'] : $default['flowplayer']['player']['plugins']['bwcheck']['rememberBitrate'],
    '#description' => t('Indicates whether the detected bandwidth should be remembered for the client browser. If true the detection is performed only once per domain and stored on the client browser. If false the detection is done every time a clip starts playing.'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_serverType'] = array(
    '#type' => 'select',
    '#title' => t('Server type'),
    '#options' => array('http' => 'HTTP', 'red5' => 'RED5', 'wowza' => 'WOWZA', 'fms' => 'Flash Media Server'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['serverType'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['serverType'] : $default['flowplayer']['player']['plugins']['bwcheck']['serverType'],
    '#description' => t('Identifies the type of server that we will be checking against. Available values are http, red5, wowza, and Flash Media Server (fms).'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_switchOnFullscreen'] = array(
    '#type' => 'checkbox',
    '#title' => t('Switch on Fullscreen'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['switchOnFullscreen'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['switchOnFullscreen'] : $default['flowplayer']['player']['plugins']['bwcheck']['switchOnFullscreen'],
    '#description' => t('Used when dynamic is set to false. Causes a bandwidth check and a switch when entering fullscreen or exiting fullscreen. When dynamic is set to true the plugin is doing QoS monitoring and switching dynamically if needed, also taking care the screen resize that happens with fullscreen mode.'),
  );

  $form['bwcheck']['dlts_bitstream_flowplayer_plugins_bwcheck_hdButton'] = array(
    '#type' => 'select',
    '#title' => t('HD Button'),
    '#options' => array('dock' => 'dock', 'controls' => 'controls', 'both' => 'both'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['bwcheck']['hdButton'])) ? $config['flowplayer']['player']['plugins']['bwcheck']['hdButton'] : $default['flowplayer']['player']['plugins']['bwcheck']['hdButton'],
    '#description' => t('Should the HD selection button be visible?.'),
  );

  /**
   * Controls plugin options
   * http://flowplayer.org/plugins/flash/controlbar.html
   */
  $form['controls'] = array(
    '#type' => 'fieldset',
    '#title' => t('Controls'),
    '#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['controls']['enabled'])) ? $config['flowplayer']['player']['plugins']['controls']['enabled'] : $default['flowplayer']['player']['plugins']['controls']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
    '#collapsible' => TRUE,
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_autoHide'] = array(
    '#type' => 'select',
    '#title' => t('Auto Hiding'),
    '#options' => array('always' => 'always', 'fullscreen' => 'fullscreen', 'never' => 'never'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['autoHide'])) ? $config['flowplayer']['player']['plugins']['controls']['autoHide'] : $default['flowplayer']['player']['plugins']['controls']['autoHide'],
    '#description' => t('The controlbar can be made to automatically hide if the user is not actively using the player.'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_play'] = array(
    '#type' => 'checkbox',
    '#title' => t('Play Button'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['play'])) ? $config['flowplayer']['player']['plugins']['controls']['play'] : $default['flowplayer']['player']['plugins']['controls']['play'],
    '#description' => t('Should the play/pause button be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_volume'] = array(
    '#type' => 'checkbox',
    '#title' => t('Volume Control'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['volume'])) ? $config['flowplayer']['player']['plugins']['controls']['volume'] : $default['flowplayer']['player']['plugins']['controls']['volume'],
    '#description' => t('Should the volume control be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_mute'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mute Button'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['mute'])) ? $config['flowplayer']['player']['plugins']['controls']['mute'] : $default['flowplayer']['player']['plugins']['controls']['mute'],
    '#description' => t('Should the mute button be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_time'] = array(
    '#type' => 'checkbox',
    '#title' => t('Time'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['time'])) ? $config['flowplayer']['player']['plugins']['controls']['time'] : $default['flowplayer']['player']['plugins']['controls']['time'],
    '#description' => t('Should the time display be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_stop'] = array(
    '#type' => 'checkbox',
    '#title' => t('Stop Button'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['stop'])) ? $config['flowplayer']['player']['plugins']['controls']['stop'] : $default['flowplayer']['player']['plugins']['controls']['stop'],
    '#description' => t('Should the stop button be visible?'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_playlist'] = array(
    '#type' => 'checkbox',
    '#title' => t('Playlist Buttons'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['playlist'])) ? $config['flowplayer']['player']['plugins']['controls']['playlist'] : $default['flowplayer']['player']['plugins']['controls']['playlist'],
    '#description' => t('Should the playlist buttons be visible? The playlist buttons allow navigation through the playlist entries of the current playlist. These buttons are always hidden if there are less than two entries in the playlist.'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_fastBackward'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fast Backward Button'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['fastBackward'])) ? $config['flowplayer']['player']['plugins']['controls']['fastBackward'] : $default['flowplayer']['player']['plugins']['controls']['fastBackward'],
    '#description' => t('Should the fast backward button be visible? The slow motion buttons allow controlling the playback speed (from 1/8 to 8x the normal speed). These buttons are always hidden if the slowmotion plugin is not loaded, and only available with the "Modern" skin.'),
  );

  $form['controls']['dlts_bitstream_flowplayer_plugins_controls_fastForward'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fast Forward Button'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['controls']['fastForward'])) ? $config['flowplayer']['player']['plugins']['controls']['fastForward'] : $default['flowplayer']['player']['plugins']['controls']['fastForward'],
    '#description' => t('Should the fast forward button be visible?'),
  );

  /**
   * RTMP plugin options
   * http://flowplayer.org/plugins/streaming/rtmp.html
   */
  $form['rtmp'] = array(
    '#type' => 'fieldset',
    '#title' => t('RTMP Plugin'),
    '#collapsed' => ( ( ( isset($config['flowplayer']['player']['plugins']['rtmp']['enabled'])) ? $config['flowplayer']['player']['plugins']['rtmp']['enabled'] : $default['flowplayer']['player']['plugins']['rtmp']['enabled'] ? 0 : 1 ) ? TRUE : FALSE ),
    '#collapsible' => TRUE,
  );

  $form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_netConnectionUrl'] = array(
    '#type' => 'textfield',
    '#title' => t('FlowPlayer Net Connection URL'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['netConnectionUrl'])) ? $config['flowplayer']['player']['plugins']['rtmp']['netConnectionUrl'] : $default['flowplayer']['player']['plugins']['rtmp']['netConnectionUrl'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The RTMP URL used to connect to the server app. This is optional and you can also specify this in the clip, so that the different clips in the playlist point to different servers.'),
  );

  $form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_objectEncoding'] = array(
    '#type' => 'textfield',
    '#title' => t('Object Encoding'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['objectEncoding'])) ? $config['flowplayer']['player']['plugins']['rtmp']['objectEncoding'] : $default['flowplayer']['player']['plugins']['rtmp']['objectEncoding'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The object encoding used with the streaming server. Change this to a value of 0 if you need to communicate to servers released prior to Flash Player 9 (Adobe Flash Media Server 2).'),
  );

  $form['rtmp']['dlts_bitstream_flowplayer_plugins_rtmp_proxyType'] = array(
    '#type' => 'select',
    '#title' => t('Proxy Type'),
    '#options' => array('none' => 'none', 'HTTP' => 'HTTP', 'CONNECT' => 'CONNECT', 'best' => 'best'),
    '#default_value' => (isset($config['flowplayer']['player']['plugins']['rtmp']['proxyType'])) ? $config['flowplayer']['player']['plugins']['rtmp']['proxyType'] : $default['flowplayer']['player']['plugins']['rtmp']['proxyType'],
    '#description' => t('The proxyType determines which fallback methods are tried if an initial connection attempt to the server fails. Flowplayer establishes the connection by doing parallel connection attempts using RTMP and RTMPT. The one that succeeds first is used and the other one is discarded - this way the connection is established as fast as possible in firewalled and proxied network environments.'),
  );

  /**
   * Clips
   * http://flowplayer.org/documentation/configuration/clips.html
   */
  $form['clip'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clip Settings'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_accelerated'] = array(
    '#type' => 'checkbox',
    '#title' => t('Accelerated'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['accelerated'] ) ) ? $config['flowplayer']['clip']['accelerated'] : $default['flowplayer']['clip']['accelerated'],
    '#description' => t('Flag indicating whether Flash 9 (and above) hardware-accelerated full screen mode should be used.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_autoBuffering'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto Buffering'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['autoBuffering'] ) ) ? $config['flowplayer']['clip']['autoBuffering'] : $default['flowplayer']['clip']['autoBuffering'],
    '#description' => t('Flag indicating whether loading of clip into player\'s memory should begin straight away. When this is true and autoPlay is false then the clip will automatically stop at first frame of the video.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_autoPlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Autoplay'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['autoPlay'] ) ) ? $config['flowplayer']['clip']['autoPlay'] : $default['flowplayer']['clip']['autoPlay'],
    '#description' => t('Flag indicating whether the player should start playback immediately upon loading.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_baseUrl'] = array(
    '#type' => 'textfield',
    '#title' => t('Base Url'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['baseUrl'] ) ) ? $config['flowplayer']['clip']['baseUrl'] : $default['flowplayer']['clip']['baseUrl'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The first part of the URL of the video\'s location. This property is prepended in front of the url property (for relative URLs). If not specified, the video file is loaded from the same directory as the enclosing HTML file.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_bufferLength'] = array(
    '#type' => 'textfield',
    '#title' => t('Buffer Length'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['bufferLength'] ) ) ? $config['flowplayer']['clip']['bufferLength'] : $default['flowplayer']['clip']['bufferLength'],
    '#size' => 5,
    '#maxlength' => 5,
    '#description' => t('The amount of video data (in seconds) which should be loaded into Flowplayer\'s memory in advance of playback commencing.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_cuepointMultiplier'] = array(
    '#type' => 'textfield',
    '#title' => t('Cuepoint Multiplier'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['cuepointMultiplier'] ) ) ? $config['flowplayer']['clip']['cuepointMultiplier'] : $default['flowplayer']['clip']['cuepointMultiplier'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The times of embedded cuepoints are multiplied by this value before being used. Some encoding tools embed cuepoints in seconds but Flowplayer processes cuepoints in milliseconds. Note that the times are also rounded to the nearest 100 milliseconds. For example, if a file has a cuepoint at 5.535 seconds, the cuepoint is fired at 5500 milliseconds (assuming the default multiplier value of 1000).'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_start'] = array(
    '#type' => 'textfield',
    '#title' => t('Start'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['start'] ) ) ? $config['flowplayer']['clip']['start'] : $default['flowplayer']['clip']['start'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The time (in seconds) at which playback should commence. This is only supported when you have a streaming server.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Duration'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['duration'] ) ) ? $config['flowplayer']['clip']['duration'] : $default['flowplayer']['clip']['duration'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('The time, in seconds and fractions of a second, for which a video clip should be played until playback ceases. This must always be less than or equal to the total length of the clip. Zero means to play the whole clip.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_fadeInSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade In Speed'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['fadeInSpeed'] ) ) ? $config['flowplayer']['clip']['fadeInSpeed'] : $default['flowplayer']['clip']['fadeInSpeed'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('Time in milliseconds to fade from zero to full opacity upon commencement of video playback.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_fadeOutSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Fade Out Speed'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['fadeOutSpeed'] ) ) ? $config['flowplayer']['clip']['fadeOutSpeed'] : $default['flowplayer']['clip']['fadeOutSpeed'],
    '#size' => 50,
    '#maxlength' => 200,
    '#description' => t('Time in milliseconds to fade from full to zero opacity upon completion of video playback.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_live'] = array(
    '#type' => 'checkbox',
    '#title' => t('Live'),
    '#default_value' => ( isset( $config['flowplayer']['clip']['live'] ) ) ? $config['flowplayer']['clip']['live'] : $default['flowplayer']['clip']['live'],
    '#description' => t('RTMP streaming servers support live streaming, which means that it is possible to setup a video camera or other live video source to stream live video data to Flowplayer. If you have an RTMP server which is providing a live video stream, you should set this property to true.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_provider'] = array(
    '#type' => 'select',
    '#title' => t('Provider'),
    '#options' => array(
      'http' => 'HTTP',
      'rtmp' => 'RTPM',
    ),
    '#default_value' => ( isset( $config['flowplayer']['clip']['provider'] ) ) ? $config['flowplayer']['clip']['provider'] : $default['flowplayer']['clip']['provider'],
    '#description' => t('Sets a connection provider to be used for clips. Connection providers can be used to create a connection to a streaming server or to a CDN network. The value of this property *should* be the name of a configured plugin.'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_bitrate'] = array(
    '#type' => 'textfield',
    '#title' => t('Clip bitrate'),
    '#size' => 50,
    '#maxlength' => 200,
    '#default_value' => ( isset( $config['flowplayer']['clip']['bitrate'] ) ) ? $config['flowplayer']['clip']['bitrate'] : $default['flowplayer']['clip']['bitrate'],
    '#description' => t('The default bitrate for all clips'),
  );

  $form['clip']['dlts_bitstream_flowplayer_clip_scaling'] = array(
    '#type' => 'select',
    '#title' => t('Scaling'),
    '#options' => array(
      'fit' => 'Fit',
      'half' => 'Half',
      'orig' => 'Original',
      'scale' => 'Scale'
    ),
    '#default_value' => ( isset( $config['flowplayer']['clip']['scaling'] ) ) ? $config['flowplayer']['clip']['scaling'] : $default['flowplayer']['clip']['scaling'],
  );

  $form['flash'] = array(
  		'#type' => 'fieldset',
  		'#title' => t('Flash settings'),
  		'#collapsed' => FALSE,
  		'#collapsible' => FALSE,
  );

  $form['flash']['dlts_bitstream_flash_disableError'] = array(
  		'#type' => 'textarea',
  		'#title' => t('Flash disable error message'),
  		'#default_value' => variable_get( 'dlts_bitstream_flash_disableError', dlts_clip_default_flash_disable_error() ),
  		'#description' => t('Error message to be display when Flash plugin is disable or installed.'),
  );

  return system_settings_form($form);
}

/**
 * Form validation
 *
 * Now we add a handler/function to validate the data If not, it displays an error.
 * The value report is $form_state['values'] (see http://drupal.org/node/144132#form-state).
 *
 * Notice the name of the function. It is simply the name of the form
 * followed by '_validate'. This is always the name of the default validation
 * function. An alternate list of validation functions could have been provided
 * in $form['#validate'].
 *
 */
function dlts_clip_player_flowplayer_config_validate($form, &$form_state) {

  $form_state['values']['dlts_bitstream_flash_disableError'] = filter_xss($form_state['values']['dlts_bitstream_flash_disableError'], array('a', 'em', 'strong', 'h1', 'h2', 'h3', 'h4', 'h5', 'p' ) );

  $config = array(
    'player' => array(
      'url' => $form_state['values']['dlts_bitstream_flowplayer_version'],
      'flash' => array(
        'errorMessage' => $form_state['values']['dlts_bitstream_flash_disableError'],
      ),
    )
  );

  if ( !empty( $form_state['values']['dlts_bitstream_flowplayer_commercial_key'] ) ) {
    $config['player']['key'] = $form_state['values']['dlts_bitstream_flowplayer_commercial_key'];
  }

  if ( !empty( $form_state['values']['dlts_bitstream_flowplayer_version'] ) ) {
  	$config['player']['version'] = $form_state['values']['dlts_bitstream_flowplayer_version'];
  }

  if ( !empty( $form_state['values']['dlts_bitstream_flowplayer_js_api'] ) ) {
    $config['player']['js_api'] = $form_state['values']['dlts_bitstream_flowplayer_js_api'];
  }

  /**
   * Available Flowplayer plugins (flash). Used to provide the plugin location
   */

  $available_flow_plugins_flash = dlts_clip_available_flowplayer_plugins_flash();

  foreach ( $form_state['values'] as $key => $value ) {

    /** Plugin enabled? */
    if ( preg_match('/dlts_bitstream_flowplayer_plugins_([a-zA-Z]*)$/', $key, $plugin ) && $value ) {

      if ( ! isset( $config['player']['plugins'] ) ) $config['player']['plugins'] = array();

      if ( ! isset( $config['player']['plugins'][$plugin[1]] ) ) $config['player']['plugins'][$plugin[1]] = array();

      $config['player']['plugins'][$plugin[1]]['enabled'] = TRUE;

      /**
       * Plug-ins don't live in the same location as the JS caller, we need to provide the
       * URL parameter for each plugin.
       */
      $config['player']['plugins'][$plugin[1]]['url'] = $available_flow_plugins_flash[$plugin[1]];

    }

  	/** Plugins */
    if (
      preg_match('/dlts_bitstream_flowplayer_plugins_([a-zA-Z]*)_([a-zA-Z]*)$/', $key, $matches )
    ) {

      /**
       * Config as pair of keys and values:
       *   $matches[1] = plugin name
       *   $matches[2] = plugin parameter
       *   $value = parameter value
       */
      if ( isset( $config['player']['plugins'][$matches[1]] ) && $config['player']['plugins'][$matches[1]]['enabled'] ) $config['player']['plugins'][$matches[1]][$matches[2]] = $value;
    }

    /** Clip */
    if ( preg_match('/dlts_bitstream_flowplayer_clip_([a-zA-Z]*)$/', $key, $matches )  ) {
      if ( isset( $form_state['values']['dlts_bitstream_flowplayer_clip_' . $matches[1] ] ) && $form_state['values']['dlts_bitstream_flowplayer_clip_' . $matches[1]] !== '' ) {
        $config['clip'][$matches[1]] = $value;
      }
    }

    /** Remove anything that match dlts_bitstream from $form_state['values']; later on we will add a serialize version of $config as a variable */
    if ( preg_match('/dlts_bitstream/', $key, $input ) && !empty( $input ) ) unset( $form_state['values'][$key] );

  }

  $form_state['values']['dlts_bitstream_globals_flowplayer'] = serialize( array( 'flowplayer' => $config ) );

}
