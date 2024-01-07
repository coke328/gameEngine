#include "script_thread.h"



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
	
	while (active) {
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
	active = false;
	thread.join();
}
