<?php

/**
 * @file
 * Metatag integration for the metatag_opengraph module.
 */

/**
 * Implements hook_metatag_bundled_config_alter().
 */
function metatag_opengraph_metatag_bundled_config_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array(
          'og:site_name' => array('value' => '[site:name]'),
          'og:title' => array('value' => '[current-page:title]'),
          'og:type' => array('value' => 'article'),
          'og:url' => array('value' => '[current-page:url:absolute]'),
        );
        break;

      case 'global:frontpage':
        $config->config += array(
          'og:description' => array('value' => '[site:slogan]'),
          'og:title' => array('value' => '[site:name]'),
          'og:type' => array('value' => 'website'),
          'og:url' => array('value' => '[site:url]'),
        );
        break;

      // On error pages point everything to the homepage.
      case 'global:403':
      case 'global:404':
        $config->config += array(
          'og:title' => array('value' => '[site:name]'),
          'og:type' => array('value' => 'website'),
          'og:url' => array('value' => '[site:url]'),
        );
        break;

      case 'node':
        $config->config += array(
          'article:modified_time' => array('value' => '[node:changed:custom:c]'),
          'article:published_time' => array('value' => '[node:created:custom:c]'),
          'og:description' => array('value' => '[node:summary]'),
          'og:title' => array('value' => '[node:title]'),
          'og:updated_time' => array('value' => '[node:changed:custom:c]'),
        );
        break;

      case 'taxonomy_term':
        $config->config += array(
          'og:description' => array('value' => '[term:description]'),
          'og:title' => array('value' => '[term:name]'),
        );
        break;

      case 'user':
        $config->config += array(
          'og:title' => array('value' => '[user:name]'),
          'og:type' => array('value' => 'profile'),
          'profile:username' => array('value' => '[user:name]'),
        );
        if (variable_get('user_pictures')) {
          $config->config += array(
            'og:image' => array('value' => '[user:picture:url]'),
            // For now keep the old default.
            // @code
            // 'og:image:url' => array('value' => '[user:picture:url]'),
            // @endcode
          );
        }
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function metatag_opengraph_metatag_info() {
  $info['groups']['open-graph'] = array(
    'label' => t('Open Graph'),
    'description' => t('The <a href="@ogp">Open Graph meta tags</a> are used control how Facebook, Pinterest, LinkedIn and other social networking sites interpret the content of the site.<br /><br />The Facebook <a href="@debugger">Sharing Debugger</a> lets you preview how your content will look when shared to Facebook and debug any issues with your Open Graph tags.',
      array(
        '@ogp' => 'https://ogp.me/',
        '@debugger' => 'https://developers.facebook.com/tools/debug/',
      )
    ),
    'form' => array(
      '#weight' => 50,
    ),
  );

  // Default values for each meta tag.
  $og_defaults = array(
    'description' => '',
    'class' => 'DrupalTextMetaTag',
    'group' => 'open-graph',
    'element' => array(
      '#theme' => 'metatag_property',
    ),
  );

  // Open Graph meta tags stack after the Facebook tags.
  $weight = 25;

  $info['tags']['og:site_name'] = array(
    'label' => t('Site name'),
    'description' => t('A human-readable name for the site, e.g., <em>IMDb</em>.'),
    'context' => array('global'),
    'weight' => ++$weight,
  ) + $og_defaults;

  $info['tags']['og:type'] = array(
    'label' => t('Content type'),
    'description' => t('The type of the content, e.g., <em>movie</em>.'),
    'weight' => ++$weight,
    'select_or_other' => TRUE,
    'form' => array(
      '#type' => 'select',
      '#options' => _metatag_opengraph_type_options(),
      '#empty_option' => t('- None -'),
    ),
    'devel_generate' => array(
      'type' => 'select',
    ),
  ) + $og_defaults;

  $info['tags']['og:url'] = array(
    'label' => t('Page URL'),
    'description' => t('Preferred page location or URL to help eliminate duplicate content for search engines, e.g., <em>https://www.imdb.com/title/tt0117500/</em>.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'canonical',
    ),
  ) + $og_defaults;

  $info['tags']['og:title'] = array(
    'label' => t('Content title'),
    'description' => t('The title of the content, e.g., <em>The Rock</em>.'),
    'maxlength' => 0,
    'weight' => ++$weight,
  ) + $og_defaults;

  $info['tags']['og:determiner'] = array(
    'label' => t('Content title determiner'),
    'description' => t("The word that appears before the content's title in a sentence. The default ignores this value, the 'Automatic' value should be sufficient if this is actually needed."),
    'weight' => ++$weight,
    'form' => array(
      '#type' => 'select',
      '#options' => array(
        'auto' => 'Automatic',
        'a' => 'A',
        'an' => 'An',
        'the' => 'The',
      ),
      '#empty_option' => t('- Ignore -'),
    ),
    'devel_generate' => array(
      'type' => 'select',
    ),
  ) + $og_defaults;

  $info['tags']['og:description'] = array(
    'label' => t('Content description'),
    'description' => t('A one to two sentence description of the content.'),
    'maxlength' => 0,
    'weight' => ++$weight,
  ) + $og_defaults;

  // Basic tags.
  $info['tags']['og:updated_time'] = array(
    'label' => t('Content modification date & time'),
    'description' => t("The date this content was last modified, with an optional time value. Needs to be in <a href='https://en.wikipedia.org/wiki/ISO_8601'>ISO 8601</a> format. Can be the same as the 'Article modification date' tag."),
    'weight' => ++$weight,
  ) + $og_defaults;

  $info['tags']['og:see_also'] = array(
    'label' => t('See also'),
    'description' => t('URLs to related content.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults;

  $info['tags']['og:image'] = array(
    'label' => t('Image'),
    'description' => t('The URL of an image which should represent the content. The image must be at least 200 x 200 pixels in size; 600 x 316 pixels is a recommended minimum size, and for best results use an image least 1200 x 630 pixels in size. Supports PNG, JPEG and GIF formats. Should not be used if og:image:url is used. Note: if multiple images are added many services (e.g. Facebook) will default to the largest image, not specifically the first one.'),
    'multiple' => TRUE,
    'image' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'image',
    ),
  ) + $og_defaults;
  $info['tags']['og:image:url'] = array(
    'label' => t('Image URL'),
    'description' => t('A alternative version of og:image and has exactly the same requirements; only one needs to be used. Note: some services do not accept this tag and will only accept the "image" tag above.'),
    'multiple' => TRUE,
    'image' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'image',
    ),
  ) + $og_defaults;
  $info['tags']['og:image:secure_url'] = array(
    'label' => t('Secure image URL'),
    'description' => t('The secure URL (HTTPS) of an image which should represent the content. The image must be at least 50px by 50px and have a maximum aspect ratio of 3:1. Supports PNG, JPEG and GIF formats. All "https://" URLs will automatically be converted to "https://". Note: if multiple images are added many services (e.g. Facebook) will default to the largest image, not the first one.'),
    'multiple' => TRUE,
    'secure' => TRUE,
    'image' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'image',
    ),
  ) + $og_defaults;
  $info['tags']['og:image:alt'] = array(
    'label' => t('Image alternative text'),
    'description' => t('A description of what is in the image (not a caption). If og:image is provided this value should also be provided.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults;
  $info['tags']['og:image:type'] = array(
    'label' => t('Image type'),
    'description' => t('The type of image referenced above. Should be either "image/gif" for a GIF image, "image/jpeg" for a JPG/JPEG image, or "image/png" for a PNG image. Note: there should be one value for each image, and having more than there are images may cause problems.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults;
  $info['tags']['og:image:width'] = array(
    'label' => t('Image width'),
    'description' => t('The width of the above image(s). Note: if both the unsecured and secured images are provided, they should both be the same size.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'image',
    ),
  ) + $og_defaults;
  $info['tags']['og:image:height'] = array(
    'label' => t('Image height'),
    'description' => t('The height of the above image(s). Note: if both the unsecured and secured images are provided, they should both be the same size.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'image',
    ),
  ) + $og_defaults;

  $info['tags']['og:latitude'] = array(
    'label' => t('Latitude'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'float',
    ),
  ) + $og_defaults;
  $info['tags']['og:longitude'] = array(
    'label' => t('Longitude'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'float',
    ),
  ) + $og_defaults;

  $info['tags']['og:street_address'] = array(
    'label' => t('Street address'),
    'weight' => ++$weight,
    'replaces' => array(
      'og:street-address',
    ),
  ) + $og_defaults;
  $info['tags']['og:locality'] = array(
    'label' => t('Locality'),
    'weight' => ++$weight,
  ) + $og_defaults;
  $info['tags']['og:region'] = array(
    'label' => t('Region'),
    'weight' => ++$weight,
  ) + $og_defaults;
  $info['tags']['og:postal_code'] = array(
    'label' => t('Postal/ZIP code'),
    'weight' => ++$weight,
    'replaces' => array(
      'og:postal-code',
    ),
  ) + $og_defaults;
  $info['tags']['og:country_name'] = array(
    'label' => t('Country name'),
    'weight' => ++$weight,
    'replaces' => array(
      'og:country-name',
    ),
  ) + $og_defaults;

  $info['tags']['og:email'] = array(
    'label' => t('Email'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'email',
    ),
  ) + $og_defaults;
  $info['tags']['og:phone_number'] = array(
    'label' => t('Phone number'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'phone',
    ),
  ) + $og_defaults;
  $info['tags']['og:fax_number'] = array(
    'label' => t('Fax number'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'phone',
    ),
  ) + $og_defaults;

  $info['tags']['og:locale'] = array(
    'label' => t('Locale'),
    'description' => 'The locale these tags are marked up in, must be in the format language_TERRITORY. Default is en_US.',
    'weight' => ++$weight,
    'is_language' => TRUE,
    'devel_generate' => array(
      'maxlength' => 1,
    ),
  ) + $og_defaults;
  $info['tags']['og:locale:alternate'] = array(
    'label' => t('Alternative locales'),
    'description' => 'Other locales this content is available in, must be in the format language_TERRITORY, e.g. "fr_FR".',
    'weight' => ++$weight,
    'multiple' => TRUE,
    'is_language' => TRUE,
    'devel_generate' => array(
      'maxlength' => 1,
    ),
  ) + $og_defaults;

  // For the "article" og:type.
  $article_defaults = array(
    'dependencies' => array(
      array(
        'dependency' => 'og:type',
        'attribute' => 'value',
        'condition' => 'value',
        'value' => 'article',
      ),
    ),
  );
  $info['tags']['article:author'] = array(
    'label' => t('Article author'),
    'description' => t("Links an article to an author's Facebook profile, should be either URLs to the author's profile page or their Facebook profile IDs."),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $article_defaults;
  $info['tags']['article:publisher'] = array(
    'label' => t('Article publisher'),
    'description' => t("Links an article to a publisher's Facebook page."),
    'weight' => ++$weight,
  ) + $og_defaults + $article_defaults;
  $info['tags']['article:section'] = array(
    'label' => t('Article section'),
    'description' => t('The primary section of this website the content belongs to.'),
    'weight' => ++$weight,
  ) + $og_defaults + $article_defaults;
  $info['tags']['article:tag'] = array(
    'label' => t('Article tag(s)'),
    'description' => t('Appropriate keywords for this content.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $article_defaults;
  $info['tags']['article:published_time'] = array(
    'label' => t('Article publication date & time'),
    'description' => t("The date this content was published on, with an optional time value. Needs to be in <a href='https://en.wikipedia.org/wiki/ISO_8601'>ISO 8601</a> format."),
    'weight' => ++$weight,
  ) + $og_defaults + $article_defaults;
  $info['tags']['article:modified_time'] = array(
    'label' => t('Article modification date & time'),
    'description' => t("The date this content was last modified, with an optional time value. Needs to be in <a href='https://en.wikipedia.org/wiki/ISO_8601'>ISO 8601</a> format."),
    'weight' => ++$weight,
  ) + $og_defaults + $article_defaults;
  $info['tags']['article:expiration_time'] = array(
    'label' => t('Article expiration date & time'),
    'description' => t("The date this content will expire, with an optional time value. Needs to be in <a href='https://en.wikipedia.org/wiki/ISO_8601'>ISO 8601</a> format."),
    'weight' => ++$weight,
  ) + $og_defaults + $article_defaults;

  // For the "profile" og:type.
  $profile_defaults = array(
    'dependencies' => array(
      array(
        'dependency' => 'og:type',
        'attribute' => 'value',
        'condition' => 'value',
        'value' => 'profile',
      ),
    ),
  );
  $info['tags']['profile:first_name'] = array(
    'label' => t('First name'),
    'description' => t("The first name of the person who's Profile page this is."),
    'weight' => ++$weight,
  ) + $og_defaults + $profile_defaults;
  $info['tags']['profile:last_name'] = array(
    'label' => t('Last name'),
    'description' => t("The person's last name."),
    'weight' => ++$weight,
  ) + $og_defaults + $profile_defaults;
  $info['tags']['profile:username'] = array(
    'label' => t('Username'),
    'description' => t("A pseudonym / alias of this person."),
    'weight' => ++$weight,
  ) + $og_defaults + $profile_defaults;
  $info['tags']['profile:gender'] = array(
    'label' => t('Gender'),
    'description' => t("Any of Facebook's gender values should be allowed, the initial two being 'male' and 'female'."),
    'weight' => ++$weight,
  ) + $og_defaults + $profile_defaults;

  // Tags related to audio.
  $info['tags']['og:audio'] = array(
    'label' => t('Audio URL'),
    'description' => t('The URL to an audio file that complements this object.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'url',
    ),
  ) + $og_defaults;
  $info['tags']['og:audio:secure_url'] = array(
    'label' => t('Audio secure URL'),
    'description' => t('The secure URL to an audio file that complements this object. All "https://" URLs will automatically be converted to "https://".'),
    'secure' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'url',
    ),
  ) + $og_defaults;
  $info['tags']['og:audio:type'] = array(
    'label' => t('Audio type'),
    'description' => t('The MIME type of the audio file. Examples include "application/mp3" for an MP3 file.'),
    'weight' => ++$weight,
  ) + $og_defaults;

  // For the "book" og:type.
  $book_defaults = array(
    'dependencies' => array(
      array(
        'dependency' => 'og:type',
        'attribute' => 'value',
        'condition' => 'value',
        'value' => 'book',
      ),
    ),
  );
  $info['tags']['book:author'] = array(
    'label' => t("Book's author"),
    'description' => t("Links to the book's author's Facebook profile, should be either URLs to the author's profile page or their Facebook profile IDs."),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $book_defaults;
  $info['tags']['book:isbn'] = array(
    'label' => t("Book's ISBN"),
    'description' => t("The book's <a href=\"https://en.wikipedia.org/wiki/International_Standard_Book_Number\">International Standard Book Number</a>, which may be in one of several formats."),
    'weight' => ++$weight,
  ) + $og_defaults + $book_defaults;
  $info['tags']['book:release_date'] = array(
    'label' => t('Book release date'),
    'description' => t("The date this content will expire, with an optional time value. Needs to be in <a href='https://en.wikipedia.org/wiki/ISO_8601'>ISO 8601</a> format."),
    'weight' => ++$weight,
  ) + $og_defaults + $book_defaults;
  $info['tags']['book:tag'] = array(
    'label' => t('Book tags'),
    'description' => t('Appropriate keywords for this book.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $book_defaults;

  // For the "video" og:type.
  $video_defaults = array();
  // @code
  //   'dependencies' => array(
  //     array(
  //       'dependency' => 'og:type',
  //       'attribute' => 'value',
  //       'condition' => 'value',
  //       'value' => 'profile',
  //     ),
  //   ),
  // @endcode
  $info['tags']['og:video:url'] = array(
    'label' => t('Video URL'),
    'description' => t('The URL of an video which should represent the content. For best results use a source that is at least 1200 x 630 pixels in size, but at least 600 x 316 pixels is a recommended minimum. Object types supported include video.episode, video.movie, video.other, and video.tv_show.'),
    'weight' => ++$weight,
    'replaces' => array(
      'og:video',
    ),
    'devel_generate' => array(
      'type' => 'url',
    ),
  ) + $og_defaults;
  $info['tags']['og:video:secure_url'] = array(
    'label' => t('Video secure URL'),
    'description' => t('A URL to a video file that complements this object using the HTTPS protocol. All "https://" URLs will automatically be converted to "https://".'),
    'secure' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'url',
    ),
  ) + $og_defaults;
  $info['tags']['og:video:width'] = array(
    'label' => t('Video width'),
    'description' => t('The width of the video.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'integer',
    ),
  ) + $og_defaults;
  $info['tags']['og:video:height'] = array(
    'label' => t('Video height'),
    'description' => t('The height of the video.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'integer',
    ),
  ) + $og_defaults;
  $info['tags']['og:video:type'] = array(
    'label' => t('Video type'),
    'description' => t('The type of video referenced above. Should be either  video.episode, video.movie, video.other, and video.tv_show. Note: there should be one value for each video, and having more than there are videos may cause problems.'),
    'weight' => ++$weight,
  ) + $og_defaults;
  $info['tags']['video:actor'] = array(
    'label' => t('Actor(s)'),
    'description' => t('Links to the Facebook profiles for actor(s) that appear in the video.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $video_defaults;
  $info['tags']['video:actor:role'] = array(
    'label' => t("Actors' role"),
    'description' => t("The roles of the actor(s)."),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $video_defaults;
  $info['tags']['video:director'] = array(
    'label' => t('Director(s)'),
    'description' => t('Links to the Facebook profiles for director(s) that worked on the video.'),
    'weight' => ++$weight,
  ) + $og_defaults + $video_defaults;
  $info['tags']['video:writer'] = array(
    'label' => t('Scriptwriter(s)'),
    'description' => t('Links to the Facebook profiles for scriptwriter(s) for the video.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $video_defaults;
  $info['tags']['video:duration'] = array(
    'label' => t('Video duration (seconds)'),
    'description' => t('The length of the video in seconds'),
    'weight' => ++$weight,
  ) + $og_defaults + $video_defaults;
  $info['tags']['video:release_date'] = array(
    'label' => t('Release date'),
    'description' => t('The date the video was released.'),
    'weight' => ++$weight,
  ) + $og_defaults + $video_defaults;
  $info['tags']['video:tag'] = array(
    'label' => t('Tag'),
    'description' => t('Tag words associated with this video.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
  ) + $og_defaults + $video_defaults;
  $info['tags']['video:series'] = array(
    'label' => t('Series'),
    'description' => t('The TV show this series belongs to.'),
    'weight' => ++$weight,
    'dependencies' => array(
      array(
        'dependency' => 'og:type',
        'attribute' => 'value',
        'condition' => 'value',
        'value' => 'video.episode',
      ),
    ),
  ) + $og_defaults + $video_defaults;

  return $info;
}

/**
 * Provide a list of Open Graph "type" values, grouped by topic.
 *
 * @return array
 *   A list of OG "type" values.
 */
function _metatag_opengraph_type_options() {
  $options = array(
    t('Activities') => array(
      'activity' => t('Activity'),
      'sport' => t('Sport'),
    ),
    t('Businesses') => array(
      'bar' => t('Bar', array('context' => 'an establishment')),
      'company' => t('Company'),
      'cafe' => t('Cafe'),
      'hotel' => t('Hotel'),
      'restaurant' => t('Restaurant'),
    ),
    t('Groups') => array(
      'cause' => t('Cause'),
      'sports_league' => t('Sports league'),
      'sports_team' => t('Sports team'),
    ),
    t('Organizations') => array(
      'band' => t('Band'),
      'government' => t('Government'),
      'non_profit' => t('Non-profit'),
      'school' => t('School'),
      'university' => t('University'),
    ),
    t('People') => array(
      'actor' => t('Actor'),
      'athlete' => t('Athlete'),
      'author' => t('Author'),
      'director' => t('Director'),
      'musician' => t('Musician'),
      'politician' => t('Politician'),
      'profile' => t('Profile'),
      'public_figure' => t('Public figure'),
    ),
    t('Places') => array(
      'city' => t('City'),
      'country' => t('Country'),
      'landmark' => t('Landmark'),
      'place' => t('Place'),
      'state_province' => t('State or province'),
    ),
    t('Products and Entertainment') => array(
      'album' => t('Album'),
      'book' => t('Book'),
      'drink' => t('Drink'),
      'food' => t('Food'),
      'game' => t('Game'),
      'product' => t('Product'),
      'product.group' => t('Product group'),
      'song' => t('Song'),
      'video.movie' => t('Movie'),
      'video.tv_show' => t('TV show'),
      'video.episode' => t('TV show episode'),
      'video.other' => t('Miscellaneous video'),
    ),
    t('Websites') => array(
      'website' => t('Website'),
      'article' => t('Article (inc blog)'),
    ),
  );

  return $options;
}
