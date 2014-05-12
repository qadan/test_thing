<?php

function test_thing_fake_form() {
  return array(
    'things' => array(
      '#title' => "Things to add",
      '#type' => 'textarea',
      '#description' => 'Comma separate up some things to add',
      '#value' => '',
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'DO IT',
      '#submit' => array('test_thing_fake_submit'),
    ),
  );
}

function test_thing_fake_submit(array $form, array &$form_state) {
  $stuff = explode(', ', $form_state['things']);
  $batch = test_thing_fake_batch($stuff);
  batch_set($batch);
  $form_state['redirect'] = "/";
}

function test_thing_fake_batch(array $stuff) {
  module_load_include('inc', 'test_thing', 'includes/magic');
  return array(
    'title' => t('Doing whatever', array('@label' => $object->label)),
    'operations' => test_thing_do_up_some_magic($stuff),
    'init_message' => t('Preparing to do whatever...'),
    'progress_message' => t('Time elapsed: @elapsed <br/>Estimated time remaining @estimate.'),
    'error_message' => t('An error has occurred.'),
    'file' => drupal_get_path('module', 'test_thing') . '/includes/thing.form.inc',
    'finished' => 'test_thing_fake_batch_finished',
  );
}

function test_thing_fake_batch_operation($thing, &$context) {
  db_insert('test_whatever')
    ->fields(array(
      'value' => $thing,
    ))
    ->execute();
}

function test_thing_fake_batch_finished($success, $results, $operations) {
  drupal_set_message("PARTYTIME");
}
