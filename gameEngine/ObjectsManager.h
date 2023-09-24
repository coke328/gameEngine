#pragma once
#include "loopsManager.h"
#include "testObject.h"
#include "testObject2.h"

class ObjectsManager
{
	static ObjectsManager *instance;

	ObjectsManager();
	//objectClasses 

	testObject* tObject;
	testObject2* tObject2;

public:
	~ObjectsManager();
	static ObjectsManager& getInstance();

	void init();
};

