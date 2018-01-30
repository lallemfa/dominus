# RPI3 / src

## domoticz_side.c

Will be called via a shell script launched by domoticz.
Will connect to a distant server mastering a relay and send it one order.

Not manually used in theory but can be used this way:

```` bash
$ ./domoticz_side IP Port Message
````

## relay_side.c

Will wait for orders from domoticz received through a TCP server.
Host a server on which domoticz will send the orders.
Then act on GPIO values.

Can be used either directly with an actuator (but limited on voltage) or with a relay.
Respect the following connections:

<p align="center">
  <img src="https://github.com/pblottiere/embsys/blob/master/labs/rpi3/imgs/relai.png" width="350" title="Relay coupling">
</p>

Use this way:

```` bash
$ ./relay_side pin port
````