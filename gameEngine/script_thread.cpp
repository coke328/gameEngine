#include "script_thread.h"



void script_thread::setLoopFPS(float loopFps)
{
	LoopFPS = loopFps;
	targetDeltaT = 1 / (float)LoopFPS;
}

float script_thread::getLoopFPS()
{
	return LoopFPS;
}

void script_thread::setStartTime()
{
	StartTime = steady_clock::now();
}

timePoint script_thread::getStartTime()
{
	return StartTime;
}

double script_thread::getTargetDeltaT()
{
	return targetDeltaT;
}

void script_thread::setDeltaT(double dt)
{
	deltaT = dt;
}

bool script_thread::getIsLoop()
{
	return isLoop;
}

void script_thread::setIsLoop(bool in)
{
	isLoop = in;
}

std::thread& script_thread::getThread()
{
	return thread;
}

void script_thread::callStart()
{


	Start();
}

void script_thread::callLoop()
{
	
	while (isLoop) {
		nanoseconds deltaNanoT = steady_clock::now() - StartTime;
		if (deltaNanoT.count() > Math::SecToNanoSec(targetDeltaT)) {
			StartTime = steady_clock::now();
			deltaT = Math::NanoSecToSec(deltaNanoT.count());
			Loop();
		}
	}
}

void script_thread::Start()
{
}

void script_thread::Loop()
{
}

script_thread::~script_thread()
{
	isLoop = false;
}
