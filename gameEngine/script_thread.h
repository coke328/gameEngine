#pragma once
#include "script.h"
#include <chrono>
#include <thread>
#include "math.h"

class script_thread : public script
{
protected:
	bool isLoop;

	std::thread thread;

public:
	script_thread();
	script_thread(float fps);
	~script_thread();
	bool getIsLoop();
	void setIsLoop(bool in);
	std::thread& getThread();

	void callStart();
	void callLoop();
};

