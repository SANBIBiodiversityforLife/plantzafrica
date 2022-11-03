/**
 * @description Javascript functionality for snap to browser Insert functionality
 */
(function ($) {
  Drupal.behaviors.pa_forms_insert = {
    attach: function (context, settings) {

      //variables used to store widget container element and the source of the snapped image field
      var sourceContainer;
      var widgetContainer;
      var toolbar;

      $('input.insert-snap').change(function(){

        //create toolbar div element if it doesn't exist yet
        if($('.insert-toolbar').length == 0){
          toolbar = document.createElement('div');
          $toolbar = $(toolbar);
          $(toolbar).addClass('insert-toolbar');
          document.body.appendChild(toolbar);
        }

        //grab our widget container element
        widgetContainer = $(this).closest('.image-widget');

        //snap our container element to browser "toolbar"
        if(this.checked){

          //move our image widget
          sourceContainer = widgetContainer.parent();
          widgetContainer.fadeOut(200);
          $(toolbar).append(widgetContainer);
          $('.form-type-textfield', toolbar).hide();
          widgetContainer.fadeIn(200);

          //disable other checkboxes while widget is snapped to toolbar
          $('input.insert-snap').attr('disabled', true);
          $(this).removeAttr('disabled');

          //show our toolbar
          $(toolbar).show();

        //snap image back into source parent container
        }else{

          //move our image widget
          widgetContainer.fadeOut(200);
          $(sourceContainer).append(widgetContainer);
          $('.form-type-textfield', sourceContainer).show();
          widgetContainer.fadeIn(200);

          //enable other checkboxes while widget is snapped to toolbar
          $('input.insert-snap').removeAttr('disabled');

          //hide our toolbar
          $(toolbar).hide();
        }
      });
    }
  }
})(jQuery);