cd $HOME/dominus/
make maintainer-clean || true
sudo docker cp $HOME/dominus/ 7994642d1e5d:/usr/build/