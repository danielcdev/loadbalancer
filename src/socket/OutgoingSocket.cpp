#include "OutgoingSocket.h"

void OutgoingSocket::create() {
	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

	fileDescriptor = socket(AF_INET, SOCK_STREAM, 0);

	if (connect(fileDescriptor, (struct sockaddr *) &serverAddress,
			sizeof(serverAddress)) < 0)
		throw LoadBalancerException("Failed to connect outgoing socket");
}

int OutgoingSocket::read(char *&data) {
	char buffer[65535];
	int bytesRead = ::read(fileDescriptor, buffer, 65535);

	if (bytesRead <= 0)
		return 0;

	data = new char[bytesRead];

	for (int i = 0; i < bytesRead; i++)
		data[i] = buffer[i];

	return bytesRead;
}

void OutgoingSocket::write(char data[], int length) {
	cout << "Count " << length << endl;
	send(fileDescriptor, (char*) data, length, MSG_NOSIGNAL);
}

void OutgoingSocket::close() {
	::close(fileDescriptor);
}

OutgoingSocket::OutgoingSocket() {

}

OutgoingSocket::~OutgoingSocket() {

}
