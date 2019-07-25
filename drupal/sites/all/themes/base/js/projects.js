/**
 * Implementation of Drupal behavior.
 */
(function($) {
  
    Drupal.behaviors.projects = {};

    Drupal.behaviors.projects.attach = function(context) {

      $(document).ready(function() {
        	
        var last = $( ".breadcrumb-link" ).last() ;
        
        if ( last.text() == '' ) last.html( '<a href="#">' + $('#page-title').text() + '</a>' ) ;
        
        function onClick (e) {
          e.preventDefault();
          $('.login_block').removeClass('element-hidden');
        }
            
        function onClickEmbed ( e ) {
              
          e.preventDefault();
              
          $.colorbox( { iframe : true, width : "95%", height : "95%", href : $(this).attr('href') + '/mode/embed' } ) ;
              
        }
            
        $('body').on('click', '.login a', 'click', onClick);
            
        $('.view-playlists-view').on( 'click', 'a', 'click', onClickEmbed ) ;
            
        $('.view-playlists').on( 'click', 'a', 'click', onClickEmbed ) ;
            
        $('.view-clips').on( 'click', '.views-field-title a', 'click', onClickEmbed ) ;
            
      });
    
    }

})(jQuery);
