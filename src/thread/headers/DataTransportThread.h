#ifndef THREAD_DATATRANSPORTTHREAD_H_
#define THREAD_DATATRANSPORTTHREAD_H_

#include "../../socket/headers/Socket.h"

#include <iostream>
using namespace std;

class DataTransportThread {

public:

	static void entryPoint(Socket *readSocket, Socket *writeSocket);
	DataTransportThread();
	virtual ~DataTransportThread();
};

#endif
