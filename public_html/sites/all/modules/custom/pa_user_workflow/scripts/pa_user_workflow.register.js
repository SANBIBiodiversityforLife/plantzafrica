/**
 * @description Javascript functionality for Patient list within Doctor's profile
 */
(function ($) {

  Drupal.behaviors.pa_user_workflow_register = {
    attach: function (context, settings) {

      //login form AJAX callback logic BEGIN ######################
      var form = $('#pa-user-workflow-register-form');
      var submitLink =  $('input.form-submit', form);

      //on click callback
      submitLink.once().click(function(e){

        e.preventDefault();

        //first validate form before we send off ajax request
        if(!form.parsley('validate')){
          return false;
        }

        //serialize form into POST data
        var postData = form.serialize();

        $.ajax({
          type: 'POST',
          url: '/modal/register',
          dataType: 'json',
          data: postData,
          beforeSend: function(){
            submitLink.toggleLoader(); //toggle AJAX loading gif
          },
          success: function(response){

            console.log(response);

            submitLink.toggleLoader(); //toggle AJAX loading gif

            if(response.success == true){

              $('<p class="success">Your account has been created successfully. Please check your inbox to validate your registration.</p>').insertBefore(submitLink);
              $('<p class="success">If you don\'t receive the email within a couple of minutes, please remember to check your junk mail folder too.</p>').insertBefore(submitLink);

            }else{

              //display error alert
              $('<p class="error">Your email address is already associated with an account.</p>').insertBefore(submitLink);

            }
          },
          error: function(jqXHR, textStatus, errorThrown) {
            console.log(jqXHR);
            $('<p class="error">Sorry, something went wrong while creating your account. Please try again.</p>').insertBefore(submitLink);
          }
        });
      });
      //login form AJAX callback logic END   ######################

      //login link click
      var registerTrigger = function(e){
        e.preventDefault();
        $('#pa_register_modal').modal();
      };

      //header link
      $('.link-text .register, .reg-fire').once().click(function(e){
        registerTrigger(e);
      });
    }
  }
})(jQuery);