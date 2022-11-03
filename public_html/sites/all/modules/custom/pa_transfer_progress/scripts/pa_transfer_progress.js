/**
 * @description Progress bar for POW home page block
 */
(function ($) {

  var percentage = 0;

  Drupal.behaviors.pa_transfer_progress = {
    attach: function (context, settings) {
      percentage = settings.progress;
    }
  }

  //on ready function
  $(function () {
    var element = $('#progressBar');
    var progressBarWidth = percentage * element.width() / 100;
    element.find('div').animate({ width: progressBarWidth }, 500).html(percentage + "%&nbsp;");
  });
})(jQuery);