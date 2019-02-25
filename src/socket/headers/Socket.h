#ifndef SOCKET_SOCKET_H_
#define SOCKET_SOCKET_H_

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <string.h>

class Socket {

public:

	virtual void create()=0;
	virtual int read(char *data)=0;
	virtual void write(char data[], int length)=0;
	virtual void close()=0;
	Socket();
	virtual ~Socket();
};

#endif
