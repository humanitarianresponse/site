<?php

/**
 * @file
 * hr_offices.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function hr_offices_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:hr_operation:editor'.
  $roles['node:hr_operation:editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'editor',
  );

  // Exported OG Role: 'node:hr_operation:manager'.
  $roles['node:hr_operation:manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hr_operation',
    'name' => 'manager',
  );

  return $roles;
}
