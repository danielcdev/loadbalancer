#include "DataTransportThread.h"

void DataTransportThread::entryPoint(Socket *readSocket, Socket *writeSocket) {
	while (1) {
		char *data;
		int bytesRead = readSocket->read(data);

		if (bytesRead <= 0)
			break;

		cout << "Writing " << data << endl;

		writeSocket->write(data, bytesRead);
	}

	readSocket->close();
	writeSocket->close();
}

DataTransportThread::DataTransportThread() {

}

DataTransportThread::~DataTransportThread() {

}
