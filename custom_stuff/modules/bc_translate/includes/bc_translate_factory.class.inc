<?php

/**
 * @file
 * Contains the BCTranslateFactory class.
 */

class BCTranslateFactory() {

  /**
   * Queue an array of qualified entities for translation.
   *
   * @param string $entity_type
   *  The Drupal machine name of the entity type.
   * @param array $entities
   *  An array of Drupal entity objects.
   * @param string $langcode
   *  An (optional) Drupal language code.
   */
  static public function translate($entity_type, $entities, $langcode = NULL) {
    $translator = new BCTranslateSubmission($entity_type, $langcode);
    $entity_ids = $this->ids($entity_type, $entities);
    $translator->send($entity_ids);
  }

  /**
   * Generate ID input for BCTranslateSubmission::send() depending on entity 
   * type.
   *
   * @param string $entity_type
   *  The Drupal machine name of the entity type.
   * @param array $entities
   *  An array of Drupal entity objects.
   *
   * @return array
   *  
   */
  private function ids($entity_type, $entities) {
    
  }

}
