#include "loopsManager.h"


loopsManager *loopsManager::instance;

loopsManager::loopsManager()
{
	//std::cout << "con" << std::endl;
	defaultFps = 120;
}

loopsManager::~loopsManager()
{
	Funcs::delete_vecAndList(scripts);

	delete instance;
}

loopsManager& loopsManager::getInstance()
{
	if (instance == NULL) {
		instance = new loopsManager();
	}
	return *instance;
}

void loopsManager::registerScript(script_loop* sc)
{
	scripts.push_back(sc);
	sc->setLoopFPS(defaultFps);
}

void loopsManager::init(int dFps)
{
	
	defaultFps = dFps;

	//std::cout << "init dfps:" << defaultFps << std::endl;

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
	if (scripts.size() > 0) 
	{
		steady_clock::time_point currentT = steady_clock::now();
		std::list<script_loop*>::iterator iter;
		nanoseconds deltaT;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			deltaT = steady_clock::now() - iter.operator*()->getStartTime();//set deltaT
			if (iter.operator*()->isActiveScript() && deltaT.count() > Math::SecToNanoSec(iter.operator*()->getTargetDeltaT())) {
				
				iter.operator*()->callLoop(Math::NanoSecToSec(deltaT.count()));
				
			}
		}
	}
}

void loopsManager::destroyScript(script_loop* sc)
{
	int lastSize = scripts.size();
	scripts.remove(sc);

	if (lastSize == scripts.size()) {
		std::cout << "destroyScript : no loop script match" << std::endl;
	}

	delete sc;
	
}


script_loop::script_loop()
{
	activateScript();

	deltaT = 0;

	//Start();
	loopsManager::getInstance().registerScript(this);
}

script_loop::script_loop(float fps)
{
	activateScript();

	setLoopFPS(fps);
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
	Funcs::delete_vecAndList(scripts);

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
	sc->setLoopFPS(defaultFps);
	scripts.push_back(sc);
}

void ThreadLoopsManager::startThread(script_thread* sc)
{
	if (!sc->isActiveScript()) {
		sc->setStartTime();
		sc->activateScript();
		sc->getThread() = std::thread(&script_thread::callLoop, sc);
		sc->getThread().detach();
		
	}
}

void ThreadLoopsManager::init(int dFps)
{
	defaultFps = dFps;

	if (scripts.size() > 0) {
		std::list<script_thread*>::iterator iter;
		for (iter = scripts.begin(); iter != scripts.end(); iter++)
		{
			iter.operator*()->Start();
			startThread(iter.operator*());
		}
	}
}

void ThreadLoopsManager::destroyThreadScript(script_thread* st)
{

	int lastSize = scripts.size();
	scripts.remove(st);

	if (lastSize == scripts.size()) {
		std::cout << "destroyScript : no loop script match" << std::endl;
	}

	delete st;


}

script_thread::script_thread()
{
	activateScript();

	deltaT = 0;

	//thread = std::thread(&script_thread::callLoop,this);

	ThreadLoopsManager::getInstance().registerScript(this);
}

script_thread::script_thread(float fps)
{
	activateScript();

	setLoopFPS(fps);
	deltaT = 0;

	//thread = std::thread(&script_thread::callLoop, this);

	ThreadLoopsManager::getInstance().registerScript(this);
}
