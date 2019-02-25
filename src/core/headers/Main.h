#ifndef CORE_HEADERS_MAIN_H_
#define CORE_HEADERS_MAIN_H_

#include <string>

#include "SocketConnector.h"
#include "../../socket/headers/Socket.h"
#include "../../socket/headers/ClientSocket.h"
#include "../../socket/headers/ServerSocket.h"
#include "../../socket/headers/OutgoingSocket.h"

#include <iostream>
#include <string.h>

#define __FILENAME__ strrchr("/" __FILE__, '/') + 1
#define LOCATION string(__FILENAME__) + ":" + string(__func__) + "():" + to_string(__LINE__)

using namespace std;

class Main {

public:

	void begin();
	Main();
	virtual ~Main();
};

#endif
