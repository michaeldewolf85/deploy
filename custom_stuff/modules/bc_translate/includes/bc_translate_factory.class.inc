<?php

/**
 * @file
 * Contains the BCTranslateFactory class.
 */

class BCTranslateFactory {

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
    $entity_ids = BCTranslateFactory::ids($entity_type, $entities);
    $src_lang = BCTranslateFactory::getSrcLang($entity_type, $entities);
    $translator = new BCTranslateSubmission($entity_type, $src_lang, $langcode);
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
   *  And array of ids in the proper format.
   */
  static private function ids($entity_type, $entities) {
    $entity_info = entity_get_info($entity_type);
    $id_key = $entity_info['entity keys']['id'];
    $vid_key = $entity_info['entity keys']['revision'];
    $ids = array();
    foreach ($entities as $entity) {
      $value = $entity->{$id_key};
      if ($entity_type == 'node') {
        $value .= "-{$entity->$vid_key}";
      }
      $ids[$value] = $value;
    }
    return $ids;
  }

  static private function getSrcLang($entity_type, $entities) {
    $entity_info = entity_get_info($entity_type);
    $lang_key = $entity_info['entity keys']['language'];    
    $entity = reset($entities);
    return $entity->{$lang_key};
  }

}
