#include "global_Classes.h"

globalVar::globalVar() {
	MainloopFPS = 120;
}

int globalVar::getMainloopFPS() {
	return MainloopFPS;
}

void globalVar::setMainloopFPS(int fps) {
	MainloopFPS = fps;
}

globalVar g_Data;