<?php

  /**
   * @file
   * Initial template for the dataset list.
   */
?>

<div id="hdx-powered-by-block" class="poweredby-logo">
    <p><?php print $powered_by; ?></p>
    <a href="<?php print variable_get('humdata_base_url', 'https://data.humdata.org'); ?>">
      <img src="/sites/all/modules/hdx/hdx_datasets/images/logo-hdx.svg" alt="Humanitarian Data Exchange (HDX)" />
    </a>
</div>
