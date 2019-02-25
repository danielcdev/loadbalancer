#include "Main.h"

int main() {
	Main mainClass = Main();
	mainClass.begin();

	return 0;
}

void Main::begin() {
	ServerSocket serverSocket;

	try {
		serverSocket.create();
	} catch (exception &e) {
		cerr << "Caught exception at " << LOCATION << "\n" << e.what() << endl;
	}

	while (1) {
		int newSocket = serverSocket.listenForConnection();

		if (newSocket == 0)
			continue;

		TestThread *thisThread = new TestThread();
		thisThread->alive(newSocket);
	}
}

Main::Main() {

}

Main::~Main() {

}
