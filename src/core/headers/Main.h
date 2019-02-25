#ifndef CORE_HEADERS_MAIN_H_
#define CORE_HEADERS_MAIN_H_

#include <string>

#include "../../socket/headers/ServerSocket.h"
#include "../../thread/headers/TestThread.h"

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
