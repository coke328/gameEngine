#pragma once
#include "Color.h"

class globalVar {
private:

	int MainloopFPS;

public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	Color backgroundColor;

	globalVar();

	int getMainloopFPS();
	void setMainloopFPS(int fps);
};


extern globalVar Data;