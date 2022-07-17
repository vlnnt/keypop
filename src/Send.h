#ifndef SEND_H
#define SEND_H

#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Send {
public:
	Send();

private:
	ofstream _file;
	string _powershell;
};

#endif // !SEND_H