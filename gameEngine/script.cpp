#include "script.h"



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

void script::setDeltaT(double dt)
{
	deltaT = dt;
}

void script::callStart()
{
	setStartTime();
	Start();
}

void script::callLoop(double deltaT)
{
	setDeltaT(deltaT);
	Loop();
	setStartTime();
}

void script::Start()
{
}

void script::Loop()
{
}
