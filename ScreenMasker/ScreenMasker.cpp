
#include "Control.h"

int main(int argc, char* argv[])
{
	Control* ctrl = new Control();

	ctrl->run();

	delete ctrl;
	ctrl = nullptr;

	return 0x5363;
}