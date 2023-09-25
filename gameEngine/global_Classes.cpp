#include "global_Classes.h"

globalVar::globalVar() {
	WindowFPS = 144;
}

int globalVar::getWindowFPS() {
	return WindowFPS;
}

void globalVar::setWindowFPS(int fps) {
	WindowFPS = fps;
}

globalVar g_Data;