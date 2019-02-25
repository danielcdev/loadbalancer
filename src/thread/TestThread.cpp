#include "TestThread.h"

void TestThread::alive(int socketFileDescriptor) {
	cout << "Spawning new thread\n";
	thread(TestThread::test, socketFileDescriptor).detach();
}

void TestThread::test(int socketFileDescriptor) {
	cout << "New thread here\n";
	struct sockaddr_in serverAddress;
	int outgoingSocket = socket(AF_INET, SOCK_STREAM, 0);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);

	inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

	if (connect(outgoingSocket, (struct sockaddr *) &serverAddress,
			sizeof(serverAddress)) < 0)
		cout << "Failed to connect\n";

	TestThread what;
	thread(TestThread::sendData, outgoingSocket, socketFileDescriptor).detach();

	while (1)
		what.readData(socketFileDescriptor, outgoingSocket);
}

void TestThread::readData(int socket, int outgoingSocket) {
	char buffer[65535];
	int bytesRead = ::read(socket, buffer, 65535);
	char finalData[bytesRead];

	/*if (bytesRead <= 0) {
	 cout << "Breaking\n";
	 break;
	 }*/

	for (int i = 0; i < bytesRead; i++)
		finalData[i] = buffer[i];

	cout << "Client read " << bytesRead << endl;

	send(outgoingSocket, (char*) finalData, bytesRead, MSG_NOSIGNAL);
}

void TestThread::sendData(int outgoingSocket, int socket) {
	while (1) {
		char clientBuffer[65535];
		int clientBytesRead = ::read(outgoingSocket, clientBuffer, 65535);

		char clientFinalData[clientBytesRead];

		for (int i = 0; i < clientBytesRead; i++)
			clientFinalData[i] = clientBuffer[i];

		cout << "Received " << clientBytesRead << endl;

		send(socket, (char*) clientFinalData, clientBytesRead, MSG_NOSIGNAL);
	}
}

TestThread::TestThread() {

}

TestThread::~TestThread() {

}
