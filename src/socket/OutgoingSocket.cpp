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

OutgoingSocket::OutgoingSocket() {

}

OutgoingSocket::~OutgoingSocket() {

}
