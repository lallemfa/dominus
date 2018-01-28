#!/bin/bash
cd $HOME/dominus/
make maintainer-clean || true
sudo docker cp $HOME/dominus/ $1:/usr/build/