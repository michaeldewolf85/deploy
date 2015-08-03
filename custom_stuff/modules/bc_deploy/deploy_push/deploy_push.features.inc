<?php
/**
 * @file
 * deploy_push.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function deploy_push_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "deploy" && $api == "deploy_endpoints") {
    return array("version" => "1");
  }
  if ($module == "deploy" && $api == "deploy_plans") {
    return array("version" => "1");
  }
}
