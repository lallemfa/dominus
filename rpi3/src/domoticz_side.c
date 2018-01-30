#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

#include "../libs/gpio_set.h"
#include "../libs/server_client.h"

/*
This executable will be launched by shell script.
This will implement the desired behavior after a switch action from domoticz.
*/

int socket_RV;

void signals_handler(int signal_number)
{
	
	close(socket_RV);
	fflush(stdout);
	printf("\nClosed cleanly\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	// Check correct use and update parameters
    if (argc != 4)
    {
        printf("Listen on a TCP server.\nNeeded 3 arguments but %d given.\nUse this way -> ./domoticz_side IP Port Message\n", argc-1);
        return EXIT_FAILURE;
    }

	// SIGACTION
    struct sigaction action;

    action.sa_handler = signals_handler;
    sigemptyset(& (action.sa_mask));

    sigaction(SIGQUIT, & action, NULL);
    sigaction(SIGINT, & action, NULL);
    // END SIGACTION

    // Server client
    client(argv[1], atoi(argv[2]));

    // Send message
	send(socket_RV, argv[3], strlen(argv[3]), 0);

	close(socket_RV);

	return EXIT_SUCCESS;
}