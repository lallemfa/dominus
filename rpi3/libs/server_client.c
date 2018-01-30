#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

int socket_RV;

void signals_handler(int signal_number)
{
	close(socket_RV);
	fflush(stdout);
	printf("\nClosed cleanly\n");
}

void client(char* IP, int port)
{
	struct sockaddr_in adr;

	if( (socket_RV=socket(AF_INET, SOCK_STREAM, 0)) == -1 )
	{
		perror("Socket RV failure");
		exit(1);
	}
	
	adr.sin_addr.s_addr = inet_addr(IP);
	adr.sin_family = AF_INET;
	adr.sin_port = htons(port);

	if ( connect(socket_RV,(struct sockaddr *)&adr, sizeof(adr))==-1 )
	{
		perror("Connection failure");
		exit(1);
	}

}

/*
int main(int argc, char *argv[]) {

	// Check correct use and update parameters
    if (argc != 4)
    {
        printf("Listen on a TCP server.\nNeeded 3 arguments but %d given.\nUse this way -> ./listener IP Port Message\n", argc-1);
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
*/