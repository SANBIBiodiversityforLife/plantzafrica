<?php
/**
 * @file
 * terms_conditions_page.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function terms_conditions_page_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'12636\',
      \'uid\' => \'1\',
      \'title\' => \'Terms & Conditions\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'fd7f8031-74b8-4fff-8d53-71fdd4acc1d5\',
      \'nid\' => \'12636\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1414594447\',
      \'changed\' => \'1414745358\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5cb3946e-9553-4808-8725-24a24b500d73\',
      \'revision_timestamp\' => \'1414745358\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<h2>Terms &amp; Conditions</h2><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent tincidunt dapibus felis, a cursus ante venenatis eu. In quis enim sodales, ultrices dolor ac, accumsan purus. Suspendisse nibh est, placerat ac velit sit amet, commodo consequat odio. Aenean eu posuere felis. Etiam at velit purus. Praesent vel laoreet eros. Quisque porttitor maximus tristique. Nullam eleifend ligula posuere finibus rhoncus. Curabitur eu mi sit amet nisi vehicula pharetra et et nunc. In hac habitasse platea dictumst. Praesent rutrum orci urna, pretium iaculis lectus accumsan eu. Nunc eu fringilla dui, ac volutpat diam. Suspendisse eget sem tellus. Curabitur vel massa aliquam metus interdum gravida ac ut magna. Aenean id facilisis est, nec fermentum quam. Donec nisl felis, ullamcorper quis volutpat eu, varius a ipsum. Sed imperdiet lorem elit, mollis suscipit odio pretium sed. Nam id ultricies neque, non interdum augue. Praesent viverra mauris ac ullamcorper elementum. Aliquam malesuada, enim sit amet dictum vestibulum, ante purus porttitor ipsum, efficitur imperdiet metus ipsum feugiat odio. Phasellus porta auctor sapien sit amet convallis. Mauris fermentum tristique urna, nec commodo ligula dapibus et. Nam eleifend augue risus, a sodales justo convallis cursus.</p>\',
            \'summary\' => \'\',
            \'format\' => \'full_html\',
          ),
        ),
      ),
      \'field_image\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1414594447\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'path\' => array(
        \'pid\' => \'47552\',
        \'source\' => \'node/12636\',
        \'alias\' => \'terms-conditions\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
