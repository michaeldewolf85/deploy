#!/bin/bash
drush si --db-url=mysql://root:@localhost/root1 --account-name=root1 --account-pass=pass --site-name=Root1
drush si --db-url=mysql://root:@localhost/root2 --account-name=root2 --account-pass=pass --site-name=Root2
