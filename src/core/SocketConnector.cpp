#include "SocketConnector.h"

void SocketConnector::connect(Socket *clientSocket, Socket *outgoingSocket) {
	thread(DataTransportThread::entryPoint, clientSocket, outgoingSocket).detach();

	thread(DataTransportThread::entryPoint, outgoingSocket, clientSocket).detach();
}

SocketConnector::SocketConnector() {

}

SocketConnector::~SocketConnector() {

}
