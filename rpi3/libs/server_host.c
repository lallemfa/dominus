#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>

int socket_RV;
int socket_service;

struct sockaddr_in adr;
socklen_t lgadresse;

void signals_handler(int signal_number)
{
	close(socket_RV);
	close(socket_service);
	fflush(stdout);
	printf("\nClosed cleanly\n");
	exit(1);
}

void actionTCP(char* msg)
{
	switch(atoi(msg)) {
		case 1:
			printf("On\n");
			break;

		case 0:
			printf("Off\n");
			break;

		default:
			printf("Wrong message\n");
			break;
	}
}

int server(int port)
{
	if((socket_RV=socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Socket RV failure");
		exit(1);
	}

	adr.sin_family=AF_INET;
	adr.sin_port=htons(port);
	adr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(socket_RV, (struct sockaddr *) &adr, sizeof(adr))==-1)
	{
		perror("Binding failure");
		exit(1);
	}			

	if (listen(socket_RV,1)==-1)
	{
		perror("Listening failure");
		exit(1);
	}

	return socket_RV;
}

int listenOnceTCP(int socket_RV, void(*p_method)(char*)) 
{
	do
	{
		printf("Waiting for a client...\n");
		// Accept client
		socket_service = accept(socket_RV,(struct sockaddr *)&adr, &lgadresse);

		printf("Client accepted\n");

		// Listen
		char msg[1];
		recv(socket_service, &msg, 1, 0);

		// Interpret message
		(*p_method)(msg);

		// Bye client
		close(socket_service);

	} while(1);

	return EXIT_SUCCESS;
}

/*
int main(int argc, char *argv[])
{	
    if (argc != 2)
    {
        printf("Host a TCP server.\nNeeded 1 arguments but %d given.\nUse this way -> ./listener Port\n", argc-1);
        return EXIT_FAILURE;
    }

	// SIGACTION
    struct sigaction action;

    action.sa_handler = signals_handler;
    sigemptyset(& (action.sa_mask));

    sigaction(SIGQUIT, & action, NULL);
    sigaction(SIGINT, & action, NULL);
    // END SIGACTION

    // Pointeur fonction
    void (*p_method)(char*);
    p_method = actionTCP;

	// Server host
	socket_RV = server(atoi(argv[1]));

	listenOnceTCP(socket_RV, p_method);



	return EXIT_SUCCESS;
}
*/