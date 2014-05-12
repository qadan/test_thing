<?php

function test_thing_run_fake_batch($stuff) {
  batch_set(
    array(
      'init_message' => t('Doing up a batchy batch'),
      'error_message' => t('An error occurred doing that batchy batch'),
      'progress_message' => t(
        'Batching up a batch <br/>Time elapsed: @elapsed <br/>
          Estimated time remaining @estimate.'),
      'file' => drupal_get_path('module', 'test_thing') . '/includes/thing.form.inc',
      'operations' => test_thing_do_up_some_magic($stuff),
    )
  );
}

function test_thing_do_up_some_magic($stuff) {
  $operations = array();
  foreach ($stuff as $thing) {
    $operations[] = array(
      'test_thing_fake_batch_operation',
      array($thing),
    );
  }
  return $operations;
}
