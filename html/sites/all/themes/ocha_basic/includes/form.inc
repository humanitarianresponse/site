<?php
/**
 * @file
 * Theme and preprocess functions for forms
 */

/**
 * Form theme declarations.
 *
 * @see hook_theme()
 */
function ocha_basic_form_themes($existing, $type, $theme, $path) {
  $themes = array();
  $types = array(
    'hr_assessment',
    'hr_document',
    'hr_event',
    'hr_infographic',
    'hr_office',
  );

  // Templates for the node types.
  foreach (node_type_get_names() as $type => $name) {
    if (!in_array($type, $types)) {
      continue;
    }
    // Edit form templates.
    $themes[$type . '_node_form'] = array(
      'render element' => 'form',
      'template' => 'node-edit--' . $type,
      'path' => $path . '/tpl/forms',
      'preprocess functions' => array(),
    );
  }

  return $themes;
}

/**
 * Implements theme_container().
 */
function ocha_basic_container($variables) {
  $element = $variables['element'];
  // Ensure an array is always passed to drupal_attributes().
  $element['#attributes'] = isset($element['#attributes']) && is_array($element['#attributes']) ? $element['#attributes'] : array();

  // Special handling for form elements.
  if (isset($element['#array_parents'])) {
    // Assign an html ID.
    if (!isset($element['#attributes']['id'])) {
      $element['#attributes']['id'] = $element['#id'];
    }

    // Remove any set form-control class at this point.
    // Not needed for form-wrappers.
    if (!empty($element['#attributes']['class'])) {
      if (($key = array_search('form-control', $element['#attributes']['class'])) !== false) {
        unset($element['#attributes']['class'][$key]);
      }
    }

    // Add the 'form-wrapper' class.
    $element['#attributes']['class'][] = 'form-wrapper';
  }

  return '<div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}

/**
 * Implements hook_element_info_alter().
 */
function ocha_basic_element_info_alter(&$elements) {
  foreach ($elements as &$element) {
    // Process all elements.
    $element['#pre_render'][] = '_ocha_basic_pre_render_element';
    // Process input elements.
    if (!empty($element['#input'])) {
      $element['#pre_render'][] = '_ocha_basic_pre_render_input';
    }
    // Process text format elements.
    if (!empty($element['#type']) && $element['#type'] == 'text_format') {
      $element['#after_build'][] = '_ocha_basic_text_format_after_build';
    }
  }
}

/**
 * Pre render callback for all elements.
 */
function _ocha_basic_pre_render_element(&$element) {
  // Add form-inline or form-group classes.
  if (!empty($element['#attributes']['class']) && is_array($element['#attributes']['class'])) {
    if (in_array('container-inline', $element['#attributes']['class'])) {
      $element['#attributes']['class'][] = 'form-inline';
    }
    if (in_array('form-wrapper', $element['#attributes']['class'])) {
      $element['#attributes']['class'][] = 'form-group';
    }
  }
  return $element;
}

/**
 * Pre render callback for input elements.
 */
function _ocha_basic_pre_render_input(&$element) {
  // Add form-control class.
  $types = array(
    'textfield',
    'textarea',
    'password',
    'password_confirm',
    'select',
    'machine_name',
    'emailfield',
    'numberfield',
    'rangefield',
    'searchfield',
    'telfield',
    'urlfield',
    'email',
    'webform_email',
    'webform_number',
    'number',
  );

  // Skip elements with these #theme key.
  $skip_themes = array(
    'select_as_checkboxes',
  );

  if (!empty($element['#type']) && in_array($element['#type'], $types) && (empty($element['#theme']) || (!empty($element['#theme']) && !in_array($element['#theme'], $skip_themes)))) {
    $element['#attributes']['class'][] = 'form-control';
  }

  return $element;
}

/**
 * Last minute theming for format selectors.
 */
function _ocha_basic_text_format_after_build($element, &$form_state) {
  // This thing runs twice, but the first time around format is not set yet.
  if (empty($element['format'])) { return $element; }

  $format = &$element['format']['format'];
  // Set title to show in a field group before the input.
  $format['#input_group'] = TRUE;
  $format['#title_display'] = 'prefix';

  return $element;
}

/**
 * Implements theme_form_element().
 */
function ocha_basic_form_element($variables) {
  $element = &$variables['element'];
  $is_checkbox = FALSE;
  $is_radio = FALSE;
  $is_input_group = FALSE;

  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add the default form-item class.
  $attributes['class'][] = 'form-item';

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
      ' ' => '-',
      '_' => '-',
      '[' => '-',
      ']' => '',
    ));
  }

  // Add error class.
  if (isset($element['#parents']) && form_get_error($element) !== NULL && !empty($element['#validated'])) {
    $attributes['class'][] = 'has-error';
  }

  // Add radios, checkboxes and form-group classes.
  if (isset($element['#type'])) {
    if ($element['#type'] == "radio") {
      $attributes['class'][] = 'radio';
      $is_radio = TRUE;
    }
    elseif ($element['#type'] == "checkbox") {
      $attributes['class'][] = 'checkbox';
      $is_checkbox = TRUE;
    }
    else {
      $attributes['class'][] = 'form-group';
    }
  }

  // Recognize non-standard #input_group key to use a Bootstrap input group.
  if (!empty($element['#input_group'])) {
    $attributes['class'][] = 'input-group';
    $is_input_group = TRUE;
  }

  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  // Support for non-standard #title_display options.
  if ($element['#title_display'] == 'prefix') {
    if (empty($element['#field_prefix'])) {
      $element['#field_prefix'] = '';
    }
    $element['#field_prefix'] = theme('form_element_label', $variables) . $element['#field_prefix'];
    $element['#title_display'] = 'none';
  }
  elseif ($element['#title_display'] == 'suffix') {
    if (empty($element['#field_suffix'])) {
      $element['#field_suffix'] = '';
    }
    $element['#field_suffix'] .= theme('form_element_label', $variables);
    $element['#title_display'] = 'none';
  }

  // Generate the prefix and suffix.
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'invisible':
      if ($is_radio || $is_checkbox) {
        // render the normal invisible label for screen readers
        $output .= ' ' . theme('form_element_label', $variables);
        // but still ensure checkbox is wrapped in an empty label
        $element['#title_display'] = 'before';
        $element['#title'] = '';
        $output .= ' ' . $prefix . theme('form_element_label', $variables) . $suffix . "\n";
      }
      else {
        $output .= ' ' . theme('form_element_label', $variables);
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      }
      break;

    case 'before':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      if ($is_radio || $is_checkbox) {
        $output .= ' ' . $prefix . theme('form_element_label', $variables) . $suffix . "\n";
      }
      else {
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
        $output .= ' ' . theme('form_element_label', $variables) . "\n";
      }
      break;

    case 'none':
    case 'attribute':
      if ($is_radio || $is_checkbox) {
        // ensure checkboxes still wrapped in a label
        $element['#title_display'] = 'before';
        $output .= ' ' . $prefix . theme('form_element_label', $variables) . $suffix;
      }
      else {
        // Output no label and no required marker, only the children.
        $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      }
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<span class="help-block">' . $element['#description'] . "</span>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Implements theme_form_element_label().
 */
function ocha_basic_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // Radios and checkboxes are rendered differently.
  $is_radio_or_checkbox = (isset($element['#type']) && ('checkbox' === $element['#type'] || 'radio' === $element['#type']));

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required']) && !$is_radio_or_checkbox) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = !empty($element['#title']) ? filter_xss_admin($element['#title']) : '';

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after' && !$is_radio_or_checkbox) {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // Radio and checkboxes goes inside label.
  $output = '';
  if ($is_radio_or_checkbox && isset($element['#children']) && ($element['#title_display'] != 'invisible')) {
    $output .= $element['#children'];
  }

  // Append label.
  $output .= $t('!title !required', array('!title' => $title, '!required' => $required));

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $output . "</label>\n";
}

/**
 * Implements theme_button().
 */
function ocha_basic_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  $element['#attributes']['class'][] = 'btn';
  $element['#attributes']['class'][] = 'btn-default';
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  // Add a btn-primary class if submit button.
  if (isset($element['#parents']) && ($element['#parents'][0] == 'submit')) {
    $element['#attributes']['class'][] = 'btn-primary';
  }

  if (!empty($element['#button_icon'])) {
    $value  = theme('ocha_basic_icon', array('icon' => $element['#button_icon']));
    $value .= ' ';
    $value .= '<span class="button-text">' . check_plain($element['#value']) . '</span>';

    return '<button' . drupal_attributes($element['#attributes']) . '>' . $value . '</button>';
  }

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Implements theme_date().
 */
function ocha_basic_date($variables) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'form-inline';

  return '<div' . drupal_attributes($attributes) . '>' . drupal_render_children($element) . '</div>';
}

/**
 * Implements theme_fieldset().
 */
function ocha_basic_fieldset($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id'));
  _form_set_class($element, array('form-wrapper'));
  _form_set_class($element, array('panel', 'panel-default'));

  $output = '<fieldset' . drupal_attributes($element['#attributes']) . '>';
  if (!empty($element['#title'])) {
    // Always wrap fieldset legends in a SPAN for CSS positioning.
    $output .= '<legend class="panel-heading"><div class="panel-title fieldset-legend">' . $element['#title'] . '</div></legend>';
  }
  $output .= '<div class="panel-body fieldset-wrapper">';
  if (!empty($element['#description'])) {
    $output .= '<p class="help-block">' . $element['#description'] . '</p>';
  }
  $output .= render($element['#children']);
  if (isset($element['#value'])) {
    $output .= $element['#value'];
  }
  $output .= '</div>';
  $output .= "</fieldset>\n";
  return $output;
}
