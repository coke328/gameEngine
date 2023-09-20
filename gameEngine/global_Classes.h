#pragma once
#include "Color.h"

class globalVar {
private:

public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	Color backgroundColor;

	globalVar();
};


extern globalVar Data;