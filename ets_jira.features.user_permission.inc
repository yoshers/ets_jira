<?php
/**
 * @file
 * ets_jira_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ets_jira_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer ets jira settings'.
  $permissions['administer ets jira settings'] = array(
    'name' => 'administer ets jira settings',
    'roles' => array(
      'administrator' => 'administrator',
      'builder' => 'builder',
    ),
    'module' => 'ets_jira',
  );

  return $permissions;
}
