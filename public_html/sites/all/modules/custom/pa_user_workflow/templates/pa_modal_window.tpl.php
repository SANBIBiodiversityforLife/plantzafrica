<?php
/*
 * @file pa_modal_window.tpl.php
 * template file providing HTML markup for bootstrap modals
 */
?>
<!-- Modal -->
<div class="modal fade <?php print isset($class)? $class : ''; ?>" id="<?php print $modal_id; ?>" tabindex="-1" role="dialog" aria-labelledby="<?php print $modal_id; ?>Label" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content clearfix">
      <div class="modal-close"></div>
      <div class="head rounded">
        <div class="logo1"><img src="<?php echo base_path() . drupal_get_path('theme', $GLOBALS['theme']);?>/images/plantzafrica-logo.jpg" alt=""></div>
        <h1 class="modal-title"><?php print $title; ?></h1>
      </div>
      <div class="modal-inner-content clearfix">
        <?php print render($content); ?>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->