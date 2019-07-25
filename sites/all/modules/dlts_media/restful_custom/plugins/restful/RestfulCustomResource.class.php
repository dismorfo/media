<?php

class RestfulCustomResource extends RestfulEntityBaseNode {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {

    $public_fields = parent::publicFieldsInfo();
    
    $public_fields['identifier'] = array(
      'property' => 'field_identifier'
    );
    
    $public_fields['rights'] = array(
      'property' => 'field_rights'
    );
    
    return $public_fields;
    
  }
}