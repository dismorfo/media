; (function ($) {
  Drupal.behaviors.dlts_google_analytics = {
    attach: function (context, settings) {
      var module = settings.dlts_google_analytics;
      if (module) {
        var enable = module.enable;
        var debug = module.debug;
        if (enable === 1 && jQuery.isFunction(window.ga)) {
          window.ga("create", module.ua, { "cookieDomain": module.cookieDomain });
          window.ga("set", "anonymizeIp", module.anonymizeIp);
          if (module.dimensions.collections &&
              module.dimensions.collections.length > 0) {
            /* We will only record the first collection for now.  Later we might start
             tracking the full list of collections once we come up with a strategy.
             We can't use pageviews because that would cause hit inflation.
             Event tracking might work but requires planning, and it's possible
             Google rate throttling would cause problems.

             So one day, we might put something like this here:

             $.each(settings.dlts_google_analytics.collections, function(key, collection) {
               window.ga("set", "dimension1", collection.name);
               window.ga('send', {
                 hitType: 'event',
                 dimension1: collection_name,
                 eventCategory: 'Collection Usage',
                 eventAction: 'view',
                 eventLabel: 'Asset viewed'
               });
             });
             For more details, refer to:
                 https://jira.nyu.edu/browse/DLTSVIDEO-83
                 https://jira.nyu.edu/browse/DLTSVIDEO-67
             */
            window.ga("set", "dimension1", module.dimensions.collections[0].name);
          }
          if (debug) {
            console.log('GoogleAnalyticsObject: ' + GoogleAnalyticsObject);
            console.log(module);
          }
          else {
            window.ga("send", "pageview");
          }
        }
      }
    }
  }
})(jQuery);
