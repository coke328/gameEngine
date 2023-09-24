#include "loopsManager.h"


loopsManager *loopsManager::instance;

loopsManager::loopsManager()
{
	runningUpdate = false;
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

bool loopsManager::registerScript(script* sc)
{
	if (!isUpdate()) {
		scripts.push_back(sc);
		return true;
	}
	else {
		return false;
	}
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
		runningUpdate = true;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			deltaT = steady_clock::now() - iter.operator*()->getStartTime();
			if (deltaT.count() > Math::SecToNanoSec(iter.operator*()->getTargetDeltaT())) {
				iter.operator*()->setDeltaT(Math::NanoSecToSec(deltaT.count()));
				iter.operator*()->Loop();
				setStartTimeAsNow();
			}
		}
		runningUpdate = false;
	}
}

bool loopsManager::isUpdate()
{
	return runningUpdate;
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

//-------------------------------------threadLoop----------------------

ThreadLoopsManager *ThreadLoopsManager::instance;

ThreadLoopsManager::ThreadLoopsManager()
{
	
}

ThreadLoopsManager::~ThreadLoopsManager()
{
	delete instance;
}

ThreadLoopsManager& ThreadLoopsManager::getInstance()
{
	if (instance == NULL) {
		instance = new ThreadLoopsManager();
	}
	return *instance;
}

void ThreadLoopsManager::registerScript(script_thread* sc)
{
	scripts.push_back(sc);
}

void ThreadLoopsManager::startThread(script_thread* sc)
{
	if (!sc->getIsLoop()) {
		sc->setStartTime();
		sc->setIsLoop(true);
		sc->getThread() = std::thread(&script_thread::callLoop, sc);
		sc->getThread().detach();
		
	}
}

void ThreadLoopsManager::init()
{
	if (scripts.size() > 0) {
		std::list<script_thread*>::iterator iter;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			iter.operator*()->Start();
			startThread(iter.operator*());
		}
	}
}

script_thread::script_thread()
{
	LoopFPS = 144;
	targetDeltaT = 1 / LoopFPS;
	deltaT = 0;
	isLoop = false;

	//thread = std::thread(&script_thread::callLoop,this);

	ThreadLoopsManager::getInstance().registerScript(this);
}

script_thread::script_thread(float fps)
{
	LoopFPS = fps;
	targetDeltaT = 1 / LoopFPS;
	deltaT = 0;
	isLoop = false;

	//thread = std::thread(&script_thread::callLoop, this);

	ThreadLoopsManager::getInstance().registerScript(this);
}
