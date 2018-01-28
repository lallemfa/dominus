# RPI3 / src

## gpio_set.c

Source code for GPIO control.
If the GPIO folder does not exist already, will be created.

```` bash
$ ./gpio_set Pin Value
````

Can be used either directly with an actuator (but limited on voltage) or with a relay.
Respect the following connections:

<p align="center">
  <img src="https://github.com/pblottiere/embsys/blob/master/labs/rpi3/imgs/relai.png" width="350" title="Relay coupling">
</p>

## server_client.c

TCP client source code which will be used later.

## server_host.c

TCP host source code which will be used later.