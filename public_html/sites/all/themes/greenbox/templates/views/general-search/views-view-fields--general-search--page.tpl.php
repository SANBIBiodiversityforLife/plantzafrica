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
<?php if($fields['type']->content == 'Plant'): ?>

  <div class="item-title">
    <h3><a href="<?php print $fields['url']->content; ?>"><?php print $fields['title']->content; ?></a></h3>
    <span class="pull-right">Plant</span>
  </div>
  <div class="names">Common names: <?php print $fields['field_common_names']->content; ?></div>
  <div class="names">Family: <?php print $fields['field_family_name']->content; ?></div>
  <p><?php print $fields['search_api_excerpt']->content; ?></p>
  <div class="date-info">
    <span><?php print $fields['field_week']->content; ?></span> | <?php print $fields['field_authors_field_first_name']->content; ?> <?php print $fields['field_authors_field_last_name']->content; ?> | <?php print $fields['field_cost_center_name']->content; ?>
  </div>

<?php elseif($fields['type']->content == 'Basic page'): ?>

  <div class="item-title">
    <h3><a href="<?php print $fields['url']->content; ?>"><?php print $fields['title']->content; ?></a></h3>
    <span class="pull-right">Content page</span>
  </div>
  <p><?php print $fields['search_api_excerpt']->content; ?></p>

<?php elseif($fields['type']->content == 'Info Library entry'): ?>

  <div class="item-title">
    <h3><a href="<?php print $fields['field_file']->content; ?>"><?php print $fields['title']->content; ?></a></h3>
    <span class="pull-right">Information Library item</span>
  </div>
  <div class="item-info">
    <?php
      $keywords = explode(',', $fields['field_keywords_name']->content);
      $key_links = array();
      foreach($keywords as $delta => $word){
        $key_links[] = '<a href="/search?s=' . urlencode($word) . '">' . $word . '</a>';
      }
      $key_links = implode(', ', $key_links);
    ?>
    Author: <?php print $fields['field_author_name']->content; ?> &nbsp; | &nbsp; Date: <?php print $fields['field_date']->content; ?> <br>
    Source: <?php print print $fields['field_source']->content; ?> &nbsp; | &nbsp; Copyright: <?php print $fields['field_publisher_copyright_name']->content; ?>
  </div>
  <p><?php print $fields['search_api_excerpt']->content; ?></p>
  <dfn><p><?php print $key_links; ?></p></dfn>

<?php elseif($fields['type']->content == 'Vegetation'): ?>
  <div class="item-title">
    <h3><a href="<?php print $fields['url']->content; ?>"><?php print $fields['title']->content; ?></a></h3>
    <span class="pull-right">Vegetation</span>
  </div>
  <p><?php print $fields['search_api_excerpt']->content; ?></p>
<?php endif; ?>