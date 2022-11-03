<div class="search-test-container">
  <hr/>
  <div class="glossary-sort">
    <strong>Glossary: </strong> <?php print $glossary_nav; ?>
  </div>
  <hr/>
  <?php if(!empty($results)): ?>
    <div class="results-sort">
      <strong>Sort by Date: </strong> <?php print $sort['date']['asc']; ?> | <?php print $sort['date']['desc']; ?>
    </div>
    <hr/>
    <div class="test-results">
      <p>Displaying <strong><?php print $stats['viewing']; ?></strong> of <strong><?php print $stats['total']; ?></strong> plants on <strong>page <?php print $stats['page']; ?></strong>.</p>
      <?php foreach($results as $delta => $p): ?>
        <div class="search-result clearfix">
          <h2><strong><a href="/<?php print drupal_get_path_alias('node/' . $p->nid); ?>"><?php print $p->title; ?></a></strong></h2>

          <!--Primary image style themed output-->
          <?php if(isset($p->field_primary_image[$p->language][0]['uri'])): ?>
            <?php
              $image = theme('image_style', array(
              'style_name' => 'plant_listing',
              'path' => $p->field_primary_image[$p->language][0]['uri'],
              'alt' => $p->field_primary_image[$p->language][0]['alt'],
              'title' => $p->field_primary_image[$p->language][0]['title'],
              'attributes' => array('style' => 'float:left;')
                )
              );
            ?>
            <a href="/<?php print drupal_get_path_alias('node/' . $p->nid); ?>"><?php print $image; ?></a>
          <?php endif; ?>

          <!--Common name-->
          <?php if(isset($p->field_common_names[$p->language][0]['value'])): ?>
            <strong>Common name:</strong> <?php print $p->field_common_names[$p->language][0]['value']; ?><br/>
          <?php endif; ?>

          <!--Familly-->
          <?php if(isset($p->field_family[$p->language][0]['tid'])): ?>
            <?php $family = taxonomy_term_load($p->field_family[$p->language][0]['tid']); ?>
            <strong>Family:</strong> <?php print $family->name; ?><br/>
          <?php endif; ?>

          <!--Description-->
          <?php if(isset($p->field_description[$p->language][0]['safe_value'])): ?>
            <?php $desc = strip_tags($p->field_description[$p->language][0]['safe_value']); ?>
            <?php $pos = strpos($desc, ' ', 150); ?>
            <?php $desc = substr($desc, 0, $pos); ?>
            <p><?php print ($desc); ?>...</p>
          <?php endif; ?>

          <!--Authors-->
          <?php $name = ''; ?>
          <?php if(isset($p->field_authors[$p->language][0]['target_id'])): ?>
            <?php $author = user_load($p->field_authors[$p->language][0]['target_id']); ?>
            <?php if(isset($author->field_first_name[$p->language]) && isset($author->field_last_name[$p->language])): ?>
              <?php $name = $author->field_first_name[$p->language][0]['safe_value'] . ' ' . $author->field_last_name[$p->language][0]['safe_value']; ?>
            <?php endif; ?>
          <?php endif; ?>

          <!--Cost centre-->
          <?php if(isset($p->field_cost_center[$p->language][0]['tid'])): ?>
            <?php $cc = taxonomy_term_load($p->field_cost_center[$p->language][0]['tid']); ?>
          <?php endif; ?>

          <!--Author, date and cost centre output-->
          <strong><?php print format_date(strtotime($p->field_week[$p->language][0]['value']), 'custom', 'd / m / Y'); ?> | <?php print ($name != '')? $name : ''; ?> | <?php print (isset($cc->name))? $cc->name : ''; ?></strong>
        </div>
      <?php endforeach; ?>
      <?php if($pager): ?>
      <div class="pager">
        <?php print $pager; ?>
      </div>
      <?php endif; ?>
    </div>
  <?php else: ?>
    <p>Unfortunately we couldn't find any Plants which match your search criteria. Please refine your search and try again.</p>
  <?php endif; ?>
</div>