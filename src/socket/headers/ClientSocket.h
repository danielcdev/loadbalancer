#ifndef SOCKET_CLIENTSOCKET_H_
#define SOCKET_CLIENTSOCKET_H_

#include "Socket.h"

#include <iostream>
using namespace std;

class ClientSocket: public Socket {

	int fileDescriptor;

public:

	void create();
	int read(char *&data);
	void write(char data[], int length);
	void close();
	ClientSocket(int fileDescriptor);
	virtual ~ClientSocket();
};

#endif
