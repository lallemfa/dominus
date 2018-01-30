#ifndef server_host_h
#define server_host_h
 
int server(int port);
int listenOnceTCP(int socket_RV, void(*p_method)(char*));
 
#endif