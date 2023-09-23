#include "loopsManager.h"


double FpsToNanoSec(float fps) {
	return nanoSec / fps;
}

double nanoSecToSec(long long nSec) {
	return nSec / nanoSec;
}

double SecToNanoSec(double sec) {
	return sec * nanoSec;
}

loopsManager *loopsManager::instance;

loopsManager::loopsManager()
{
}

loopsManager::~loopsManager()
{
	delete instance;
}

loopsManager& loopsManager::getInstance()
{
	if (instance == NULL) {
		instance = new loopsManager();
	}
	return *instance;
}

void loopsManager::registerScript(script* sc)
{
	scripts.push_back(sc);
}

void loopsManager::setStartTimeAsNow()
{
	if (scripts.size() > 0) {
		std::list<script*>::iterator iter;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			iter.operator*()->setStartTime();
		}
	}
}

void loopsManager::init()
{
	if (scripts.size() > 0) {
		std::list<script*>::iterator iter;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			iter.operator*()->Start();
		}
	}

	setStartTimeAsNow();
}

void loopsManager::update()
{
	steady_clock::time_point currentT = steady_clock::now();
	std::list<script*>::iterator iter;
	nanoseconds deltaT;
	if (scripts.size() > 0) 
	{
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			deltaT = steady_clock::now() - iter.operator*()->getStartTime();
			if (deltaT.count() > SecToNanoSec(iter.operator*()->getTargetDeltaT())) {
				iter.operator*()->setDeltaT(nanoSecToSec(deltaT.count()));
				iter.operator*()->Loop();
				setStartTimeAsNow();
			}
		}
	}
}

script::script()
{
	LoopFPS = 144;
	targetDeltaT = 1 / LoopFPS;
	deltaT = 0;

	//Start();
	loopsManager::getInstance().registerScript(this);
}

script::script(float fps)
{
	LoopFPS = fps;
	targetDeltaT = 1 / LoopFPS;
	deltaT = 0;

	//Start();
	loopsManager::getInstance().registerScript(this);
}