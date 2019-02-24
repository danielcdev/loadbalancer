#include "Main.h"

int main() {
	Main mainClass = Main();
	mainClass.begin();

	return 0;
}

void Main::begin() {
	try {
		makeSocket();
	} catch (const char* e) {
		cout << "Caught exception " << e << endl;
	}

	while (1) {
		int newSocket = listenForConnection();

		if (newSocket == 0)
			continue;

		while (1) {
			struct sockaddr_in serverAddress;
			int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
			serverAddress.sin_family = AF_INET;
			serverAddress.sin_port = htons(8080);

			inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

			if (connect(clientSocket, (struct sockaddr *) &serverAddress,
					sizeof(serverAddress)) < 0)
				cout << "Failed to connect\n";

			readData(newSocket, clientSocket);
		}
	}
}

void Main::makeSocket() {
	timeout.tv_sec = timeoutSeconds;
	timeout.tv_usec = timeoutMilliseconds;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	addressLength = sizeof(address);

	if ((actualSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		throw "Failed to create socket [Errno: " + to_string(errno) + "]";

	if (setsockopt(actualSocket, SOL_SOCKET, SO_REUSEADDR, (char *) &yes,
			sizeof(yes)) < 0)
		throw "Failed to set socket options [Errno: " + to_string(errno) + "]";

	if (bind(actualSocket, (struct sockaddr *) &address, sizeof(address)) < 0)
		throw "Failed to bind socket [Errno: " + to_string(errno) + "]";

	if (listen(actualSocket, SOMAXCONN) < 0)
		throw "Failed to listen [Errno: " + to_string(errno) + "]";
}

int Main::listenForConnection() {
	int activity, newSocket = 0;
	fd_set readfds;

	FD_ZERO(&readfds);
	FD_SET(actualSocket, &readfds);

	try {
		activity = select(100, &readfds, 0, 0, 0);

		if (activity < 0
				|| (newSocket = accept(actualSocket,
						(struct sockaddr *) &address,
						(socklen_t*) &addressLength)) < 0
				|| setsockopt(actualSocket, SOL_SOCKET, SO_RCVTIMEO,
						(char *) &timeout, sizeof(struct timeval)) < 0
				|| newSocket < 1)
			return 0;

		cout << "New socket (" << to_string(newSocket) << ") connection from "
				<< endl;
		//+ getCurrentIp() + ":" + to_string(port)
		//);
	} catch (const char* e) {
		cout << "Failure to accept new socket connection [" << e << "]" << endl;
	}

	return newSocket;
}

void Main::readData(int socket, int clientSocket) {
	while (1) {
		char buffer[65535];
		int bytesRead = ::read(socket, buffer, 65535);
		char finalData[bytesRead];

		if (bytesRead <= 0) {
			cout << "Breaking\n";
			break;
		}

		for (int i = 0; i < bytesRead; i++)
			finalData[i] = buffer[i];

		cout << "Read " << bytesRead << endl;

		send(clientSocket, (char*) finalData, bytesRead, MSG_NOSIGNAL);

		char clientBuffer[65535];
		int clientBytesRead = ::read(clientSocket, clientBuffer, 65535);

		char clientFinalData[clientBytesRead];

		for (int i = 0; i < clientBytesRead; i++)
			clientFinalData[i] = clientBuffer[i];

		cout << "Received " << clientBytesRead << endl;

		send(socket, (char*) clientFinalData, clientBytesRead, MSG_NOSIGNAL);
	}
}

Main::Main() {

}

Main::~Main() {

}
