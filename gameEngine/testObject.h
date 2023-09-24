#pragma once
#include "script.h"
#include <iostream>

class testObject : public script
{

public:
	testObject();

	void Start();
	void Loop();
};

