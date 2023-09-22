#include "loopsManager.h"


funcpAndFPS::funcpAndFPS()
{
	fp = nullptr;
	FPS = 60;
}

funcpAndFPS::funcpAndFPS(void(*funcp)(float), int fps)
{
	fp = funcp;
	FPS = fps;
}

void funcpAndFPS::setFPS(int fps)
{
	FPS = fps;
}

loopsManager* loopsManager::instance = nullptr;

loopsManager* loopsManager::GetInstance() {
	if (instance == nullptr) {
		instance = new loopsManager();
	}
	return instance;
}

loopsManager::loopsManager()
{
}

