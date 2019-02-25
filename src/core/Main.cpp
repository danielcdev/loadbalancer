#include "Main.h"

int main() {
	Main mainClass = Main();
	mainClass.begin();

	return 0;
}

void Main::begin() {
	ServerSocket serverSocket;

	try {
		serverSocket.create();
	} catch (exception &e) {
		cerr << "Caught exception at " << LOCATION << "\n" << e.what() << endl;
	}

	while (1) {
		int newSocket = serverSocket.listenForConnection();

		if (newSocket == 0)
			continue;

		Socket *clientSocket = new ClientSocket(newSocket);
		Socket *outgoingSocket = new OutgoingSocket();

		try {
			outgoingSocket->create();
		} catch (exception &e) {
			cerr << "Caught exception at " << LOCATION << "\n" << e.what()
					<< endl;
		}

		SocketConnector *socketConnector = new SocketConnector();
		socketConnector->connect(clientSocket, outgoingSocket);
	}
}

Main::Main() {

}

Main::~Main() {

}
