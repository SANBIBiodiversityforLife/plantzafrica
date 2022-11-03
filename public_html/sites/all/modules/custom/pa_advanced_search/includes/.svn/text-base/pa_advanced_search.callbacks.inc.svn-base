<?php
/**
 * @file pa_advanced_search.callbacks.inc
 * Provides custom Search API data alteration callbacks to store the first letter of Plant titles for indexing.
 */

/**
 * Implements hook_search_api_alter_callback_info().
 */
function pa_advanced_search_search_api_alter_callback_info() {
  $callbacks['pa_advanced_search_alter_add_first_letter_title'] = array(
    'name' => t('First letter of Plant title'),
    'description' => t('This module provides first letter of title for glossary view.'),
    'class' => 'AdvancedSearchAddFirstLetter',
  );

  return $callbacks;
}

/**
 * Search API data alteration callback that adds the first letter of title  for glossary mode.
 */
class AdvancedSearchAddFirstLetter extends SearchApiAbstractAlterCallback {

  //declare our new solr index field "search_api_title_first_letter"
  public function propertyInfo() {
    return array(
      'search_api_title_first_letter' => array(
        'label' => t('First Letter of title field'),
        'description' => t('For listings grouped by first letter (glossary mode).'),
        'type' => 'text',
      ),
    );
  }

  //alterItems declaration to allow us to set our first letter index field value
  public function alterItems(array &$items) {
    foreach ($items as $id => &$item) {
      if (!isset($item->title)) {
        $item->search_api_title_first_letter = NULL;
        continue;
      }
      $item->search_api_title_first_letter = substr($item->title,0,1);
    }
  }

}