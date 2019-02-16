
#include "Control.h"

void main(int argc, char* argv[])
{
	Control* ctrl = new Control();

	ctrl->run();

	delete ctrl;
	ctrl = nullptr;
}