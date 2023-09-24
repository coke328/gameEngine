#pragma once
#include "script.h"
#include <iostream>

class testObject : public script
{

public:
	testObject(float fps) : script(fps) {}

	void Start();
	void Loop();
};

