#!/bin/bash
drush make deploy.make /vagrant/root
sudo ln -s /vagrant/root /var/www/root
cd /vagrant/root
drush si -y --db-url=mysql://root:@localhost/root1 --account-name=root1 --account-pass=pass --site-name=Root1 --sites-subdir=www.root1.com
drush si -y --db-url=mysql://root:@localhost/root2 --account-name=root2 --account-pass=pass --site-name=Root2 --sites-subdir=www.root2.com
