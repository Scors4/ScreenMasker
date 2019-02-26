#include "Scanner.h"

// Pulled from https://stackoverflow.com/questions/9524393/how-to-capture-part-of-the-screen-and-save-it-to-a-bmp
// 
bool Scanner::CaptureArea(int x, int y, int width, int height)
{
	HDC hdcSource = GetDC(NULL);
	HDC hdcMemory = CreateCompatibleDC(hdcSource);

	HBITMAP hBitmap = CreateCompatibleBitmap(hdcSource, width, height);
	HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcMemory, hBitmap);

	BitBlt(hdcMemory, 0, 0, height, width, hdcSource, x, y, SRCCOPY);
	hBitmap = (HBITMAP)SelectObject(hdcMemory, hBitmapOld);
	
	DeleteDC(hdcSource);
	DeleteDC(hdcMemory);

	return GetPixels(hBitmap, width, height);
}

// Pulled from https://stackoverflow.com/questions/22050413/c-get-raw-pixel-data-from-hbitmap
//
bool Scanner::GetPixels(HBITMAP Bitmap, int width, int height)
{
	BITMAP Bmp = { 0 };
	BITMAPINFO Info = { 0 };
	vector<unsigned char> Pixels = vector<unsigned char>();

	HDC DC = CreateCompatibleDC(NULL);
	memset(&Info, 0, sizeof(BITMAPINFO));
	HBITMAP OldBitmap = (HBITMAP)SelectObject(DC, Bitmap);
	GetObject(Bitmap, sizeof(Bmp), &Bmp);

	Info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	Info.bmiHeader.biWidth = width = Bmp.bmWidth;
	Info.bmiHeader.biHeight = -Bmp.bmHeight;
	height = Bmp.bmHeight;
	Info.bmiHeader.biPlanes = 1;
	Info.bmiHeader.biBitCount = Bmp.bmBitsPixel;
	Info.bmiHeader.biCompression = BI_RGB;
	Info.bmiHeader.biSizeImage = ((width * Bmp.bmBitsPixel + 31) / 32) * 4 * height;

	Pixels.resize(Info.bmiHeader.biSizeImage);
	GetDIBits(DC, Bitmap, 0, height, &Pixels[0], &Info, DIB_RGB_COLORS);
	SelectObject(DC, OldBitmap);

	height = abs(height);
	DeleteDC(DC);
	
	if (Pixels.size() > 0)
	{
		this->Pixels = Pixels;
		return true;
	}

	return false;
}