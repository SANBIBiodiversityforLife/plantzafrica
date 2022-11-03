/**
 * @description Javascript functionality for Patient list within Doctor's profile
 */
(function ($) {
  Drupal.behaviors.pa_pow_date_range = {
    attach: function (context, settings) {
      //onclick event handler for clearing our date input values
      $('#pa-advanced-search-date-range-form #edit-reset').click(function(e){
        e.preventDefault();
        $('#pa-advanced-search-date-range-form input.form-text').val('');
      });
    }
  }
})(jQuery);