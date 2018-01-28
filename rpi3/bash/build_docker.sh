#!/bin/bash
cd /usr/build/dominus
sh autogen.sh
./configure --host arm-linux CC=/root/buildroot-2017.08/output/host/bin/arm-linux-gcc
make