#include "SocketConnector.h"

void SocketConnector::connect(Socket *clientSocket, Socket *outgoingSocket) {
	try {
		outgoingSocket->create();
	} catch (exception &e) {
		cerr << e.what() << endl;
	}

	thread(DataTransportThread::entryPoint, clientSocket, outgoingSocket).detach();

	thread(DataTransportThread::entryPoint, outgoingSocket, clientSocket).detach();
}

SocketConnector::SocketConnector() {

}

SocketConnector::~SocketConnector() {

}
