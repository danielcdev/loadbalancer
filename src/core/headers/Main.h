#ifndef CORE_HEADERS_MAIN_H_
#define CORE_HEADERS_MAIN_H_

#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <iostream>

using namespace std;

class Main {

	unsigned short int port = 80;
	int actualSocket, timeoutSeconds = 0, timeoutMilliseconds = 0,
			addressLength = 0, yes = 1, no = 0;
	struct timeval timeout;
	struct sockaddr_in address;

	void makeSocket();
	int listenForConnection();
	void readData(int socket, int clientSocket);

public:

	void begin();
	Main();
	virtual ~Main();
};

#endif
