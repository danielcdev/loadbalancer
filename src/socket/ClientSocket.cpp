#include "ClientSocket.h"

void ClientSocket::create() {

}

int ClientSocket::read(char *&data) {
	char buffer[65535];
	int bytesRead = ::read(fileDescriptor, buffer, 65535);

	if (bytesRead <= 0)
		return 0;

	data = new char[bytesRead];

	for (int i = 0; i < bytesRead; i++)
		data[i] = buffer[i];

	cout << data;

	return bytesRead;
}

void ClientSocket::write(char data[], int length) {
	cout << "Count " << length << endl;
	send(fileDescriptor, data, length, MSG_NOSIGNAL);
}

void ClientSocket::close() {
	::close(fileDescriptor);
}

ClientSocket::ClientSocket(int fileDescriptor) {
	this->fileDescriptor = fileDescriptor;
}

ClientSocket::~ClientSocket() {

}
