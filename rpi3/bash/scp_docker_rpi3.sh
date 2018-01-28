#!/bin/bash
sshpass -p "$2" scp /usr/build/dominus/rpi3/scripts/switch_off.sh switch@$1:/opt/domoticz/scripts
sshpass -p "$2" scp /usr/build/dominus/rpi3/scripts/switch_on.sh switch@$1:/opt/domoticz/scripts

sshpass -p "$2" scp /usr/build/dominus/rpi3/src/gpio_set switch@$1:/home/switch/dominus/app
sshpass -p "$2" scp /usr/build/dominus/rpi3/src/server_host switch@$1:/home/switch/dominus/app
sshpass -p "$2" scp /usr/build/dominus/rpi3/src/server_client switch@$1:/home/switch/dominus/app