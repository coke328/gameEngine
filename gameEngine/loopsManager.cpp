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

bool loopsManager::registerScript(script_loop* sc)
{
	if (!isUpdate()) {
		scripts.push_back(sc);
		return true;
	}
	else {
		return false;
	}
}

void loopsManager::init()
{
	if (scripts.size() > 0) {
		std::list<script_loop*>::iterator iter;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			iter.operator*()->callStart();
		}
	}
}

void loopsManager::update()
{
	steady_clock::time_point currentT = steady_clock::now();
	std::list<script_loop*>::iterator iter;
	nanoseconds deltaT;
	if (scripts.size() > 0) 
	{
		runningUpdate = true;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			deltaT = steady_clock::now() - iter.operator*()->getStartTime();
			if (deltaT.count() > Math::SecToNanoSec(iter.operator*()->getTargetDeltaT())) {
				iter.operator*()->callLoop(Math::NanoSecToSec(deltaT.count()));
			}
		}
		runningUpdate = false;
	}
}

bool loopsManager::isUpdate()
{
	return runningUpdate;
}

script_loop::script_loop()
{
	LoopFPS = 144;
	targetDeltaT = 1 / LoopFPS;
	deltaT = 0;

	//Start();
	loopsManager::getInstance().registerScript(this);
}

script_loop::script_loop(float fps)
{
	setLoopFPS(fps);
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
	setLoopFPS(144);
	deltaT = 0;
	isLoop = false;

	//thread = std::thread(&script_thread::callLoop,this);

	ThreadLoopsManager::getInstance().registerScript(this);
}

script_thread::script_thread(float fps)
{
	setLoopFPS(fps);
	deltaT = 0;
	isLoop = false;

	//thread = std::thread(&script_thread::callLoop, this);

	ThreadLoopsManager::getInstance().registerScript(this);
}
