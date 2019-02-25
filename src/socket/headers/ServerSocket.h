#ifndef SOCKET_SERVERSOCKET_H_
#define SOCKET_SERVERSOCKET_H_

#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "../../logging/headers/LoadBalancerException.h"

using namespace std;

class ServerSocket {

	unsigned short int listenPort = 80;
	int fileDescriptor, timeoutSeconds = 0, timeoutMilliseconds = 0,
			addressLength = 0, yes = 1, no = 0;
	struct timeval timeout;
	struct sockaddr_in address;

public:

	void create();
	int listenForConnection();
	ServerSocket();
	virtual ~ServerSocket();
};

#endif
