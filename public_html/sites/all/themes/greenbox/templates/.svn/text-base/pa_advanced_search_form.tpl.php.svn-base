<?php
/**
 * Template file which allows us to place form elements within custom HTML markup.
 * To output a form field use the following syntax: print render($form['ELEMENT_ID']);
 * drupal_render_children then outputs the remaining hidden input elements etc at the bottom of the form.
 *
 * Use krumo($form) to have a look at the structure. If you need to add custom classes etc do so in the pa_advanced_search_form
 * function contained in pa_advanced_search.forms.inc. You can assign new attributes using the #attributes FAPI key.
 */
?>
<?php if(arg(2) == 'advanced'): ?>
  <div class="top-link-bar">
    <a href="/plants/search/list">Go to Plants of the Week to browse all plants alphabetically or by date.</a>
  </div>
<?php endif; ?>
<div class="grey-container top clear">
  <div class="grey-content clear">
    <div class="advanced-top-content">
      <div class="row">
        <span>Search within the Plants Of the Week article text</span>
        <?php print drupal_render($form['name']); ?>
        <?php print drupal_render($form['top_submit']); ?>
      </div>
    </div>
  
    <div class="advanced-mid-content clear">
      <div class="column1">
        <div class="select-container">
          <h4>The plant</h4>
          <div class="select-left-column">

            <!-- PLANT TYPE -->
          <?php if(isset($form['facets']['plant']['plant_type'])): ?>
            <div class="row">
              <span>Type of plant</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Click in block &amp; Press CTRL key to select 2 or more types.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['plant']['plant_type']); ?>
            </div>
          <?php endif; ?>

          <!--FLOWERING SEASON-->
          <?php if(isset($form['facets']['plant']['flowering_season'])): ?>
            <div class="row">
              <span>Flowering season</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Click in block &amp; Press CTRL key to select 2 or more seasons.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['plant']['flowering_season']); ?>
            </div>
          <?php endif; ?>

          <!--DISTRO-->
          <?php if(isset($form['facets']['plant']['distribution'])): ?>
            <div class="row">
              <span>SA distribution</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Click in block &amp; Press CTRL key to select 2 or more provinces.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['plant']['distribution']); ?>
            </div>
          <?php endif; ?>
          </div>

          <div class="select-right-column">
          <!--FLOWER COLOUR-->
          <?php if(isset($form['facets']['plant']['flower_colour'])): ?>
            <div class="row">
              <span>Flower colour</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Click in block &amp; Press CTRL key to select 2 or more colours.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['plant']['flower_colour']); ?>
            </div>
          <?php endif; ?>

          <!--GARDENING SKILL-->
          <?php if(isset($form['facets']['plant']['gardening_skill'])): ?>
            <div class="row">
              <span>Gardening skill</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Some plants are easier to grow than others.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['plant']['gardening_skill']); ?>
            </div>
          </div>
        <?php endif; ?>
        </div>
        <!-- Special feature checkboxes BEGIN -->
        <div class="special-features">
          <h4>Special features</h4>
          <div class="row">
          <!--ATTRACTS BIRDS-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Attracts birds'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/birds-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Attracts birds']); ?>
                Attracts birds
              </label>
            </div>
          <?php endif; ?>

          <!--FRAGRANT-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Fragrant'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/fragrant-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Fragrant']); ?>
                Fragrant
              </label>
            </div>
          <?php endif; ?>
          </div>

          <div class="row">
          <!--ATTRACTS BUTTERFLIES-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Attracts butterflies'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/butterflies-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Attracts butterflies']); ?>
                Attracts butterflies
              </label>
            </div>
          <?php endif; ?>

          <!--FEEDS HONEYBEES-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Feeds honeybees'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/honeybees-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Feeds honeybees']); ?>
                Feeds honeybees
              </label>
            </div>
          <?php endif; ?>
          </div>

          <div class="row">
          <!--PIONEER PLANT-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Pioneer plant'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/pioneer-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Pioneer plant']); ?>
                Pioneer plant
              </label>
            </div>
          <?php endif; ?>

          <!--DROUGHT RESISTANT-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Drought resistant'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/resistent-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Drought resistant']); ?>
                Drought resistent
              </label>
            </div>
          <?php endif; ?>
          </div>

          <div class="row">
          <!--WET SITES-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Wet sites'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/sites-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Wet sites']); ?>
                Wet sites
              </label>
            </div>
          <?php endif; ?>
          </div>

          <div class="row">
          <!--GOOD POTPLANT-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Good potplant'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/potplant-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Good potplant']); ?>
                Good potplant
              </label>
            </div>
          <?php endif; ?>

          <!--INDOOR PLANT-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Indoor plant'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/indoor-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Indoor plant']); ?>
                Indoor plant
              </label>
            </div>
          <?php endif; ?>
          </div>

            <div class="row">
            <!--Architectural plant-->
            <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Feature plant'])): ?>
              <div class="checkbox-content">
                <div class="special-features-icon">
                  <img src="<?php echo base_path() . path_to_theme();?>/images/architectural-icon.png" alt="">
                </div>
                <label>
                  <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Feature plant']); ?>
                  Feature plant
                </label>
              </div>
            <?php endif; ?>
            <!--HEDGE PLANT-->
            <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Hedge/screen'])): ?>
              <div class="checkbox-content">
                <div class="special-features-icon">
                  <img src="<?php echo base_path() . path_to_theme();?>/images/hedge-icon.png" alt="">
                </div>
                <label>
                  <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Hedge/screen']); ?>
                  Hedge/screen
                </label>
              </div>
            <?php endif; ?>
            </div>

            <div class="row">
            <!--POISONOUS-->
            <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Poisonous'])): ?>
              <div class="checkbox-content">
                <div class="special-features-icon">
                  <img src="<?php echo base_path() . path_to_theme();?>/images/poisonous-icon.png" alt="">
                </div>
                <label>
                  <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Poisonous']); ?>
                  Poisonous
                </label>
              </div>
            <?php endif; ?>

            <!--OTHER USES-->
            <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Useful plant'])): ?>
              <div class="checkbox-content">
                <div class="special-features-icon">
                  <img src="<?php echo base_path() . path_to_theme();?>/images/uses-icon.png" alt="">
                </div>
                <label>
                  <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Useful plant']); ?>
                  Other uses
                </label>
              </div>
            <?php endif; ?>
            </div>

          <div class="row">
          <!--EDIBLE-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Edible plant'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/edible-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Edible plant']); ?>
                Edible
              </label>
            </div>
          <?php endif; ?>

          <!--MEDICIAL-->
          <?php if(isset($form['facets']['features']['special_features']['field_special_features%3Aname:Medical plant'])): ?>
            <div class="checkbox-content">
              <div class="special-features-icon">
                <img src="<?php echo base_path() . path_to_theme();?>/images/medicinal-icon.png" alt="">
              </div>
              <label>
                <?php print drupal_render($form['facets']['features']['special_features']['field_special_features%3Aname:Medical plant']); ?>
                Medicinal
              </label>
            </div>
          <?php endif; ?>
          </div>

        </div>
      </div>

      <div class="column2">
        <div class="map-title-bar">
          <h4>The gardening site</h4>
          <p>Horticultural zones <a target="_blank" href="/horticultural-zones">Learn more about Horticultural zones</a></p>
        </div>
        <div class="map-features-wrap clear">
          <div class="map-container" id="mapContainer">
            <div class="map-zone-number">
              <div id="zone-number1">1</div>
              <div id="zone-number2">2</div>
              <div id="zone-number3">3</div>
              <div id="zone-number4">4</div>
              <div id="zone-number5">5</div>
            </div>
            <div class="country-one-tooltip">
              <p>Zone1<br> Coastal summer rainfall</p>
              <div class="bubble"></div>
            </div>
            <div class="country-two-tooltip">
              <p>Zone2<br> Coastal winter rainfall</p>
              <div class="bubble"></div>
            </div>
            <div class="country-three-tooltip">
              <p>Zone3<br> Winter rainfall Karoo</p>
              <div class="bubble"></div>
            </div>
            <div class="country-four-tooltip">
              <p>Zone4<br> Summer rainfall Karoo/Highveld</p>
              <div class="bubble"></div>
            </div>
            <div class="country-five-tooltip">
              <p>Zone5<br> Bushveld summer rainfall</p>
              <div class="bubble"></div>
            </div>

            <div id="zone-bullet1">
              <div class="map-bullet-tooltip">
                <p>Pietermaritzburg - Zone 5</p>
                <div class="red-bullet-bubble"></div>
              </div>
            </div>
            <div id="zone-bullet2">
              <div class="map-bullet-tooltip">
                <p>Port Elizabeth - Zone 1</p>
                <div class="red-bullet-bubble"></div>
              </div>
            </div>
            <div id="zone-bullet3">
              <div class="map-bullet-tooltip">
                <p>Worcester - Zone 3</p>
                <div class="red-bullet-bubble"></div>
              </div>
            </div>
            <div id="zone-bullet4">
              <div class="map-bullet-tooltip">
                <p>Pretoria - Zone 4</p>
                <div class="red-bullet-bubble"></div>
              </div>
            </div>
            <div class="map-transparent-img">
              <img src="<?php echo base_path() . path_to_theme();?>/images/map-transparent.gif" alt="" usemap="#map">
              <map name="map" id="map">
                <area shape="poly" id="zoneOne" alt="" coords="283,1,285,8,285,12,284,18,278,27,274,31,270,40,263,43,258,50,250,66,250,78,250,92,251,105,254,137,250,150,244,163,236,173,229,186,221,195,209,206,198,212,184,220,174,223,166,225,165,229,173,234,187,226,193,225,203,215,210,211,220,202,235,187,247,171,252,165,255,158,264,151,272,148,279,137,283,131,284,123,289,109,291,99,286,94,290,90,294,87,298,85,302,84,303,80,304,78,305,1,284,2" href="country-one-tooltip">
                <area shape="poly" id="zoneTwo" alt="" coords="168,231,165,226,161,224,156,226,144,227,128,227,118,227,105,228,94,228,82,227,75,224,67,218,60,212,54,205,50,205,46,204,46,207,42,206,41,207,42,212,44,215,46,218,47,221,50,223,49,226,49,229,50,232,51,233,55,235,57,239,61,238,64,241,68,244,69,246,75,243,80,241,86,239,95,239,100,238,107,236,109,233,115,233,121,233,127,233,135,232,141,232,146,233,150,234,154,233,158,232,165,232,167,232,169,232" href="country-two-tooltip">
                <area shape="poly" id="zoneThree" alt="" coords="1,75,6,83,8,91,11,100,17,107,23,113,26,119,34,122,44,127,52,132,60,139,68,147,77,161,83,173,92,184,102,196,116,206,131,213,147,217,156,218,166,218,160,224,147,226,131,227,116,227,99,228,86,227,74,223,63,214,55,208,52,206,46,206,48,198,47,191,45,185,43,179,40,177,36,175,35,169,36,165,30,162,29,156,28,149,24,149,24,145,23,139,20,136,16,134,13,130,10,125,6,121,3,117,1,115,0,75,1,74" href="country-three-tooltip">
                <area shape="poly" id="zoneFour" alt="" coords="39,124,34,122,29,119,26,117,27,111,36,107,46,103,56,101,70,101,83,101,102,101,107,96,115,94,123,85,133,80,149,78,168,82,177,82,189,79,197,79,204,80,211,79,224,71,230,63,232,56,233,54,237,59,239,65,241,72,243,88,242,95,241,101,236,113,233,119,230,127,228,137,226,147,223,154,222,162,215,172,207,184,197,193,188,202,182,207,174,212,168,216,166,217,161,217,150,216,137,214,126,210,112,203,104,198,98,189,82,169,78,159,68,144,56,133,43,126,46,127" href="country-four-tooltip">
                <area shape="poly" id="zoneFive" alt="" coords="1,1,283,1,285,7,283,17,275,27,270,37,258,47,250,62,249,71,249,92,252,116,252,140,243,165,232,180,223,193,204,209,189,217,174,223,165,225,161,223,173,213,187,203,201,191,210,180,215,173,219,166,223,161,225,146,228,137,229,125,233,117,239,104,242,97,243,88,241,75,239,67,237,60,232,53,229,59,228,64,225,70,221,76,209,80,198,78,187,80,179,81,174,83,165,81,156,79,145,77,137,78,126,81,121,87,115,92,108,96,102,101,89,101,72,100,51,101,37,105,28,110,24,115,17,107,14,103,11,97,8,88,5,80,2,75,2,3" href="country-five-tooltip">
              </map>
            </div>
            <div id="coloredMaps">
              <div class="zoneOne"></div>
              <div class="zoneTwo"></div>
              <div class="zoneThree"></div>
              <div class="zoneFour"></div>
              <div class="zoneFive"></div>
            </div>
          </div>
          <div class="zone-bar" id="zoneChecks">
          <?php if(isset($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 1 Coastal summer rainfall, frost free'])): ?>
            <div class="countryCheck1">
              <small>
                <?php print drupal_render($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 1 Coastal summer rainfall, frost free']); ?>
                Zone 1 <span>Coastal Summer rainfall</span>
              </small>
            </div>
          <?php endif; ?>
          <?php if(isset($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 2 Coastal winter rainfall, frost free'])): ?>
            <div class="countryCheck2">
              <small>
                <?php print drupal_render($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 2 Coastal winter rainfall, frost free']); ?>
                Zone 2 <span>Coastal Winter rainfall</span>
              </small>
            </div>
          <?php endif; ?>
          <?php if(isset($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 3 Winter rainfall Karoo, light frost'])): ?>
            <div class="countryCheck3">
              <small>
                <?php print drupal_render($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 3 Winter rainfall Karoo, light frost']); ?>
                Zone 3 <span>Winter rainfall Karoo</span>
              </small>
            </div>
          <?php endif; ?>
          <?php if(isset($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 4 Summer rainfall Karoo and Highveld, Frost in winter'])): ?>
            <div class="countryCheck4">
              <small>
                <?php print drupal_render($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 4 Summer rainfall Karoo and Highveld, Frost in winter']); ?>
                Zone 4 <span>Summer rainfall Karoo/Highveld</span>
              </small>
            </div>
          <?php endif; ?>
          <?php if(isset($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 5  Bushveld summer rainfall, Light frost'])): ?>
            <div class="countryCheck5">
              <small>
                <?php print drupal_render($form['facets']['gardening']['hort_zone']['field_hort_zone%3Aname:Zone 5  Bushveld summer rainfall, Light frost']); ?>
                Zone 5 <span>Bushveld Summer rainfall</span>
              </small>
            </div>
          <?php endif; ?>
          </div>
        </div>

        <div class="select-container mbPadding clear">
          <div class="select-left-column">
          <!--SOIL TYPE-->
          <?php if(isset($form['facets']['gardening']['soil_type'])): ?>
            <div class="row">
              <span>Soil type</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Click in block &amp; Press CTRL key to select 2 or more soil types.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['gardening']['soil_type']); ?>
            </div>
          <?php endif; ?>

          <!--EXPOSURE-->
          <?php if(isset($form['facets']['gardening']['exposure'])): ?>
            <div class="row">
              <span>Exposure</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Click in block &amp; Press CTRL key to select 2 or more exposures.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['gardening']['exposure']); ?>
            </div>
          <?php endif; ?>
          </div>

          <div class="select-right-column">
          <!--EXPOSURE-->
          <?php if(isset($form['facets']['gardening']['ph'])): ?>
            <div class="row">
              <span>PH</span>
              <div class="question-icon">
                <div class="tooltip">
                  <p>Click in block &amp; Press CTRL key to select 2 or more PH levels.</p>
                  <div class="select-bubble"></div>
                </div>
              </div>
              <?php print drupal_render($form['facets']['gardening']['ph']); ?>
            </div>
          <?php endif; ?>
          </div>

        </div>
      </div>
    </div>
  </div>
  <?php print drupal_render($form['submit']); ?>
</div>
<?php print drupal_render_children($form); ?>