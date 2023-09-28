#pragma once
#include "script_loop.h"
#include <iostream>

class testObject : public script_loop
{

public:
	testObject();

	void Start();
	void Loop();
};

