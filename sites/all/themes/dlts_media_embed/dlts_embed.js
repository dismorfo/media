;(function ($) {
  Drupal.behaviors.dlts_embed = {
    attach: function ( context, settings ) {
    
      return ; 

      if ( flashembed && flashembed.isSupported([9, 115]) ) {
    	  
    	var key = '#$623666ca2f667514416';
    	
    	var flowplayer_swf = '/media/sites/all/libraries/flowplayer/flowplayer.commercial-3.2.18.swf' ;
    	
    	var plugins_root = '/media/sites/all/libraries/flowplayer/plugins/flash/' ;
    	
    	var plugins = {
      	      f4m: {
      	        url: plugins_root + "flowplayer.f4m-3.2.10.swf"
      	      },
      	      rtmp: { 
      	        url: plugins_root + "flowplayer.rtmp-3.2.13.swf"
      	      },
      	      controls: { 
      	        url: plugins_root + "flowplayer.controls-3.2.16.swf",
      	        playlist: true
      	      },
      	      bwcheck: {
      	        url: plugins_root + "flowplayer.bwcheck-3.2.13.swf" ,
      	        dynamic: true,
      	        checkOnStart: true,
      	        qos: {
      	          screen: false
      	        },
      	        serverType: "fms"
      	      }
      	};
    	
    	var clip = {
      	  autoPlay: true,
    	  provider: 'rtmp',
    	  urlResolvers: [ 'f4m' , 'bwcheck' ]
    	} ;
    	
    	var playlist = [] ;
 
        $.each ( Drupal.settings.dlts_clip.media, function ( index, media ) {
          playlist.push ( media['stream'] ) ;
        } ) ;
        
        flowplayer ( $('.dlts_clip').attr('id') , flowplayer_swf, { key : key, plugins : plugins, clip : clip, playlist : playlist } ) ;
        
        $('.player').click ( function() { 
          $(this).removeClass('.stop') ; 
        } ) ;
        
      }
      
    }
  }
})(jQuery);
