# Humanitarian Response - [![Dev branch Build Status](https://travis-ci.com/UN-OCHA/hrinfo-site.svg?branch=dev)](https://travis-ci.com/UN-OCHA/hrinfo-site) [![Master branch Build Status](https://travis-ci.com/UN-OCHA/hrinfo-site.svg?branch=master)](https://travis-ci.com/UN-OCHA/hrinfo-site)

This is the humanitarianresponse.info Drupal 7 web site repository.

# Deployment notes
Recurrent errors on deploy, detailed in https://humanitarian.atlassian.net/browse/OPS-7193?focusedCommentId=121782

# Update notes
Composer behaves oddly, failing to preserve paths and deleting custom modules
and themes. Appears to be mentioned (it's Drupal7 only) in
https://github.com/drupal-composer/preserve-paths/issues/10
A general `composer update` updates contrib modules too, which produce more
errors. Until we've worked out which should be pinned and which not, better to
stick with `composer require PROJECT:VERSION` for each update.
