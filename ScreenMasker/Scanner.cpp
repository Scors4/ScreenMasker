#include "Scanner.h"


bool Scanner::CaptureArea(int x, int y, int width, int height)
{
	HDC hdcSource = GetDC(NULL);
	HDC hdcMemory = CreateCompatibleDC(hdcSource);

	HBITMAP hBitmap = CreateCompatibleBitmap(hdcSource, width, height);
	HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcMemory, hBitmapOld);




	return true;
}