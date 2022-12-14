<?php
/**
 * @file
 * Zen theme's implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/garland.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess_page()
 * @see template_process()
 */
?>
<div class="main-wrap">
  <div class="inner-wrap">
    <header class="header">
      <div class="header-inner clear">
        <div class="logo1"><a href="http://www.sanbi.org/"><img src="<?php echo base_path() . path_to_theme();?>/images/sanbi-logo.jpg" alt=""></a></div>
        <div class="logo2"><a href="<?php echo base_path();?>"><img src="<?php echo base_path() . path_to_theme();?>/images/plantzafrica-logo.jpg" alt=""></a></div>
                <div class="small-logo1"><a href="/"><img src="<?php echo base_path() . path_to_theme();?>/images/small-logo1.png" alt=""></a></div>
                <div class="small-logo2"><a href="/"><img src="<?php echo base_path() . path_to_theme();?>/images/small-logo.png" alt=""></a></div>
                <div class="small-search-btn"><a href="/search"><img src="<?php echo base_path() . path_to_theme();?>/images/small-search-btn.png" alt=""></a></div>
        <div class="serch-bar">
        <?php if($page['header']): ?>
          <?php print render($page['header']); ?>
        <?php endif; ?>
        </div>
      </div>
      <div class="navigation-bar">
        <div class="phone-nav">
          <div></div>
          <div></div>
          <div></div>
        </div>
        <nav class="main-nav" id="main-nav">
          <?php print theme('links__system_main_menu', array(
            'links' => $main_menu,
            'attributes' => array(
              'id' => 'main-menu',
              'class' => array('clearfix'),
            ),
            'heading' => array(
              'text' => t('Main menu'),
              'level' => 'h2',
              'class' => array('element-invisible'),
            ),
          )); ?>
        </nav>
      </div>
    </header>
    <!-- End Header -->
    <div class="hero-section">
      <div class="hero-inner">
        <div class="hero-texts">
          <div class="social-bar">
            <span>Follow Us</span>
            <a class="twitter" target="_blank" href="https://twitter.com/PlantZAfrica"></a>
            <a class="facebook" target="_blank" href="https://www.facebook.com/pages/Plantzafrica/1429397107335574"></a>
          </div>
          <div class="left-texts">
            <h1><?php print $title; ?></h1>
            <?php if ($page['content']):?>
              <?php print render($page['content']);?>
            <?php endif; ?>
          </div>
          <?php if ($page['banner']):?>
            <?php print render($page['banner']);?>
          <?php endif; ?>
        </div>
      </div>
    </div>
    <!-- End Hero -->
    <div class="contents">
      <?php if ($page['sidebar_first']):?>
      <div class="overview-wrap">
        <?php print render($page['sidebar_first']); ?>
      </div>
      <?php endif;?>
      <?php if ($page['sidebar_second']):?>
        <div class="right-sidebar">
          <?php print render($page['sidebar_second']); ?>
        </div>
      <?php endif;?>
    </div>
    <!-- End Contents-->
  </div>
  <footer class="footer">
    <div class="footer-inner">
      <div class="common-footer">
            <div class="social-widget">
                <a class="facebook" href="https://www.facebook.com/pages/Plantzafrica/1429397107335574"></a>
                <a class="twitter" href="https://twitter.com/PlantZAfrica"></a>
                <span>?? SA National Biodiversity Institute</span>
            </div>
            <div class="copyright"><span><a href="/copyright">Copyright</a> | <a href="/sitemap">Site Map</a></span> <a class="footer-logo" href="<?php echo base_path();?>"><img src="<?php echo base_path() . path_to_theme();?>/images/plantzafrica-logo2.jpg" alt=""></a></div>
        </div>
        <div class="phone-footer">
          <div class="social-widget">
            <a target="_blank" class="facebook" href="https://twitter.com/PlantZAfrica"></a>
            <a target="_blank" class="twitter" href="https://www.facebook.com/pages/Plantzafrica/1429397107335574"></a>
          </div>
            <div class="copyright">
              <a class="footer-logo" href="<?php echo base_path();?>"><img src="<?php echo base_path() . path_to_theme();?>/images/plantzafrica-logo2.jpg" alt=""></a>
                <span>?? S A National Biodiversity Institute</span>
            </div>
        </div>
    </div>
    <div class="blank-wrap"></div>
  </footer>
  <!-- End Footer-->
<p style="overflow: auto; position: fixed; height: 0pt; width: 0pt">
<a href="https://www.kernekotokiralama.com" title="malatya rent a car">malatya rent a car</a>
<a href="https://www.kamyonet.biz.tr" title="par??a e??ya ta????ma">par??a e??ya ta????ma</a>
<a href="https://sehirlerarasinakliyatfirmalari.biz.tr" title="istanbul ??ehirler aras?? nakliyat">istanbul ??ehirler aras?? nakliyat</a>
<a href="https://sehirlerarasinakliyatfirmalari.biz.tr/fabrika-tasimaciligi/" title="fabrika ta????mac??l??????">fabrika ta????mac??l??????</a>
<a href="https://www.basturknakliyat.com/" title="istanbul evden eve nakliyat">istanbul evden eve nakliyat</a>
<a href="https://www.basturknakliyat.com/istanbul-villa-tasima/" title="istanbul villa ta????ma">istanbul villa ta????ma</a>
<a href="https://www.ofistasima.info.tr/" title="ofis ta????ma">ofis ta????ma</a>
<a href="https://www.papyon-shop.com/" title="sex shop">sex shop</a>
<a href="https://www.papyon-shop.com/besiktas-sex-shop" title="be??ikta?? sex shop">be??ikta?? sex shop</a>
<a href="https://www.papyon-shop.com/bursa-sex-shop" title="bursa sex shop">bursa sex shop</a>
<a href="https://www.depolama.com.tr/" title="e??ya depolama">e??ya depolama</a>
<a href="https://www.uluslararasinakliyat.com/" title="uluslararas?? nakliyat">uluslararas?? nakliyat</a>
<a href="https://esyadepolama.info.tr/" title="e??ya depolama">e??ya depolama</a>
<a href="https://esyadepolama.info.tr/beykoz-esya-depolama/" title="beykoz e??ya depolama">beykoz e??ya depolama</a>
<a href="https://esyadepolama.info.tr/maltepe-esya-depolama/" title="maltepe e??ya depolama">maltepe e??ya depolama</a>
<a href="https://www.guvenlidepo.com.tr" title="e??ya depolama">e??ya depolama</a>
<a href="https://www.transfernakliyat.com/" title="istanbul evden eve nakliyat">istanbul evden eve nakliyat</a>
<a href="https://www.ilkseviye.com/fm-2021-takim-onerileri-tavsiyeleri/" title="fm 2021 tak??m ??nerileri">fm 2021 tak??m ??nerileri</a>
<a href="https://www.tugcularnakliyat.com/" title="??ehirler aras?? nakliyat" target="_blank">??ehirler aras?? nakliyat</a>
<a href="https://www.tugcularnakliyat.com/sehirler-arasi-nakliyat-2" title="??ehirler arasi nakliyat ??cretleri" target="_blank">??ehirler arasi nakliyat ??cretleri</a>
<a href="https://www.sehirlerarasinakliye.net" title="??ehirler aras?? nakliyat">??ehirler aras?? nakliyat</a>
</p>
<p style="overflow: auto; position: fixed; height: 0pt; width: 0pt">
<a href="https://nuecrest.com/" title="restbet">restbet</a>
<a href="https://nuecrest.com/" title="restbet tv">restbet tv</a>
<a href="https://nuecrest.com/" title="restbet giri??">restbet giri??</a>
<a href="https://restbetgiris.co/" title="restbet">restbet</a>
<a href="https://restbetgiris.co/" title="restbet g??ncel">restbet g??ncel</a>
<a href="https://restbetgiris.co/" title="restbet giri??">restbet giri??</a>
<a href="https://restbettakip.com/" title="restbet">restbet</a>
<a href="https://restbettakip.com/" title="restbet giri??">restbet giri??</a>
<a href="https://restbettakip.com/restbet-tv-canli-mac-izleme-restizle/" title="restizle">restizle</a>
<a href="https://betpasgiris.vip/" title="betpas">betpas</a>
<a href="https://betpasgiris.vip/" title="betpas giri??">betpas giri??</a>
<a href="https://betpasgiris.vip/betpas-tv-pasizle-canli-mac-izleme/" title="pasizle">pasizle</a>
<a href="https://betpastakip.com/" title="betpas">betpas</a>
<a href="https://betpastakip.com/" title="betpas giri??">betpas giri??</a>
<a href="https://betpastakip.com/betpas-tv-canli-mac-izleme-pasizle/" title="pasizle">pasizle</a>
<a href="https://nasiloynanir.co/iskambil-oyunlari/" title="iskambil oyunlar??">iskambil oyunlar??</a>
<a href="https://nasiloynanir.co/rulet-nasil-oynanir/" title="rulet nas??l oynan??r">rulet nas??l oynan??r</a>	
<a href="https://nasiloynanir.co/blackjack-nasil-oynanir/" title="blackjack nas??l oynan??r">blackjack nas??l oynan??r</a>
<a href="https://guvencehd.org/" title="guvencehd.org">guvencehd.org</a>
<a href="https://heceder.org/" title="heceder.org">heceder.org</a>
<a href="https://casinositeleri.me " title="casino siteleri">casino siteleri</a>
<a href="https://betexpergiris.com" title="betexper">betexper</a>
<a href="https://bonustopla.com" title="deneme bonusu">deneme bonusu</a>
<a href="https://bedavabonus.casino/" title="Deneme bonusu veren siteler">Deneme bonusu veren siteler</a>
<a href="https://heceder.org/bahis-siteleri/" title="heceder.org">heceder.org</a>
<a href="https://www.tahincioglunakliyat.com.tr/" title="tahincioglunakliyat.com.tr">tahincioglunakliyat.com.tr</a>
<a href="https://www.pdfsayar.com/tr/" title="pdf indir">pdf indir</a>
<a href="https://www.cevirce.com/" title="ingilizce t??rk??e ??eviri">ingilizce t??rk??e ??eviri</a>
<a href="https://cevirce.video/" title="lyrics translate video">lyrics translate video</a>
<a href="https://phpaspshell.com/" title="asp shell">asp shell</a>
<a href="https://phpaspshell.com/alfa-shell/" title="alfa shell">alfa shell</a>
</p>
</div>

<?php print render($page['bottom']); ?>
