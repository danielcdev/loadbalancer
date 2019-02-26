#ifndef SOCKET_SOCKETDATA_H_
#define SOCKET_SOCKETDATA_H_

class SocketData {

	int bytesReceived = 0;
	char *data = new char[0];

public:

	void setBytesReceived(int bytesReceived);
	int getBytesReceived();
	void setData(char *data);
	char* getData();
	SocketData();
	virtual ~SocketData();
};

#endif
