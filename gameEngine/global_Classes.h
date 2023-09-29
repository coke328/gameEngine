#pragma once
#include "Color.h"
#include <vector>

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

namespace Funcs {
	template<typename t>
	void deleteVecPtr(std::vector<void*> vec);

	template<typename Container>
	void delete_vecAndList(Container& c) { while (!c.empty()) delete c.back(), c.pop_back(); }



}


extern globalVar g_Data;


