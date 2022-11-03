<?php
/**
 * @file
 * contact_page.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function contact_page_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'953\',
      \'uid\' => \'1\',
      \'title\' => \'Contact\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'fe2b7fd7-e7ea-417a-a5e1-dd31be1959ab\',
      \'nid\' => \'953\',
      \'type\' => \'webform\',
      \'language\' => \'und\',
      \'created\' => \'1414592747\',
      \'changed\' => \'1414592944\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'bec23124-55a8-4d6e-af67-fe58e35c143a\',
      \'revision_timestamp\' => \'1414592944\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<p><span style="font-family: proxima_nova_rgregular, Arial, Helvetica, sans-serif; font-size: 14px; line-height: 20px;">Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry&#39;s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.</span></p>\',
            \'summary\' => \'\',
            \'format\' => \'full_html\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'webform\' => array(
        \'nid\' => \'953\',
        \'confirmation\' => \'\',
        \'confirmation_format\' => NULL,
        \'redirect_url\' => \'<confirmation>\',
        \'status\' => \'1\',
        \'block\' => \'0\',
        \'teaser\' => \'0\',
        \'allow_draft\' => \'0\',
        \'auto_save\' => \'0\',
        \'submit_notice\' => \'1\',
        \'submit_text\' => \'\',
        \'submit_limit\' => \'-1\',
        \'submit_interval\' => \'-1\',
        \'total_submit_limit\' => \'-1\',
        \'total_submit_interval\' => \'-1\',
        \'record_exists\' => TRUE,
        \'roles\' => array(
          \'1\',
          \'2\',
        ),
        \'emails\' => array(
          1 => array(
            \'nid\' => \'953\',
            \'eid\' => \'1\',
            \'email\' => \'webmaster@sanbi.org.za\',
            \'subject\' => \'default\',
            \'from_name\' => \'no-reply@sanbi.org.za\',
            \'from_address\' => \'2\',
            \'template\' => \'default\',
            \'excluded_components\' => array(),
            \'html\' => \'0\',
            \'attachments\' => \'0\',
          ),
        ),
        \'components\' => array(
          1 => array(
            \'nid\' => 953,
            \'cid\' => \'1\',
            \'pid\' => \'0\',
            \'form_key\' => \'name\',
            \'name\' => \'Name\',
            \'type\' => \'textfield\',
            \'value\' => \'\',
            \'extra\' => array(
              \'title_display\' => \'before\',
              \'private\' => 0,
              \'disabled\' => 0,
              \'unique\' => 0,
              \'conditional_operator\' => \'=\',
              \'width\' => \'\',
              \'maxlength\' => \'\',
              \'field_prefix\' => \'\',
              \'field_suffix\' => \'\',
              \'description\' => \'\',
              \'attributes\' => array(),
              \'conditional_component\' => \'\',
              \'conditional_values\' => \'\',
            ),
            \'mandatory\' => \'0\',
            \'weight\' => \'0\',
            \'page_num\' => 1,
          ),
          2 => array(
            \'nid\' => 953,
            \'cid\' => \'2\',
            \'pid\' => \'0\',
            \'form_key\' => \'email\',
            \'name\' => \'Email\',
            \'type\' => \'email\',
            \'value\' => \'\',
            \'extra\' => array(
              \'title_display\' => \'before\',
              \'private\' => 0,
              \'disabled\' => 0,
              \'unique\' => 0,
              \'conditional_operator\' => \'=\',
              \'width\' => \'\',
              \'description\' => \'\',
              \'attributes\' => array(),
              \'conditional_component\' => \'\',
              \'conditional_values\' => \'\',
            ),
            \'mandatory\' => \'1\',
            \'weight\' => \'1\',
            \'page_num\' => 1,
          ),
          3 => array(
            \'nid\' => 953,
            \'cid\' => \'3\',
            \'pid\' => \'0\',
            \'form_key\' => \'phone_number\',
            \'name\' => \'Phone number\',
            \'type\' => \'textfield\',
            \'value\' => \'\',
            \'extra\' => array(
              \'title_display\' => \'before\',
              \'private\' => 0,
              \'disabled\' => 0,
              \'unique\' => 0,
              \'conditional_operator\' => \'=\',
              \'width\' => \'\',
              \'maxlength\' => \'\',
              \'field_prefix\' => \'\',
              \'field_suffix\' => \'\',
              \'description\' => \'\',
              \'attributes\' => array(),
              \'conditional_component\' => \'\',
              \'conditional_values\' => \'\',
            ),
            \'mandatory\' => \'0\',
            \'weight\' => \'2\',
            \'page_num\' => 1,
          ),
          5 => array(
            \'nid\' => 953,
            \'cid\' => \'5\',
            \'pid\' => \'0\',
            \'form_key\' => \'country\',
            \'name\' => \'Country\',
            \'type\' => \'select\',
            \'value\' => \'ZA\',
            \'extra\' => array(
              \'items\' => "AF|Afghanistan\\r\\nAX|Aland Islands\\r\\nAL|Albania\\r\\nDZ|Algeria\\r\\nAS|American Samoa\\r\\nAD|Andorra\\r\\nAO|Angola\\r\\nAI|Anguilla\\r\\nAQ|Antarctica\\r\\nAG|Antigua and Barbuda\\r\\nAR|Argentina\\r\\nAM|Armenia\\r\\nAW|Aruba\\r\\nAU|Australia\\r\\nAT|Austria\\r\\nAZ|Azerbaijan\\r\\nBS|Bahamas\\r\\nBH|Bahrain\\r\\nBD|Bangladesh\\r\\nBB|Barbados\\r\\nBY|Belarus\\r\\nBE|Belgium\\r\\nBZ|Belize\\r\\nBJ|Benin\\r\\nBM|Bermuda\\r\\nBT|Bhutan\\r\\nBO|Bolivia\\r\\nBA|Bosnia and Herzegovina\\r\\nBW|Botswana\\r\\nBV|Bouvet Island\\r\\nBR|Brazil\\r\\nIO|British Indian Ocean Territory\\r\\nVG|British Virgin Islands\\r\\nBN|Brunei\\r\\nBG|Bulgaria\\r\\nBF|Burkina Faso\\r\\nBI|Burundi\\r\\nKH|Cambodia\\r\\nCM|Cameroon\\r\\nCA|Canada\\r\\nCV|Cape Verde\\r\\nBQ|Caribbean Netherlands\\r\\nKY|Cayman Islands\\r\\nCF|Central African Republic\\r\\nTD|Chad\\r\\nCL|Chile\\r\\nCN|China\\r\\nCX|Christmas Island\\r\\nCC|Cocos (Keeling) Islands\\r\\nCO|Colombia\\r\\nKM|Comoros\\r\\nCG|Congo (Brazzaville)\\r\\nCD|Congo (Kinshasa)\\r\\nCK|Cook Islands\\r\\nCR|Costa Rica\\r\\nHR|Croatia\\r\\nCU|Cuba\\r\\nCW|Curaçao\\r\\nCY|Cyprus\\r\\nCZ|Czech Republic\\r\\nDK|Denmark\\r\\nDJ|Djibouti\\r\\nDM|Dominica\\r\\nDO|Dominican Republic\\r\\nEC|Ecuador\\r\\nEG|Egypt\\r\\nSV|El Salvador\\r\\nGQ|Equatorial Guinea\\r\\nER|Eritrea\\r\\nEE|Estonia\\r\\nET|Ethiopia\\r\\nFK|Falkland Islands\\r\\nFO|Faroe Islands\\r\\nFJ|Fiji\\r\\nFI|Finland\\r\\nFR|France\\r\\nGF|French Guiana\\r\\nPF|French Polynesia\\r\\nTF|French Southern Territories\\r\\nGA|Gabon\\r\\nGM|Gambia\\r\\nGE|Georgia\\r\\nDE|Germany\\r\\nGH|Ghana\\r\\nGI|Gibraltar\\r\\nGR|Greece\\r\\nGL|Greenland\\r\\nGD|Grenada\\r\\nGP|Guadeloupe\\r\\nGU|Guam\\r\\nGT|Guatemala\\r\\nGG|Guernsey\\r\\nGN|Guinea\\r\\nGW|Guinea-Bissau\\r\\nGY|Guyana\\r\\nHT|Haiti\\r\\nHM|Heard Island and McDonald Islands\\r\\nHN|Honduras\\r\\nHK|Hong Kong S.A.R., China\\r\\nHU|Hungary\\r\\nIS|Iceland\\r\\nIN|India\\r\\nID|Indonesia\\r\\nIR|Iran\\r\\nIQ|Iraq\\r\\nIE|Ireland\\r\\nIM|Isle of Man\\r\\nIL|Israel\\r\\nIT|Italy\\r\\nCI|Ivory Coast\\r\\nJM|Jamaica\\r\\nJP|Japan\\r\\nJE|Jersey\\r\\nJO|Jordan\\r\\nKZ|Kazakhstan\\r\\nKE|Kenya\\r\\nKI|Kiribati\\r\\nKW|Kuwait\\r\\nKG|Kyrgyzstan\\r\\nLA|Laos\\r\\nLV|Latvia\\r\\nLB|Lebanon\\r\\nLS|Lesotho\\r\\nLR|Liberia\\r\\nLY|Libya\\r\\nLI|Liechtenstein\\r\\nLT|Lithuania\\r\\nLU|Luxembourg\\r\\nMO|Macao S.A.R., China\\r\\nMK|Macedonia\\r\\nMG|Madagascar\\r\\nMW|Malawi\\r\\nMY|Malaysia\\r\\nMV|Maldives\\r\\nML|Mali\\r\\nMT|Malta\\r\\nMH|Marshall Islands\\r\\nMQ|Martinique\\r\\nMR|Mauritania\\r\\nMU|Mauritius\\r\\nYT|Mayotte\\r\\nMX|Mexico\\r\\nFM|Micronesia\\r\\nMD|Moldova\\r\\nMC|Monaco\\r\\nMN|Mongolia\\r\\nME|Montenegro\\r\\nMS|Montserrat\\r\\nMA|Morocco\\r\\nMZ|Mozambique\\r\\nMM|Myanmar\\r\\nNA|Namibia\\r\\nNR|Nauru\\r\\nNP|Nepal\\r\\nNL|Netherlands\\r\\nAN|Netherlands Antilles\\r\\nNC|New Caledonia\\r\\nNZ|New Zealand\\r\\nNI|Nicaragua\\r\\nNE|Niger\\r\\nNG|Nigeria\\r\\nNU|Niue\\r\\nNF|Norfolk Island\\r\\nMP|Northern Mariana Islands\\r\\nKP|North Korea\\r\\nNO|Norway\\r\\nOM|Oman\\r\\nPK|Pakistan\\r\\nPW|Palau\\r\\nPS|Palestinian Territory\\r\\nPA|Panama\\r\\nPG|Papua New Guinea\\r\\nPY|Paraguay\\r\\nPE|Peru\\r\\nPH|Philippines\\r\\nPN|Pitcairn\\r\\nPL|Poland\\r\\nPT|Portugal\\r\\nPR|Puerto Rico\\r\\nQA|Qatar\\r\\nRE|Reunion\\r\\nRO|Romania\\r\\nRU|Russia\\r\\nRW|Rwanda\\r\\nBL|Saint Barthélemy\\r\\nSH|Saint Helena\\r\\nKN|Saint Kitts and Nevis\\r\\nLC|Saint Lucia\\r\\nMF|Saint Martin (French part)\\r\\nPM|Saint Pierre and Miquelon\\r\\nVC|Saint Vincent and the Grenadines\\r\\nWS|Samoa\\r\\nSM|San Marino\\r\\nST|Sao Tome and Principe\\r\\nSA|Saudi Arabia\\r\\nSN|Senegal\\r\\nRS|Serbia\\r\\nSC|Seychelles\\r\\nSL|Sierra Leone\\r\\nSG|Singapore\\r\\nSX|Sint Maarten\\r\\nSK|Slovakia\\r\\nSI|Slovenia\\r\\nSB|Solomon Islands\\r\\nSO|Somalia\\r\\nZA|South Africa\\r\\nGS|South Georgia and the South Sandwich Islands\\r\\nKR|South Korea\\r\\nSS|South Sudan\\r\\nES|Spain\\r\\nLK|Sri Lanka\\r\\nSD|Sudan\\r\\nSR|Suriname\\r\\nSJ|Svalbard and Jan Mayen\\r\\nSZ|Swaziland\\r\\nSE|Sweden\\r\\nCH|Switzerland\\r\\nSY|Syria\\r\\nTW|Taiwan\\r\\nTJ|Tajikistan\\r\\nTZ|Tanzania\\r\\nTH|Thailand\\r\\nTL|Timor-Leste\\r\\nTG|Togo\\r\\nTK|Tokelau\\r\\nTO|Tonga\\r\\nTT|Trinidad and Tobago\\r\\nTN|Tunisia\\r\\nTR|Turkey\\r\\nTM|Turkmenistan\\r\\nTC|Turks and Caicos Islands\\r\\nTV|Tuvalu\\r\\nVI|U.S. Virgin Islands\\r\\nUG|Uganda\\r\\nUA|Ukraine\\r\\nAE|United Arab Emirates\\r\\nGB|United Kingdom\\r\\nUS|United States\\r\\nUM|United States Minor Outlying Islands\\r\\nUY|Uruguay\\r\\nUZ|Uzbekistan\\r\\nVU|Vanuatu\\r\\nVA|Vatican\\r\\nVE|Venezuela\\r\\nVN|Vietnam\\r\\nWF|Wallis and Futuna\\r\\nEH|Western Sahara\\r\\nYE|Yemen\\r\\nZM|Zambia\\r\\nZW|Zimbabwe\\r\\n",
              \'options_source\' => \'countries\',
              \'multiple\' => 0,
              \'title_display\' => \'none\',
              \'private\' => 0,
              \'aslist\' => 1,
              \'optrand\' => 0,
              \'conditional_operator\' => \'=\',
              \'other_option\' => NULL,
              \'other_text\' => \'Other...\',
              \'description\' => \'\',
              \'custom_keys\' => FALSE,
              \'conditional_component\' => \'\',
              \'conditional_values\' => \'\',
            ),
            \'mandatory\' => \'0\',
            \'weight\' => \'3\',
            \'page_num\' => 1,
          ),
          4 => array(
            \'nid\' => 953,
            \'cid\' => \'4\',
            \'pid\' => \'0\',
            \'form_key\' => \'message\',
            \'name\' => \'Message\',
            \'type\' => \'textarea\',
            \'value\' => \'\',
            \'extra\' => array(
              \'title_display\' => 0,
              \'private\' => 0,
              \'resizable\' => 1,
              \'disabled\' => 0,
              \'conditional_operator\' => \'=\',
              \'cols\' => \'\',
              \'rows\' => \'\',
              \'description\' => \'\',
              \'attributes\' => array(),
              \'conditional_component\' => \'\',
              \'conditional_values\' => \'\',
            ),
            \'mandatory\' => \'1\',
            \'weight\' => \'4\',
            \'page_num\' => 1,
          ),
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1414592747\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'28595\',
        \'source\' => \'node/953\',
        \'alias\' => \'contact\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}