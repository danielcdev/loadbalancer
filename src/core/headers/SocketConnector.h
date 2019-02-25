#ifndef CORE_SOCKETCONNECTOR_H_
#define CORE_SOCKETCONNECTOR_H_

#include <thread>

#include "../../thread/headers/DataTransportThread.h"
#include "../../socket/headers/Socket.h"

using namespace std;

class SocketConnector {

public:

	void connect(Socket *clientSocket, Socket *outgoingSocket);
	SocketConnector();
	virtual ~SocketConnector();
};

#endif
