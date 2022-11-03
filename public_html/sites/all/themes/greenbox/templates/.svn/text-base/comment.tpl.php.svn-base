<?php
/**
 * @file
 * Zen theme's implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   - first: The first comment in the list of displayed comments.
 *   - last: The last comment in the list of displayed comments.
 *   - odd: An odd-numbered comment in the list of displayed comments.
 *   - even: An even-numbered comment in the list of displayed comments.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since the last visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see zen_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 */

// Author username
$comment_author = $content['comment_body']['#object']->name;

// Comment created
$comment_created = $content['comment_body']['#object']->created;

// Load profile
if ($user = user_load($content['comment_body']['#object']->uid)){

  // First name
  $display_name = (isset($user->field_first_name['und'][0]['value'])) ? $user->field_first_name['und'][0]['value'] . ' ' : '';

  // Last name
  $display_name.= (isset($user->field_last_name['und'][0]['value'])) ? $user->field_last_name['und'][0]['value'] : '';

  // The country
  if (isset($user->field_country['und'][0]['iso2'])){

    // Iso2
    $iso2 = $user->field_country['und'][0]['iso2'];

    // Load country
    $country = country_load($iso2);

    // Add country name to display name
    $display_name.= ', ' . $country->name;
  }

}

// If empty then show message
$display_name = ($display_name) ? $display_name : "*Unable to load user information*";

?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="date-time">

    <?php //print render($title_prefix); ?>
    <?php if ($display_name): ?>
      <h4>
        <?php print render($display_name); ?>
      </h4>
    <?php endif;?>
    <?php print render($title_suffix); ?>

    <span><?php print gmdate("F d, Y", $comment_created);?> at <?php print date("g:i A", $comment_created); ?></span>
  </div>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['links']);
      print render($content);
    ?>
    <?php if ($signature): ?>
      <div class="user-signature clearfix">
        <?php print $signature; ?>
      </div>
    <?php endif; ?>
  </div>

  <?php print $picture; ?>

  <?php if ($status == 'comment-unpublished'): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>

  <div class="submitted">
    <?php //print $permalink; ?>
  </div>

  <?php //print render($content['links']) ?>
</div><!-- /.comment -->
