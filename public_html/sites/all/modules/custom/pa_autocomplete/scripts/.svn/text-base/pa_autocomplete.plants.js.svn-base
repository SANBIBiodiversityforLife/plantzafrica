/**
 * @description Javascript functionality for autocomplete Plants search
 */
(function ($) {
  Drupal.behaviors.pa_autocomplete_plants = {
    attach: function (context, settings) {
      //init jQuery UI autocomplete
      var input = $('.autocomplete-pa-basic');
      input.autocomplete({
        source: "/pa/autocomplete/plants",
        minLength: 3
      });

      //onclick function for selected autocomplete terms
      $('ul.ui-autocomplete').on('click', 'li', function() {
        console.log($(this));
      });
    }
  }
})(jQuery);