#pragma once
#include "Color.h"

class globalVar {
private:

	int WindowFPS;

public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	Color backgroundColor;

	globalVar();

	int getWindowFPS();
	void setWindowFPS(int fps);
};


extern globalVar g_Data;