<?php
function event_form($form, &$form_state) {

  $form['name']['first'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#default_value' => "First name",
    '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['name']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#default_value' => "Last name",
    '#description' => "Please enter your last name.",
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['tickets'] = array(
    '#type' => 'textfield',
    '#title' => "tickets",
    '#default_value' => "10",
    '#description' => 'Please enter number of tickets',
    '#size' => 20,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

function event_callback() {
  $form = drupal_get_form('event_form');
  $form = drupal_render($form);
  return $form;
}

function event_form_submit(&$form, &$form_state) {
  $name = $form_state['values']["first"];
  $last_name = $form_state['values']["last"];
  $tickets = $form_state['values']["tickets"];
  module_invoke_all('custom_hook_insert_event', $name, $last_name, $tickets);
  $form_state['redirect'] = "event/result";

}

function event_result_callback() {
  return module_invoke_all('custom_hook_message');
}
