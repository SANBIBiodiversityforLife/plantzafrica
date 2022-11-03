<div class="tab-item">
  <?php if(arg(2) == 'list'): ?>
    <h2>Browse through all previous entries of Plants Of The Week</h2>
  <?php elseif(!empty($results)): ?>
    <br/>
    <h2>Search results <?php print (isset($_GET['name']) && $_GET['name'] != '')? 'for "' . $_GET['name'] . '"' : '' ?> (displaying <?php print $stats['viewing']; ?> of <?php print $stats['total']; ?> on page <?php print $stats['page']; ?>)</h2>
    <a class="Search-link" href="#">Refine your search</a>
  <?php else: ?>
    <br/>
    <h2>Search results</h2>
  <?php endif; ?>

  <div class="tabs">
    <ul id="tab-list">
      <li data-redirect="<?php print $tab_url['date']; ?>">Sort by date added</li>
      <li data-redirect="<?php print $tab_url['title']; ?>">Sort Alphabetically</li>
    </ul>
    <?php if(arg(2) == 'list'): ?>
      <a href="/plants/search/advanced" class="sort-search-link">Go to Plants of the Week Advanced Search</a>
    <?php endif; ?>
  </div>

  <div id="tab-contents">
    <div class="post-wrap sort-by-date tab-contents clearfix" style="display: block;">
      <div class="selection-item">
        <div class="search-option sort-options">
          <?php if(arg(2) == 'list'): ?>
            <div class="date-widget clearfix"><?php print render($date_form); ?></div>
          <?php endif; ?>
          <div class="date-sort clearfix"><?php print $sort['date']['asc']; ?> | <?php print $sort['date']['desc']; ?></div>
        </div>
      </div>
      <div class="selection-item">
      <?php if(arg(2) == 'list'): ?>
        <div class="pagination">
          <?php print $glossary_nav; ?>
        </div>
      <?php endif; ?>
        <div class="search-option sort-options">
          <div class="date-sort clearfix"><?php print $sort['title']['asc']; ?> | <?php print $sort['title']['desc']; ?></div>
        </div>
      </div>
      <?php if(!empty($results)): ?>
        <?php if($pager): ?>
          <div class="pagination2 first">
            <div class="pager">
              <?php print $pager; ?>
            </div>
          </div>
        <?php endif; ?>

        <?php $i = 0; ?>
        <?php foreach($results as $delta => $p): ?>
          <div class="post <?php echo fmod($i, 2) ? '' : 'gray-bg' ?>">
            <h3><a href="/<?php print drupal_get_path_alias('node/' . $p->nid); ?>"><?php print $p->title; ?></a></h3>

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
              <div class="img-figure">
                <a href="/<?php print drupal_get_path_alias('node/' . $p->nid); ?>"><?php print $image; ?></a>
              </div>
            <?php endif; ?>

            <div class="text-wrap">

              <!--Common name-->
              <?php if(isset($p->field_common_names[$p->language][0]['value'])): ?>
                <?php $names = strip_tags($p->field_common_names[$p->language][0]['value']); ?>
                <?php $names = substr($names, 0, 150); ?>
                <div class="names"><span>Common names:</span> <?php print $names; ?></div>
              <?php endif; ?>

              <!--Familly-->
              <?php if(isset($p->field_family[$p->language][0]['tid'])): ?>
                <?php $family = taxonomy_term_load($p->field_family[$p->language][0]['tid']); ?>
                <div class="names"><span>Family:</span> <?php print $family->name; ?></div>
              <?php endif; ?>

              <!--Introduction /* was Description */ -->
              <?php if(isset($p->excerpt)): ?>
                <p><?php print $p->excerpt; ?></p>
              <?php /* RR was field_description */ elseif(isset($p->field_introduction[$p->language][0]['value'])): ?>
                <?php $desc = strip_tags($p->field_introduction[$p->language][0]['value']); ?>
                <?php if(strlen($desc) >= 150): ?>
                  <?php $pos = strpos($desc, ' ', 150); ?>
                  <?php $desc = substr($desc, 0, $pos); ?>
                <?php endif; ?>
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
              <div class="date-info">
                <span><strong><?php if (isset($p->field_week[$p->language][0]['value'])) print format_date(strtotime($p->field_week[$p->language][0]['value']), 'custom', 'd / m / Y'); ?></strong></span> | <?php print ($name != '')? $name : ''; ?> | <?php print (isset($cc->name))? $cc->name : ''; ?>
              </div>

              <a class="readmore-btn" href="/<?php print drupal_get_path_alias('node/' . $p->nid); ?>">Read More</a>

            </div>
          </div>
          <?php $i++; ?>
        <?php endforeach; ?>

        <div class="pagination-wrap">
          <?php if($pager): ?>
            <div class="pagination2">
              <div class="pager">
                <?php print $pager; ?>
              </div>
            </div>
          <?php endif; ?>
          <a class="backtop-btn" href="#">Back to top</a>
        </div>

      <!-- if no results found -->
      <?php else: ?>
        <p>Unfortunately we couldn't find any Plants which match your search criteria.<br/><br/></p>
        <p>Please refine your search and try again.</p>
      <?php endif; ?>

    </div>
  </div>
</div>