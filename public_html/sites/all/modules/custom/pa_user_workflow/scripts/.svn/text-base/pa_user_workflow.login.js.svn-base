/**
 * @description Javascript functionality for Patient list within Doctor's profile
 */
(function ($) {

  Drupal.behaviors.pa_user_workflow_login = {
    attach: function (context, settings) {

      //login form AJAX callback logic BEGIN ######################
      var loginForm = $('#pa-user-workflow-login-form');
      var submitLink =  $('input.form-submit', loginForm);

      //on click callback
      submitLink.once().click(function(e){

        e.preventDefault();

        //first validate form before we send off ajax request
        if(!loginForm.parsley('validate')){
          return false;
        }

        //serialize form into POST data
        var postData = loginForm.serialize();

        $.ajax({
          type: 'POST',
          url: '/modal/login',
          dataType: 'json',
          data: postData,
          beforeSend: function(){
            submitLink.toggleLoader(); //toggle AJAX loading gif
          },
          success: function(response){

            submitLink.toggleLoader(); //toggle AJAX loading gif

            if(response.success == true){

              $('<p class="success">You have logged in successfully. Please wait while this page is reloaded.</p>').insertBefore(submitLink);

              //refresh our page
              var outtaHash = window.location.toString();
              document.location.href = outtaHash.split('#')[0];

            }else{

              //display error alert
              $('<p class="error">Incorrect username or password. Please check your details and try again.</p>').insertBefore(submitLink);

            }
          },
          error: function(jqXHR, textStatus, errorThrown) {
            /*console.log(jqXHR + " :: " + textStatus + " :: " + errorThrown);
            console.log(jqXHR);*/
          }
        });
      });
      //login form AJAX callback logic END   ######################

      //login link click
      var loginTrigger = function(e){
        e.preventDefault();
        $('#pa_login_modal').modal();
      };

      //modal close button
      $('.modal-close').click(function(e){
        $(this).closest('.modal').modal('hide');
      });

      //header link
      $('.link-text .login, .login-fire').once().click(function(e){
        loginTrigger(e);
      });
    }
  }

  //on ready function
  $(function () {
    //check to see if we need to auto fire our login modal after email verification
    var param = window.location.hash;
    if(param == '#loginmodal'){
      $('#pa_login_modal').modal();
    }
  });
})(jQuery);