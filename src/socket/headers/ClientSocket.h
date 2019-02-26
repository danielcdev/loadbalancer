#ifndef SOCKET_CLIENTSOCKET_H_
#define SOCKET_CLIENTSOCKET_H_

#include "Socket.h"

#include <iostream>
using namespace std;

class ClientSocket: public Socket {

public:

	ClientSocket(int fileDescriptor);
	virtual ~ClientSocket();
};

#endif
