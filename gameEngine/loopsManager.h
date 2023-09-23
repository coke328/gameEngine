#pragma once
#include <list>
#include <chrono>
#include "script.h"

using std::chrono::nanoseconds;
using std::chrono::steady_clock;

typedef void (script::*funcP)(double param);


class loopsManager
{
private:
	static loopsManager *instance;

	loopsManager();

	std::list<script*> scripts;

public:

	~loopsManager();

	static loopsManager& getInstance();

	void registerScript(script* sc);

	void setStartTimeAsNow();

	void init();

	void update();


};

class ThreadLoopsManager 
{

};

