#include "ClientSocket.h"

ClientSocket::ClientSocket(int fileDescriptor) {
	this->fileDescriptor = fileDescriptor;
}

ClientSocket::~ClientSocket() {

}
