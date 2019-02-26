#include "SocketData.h"

void SocketData::setBytesReceived(int bytesReceived) {
	this->bytesReceived = bytesReceived;
}

int SocketData::getBytesReceived() {
	return bytesReceived;
}

char* SocketData::getData() {
	return this->data;
}

SocketData::SocketData() {

}

SocketData::~SocketData() {

}
