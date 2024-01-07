#pragma once
#include <chrono>
#include "component.h"
#include "gameObject.h"
#define nanoSec 1000000000
using std::chrono::steady_clock;
using std::chrono::nanoseconds;

typedef steady_clock::time_point timePoint;

class script : public component
{
protected:
	float LoopFPS;
	double targetDeltaT;//deltaT will little more than this
	timePoint StartTime;
	double deltaT;//time between loop and loop

	bool active;

public:
	virtual ~script();
	void setLoopFPS(float LoopFps);
	float getLoopFPS();
	void setStartTime();
	timePoint getStartTime();
	double getTargetDeltaT();
	double getDeltaT();
	void setDeltaT(double dt);
	void disableScript();
	void activateScript();
	bool isActiveScript();

	virtual void callStart() = 0;

	virtual void Start() = 0;

	virtual void Loop() = 0;

};

