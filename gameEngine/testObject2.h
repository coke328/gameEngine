#pragma once
#include <iostream>
#include "script_thread.h"

class testObject2 : public script_thread
{

public:
	testObject2(float fps) : script_thread(fps) {}

	void Start();
	void Loop();
};

