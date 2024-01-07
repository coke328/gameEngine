#pragma once
#include "script.h"
#include <chrono>
#include <thread>
#include "math.h"

class script_thread : public script
{
protected:

	std::thread thread;

public:
	script_thread();
	script_thread(float fps);
	virtual ~script_thread();
	std::thread& getThread();

	void callStart();
	void callLoop();
};

