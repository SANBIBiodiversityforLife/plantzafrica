/**
 * User: Alex Kirsten
 * Date: 2013/09/03
 * Time: 6:24 PM
 * Provides jQuery utility functions within the Doc Diary UI
 */

var getQueryStringParams;

(function ($) {

  //Function which toggles the display of the AJAX loading gif after selector
  jQuery.fn.toggleLoader = function(){

    var imagePath = '/sites/all/themes/greenbox/images/ajax-loader.gif';
    var loaderHTML = '<img alt="Loading..." title="Loading..." class="ajax-loader hidden" src="' + imagePath + '" />';

    //toggle display of loading gif
    if(this.next('.ajax-loader').length > 0){

      this.next('.ajax-loader').fadeOut(500);
      this.next('.ajax-loader').remove();

    }else{

      //add loading gif after selector
      $(loaderHTML).insertAfter(this);
      this.next('.ajax-loader').fadeIn(500);
    }
  };

  //Function which adds Bootstrap "Alert" element after selector
  jQuery.fn.displayAlert = function(alert){

    //console.log(alert);

    //alert HTML content tp be inserted into DOM
    var alertHTML = '<div class="alert alert-dismissable fade in hidden ' + alert.id + '">\
                      <a class="close" data-dismiss="alert" href="#" aria-hidden="true">&times;</a>\
                      <strong class="alert-type"></strong><br/>\
                      <span class="alert-content"></span>\
                     </div>';

    //we close any previously shown alert of this type to avoid duplicates stacking up
    $(".alert." + alert.id).remove();

    //we insert alert HTML after selected DOM element
    $(alertHTML).insertBefore(this);

    var alertContainer = $('.alert.' + alert.id);

    switch(alert.type){
      case 'success':
        $('.alert-type').text(alert.prefix);
        $('.alert-content').text(alert.message);
        alertContainer.addClass('alert-success');
        alertContainer.fadeIn(500);
        break;

      case 'info':
        $('.alert-type').text(alert.prefix);
        $('.alert-content').text(alert.message);
        alertContainer.addClass('alert-info');
        alertContainer.fadeIn(500);
        break;

      case 'error':
        $('.alert-type').text(alert.prefix);
        $('.alert-content').text(alert.message);
        alertContainer.addClass('alert-danger');
        alertContainer.fadeIn(500);
        break;

      case 'warning':
        $('.alert-type').text(alert.prefix);
        $('.alert-content').text(alert.message);
        alertContainer.addClass('alert-warning');
        alertContainer.fadeIn(500);
        break;
    }
  };

  //function for getting query string from URL
  getQueryStringParams = function(sParam){

    var sPageURL = window.location.search.substring(1);
    var sURLVariables = sPageURL.split('&');
    var paramVal = false;

    for (var i = 0; i < sURLVariables.length; i++){
      var sParameterName = sURLVariables[i].split('=');
      if (sParameterName[0] == sParam){
        paramVal = sParameterName[1];
      }
    }

    return paramVal;
  };

  /**
  * Behaviour which supresses ugly AJAX error alert for Drupal
  */
  Drupal.behaviors.prevent_js_alerts = {
    attach: function(context, settings) {
      // Override the alert() function.
      window.alert = function(text) {
        // Check if the console exists (required e.g. for older IE versions).
        if (typeof console != "undefined") {
          // Log error to console instead.
          console.error("Module 'prevent_js_alerts' prevented the following alert: " + text);
        }
        return true;
      };
    }
  };

  //on ready function
  $(function () {

    //init lexicon qtip
    $('.lexicon-term').qtip({
      content: {
        attr: 'data-term-info'
      }
    });


  });

})(jQuery);