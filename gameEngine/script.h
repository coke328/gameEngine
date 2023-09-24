#pragma once
#include <chrono>
#define nanoSec 1000000000
using std::chrono::steady_clock;
using std::chrono::nanoseconds;

typedef steady_clock::time_point timePoint;

class script
{
protected:
	float LoopFPS;
	double targetDeltaT;
	timePoint StartTime;
	double deltaT;

	

public:
	script();
	script(float fps);
	void setLoopFPS(float LoopFps);
	float getLoopFPS();
	void setStartTime();
	timePoint getStartTime();
	double getTargetDeltaT();
	void setDeltaT(double dt);

	void callStart();
	void callLoop(double deltaT);

	virtual void Start();

	virtual void Loop();

};

