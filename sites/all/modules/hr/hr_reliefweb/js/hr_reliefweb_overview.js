(function ($, Drupal) {
  'use strict';

  $(document).ready(function () {
    if (!document.querySelector('.reliefweb--facets')) {
      return;
    }

    // Bind to search.
    if (document.getElementById('block-hr-reliefweb-hr-reliefweb-search')) {
      // Redirect to search, overwrite previous search.
      var handleSearch = function () {
        var q = document.querySelector('#block-hr-reliefweb-hr-reliefweb-search input').value;
        window.location = window.location.pathname + '?s=' + q;
      };

      var search = document.querySelector('#block-hr-reliefweb-hr-reliefweb-search input');
      if (search) {
        search.addEventListener('keyup', function (e) {
          if (event.keyCode == 13) {
            handleSearch();
          }
        });
      }

      var searchButton = document.querySelector('#block-hr-reliefweb-hr-reliefweb-search button');
      if (searchButton) {
        searchButton.addEventListener('click', function (e) {
          handleSearch();
        });
      }
    }

    // Redirect to selected option.
    var handleSelect = function (e) {
      if (e.target.value) {
        window.location = e.target.value;
      }
    };

    var details = document.querySelectorAll('.reliefweb--facets details');
    for (var i = 0; i < details.length; i++) {
      var detail = details[i];

      // Construct label.
      var newLabel = document.createElement('label');
      newLabel.innerText = detail.querySelector('summary').innerText;
      newLabel.classList.add('invisible');

      // Construct select.
      var newSelect = document.createElement('select');
      var options = detail.querySelectorAll('li a');

      // Add empty option.
      var newOption = document.createElement('option');
      newOption.value = '';
      newOption.text = newLabel.innerText;
      newSelect.appendChild(newOption);

      // Add options.
      for (var j = 0; j < options.length; j++) {
        var option = options[j];
        var newOption = document.createElement('option');
        newOption.value = option.href;
        newOption.text = option.innerText;
        newSelect.appendChild(newOption);
      }

      // Hide details.
      detail.classList.add('processed');
      detail.parentNode.appendChild(newLabel);
      detail.parentNode.appendChild(newSelect);
    }

    // Listen for change events.
    var details = document.querySelector('.reliefweb--facets').addEventListener("change", handleSelect);

  });
})(jQuery, Drupal);
