#pragma once
#include <list>
#include <chrono>

class funcpAndFPS {
	void (*fp)(float);
	int FPS;
public:
	funcpAndFPS();
	funcpAndFPS(void (*funcp)(float),int fps);
	void setFPS(int fps);
};

class loopsManager
{
protected:

	loopsManager();

	static loopsManager* instance;

	std::list<funcpAndFPS> funcs;

public:
	loopsManager(loopsManager& other) = delete;
	void operator=(const loopsManager&) = delete;

	static loopsManager* GetInstance();

	void registerFunc(void (*funcp)(float),float fps) {
		funcs.push_back(funcpAndFPS(funcp,fps));
	}

	void update();


};

class ThreadLoopsManager 
{

};

