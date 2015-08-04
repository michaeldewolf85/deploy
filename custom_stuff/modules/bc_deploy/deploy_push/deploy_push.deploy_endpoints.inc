<?php
/**
 * @file
 * deploy_push.deploy_endpoints.inc
 */

/**
 * Implements hook_deploy_endpoints_default().
 */
function deploy_push_deploy_endpoints_default() {
  $export = array();

  $endpoint = new DeployEndpoint();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 1;
  $endpoint->name = 'cn_website';
  $endpoint->title = 'CN Website';
  $endpoint->description = '';
  $endpoint->debug = 0;
  $endpoint->authenticator_plugin = 'DeployAuthenticatorSession';
  $endpoint->authenticator_config = array(
    'username' => 'root2',
    'password' => 'pass',
  );
  $endpoint->service_plugin = 'DeployServiceRestJSON';
  $endpoint->service_config = array(
    'url' => 'http://www.root2.com/services/rest',
  );
  $export['cn_website'] = $endpoint;

  $endpoint = new DeployEndpoint();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 1;
  $endpoint->name = 'de_website';
  $endpoint->title = 'DE Website';
  $endpoint->description = '';
  $endpoint->debug = 0;
  $endpoint->authenticator_plugin = 'DeployAuthenticatorSession';
  $endpoint->authenticator_config = array(
    'username' => 'root2',
    'password' => 'pass',
  );
  $endpoint->service_plugin = 'DeployServiceRestJSON';
  $endpoint->service_config = array(
    'url' => 'http://www.root2.com/services/rest',
  );
  $export['de_website'] = $endpoint;

  $endpoint = new DeployEndpoint();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 1;
  $endpoint->name = 'fr_website';
  $endpoint->title = 'FR Website';
  $endpoint->description = '';
  $endpoint->debug = 0;
  $endpoint->authenticator_plugin = 'DeployAuthenticatorSession';
  $endpoint->authenticator_config = array(
    'username' => 'root2',
    'password' => 'pass',
  );
  $endpoint->service_plugin = 'DeployServiceRestJSON';
  $endpoint->service_config = array(
    'url' => 'http://www.root2.com/services/rest',
  );
  $export['fr_website'] = $endpoint;

  $endpoint = new DeployEndpoint();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 1;
  $endpoint->name = 'uk_website';
  $endpoint->title = 'UK Website';
  $endpoint->description = '';
  $endpoint->debug = 0;
  $endpoint->authenticator_plugin = 'DeployAuthenticatorSession';
  $endpoint->authenticator_config = array(
    'username' => 'root2',
    'password' => 'pass',
  );
  $endpoint->service_plugin = 'DeployServiceRestJSON';
  $endpoint->service_config = array(
    'url' => 'http://www.root2.com/services/rest',
  );
  $export['uk_website'] = $endpoint;

  return $export;
}
