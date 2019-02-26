#include "Socket.h"

void Socket::create() {

}

int Socket::read(char *&data) {
	char buffer[65535];
	int bytesRead = ::read(fileDescriptor, buffer, 65535);

	if (bytesRead <= 0)
		return 0;

	data = new char[bytesRead];

	for (int i = 0; i < bytesRead; i++)
		data[i] = buffer[i];

	return bytesRead;
}

void Socket::write(char data[], int length) {
	send(fileDescriptor, data, length, MSG_NOSIGNAL);
}

void Socket::close() {
	::close(fileDescriptor);
}

Socket::Socket() {

}

Socket::~Socket() {

}
