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
<div class="main-wrap <?php print (isset($main_class))? $main_class : ''; ?>">
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

          <?php if ($page['banner']):?>
            <?php print render($page['banner']);?>
          <?php else: ?>
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
              <h1><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
          <?php endif;?>

        </div>
      </div>
    </div>
    <!-- End Hero -->
    <div class="contents">

      <?php if ($page['sidebar_first']):?>
      <!-- Sidebar -->
      <div class="sidebar">
        <?php print render($page['sidebar_first']); ?>
      </div>
      <?php endif;?>
      <div class="main-text sidebar-<?php print (($page['sidebar_first']) ? 'visible' : 'hidden');?>">

        <?php print render($page['highlighted']); ?>

        <?php print $messages; ?>

        <?php if ($tabs = render($tabs)): ?>
          <div class="tabs"><?php print $tabs; ?></div>
        <?php endif; ?>

        <?php print render($page['help']); ?>

        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>

        <?php print render($page['content']); ?>

      </div>

      <?php if ($page['sidebar_second']):?>
        <div class="sidebar_second">
          <?php print render($page['sidebar_second']); ?>
        </div><!-- Right sidebar -->
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
                    <span>© SA National Biodiversity Institute</span>
                </div>
                <div class="copyright"><span><a href="<?php echo base_path();?>copyright">Copyright</a> | <a href="/sitemap">Site Map</a></span> <a class="footer-logo" href="<?php echo base_path();?>"><img src="<?php echo base_path() . path_to_theme();?>/images/plantzafrica-logo2.jpg" alt=""></a></div>

            </div>


            <div class="phone-footer">
              <div class="social-widget">
                  <a target="_blank" class="facebook" href="https://twitter.com/PlantZAfrica"></a>
                  <a target="_blank" class="twitter" href="https://www.facebook.com/pages/Plantzafrica/1429397107335574"></a>
              </div>
              <div class="copyright">
                <a class="footer-logo" href="<?php echo base_path();?>"><img src="<?php echo base_path() . path_to_theme();?>/images/plantzafrica-logo2.jpg" alt=""></a>
                  <span>© S A National Biodiversity Institute</span>
              </div>
            </div>
    </div>
    <div class="blank-wrap"></div>

  </footer>

  <!-- End Footer-->
</div>
<?php print render($page['bottom']); ?>
