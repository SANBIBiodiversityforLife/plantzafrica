/* Enabling support for new HTML5 tags for IE6, IE7 and IE8 */
if(navigator.appName == 'Microsoft Internet Explorer' ){
	if( ( navigator.userAgent.indexOf('MSIE 6.0') >= 0 ) || ( navigator.userAgent.indexOf('MSIE 7.0') >= 0 ) || ( navigator.userAgent.indexOf('MSIE 8.0') >= 0 ) ){
		document.createElement('header')
		document.createElement('nav')
		document.createElement('section')
		document.createElement('aside')
		document.createElement('footer')
		document.createElement('article')
		document.createElement('hgroup')
		document.createElement('figure')
		document.createElement('figcaption')
	}
}
/* Enabling support for new HTML5 tags for IE6, IE7 and IE8 */

var totalSlides = $j('#gallerySlider > ul > li').length;

(function($j){
	$j(function(){

		// Begin input common focus and blur for value.
		$j('input:text,input:password')
			.focus(function(){
				$j(this).addClass('focused')
			})
				.blur(function(){
					$j(this).removeClass('focused')

				})

			$j('textarea')
				.focus(function(){
					$j(this).addClass('focused')
				})
					.blur(function(){
						$j(this).removeClass('focused')

					})
		// Ends input common focus and blur for value.

		if (window.PIE) {$j('.gradient, .rounded, .shadow, .txtfield , .search-btn').each(function() {PIE.attach(this);});}

		//For ie 7,8//
		if(navigator.appName == 'Microsoft Internet Explorer' ){
		   if( ( navigator.userAgent.indexOf('MSIE 7.0') >= 0 ) || ( navigator.userAgent.indexOf('MSIE 8.0') >= 0 )){
			$j('body').addClass('iebelow9')
		  }
		}

		$j(".phone-nav").click(function(){
			$j("#main-nav").slideToggle();
		});

		// Function accordion
		$j('#sidebar-list > li.has-subitem > a').click(function(e){
			//e.preventDefault()

			var $j_this = $j(this)
			if( $j_this.parent().hasClass('active')){

				$j_this = $j(this);
				$j_this.parent().removeClass('active');
				$j_this.parent().find('> ul').slideUp(500);
			}

			else{

				$j('#sidebar-list .active').removeClass('active');
				$j_this.parent().addClass('active');
				console.log($j('#sidebar-list > li.has-subitem > ul'));
				$j('#sidebar-list > li.has-subitem > ul:visible').slideUp(500);
				$j_this.parent().find('> ul').slideDown(500);

			}
		})

		$j('#navSwitch').click(function(){
			$j('#categoryNav').slideToggle()
			$j(this).toggleClass('opened')
			$j('#sidebar-list > li.has-subitem > ul:visible').hide()
			$j('#sidebar-list').find('.active').removeClass('active');
            console.log('test');
		})

		/* Information Library Sidebar on page load */
		$j('#sidebar-list a[parent="active"]').each(function(){
			$j(this).parents('.has-subitem').addClass('active').find('ul').css('display', 'block');
		});

        //back to top button
		$j("a.backtop-btn, a.Search-link").click(function (e) {
			e.preventDefault()
			$j("html, body").animate({scrollTop: 0}, 700);
		})

		if ( $j(window).width() < 768 ) {
			$j('input#textHidden').val('')
		}
	})// End ready function.

	$j(window).load(function(){
		if( $j('#listMain').length )
		$j('html, body').animate({
			scrollTop: $j("#listMain").offset().top
		}, 700 );
	})

//Quad, Cubic, Quart, Quint, Sine, Expo, Circ, Elastic, Back, Bounce
$j.easing["jswing"]=$j.easing["swing"];$j.extend($j.easing,{def:"easeOutQuad",swing:function(a,b,c,d,e){return $j.easing[$j.easing.def](a,b,c,d,e)},easeInQuad:function(a,b,c,d,e){return d*(b/=e)*b+c},easeOutQuad:function(a,b,c,d,e){return-d*(b/=e)*(b-2)+c},easeInOutQuad:function(a,b,c,d,e){if((b/=e/2)<1)return d/2*b*b+c;return-d/2*(--b*(b-2)-1)+c},easeInCubic:function(a,b,c,d,e){return d*(b/=e)*b*b+c},easeOutCubic:function(a,b,c,d,e){return d*((b=b/e-1)*b*b+1)+c},easeInOutCubic:function(a,b,c,d,e){if((b/=e/2)<1)return d/2*b*b*b+c;return d/2*((b-=2)*b*b+2)+c},easeInQuart:function(a,b,c,d,e){return d*(b/=e)*b*b*b+c},easeOutQuart:function(a,b,c,d,e){return-d*((b=b/e-1)*b*b*b-1)+c},easeInOutQuart:function(a,b,c,d,e){if((b/=e/2)<1)return d/2*b*b*b*b+c;return-d/2*((b-=2)*b*b*b-2)+c},easeInQuint:function(a,b,c,d,e){return d*(b/=e)*b*b*b*b+c},easeOutQuint:function(a,b,c,d,e){return d*((b=b/e-1)*b*b*b*b+1)+c},easeInOutQuint:function(a,b,c,d,e){if((b/=e/2)<1)return d/2*b*b*b*b*b+c;return d/2*((b-=2)*b*b*b*b+2)+c},easeInSine:function(a,b,c,d,e){return-d*Math.cos(b/e*(Math.PI/2))+d+c},easeOutSine:function(a,b,c,d,e){return d*Math.sin(b/e*(Math.PI/2))+c},easeInOutSine:function(a,b,c,d,e){return-d/2*(Math.cos(Math.PI*b/e)-1)+c},easeInExpo:function(a,b,c,d,e){return b==0?c:d*Math.pow(2,10*(b/e-1))+c},easeOutExpo:function(a,b,c,d,e){return b==e?c+d:d*(-Math.pow(2,-10*b/e)+1)+c},easeInOutExpo:function(a,b,c,d,e){if(b==0)return c;if(b==e)return c+d;if((b/=e/2)<1)return d/2*Math.pow(2,10*(b-1))+c;return d/2*(-Math.pow(2,-10*--b)+2)+c},easeInCirc:function(a,b,c,d,e){return-d*(Math.sqrt(1-(b/=e)*b)-1)+c},easeOutCirc:function(a,b,c,d,e){return d*Math.sqrt(1-(b=b/e-1)*b)+c},easeInOutCirc:function(a,b,c,d,e){if((b/=e/2)<1)return-d/2*(Math.sqrt(1-b*b)-1)+c;return d/2*(Math.sqrt(1-(b-=2)*b)+1)+c},easeInElastic:function(a,b,c,d,e){var f=1.70158;var g=0;var h=d;if(b==0)return c;if((b/=e)==1)return c+d;if(!g)g=e*.3;if(h<Math.abs(d)){h=d;var f=g/4}else var f=g/(2*Math.PI)*Math.asin(d/h);return-(h*Math.pow(2,10*(b-=1))*Math.sin((b*e-f)*2*Math.PI/g))+c},easeOutElastic:function(a,b,c,d,e){var f=1.70158;var g=0;var h=d;if(b==0)return c;if((b/=e)==1)return c+d;if(!g)g=e*.3;if(h<Math.abs(d)){h=d;var f=g/4}else var f=g/(2*Math.PI)*Math.asin(d/h);return h*Math.pow(2,-10*b)*Math.sin((b*e-f)*2*Math.PI/g)+d+c},easeInOutElastic:function(a,b,c,d,e){var f=1.70158;var g=0;var h=d;if(b==0)return c;if((b/=e/2)==2)return c+d;if(!g)g=e*.3*1.5;if(h<Math.abs(d)){h=d;var f=g/4}else var f=g/(2*Math.PI)*Math.asin(d/h);if(b<1)return-.5*h*Math.pow(2,10*(b-=1))*Math.sin((b*e-f)*2*Math.PI/g)+c;return h*Math.pow(2,-10*(b-=1))*Math.sin((b*e-f)*2*Math.PI/g)*.5+d+c},easeInBack:function(a,b,c,d,e,f){if(f==undefined)f=1.70158;return d*(b/=e)*b*((f+1)*b-f)+c},easeOutBack:function(a,b,c,d,e,f){if(f==undefined)f=1.70158;return d*((b=b/e-1)*b*((f+1)*b+f)+1)+c},easeInOutBack:function(a,b,c,d,e,f){if(f==undefined)f=1.70158;if((b/=e/2)<1)return d/2*b*b*(((f*=1.525)+1)*b-f)+c;return d/2*((b-=2)*b*(((f*=1.525)+1)*b+f)+2)+c},easeInBounce:function(a,b,c,d,e){return d-$j.easing.easeOutBounce(a,e-b,0,d,e)+c},easeOutBounce:function(a,b,c,d,e){if((b/=e)<1/2.75){return d*7.5625*b*b+c}else if(b<2/2.75){return d*(7.5625*(b-=1.5/2.75)*b+.75)+c}else if(b<2.5/2.75){return d*(7.5625*(b-=2.25/2.75)*b+.9375)+c}else{return d*(7.5625*(b-=2.625/2.75)*b+.984375)+c}},easeInOutBounce:function(a,b,c,d,e){if(b<e/2)return $j.easing.easeInBounce(a,b*2,0,d,e)*.5+c;return $j.easing.easeOutBounce(a,b*2-e,0,d,e)*.5+d*.5+c}})
})($j)

