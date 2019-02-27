#include "DataTransportThread.h"

void DataTransportThread::entryPoint(Socket *readSocket, Socket *writeSocket) {
	while (1) {
		char *data;
		int bytesRead = readSocket->read(data);

		if (bytesRead <= 0)
			break;

		writeSocket->write(data, bytesRead);
		delete[] data;
	}

	readSocket->close();
}

DataTransportThread::DataTransportThread() {

}

DataTransportThread::~DataTransportThread() {

}
