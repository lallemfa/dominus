# RPI3 / src

## gpio_set.c

Source code for GPIO control.
If the GPIO folder does not exist already, will be created.

Can be used either directly with an actuator (but limited on voltage) or with a relay.
Respect the following connections:

<p align="center">
  <img src="https://github.com/pblottiere/embsys/blob/master/labs/rpi3/imgs/relai.png" width="350" title="Relay coupling">
</p>


## server_client.c

TCP client source code.
Will run on the domoticz side. Will connect to a distant server mastering a relay and send it one message.

## server_host.c

TCP host source code.
Will run on the relay side. Will listen to orders and execute an action through a method pointer.
