#ifndef SOCKET_SOCKET_H_
#define SOCKET_SOCKET_H_

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "SocketData.h"

class Socket {

protected:

	int fileDescriptor;

public:

	virtual void create();
	virtual int read(char *&data);
	virtual void write(char data[], int length);
	virtual void close();
	Socket();
	virtual ~Socket();
};

#endif
