#include "script.h"



script::~script()
{
}

void script::setLoopFPS(float loopFps)
{
	LoopFPS = loopFps;
	targetDeltaT = 1 / (float)LoopFPS;
}

float script::getLoopFPS()
{
	return LoopFPS;
}

void script::setStartTime()
{
	StartTime = steady_clock::now();
}

timePoint script::getStartTime()
{
	return StartTime;
}

double script::getTargetDeltaT()
{
	return targetDeltaT;
}

double script::getDeltaT()
{
	return deltaT;
}

void script::setDeltaT(double dt)
{
	deltaT = dt;
}

void script::disableScript()
{
	active = false;
}

void script::activateScript()
{
	active = true;
}

bool script::isActiveScript()
{
	return active;
}
