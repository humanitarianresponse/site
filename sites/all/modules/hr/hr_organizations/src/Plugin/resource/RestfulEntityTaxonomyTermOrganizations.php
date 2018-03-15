<?php

namespace Drupal\hr_organizations\Plugin\resource;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulEntityTaxonoyTermOrganizations
 * @package Drupal\hr_organizations\Plugin\resource
 *
 * @Resource(
 *   name = "organizations:1.0",
 *   resource = "organizations",
 *   label = "Organizations",
 *   description = "Humanitarianresponse organizations",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "hr_organization"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */

class RestfulEntityTaxonomyTermOrganizations extends ResourceEntity implements ResourceInterface {
  /**
   * Overrides publicFields().
   */
  public function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['acronym'] = array(
      'property' => 'field_acronym',
    );

    $public_fields['homepage'] = array(
      'property' => 'field_website',
      'sub_property' => 'url',
    );

    $public_fields['fts_id'] = array(
      'property' => 'field_organization_fts',
    );

    $public_fields['type'] = array(
      'property' => 'field_organization_type',
      'resource' => array(
        'name' => 'organization_types',
        'majorVersion' => 1,
        'minorVersion' => 0,
      ),
    );

    return $public_fields;
  }

}