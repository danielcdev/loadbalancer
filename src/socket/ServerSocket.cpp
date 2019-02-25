#include "ServerSocket.h"

void ServerSocket::create() {
	timeout.tv_sec = timeoutSeconds;
	timeout.tv_usec = timeoutMilliseconds;

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(listenPort);
	addressLength = sizeof(address);

	//TODO Add errno back into exception

	if ((socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		throw LoadBalancerException("Failed to create socket");

	if (setsockopt(socketFileDescriptor, SOL_SOCKET, SO_REUSEADDR,
			(char *) &yes, sizeof(yes)) < 0)
		throw LoadBalancerException("Failed to set socket options");

	if (bind(socketFileDescriptor, (struct sockaddr *) &address,
			sizeof(address)) < 0)
		throw LoadBalancerException("Failed to bind socket");

	if (listen(socketFileDescriptor, SOMAXCONN) < 0)
		throw LoadBalancerException("Failed to listen");
}

int ServerSocket::listenForConnection() {
	int activity, newSocketFileDescriptor = 0;
	fd_set readFileDescriptors;

	FD_ZERO(&readFileDescriptors);
	FD_SET(socketFileDescriptor, &readFileDescriptors);

	activity = select(100, &readFileDescriptors, 0, 0, 0);

	if (activity < 0
			|| (newSocketFileDescriptor = accept(socketFileDescriptor,
					(struct sockaddr *) &address, (socklen_t*) &addressLength))
					< 0
			|| setsockopt(socketFileDescriptor, SOL_SOCKET, SO_RCVTIMEO,
					(char *) &timeout, sizeof(struct timeval)) < 0
			|| newSocketFileDescriptor < 1)
		return 0;

	return newSocketFileDescriptor;
}

ServerSocket::ServerSocket() {

}

ServerSocket::~ServerSocket() {

}
