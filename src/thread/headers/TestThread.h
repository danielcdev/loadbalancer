#ifndef THREAD_HEADERS_TESTTHREAD_H_
#define THREAD_HEADERS_TESTTHREAD_H_

#include <thread>

#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <iostream>

using namespace std;

class TestThread {

public:

	void alive(int socketFileDescriptor);
	static void test(int socketFileDescriptor);
	void readData(int socket, int outgoingSocket);
	static void sendData(int outgoingSocket, int socket);
	TestThread();
	virtual ~TestThread();
};

#endif
