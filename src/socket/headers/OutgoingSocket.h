#ifndef SOCKET_OUTGOINGSOCKET_H_
#define SOCKET_OUTGOINGSOCKET_H_

#include "Socket.h"
#include "../../logging/headers/LoadBalancerException.h"

#include <iostream>
using namespace std;

class OutgoingSocket: public Socket {

	int fileDescriptor;

public:

	void create();
	int read(char *&data);
	void write(char data[], int length);
	void close();
	OutgoingSocket();
	virtual ~OutgoingSocket();
};

#endif
