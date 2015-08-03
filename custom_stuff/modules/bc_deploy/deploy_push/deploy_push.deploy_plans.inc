<?php
/**
 * @file
 * deploy_push.deploy_plans.inc
 */

/**
 * Implements hook_deploy_plans_default().
 */
function deploy_push_deploy_plans_default() {
  $export = array();

  $plan = new DeployPlan();
  $plan->disabled = FALSE; /* Edit this to true to make a default plan disabled initially */
  $plan->api_version = 1;
  $plan->name = 'content_hub';
  $plan->title = 'Content Hub';
  $plan->description = '';
  $plan->debug = 0;
  $plan->aggregator_plugin = 'DeployAggregatorManaged';
  $plan->aggregator_config = array(
    'delete_post_deploy' => 1,
  );
  $plan->fetch_only = 0;
  $plan->processor_plugin = 'DeployProcessorQueue';
  $plan->processor_config = array();
  $plan->endpoints = array(
    'us_website' => 'us_website',
    'uk_website' => 'uk_website',
    'fr_website' => 'fr_website',
    'de_website' => 'de_website',
    'cn_website' => 'cn_website',
  );
  $plan->dependency_plugin = 'deploy_iterator';
  $export['content_hub'] = $plan;

  $plan = new DeployPlan();
  $plan->disabled = FALSE; /* Edit this to true to make a default plan disabled initially */
  $plan->api_version = 1;
  $plan->name = 'debug';
  $plan->title = 'Debug';
  $plan->description = '';
  $plan->debug = 0;
  $plan->aggregator_plugin = 'DeployAggregatorManaged';
  $plan->aggregator_config = array(
    'delete_post_deploy' => 1,
  );
  $plan->fetch_only = 0;
  $plan->processor_plugin = 'DeployProcessorQueue';
  $plan->processor_config = array();
  $plan->endpoints = array(
    'us_website' => 'us_website',
    'uk_website' => 0,
    'fr_website' => 0,
    'de_website' => 0,
    'cn_website' => 0,
  );
  $plan->dependency_plugin = 'deploy_iterator';
  $export['debug'] = $plan;

  return $export;
}
