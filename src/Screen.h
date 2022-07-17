#ifndef SCREEN_H
#define SCREEN_H

#include <Windows.h>
#include <gdiplus.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <thread>

using namespace std;
using namespace Gdiplus;

class Screen {
public:
	Screen();
	~Screen();
	BITMAPINFOHEADER createBitmapHeader(int width, int height);
	HBITMAP ScreenCapture(HWND hwnd);
	bool Save(HBITMAP* hbitmap, vector<BYTE>& data, string format);
	
private:	
	vector<BYTE> _data;
	string _dataFormat;
	Status _status;
	GdiplusStartupInput _gdiplusStartupInput;
	ULONG_PTR _gdiplusToken;
	BITMAPINFOHEADER _bi;
	BITMAPINFOHEADER _gdi_bi;
	LPVOID _pImage;
	HWND _hwnd;
	HBITMAP _hBmp;
	CLSID _clsid;
	DWORD _dwBmpSize;
	HDC _hWindowDC;
	HDC _hWindowCompatibleDC;
	HBITMAP _hbwindow;
	HANDLE _hDIB;
	HGLOBAL _hg;
	IStream* _istream;
	int _bufsize;
	int _screenX;
	int _screenY;
	int _width;
	int _height;
	char* _lpbitmap;
};

#endif // !SCREEN_H