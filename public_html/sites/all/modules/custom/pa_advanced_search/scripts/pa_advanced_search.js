/**
 * @description Javascript functionality for POWAS
 */
(function ($) {

  //on ready function
  $(function () {
   
    //init chosen lib for our select boxes
    $(".select-box").chosen({
      width: '100%'
    });

    // Begin Tab Function for sorts etc
    $('#tab-list > li').eq(0).addClass('active')
    $('#tab-contents > div.tab-contents div.selection-item').eq(0).show()
    /*$('#tab-list > li').each(function(i){
      $(this).click(function(){
        if( $(this).hasClass('active')) return false

        $('#tab-list > li.active').removeClass('active')
        $(this).addClass('active')
        $('#tab-contents > div.tab-contents div.selection-item').hide()
        $('#tab-contents > div.tab-contents div.selection-item').eq(i).show()
      })
    })*/

    /* Map form options BEGIN ###################### */

    //hide initial layers
    $('.zoneOne,.zoneTwo,.zoneThree,.zoneFour,.zoneFive').hide();

    //map area event callback definitions
    $('#map > area').each(function(i){

      //hover events
      $(this).mouseenter(function (){
        $( '.'+$(this).attr('href')).stop(true, true).fadeIn()
      })
      $(this).mouseleave(function (){
        $( '.'+$(this).attr('href')).stop(true, true).fadeOut()
      })

      //click event callback
      $(this).click(function(e){
        e.preventDefault()
        $( '.'+$(this).attr('id')).toggle()
        $('#zoneChecks > div').eq(i).toggleClass('active')
        $('#zoneChecks > div').eq(i).find('input:checkbox').prop( "checked", function( i, val ) {
          return !val;
        })
      })
    })

    //zone input checkboxes callback definitions
    $('#zoneChecks > div').each(function(j){
      $(this).click(function(){
        $('#coloredMaps > div').eq(j).toggle()
        $(this).toggleClass('active')
        $(this).find('input:checkbox').prop( "checked", function( i, val ) {
          return !val;
        })
      })

      //check if checkbox for hort zone active
      if($(this).find('input:checkbox').prop("checked")){
        //toggle the selected states
        $('#coloredMaps > div').eq(j).css('display', 'block');
        $(this).toggleClass('active');
      }
    })

    $('#zoneChecks input:checkbox').each(function(k){
      //click callback
      $(this).click(function(e){
        e.stopPropagation()
        $('#coloredMaps > div').eq(k).toggle()
        $(this).parent().parent('div').toggleClass('active')
      })
    })
    /* Map form options END   ###################### */

    //check to see if we have URL params active to auto scroll down
    if(window.location.search != ''){
      $('html, body').animate({
        scrollTop: $("#block-system-main").offset().top
      }, 700);

      //check if we need to open the date tab by default
      var glossary = (window.location.search + '').indexOf('glossary=', (0 || 0));
      var titleSort = (window.location.search + '').indexOf('title_sort=', (0 || 0));
      if(glossary !== -1 || titleSort !== -1){
        $('#tab-list li').eq(1).addClass('active');
        $('#tab-list li').eq(0).removeClass('active');
        $('#tab-contents > div.tab-contents div.selection-item').eq(1).show()
        $('#tab-contents > div.tab-contents div.selection-item').eq(0).hide()
      }
    }

    //sort tab redirects
    $('#tab-list li').click(function(e){
      document.location.href = $(this).data('redirect'); //relative to domain
    });

    //clear freetext search value when attribue search button hit
    //$('.grey-container.bottom .yellow-btn').click(function(e){
    //  e.preventDefault();
      //$('#edit-name').val(''); // RR to recombine searches
    //  $(this).closest('form').submit();
    //}); 

  });
})(jQuery);