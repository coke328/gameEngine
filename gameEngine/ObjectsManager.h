#pragma once
#include <vector>
#include "loopsManager.h"
#include "testObject.h"
#include "testObject2.h"
#include "gameObject.h"

class ObjectsManager
{
	static ObjectsManager *instance;

	ObjectsManager();
	//objectClasses 

	testObject* tObject;
	testObject2* tObject2;

	std::vector<gameObject*> Objects;

public:
	~ObjectsManager();
	void resisterObject(gameObject* o);
	static ObjectsManager& getInstance();

	void init();
};

