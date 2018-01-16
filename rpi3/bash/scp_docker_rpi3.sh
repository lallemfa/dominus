scp /usr/build/dominus/rpi3/scripts/switch_off.sh switch@172.20.29.112:/opt/domoticz/scripts
scp /usr/build/dominus/rpi3/scripts/switch_on.sh switch@172.20.29.112:/opt/domoticz/scripts

scp /usr/build/dominus/rpi3/src/gpio_set switch@172.20.29.112:/home/switch/dominus/app
scp /usr/build/dominus/rpi3/src/server_host switch@172.20.29.112:/home/switch/dominus/app
scp /usr/build/dominus/rpi3/src/server_client switch@172.20.29.112:/home/switch/dominus/app