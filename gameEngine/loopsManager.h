#pragma once
#include <list>
#include <chrono>
#include "script_loop.h"
#include "script_thread.h"
#include "math.h"
#include "global_Classes.h"

using std::chrono::nanoseconds;
using std::chrono::steady_clock;

typedef void (script_loop::*funcP)(double param);

class loopsManager
{
private:
	static loopsManager* instance;

	loopsManager();

	std::list<script_loop*> scripts;

	int defaultFps;

public:

	~loopsManager();

	static loopsManager& getInstance();

	void registerScript(script_loop* sc);

	void init(int dFps);

	void update();

	void destroyScript(script_loop* sc);

};

class ThreadLoopsManager 
{
private:
	static ThreadLoopsManager* instance;

	ThreadLoopsManager();

	std::list<script_thread*> scripts;

	int defaultFps;

public:
	~ThreadLoopsManager();

	static ThreadLoopsManager& getInstance();

	void registerScript(script_thread* sc);

	void startThread(script_thread* sc);

	void init(int dFps);

	void destroyThreadScript(script_thread* st);
};

