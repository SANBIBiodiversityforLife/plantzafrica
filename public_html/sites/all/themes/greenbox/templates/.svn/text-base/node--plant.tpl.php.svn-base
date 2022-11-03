<?php
/**
 * @file
 * Zen theme's implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   - view-mode-[mode]: The view mode, e.g. 'full', 'teaser'...
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 *   The following applies only to viewers who are registered users:
 *   - node-by-viewer: Node is authored by the user currently viewing the page.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content. Currently broken; see http://drupal.org/node/823380
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see zen_preprocess_node()
 * @see template_process()
 */

//Author
if (isset($node->field_authors['und'])){
  $author = $node->field_authors['und'][0]['entity'];
  // RR fix for missing first / last names
  $author_name = (isset($author->field_first_name['und'][0]['value'])? $author->field_first_name['und'][0]['value'] : '') . ' ' . (isset($author->field_last_name['und'][0]['value'])? $author->field_last_name['und'][0]['value'] : '');
}else{
  $author_name = '';
}

//Family
$family = (isset($node->field_family['und'][0]['taxonomy_term']->name)) ? $node->field_family['und'][0]['taxonomy_term']->name : '';

//Genus
$genus = (isset($node->field_genus['und'][0]['taxonomy_term']->name)) ? $node->field_genus['und'][0]['taxonomy_term']->name : '';

?>
<div class="articles-wrap">
  <div class="top-wrap">
    <div class="search-item">
      <a href="/plants/search/list">&lt; Back to search results</a>
      <a class="pull-right" href="/plants/search/advanced">Go to Plants of the Week Advanced Search</a>
    </div>
    <div class="author-info">
      <!-- <h2><?php print $node->title;?>, <?php print $author_name;?></h2> -->
      <h2><?php print (isset($node->field_long_scientific_name['und'])) ? strip_tags($node->field_long_scientific_name['und'][0]['value'], '<em><strong>') : '';?></h2>
      <p><span>Family:</span> <?php print (isset($node->field_family['und'])) ? $node->field_family['und'][0]['taxonomy_term']->name : '';?></p>
      <p><span>Common names:</span> <?php print (isset($node->field_common_names['und'])) ? $node->field_common_names['und'][0]['value'] : '';?></p>
      <?php if(isset($node->field_sa_tree_number['und'])): ?>
        <p><span>SA Tree No:</span> <?php print $node->field_sa_tree_number['und'][0]['value'] ?>
      <?php endif; ?>
    </div>
    <div class="btn-row">
      <a class="view-btn" href="<?php print base_path() . 'plants/search/advanced?pow_page=family&name=' . $family;?>">View other plants in this family</a>
      <a target="_blank" class="code-link" href="?qr=1">QR code link</a>
      <a class="view-btn" href="<?php print base_path() . 'plants/search/advanced?pow_page=genus&name=' . $genus;?>">View other plants in this genus</a>
    </div>
  </div>

  <div class="full-articles">

    <div class="row1">

      <!-- Introduction -->
      <?php if (isset($content['field_introduction'])):?>
        <?php print render($content['field_introduction']);?>
      <?php endif;?>

      <!-- Description -->
      <?php if (isset($content['field_description'])):?>
        <h3>Description</h3>
        <?php print render($content['field_description']);?>
      <?php endif;?>

    </div>

    <div class="row2">

      <!-- Conservation Status -->
      <?php if (isset($content['field_status'])):?>
        <h3>Conservation Status</h3>
        <?php print render($content['field_status']);?>
      <?php endif;?>

      <?php if (isset($content['field_distribution_description'])):?>
        <!-- Distribution and habitat -->
        <h3>Distribution and habitat</h3>
        <?php print render($content['field_distribution_description']);?>
      <?php endif;?>

    </div>

    <?php if (isset($content['field_history'])):?>
      <!-- Derivation of name and historical aspects -->
      <h3>Derivation of name and historical aspects</h3>
      <?php print render($content['field_history']);?>
    <?php endif;?>

    <?php if (isset($content['field_ecology'])):?>
      <!-- Ecology -->
      <h3>Ecology</h3>
      <?php print render($content['field_ecology']);?>
    <?php endif;?>

    <?php if (isset($content['field_use'])):?>
      <!-- Uses -->
      <h3>Uses</h3>
      <?php print render($content['field_use']);?>
    <?php endif;?>

    <?php if (isset($content['field_grow'])):?>
      <!-- Growing -->
      <h3>Growing <?php print $node->title;?></h3>
      <?php print render($content['field_grow']);?>
    <?php endif;?>

    <?php if(!empty($species)): ?>
      <!-- Species -->
      <h3>Species</h3>
      <?php foreach($species as $delta => $row): ?>
      <div class="species-row <?php print ($delta%2 == 0)? 'even' : 'odd'; ?>">
        <div class="species-img"><?php print $row['img']; ?></div>
        <div class="specied-description"><?php print $row['description']; ?></div>
      </div>
      <?php endforeach; ?>
    <?php endif; ?>

    <?php if (isset($content['field_references_taxonomy']) || isset($content['field_references'])):?>
      <div class="references">
        <h3>References</h3>
        <?php print $references; ?>
      </div>
    <?php endif;?>

    <?php if (isset($content['field_credits'])):?>
      <div class="date-place">
        <?php print render($content['field_credits']);?>
      </div>
    <?php endif;?>

  </div>
  <div class="sidebar">
    <div class="attributes">
      <h4>Plant Attributes:</h4>
      <p><span>Plant Type:</span> <?php print $attr['plant_type'];?></p>
      <p><span>SA Distribution:</span> <?php print $attr['sa_distribution'];?></p>
      <p><span>Soil type:</span> <?php print $attr['soil_type'];?></p>
      <!--<p><span>Hort zone:</span> <?php /*print isset($node->field_hort_zone['und']) ? $node->field_hort_zone['und'][0]['taxonomy_term']->name : "" ;*/?></p>-->
      <p><span>Flowering season:</span> <?php print $attr['flowering_season'];?></p>
      <p><span>PH:</span> <?php print $attr['soil_ph'];?></p>
      <p><span>Flower colour:</span> <?php print $attr['flower_colour'];?></p>
      <p><span>Aspect:</span> <?php print $attr['exposure'];?></p>
      <p><span>Gardening skill:</span> <?php print $attr['gardening_skill'];?></p>
      <h4>Special Features:</h4>

      <?php if (isset($node->field_special_features['und'])):?>
        <?php foreach ($node->field_special_features['und'] as $key => $special_feature):?>
          <?php

          // Check that the term has an image
          if (isset($special_feature['taxonomy_term']->field_image['und'])) {

              // Get URL
              $uri = $special_feature['taxonomy_term']->field_image['und'][0]['uri'];

              // Get Real path
              if ($wrapper = file_stream_wrapper_get_instance_by_uri($uri)) {

                // Real path
                //$realpath = $wrapper->realpath();

                // Relative path
                $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
              }

          }else{

            // Set to blank
            $path = '';

          }

          ?>
          <div class="feature-item">
            <img src="/<?php print $path;?>" alt="">
             <span><?php print $special_feature['taxonomy_term']->name;?></span>
          </div>
        <?php endforeach;?>
      <?php endif;?>

      <div class="special-features">
        <h3>Horticultural zones</h3>
        <div class="map-img">
          <img src="<?php print base_path() . path_to_theme();?>/images/advanced-map-img.png" alt="">
          <?php if (isset($hort_overlay)):?>
            <?php foreach($hort_overlay as $delta => $zone): ?>
              <img class="overlay <?php print $zone['class'];?>" src="<?php echo base_path() . path_to_theme();?>/images/<?php print $zone['image_name'];?>" alt="">
            <?php endforeach; ?>
          <?php endif;?>
        </div>
        <?php if (isset($node->field_hort_zone['und'][0])):?>
          <?php foreach($node->field_hort_zone['und'] as $delta => $zone): ?>
            <h4><?php print $zone['taxonomy_term']->name;?></h4>
          <?php endforeach; ?>
        <?php endif;?>
      </div>
    </div>
    <?php print render($region['sidebar_second']); ?>
  </div>
</div>
<div id="comments" class="share-comments <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="share">
    <?php print render($content['links']); ?>
    <div class="rating-wrap">
      <div class="share-col">
        <h4>Rate this article</h4>
        <p>Article well written and informative</p>
        <?php print render($content['field_rating_article']);?>
      </div>
      <div class="share-col">
        <h4>Rate this plant</h4>
        <p>Is this an interesting plant?</p>
        <?php print render($content['field_rating_plant']);?>
      </div>
    </div>
  </div>
  <?php print render($content['comments']); ?>
  <?php if (!user_is_logged_in()):?>
  <div class="comments-area not-login">
    <p>
      <a href="#" class="login-fire">Login</a> to add your Comment<br>
      Not registered yet? <a href="#" class="reg-fire">Click here to register.</a>
    </p>
    <a class="backtop-btn" href="#">Back to top</a>
  </div>
  <?php endif;?>
</div>
<div class="clear"></div>