#pragma once
#include "script.h"
#include <iostream>

class testObject : public script
{
	float LoopFps;

public:
	testObject(float fps) : script(fps) {
		LoopFps = fps;
	}

	void Start();
	void Loop();
};

