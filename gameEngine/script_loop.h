#pragma once
#include "script.h"

class script_loop : public script
{

public:
	script_loop();
	script_loop(float fps);
	virtual ~script_loop();

	void callStart();
	void callLoop(double deltaT);
};

