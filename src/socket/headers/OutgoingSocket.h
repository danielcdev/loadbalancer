#ifndef SOCKET_OUTGOINGSOCKET_H_
#define SOCKET_OUTGOINGSOCKET_H_

#include "Socket.h"
#include "../../logging/headers/LoadBalancerException.h"

#include <iostream>
using namespace std;

class OutgoingSocket: public Socket {

public:

	void create();
	OutgoingSocket();
	virtual ~OutgoingSocket();
};

#endif
