#pragma once
#include <chrono>
#include <thread>
#include "math.h"

#define nanoSec 1000000000
using std::chrono::steady_clock;
using std::chrono::nanoseconds;

typedef steady_clock::time_point timePoint;


class script_thread
{
protected:
	float LoopFPS;
	double targetDeltaT;
	timePoint StartTime;
	double deltaT;

	bool isLoop;

	std::thread thread;

public:
	script_thread();
	script_thread(float fps);
	~script_thread();
	void setLoopFPS(float LoopFps);
	float getLoopFPS();
	void setStartTime();
	timePoint getStartTime();
	double getTargetDeltaT();
	void setDeltaT(double dt);
	bool getIsLoop();
	void setIsLoop(bool in);
	std::thread& getThread();

	void callStart();
	void callLoop();

	virtual void Start();

	virtual void Loop();

};

