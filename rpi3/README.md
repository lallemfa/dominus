# RPI3

This folder contains the evolution of switch interaction through Domoticz.
The aim is to use cross-compilation (from laptop to RPi3) to define the action done by the Raspberry when an order is sent via the Domoticz server.

## bash

Bash scripts used to easily transfer files between docker / RPI3 / host.
	
build_docker.sh 		-> 	Must be launched from the docker container.
							Will cross-compile src files for RPi3.
							Parameters: None

```` bash
$ sh build_docker.sh
````

copy_from_docker.sh 	-> 	Must be launched from the host.
							Copy dominus directory from the docker to the host.
							Parameters: Docker_ID

```` bash
$ sh copy_from_docker.sh ID
````

copy_to_docker.sh 		-> 	Must be launched from the host.
							Copy dominus directory from the host to the docker.
							Parameters: Docker_ID

```` bash
$ sh copy_to_docker.sh ID
````

scp_docker_rpi3.sh 		-> 	Must be launched from the docker container.
							Copy binaries from the docker container to the RPi3.
							Parameters: RPi3_IP Switch_Password

```` bash
$ sh scp_docker_rpi3.sh IP password
````

## log

This folder contains one log of interractions. Was used for V1.0.

## scripts

Scripts launched by the RPi 3 in reaction of switch interaction.

## src

Source code for the different implementations.