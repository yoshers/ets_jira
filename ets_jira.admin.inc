<?php
// ETS JIRA Admin settings form variables
function ets_jira_admin_form($form, &$form_state) {

  $form = array();

  $form['ets_jira_server'] = array(
    '#type' => 'textfield',
    '#title' => 'ETS Jira Server SOAP WSDL URL',
    '#default_value' => variable_get('ets_jira_server'),
    '#required' => TRUE,
  );

  $form['ets_jira_username'] = array(
    '#type' => 'textfield',
    '#title' => 'ETS Jira Username',
    '#default_value' => variable_get('ets_jira_username'),
    '#required' => TRUE,
  );

  $form['ets_jira_password'] = array(
    '#type' => 'password_confirm',
    '#title' => 'ETS Jira Password',
    '#required' => TRUE,
  );
  
  $form['ets_jira_error_email'] = array(
    '#type' => 'textfield',
    '#title' => 'ETS Jira Error Email Recipient',
    '#default_value' => variable_get('ets_jira_error_email'),
    '#required' => TRUE,
  );

  $form['ets_jira_send_backup_email'] = array(
    '#type' => 'checkbox',
    '#title' => 'ETS Jira - Send Backup Email?',
    '#default_value' => variable_get('ets_jira_send_backup_email', TRUE),
  );

  return system_settings_form($form);
}
