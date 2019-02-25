#pragma once
#include <Ole2.h>
#include <vector>

using namespace std;

class Scanner
{
public:
	
	bool CaptureArea(int x, int y, int width, int height);
	bool GetPixels(HBITMAP Bitmap, int width, int height);

	vector<unsigned char> Pixels;
};

