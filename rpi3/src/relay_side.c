#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

#include "../libs/gpio_set.h"
#include "../libs/server_host.h"

/*
This executable would run on a distant embedded system controling a relay.
Depending on the order received, will make some actions.
*/

char* pin; // Pin number

int socket_RV;


void signals_handler(int signal_number)
{
	close(socket_RV);
	fflush(stdout);
	printf("\nClosed cleanly\n");
	exit(1);
}

void behavior(char* msg)
{
	switch(atoi(msg))
	{
		case 0:
			setGPIO(pin, "0");
			break;

		case 1:
			setGPIO(pin, "1");
			break;

		default:
			break;
	}
	
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Relay side. Host a TCP server.\nNeeded 2 arguments but %d given.\nUse this way -> ./relay_side pin port\n", argc-1);
        return EXIT_FAILURE;
    }

    pin = argv[1];

	// SIGACTION
    struct sigaction action;

    action.sa_handler = signals_handler;
    sigemptyset(& (action.sa_mask));

    sigaction(SIGQUIT, & action, NULL);
    sigaction(SIGINT, & action, NULL);
    // END SIGACTION

    // Behavior method
    void (*p_method)(char*);
    p_method = behavior;

    // Create server as an host
    socket_RV = server(atoi(argv[2]));

	listenOnceTCP(socket_RV, p_method);

	return EXIT_SUCCESS;
}