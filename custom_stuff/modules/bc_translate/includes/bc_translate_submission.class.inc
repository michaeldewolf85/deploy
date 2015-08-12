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
 * @param string $src_lang
 *  A Drupal language code (optional) for the source defaults to default lang 
 *  code.
 * @param string $lang_code
 *  A Drupal language code (optional) for the translation defaults to default 
 *  lang code.
 */
class BCTranslateSubmission {

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

  /**
   * @var object $lang_session
   *  The Transperfect modules uses a session var to track available languages.
   *  (Very poor architecture). Then they never unset these vars. We need to
   *  track this vars keys so that we can unset it.
   */
  private $lang_session;

  public function __construct($entity_type, $src_lang = NULL, $lang_code = NULL) {
    $this->languages = language_list();
    if (!empty($lang_code) && empty($this->languages[$lang_code])) {
      throw new InvalidArgumentException("Language code {$lang_code} was not found or is not configured.");      
    }

    $this->setFormParams($entity_type, $src_lang);
    $this->setLanguage($lang_code);
  }

  /**
   * Send entity for translation.
   *
   * @param array $ids
   *  An array of ids. Keys are revision ids, values are entity ids.
   */
  public function send($ids = array()) {
    $this->form_state['values']['table'] = $ids;
    $this->form_state['values']['op'] = TPT_BTN_DASHBOARD_SEND;
    drupal_form_submit($this->form_id, $this->form_state);
    unset($_SESSION[$this->lang_session]);
  }

  /**
   * Helper setter for form id.
   *
   * @param string $entity_type
   *  The machine name of the entity type to queue up for submission.
   * @param string $src_lang
   *  A Drupal language code (optional) for the source defaults to default lang 
   *  code.
   */
  private function setFormParams($entity_type, $src_lang = NULL) {
    switch ($entity_type) {
      case 'fieldable_panels_pane':
        module_load_include('inc', 'transperfect_fieldable_panels', 'transperfect_fieldable_panels_send');
        $entity_type = 'fieldable_panels';
        $this->lang_session = "transperfect_selected_{$entity_type}_language";
        break;
      case 'menu_link':
        module_load_include('inc', 'transperfect_menu', 'transperfect_menu_send');
        $entity_type = 'menu';
        $this->lang_session = "transperfect_selected_{$entity_type}_language";
        break;
      case 'taxonomy_term':
        module_load_include('inc', 'transperfect_taxonomy', 'transperfect_taxonomy_send');
        $entity_type = 'taxonomy';
        $this->lang_session = "transperfect_selected_{$entity_type}_language";
        break;
      case 'node':
        module_load_include('inc', 'transperfect', 'transperfect_send_translations');
        $this->lang_session = 'transperfect_selected_language';
        break;
    }
    $this->form_id = "transperfect_dashboard_{$entity_type}_form";
    if (!empty($src_lang)) {
      $_SESSION[$this->lang_session] = $src_lang;
    }
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
