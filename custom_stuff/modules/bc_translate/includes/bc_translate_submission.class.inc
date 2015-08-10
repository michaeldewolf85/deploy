<?php

/**
 * @file
 * Contains the BCTranslateSubmission class.
 */

/**
 * The BCTranslateSubmission class.
 *
 * @param string $entity_type
 *  The machine name of the entity type to queue up for submission.
 * @param string $lang_code
 *  A Drupal language code (optional) defaults to default lang code.
 */
class BCTranslateSubmission {

  const TMS_OP = 'Send for Translation';

  /**
   * @var string $form_id
   *  The form_id of the form to submit.
   */
  private $form_id;

  /**
   * @var array $form_state
   *  The form state array for the translation form.
   */
  private $form_state = array();

  /**
   * @var object $languages
   *  Drupal's languages.
   */
  private $languages;

  public function __construct($entity_type, $lang_code = NULL) {
    $this->languages = language_list();
    if (!empty($lang_code) && empty($this->languages[$lang_code])) {
      throw new InvalidArgumentException("Language code {$lang_code} was not found or is not configured.");      
    }

    $this->setFormID($entity_type);
    $this->setLanguage($lang_code);
  }

  /**
   * Send entity for translation.
   *
   * @param array $ids
   *  An array of ids. Keys are entity ids, values are revision ids.
   */
  public function send($ids = array()) {
    module_load_include('inc', 'transperfect', 'transperfect_send_translations');
    foreach ($ids as $id => $vid) {
      $identifier = "{$id}-{$vid}";
      $this->form_state['values']['table'][$identifier] = $identifier;
    }
    $this->form_state['values']['op'] = $this::TMS_OP;
    drupal_form_submit($this->form_id, $this->form_state);
  }

  /**
   * Helper setter for form id.
   *
   * @param string $entity_type
   *  The machine name of the entity type to queue up for submission.
   */
  private function setFormID($entity_type) {
    switch ($entity_type) {

    }
    $this->form_id = "transperfect_dashboard_{$entity_type}_form";
  }

  /**
   * Helper setter for submission language.
   *
   * @param string $lang_code
   *  A Drupal language code.
   */
  private function setLanguage($lang_code) {
    $lang = language_default();
    if (!empty($this->languages[$lang_code])) {
      $lang = $languages[$lang_code];
    }
    $tpt_code = get_tpt_locale_code($lang->language);
    $this->form_state['values']['submission_target_locale'][$tpt_code] = $tpt_code;
  }

}
