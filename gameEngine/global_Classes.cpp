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

template<typename t>
void Funcs::deleteVecPtr(std::vector<void*> vec)
{
	for (void* p : vec) {
		delete dynamic_cast<t*>(p);
	}
	vec.clear();
}