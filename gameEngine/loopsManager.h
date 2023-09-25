#pragma once
#include <list>
#include <chrono>
#include "script.h"
#include "script_thread.h"
#include "math.h"

using std::chrono::nanoseconds;
using std::chrono::steady_clock;

typedef void (script::*funcP)(double param);

class loopsManager
{
private:
	static loopsManager* instance;

	loopsManager();

	std::list<script*> scripts;

	bool runningUpdate;

public:

	~loopsManager();

	static loopsManager& getInstance();

	bool registerScript(script* sc);

	void init();

	void update();

	bool isUpdate();
};

class ThreadLoopsManager 
{
private:
	static ThreadLoopsManager* instance;

	ThreadLoopsManager();

	std::list<script_thread*> scripts;


public:
	~ThreadLoopsManager();

	static ThreadLoopsManager& getInstance();

	void registerScript(script_thread* sc);

	void startThread(script_thread* sc);

	void init();

};

