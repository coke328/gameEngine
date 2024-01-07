#pragma once
#include <deque>
#include <string>
#include "loopsManager.h"
#include "testObject.h"
#include "testObject2.h"
#include "gameObject.h"
#include "global_Classes.h"

class ObjectsManager
{
	static ObjectsManager *instance;

	ObjectsManager();

	std::deque<gameObject*> Objects;

public:
	~ObjectsManager();
	void resisterObject(gameObject* o);
	static ObjectsManager& getInstance();
	void init();
	void destroyGameObject(gameObject* go);
	int getIdxOfGameObject(gameObject* go);
	gameObject* getGameObjectByName(std::string name);
};

