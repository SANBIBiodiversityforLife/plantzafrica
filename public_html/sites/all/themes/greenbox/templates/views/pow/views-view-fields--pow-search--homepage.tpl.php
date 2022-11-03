<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
  <div class="img-figure"><?php print $fields['field_primary_image']->content; ?></div>
  <div class="start-texts">
    <p><span>Common names: </span> <?php print $fields['field_common_names']->content; ?><br/><br/>
      <?php print $fields['field_introduction']->content; ?>
    </p>
    <div>
      <span><?php print $fields['field_cost_center_name']->content; ?></span>
    </div>
    <a class="readmore-btn" href="<?php print $fields['url']->content; ?>">Read more</a>
  </div>
  <div class="img-overlay">
    <a href="<?php print $fields['url']->content; ?>"><?php print $fields['title']->content; ?></a>
  </div>