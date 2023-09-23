#pragma once
#include "loopsManager.h"
#include "testObject.h"

class ObjectsManager
{
	static ObjectsManager *instance;

	ObjectsManager();
	//objectClasses 

	testObject tObject = testObject(1);

public:
	~ObjectsManager();
	static ObjectsManager& getInstance();

	void init();
};

