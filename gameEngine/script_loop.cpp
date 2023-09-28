#include "script_loop.h"

script_loop::~script_loop()
{
}

void script_loop::callStart()
{
	setStartTime();
	Start();
}

void script_loop::callLoop(double deltaT)
{
	setDeltaT(deltaT);
	Loop();
	setStartTime();
}
