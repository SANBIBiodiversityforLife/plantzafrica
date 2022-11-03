/**
 * @description Javascript functionality for autocomplete General search
 */
(function ($) {
  Drupal.behaviors.pa_autocomplete_general = {
    attach: function (context, settings) {

      //init jQuery UI autocomplete for homepage block
      var homepageSearch = $('#pa-advanced-search-basic-form .autocomplete-general');
      homepageSearch.autocomplete({
        source: "/pa/autocomplete/general",
        minLength: 3,
      });

      //init jQuery UI autocomplete for header block
      var headerSearch = $('#views-exposed-form-general-search-page .autocomplete-general');
      headerSearch.autocomplete({
        source: "/pa/autocomplete/general",
        minLength: 3,
      });

      //onclick function for selected autocomplete terms
      $('ul.ui-autocomplete').on('click', 'li', function() {
        console.log($(this));
      });
    }
  }
})(jQuery);