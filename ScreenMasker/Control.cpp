#include "Control.h"

#include <iostream>
using namespace std;

Control::Control()
{

}


Control::~Control()
{

}

void Control::run()
{
	Scanner* Scan = new Scanner();
	if (!Scan->CaptureArea(0, 0, 100, 100))
	{
		cout << "Scan failed!" << endl;
		cin.ignore();
		return;
	}

	cout << (int)Scan->Pixels[0] << ":" << (int)Scan->Pixels[1] << ":" << (int)Scan->Pixels[2] << endl;

	cin.ignore();
}