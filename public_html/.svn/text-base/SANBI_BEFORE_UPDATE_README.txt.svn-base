note that module Taxonomy Single Tag has been customized to display a longer list of possible matches:
In 'function taxonomy_single_tag_autocomplete($field_name, $tag_typed = '') {' change
// Select rows that match by term name.
    $tags_return = $query
      ->fields('t', array('tid', 'name'))
      ->condition('t.vid', $vids)
      ->condition('t.name', '%' . db_like($tag) . '%', 'LIKE')
      ->range(0, 20)
      ->execute()
      ->fetchAllKeyed();
    /* RR changed range from 0,10 to 0,20 */
	