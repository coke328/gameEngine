#include "script_thread.h"




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
			setStartTime();
			setDeltaT(Math::NanoSecToSec(deltaNanoT.count()));
			Loop();
		}
	}
}


script_thread::~script_thread()
{
	isLoop = false;
}
