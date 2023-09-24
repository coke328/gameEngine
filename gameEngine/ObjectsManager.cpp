#include "ObjectsManager.h"

ObjectsManager::ObjectsManager() 
{
    tObject = new testObject(1);
    tObject2 = new testObject2(1);
}

ObjectsManager::~ObjectsManager() 
{
    delete instance;

    delete tObject;
    delete tObject2;
}

ObjectsManager& ObjectsManager::getInstance()
{
    if (instance == NULL) {
        instance = new ObjectsManager();
    }

    return *instance;
}

void ObjectsManager::init()
{
    
}

ObjectsManager *ObjectsManager::instance;
