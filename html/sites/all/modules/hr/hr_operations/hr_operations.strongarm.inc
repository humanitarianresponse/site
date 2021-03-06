<?php

/**
 * @file
 * hr_operations.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hr_operations_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_hr_operation';
  $strongarm->value = 0;
  $export['entity_translation_hide_translation_links_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_hr_operation';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__hr_operation';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 0,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hr_operation';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'og_menu' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '20',
        ),
        'redirect' => array(
          'weight' => '21',
        ),
        'language' => array(
          'weight' => '19',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_hr_operation';
  $strongarm->value = '4';
  $export['language_content_type_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hr_operation';
  $strongarm->value = array();
  $export['menu_options_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hr_operation';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hr_operation';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
  );
  $export['node_options_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hr_operation';
  $strongarm->value = '1';
  $export['node_preview_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hr_operation';
  $strongarm->value = 0;
  $export['node_submitted_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_features_settings_node_hr_operation';
  $strongarm->value = array(
    'acc_applications' => '0',
    'acc_incidents' => '0',
    'ev_events' => '3',
    'hdx_datasets' => '2',
    'hr_assessments' => '2',
    'hr_datasets' => '0',
    'hr_disasters' => '1',
    'hr_documents' => '2',
    'hr_events' => '2',
    'hr_infographics' => '2',
    'hr_news' => '0',
    'hr_offices' => '2',
    'hr_pages' => '2',
    'hr_reliefweb_documents' => '0',
    'hr_reliefweb_meeting_documents' => '3',
    'hr_users' => '3',
  );
  $export['og_features_settings_node_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_hr_operation';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'search_result' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_hr_operation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_operation_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:27:"panelizer_node:hr_operation";s:23:"allowed_layout_settings";a:40:{s:8:"flexible";b:0;s:6:"onecol";b:0;s:17:"threecol_33_34_33";b:0;s:14:"twocol_stacked";b:1;s:17:"threecol_25_50_25";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:6:"twocol";b:0;s:13:"twocol_bricks";b:0;s:23:"radix_sanderson_flipped";b:1;s:14:"radix_mccoppin";b:1;s:21:"radix_hewston_flipped";b:1;s:12:"radix_phelan";b:1;s:18:"radix_burr_flipped";b:1;s:11:"radix_sutro";b:1;s:12:"radix_harris";b:1;s:21:"radix_moscone_flipped";b:1;s:11:"radix_geary";b:1;s:13:"radix_brenham";b:1;s:12:"radix_taylor";b:1;s:20:"radix_bryant_flipped";b:1;s:12:"radix_whelan";b:1;s:22:"radix_bartlett_flipped";b:1;s:14:"radix_bartlett";b:1;s:12:"radix_bryant";b:1;s:13:"radix_moscone";b:1;s:13:"radix_hewston";b:1;s:21:"radix_brenham_flipped";b:1;s:20:"radix_taylor_flipped";b:1;s:10:"radix_burr";b:1;s:11:"radix_brown";b:1;s:12:"radix_boxton";b:1;s:15:"radix_sanderson";b:1;s:18:"radix_webb_flipped";b:1;s:18:"radix_sutro_double";b:1;s:11:"radix_selby";b:1;s:10:"radix_webb";b:1;s:11:"radix_rolph";b:1;s:10:"radix_pond";b:1;s:19:"radix_selby_flipped";b:1;}s:10:"form_state";N;}';
  $export['panelizer_node:hr_operation_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_operation_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_node:hr_operation_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_operation_allowed_types';
  $strongarm->value = array(
    'bean_pane-fts_visualization' => TRUE,
    'bean_pane-existing_bean' => TRUE,
    'node_body-node_body' => TRUE,
    'hr_documents_key_documents-hr_documents_key_documents' => TRUE,
    'hr_infographics_key_infographics-hr_infographics_key_infographics' => TRUE,
    'hr_layout_reliefweb-hr_layout_reliefweb' => TRUE,
    'hr_layout_rss_feeds-hr_layout_rss_feeds' => TRUE,
    'hr_layout_standard-hr_layout_standard' => TRUE,
    'hr_reliefweb_featured_document-hr_reliefweb_featured_document' => TRUE,
    'hr_reliefweb_key_documents-hr_reliefweb_key_documents' => TRUE,
    'hr_reliefweb_ocha_products-hr_reliefweb_ocha_products' => TRUE,
    'twitter-twitter' => TRUE,
    'fieldable_panels_pane-fieldable_panels_pane' => TRUE,
    'views_panes-hr_events_panes-upcoming' => TRUE,
    'views_panes-hr_events_panes-upcoming_from_context' => TRUE,
    'views_panes-hr_news_panes-list' => TRUE,
    'views_panes-hr_documents_panes-list' => TRUE,
    'views_panes-hr_infographics_panes-list' => TRUE,
    'views_panes-assessments_from_registry-panel_pane_1' => TRUE,
  );
  $export['panelizer_node:hr_operation_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_operation_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:hr_operation_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:hr_operation_default';
  $strongarm->value = array(
    'bean_pane' => 0,
    'token' => 0,
    'entity_form_field' => 0,
    'entity_field' => 0,
    'entity_field_extra' => 0,
    'custom' => 0,
    'block' => 0,
    'entity_view' => 0,
    'fieldable_panels_pane' => 0,
    'flag_link' => 0,
    'openlayers_map' => 0,
    'panels_mini' => 0,
    'views' => 0,
    'views_panes' => 0,
    'other' => 0,
  );
  $export['panelizer_node:hr_operation_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_operation_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_operation_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_operation_es_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_operation_es_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_operation_fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_operation_fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_operation_pattern';
  $strongarm->value = 'operations/[node:title]';
  $export['pathauto_node_hr_operation_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_hr_operation_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_hr_operation_und_pattern'] = $strongarm;

  return $export;
}
