#include "ObjectsManager.h"

ObjectsManager::ObjectsManager() 
{

}

ObjectsManager::~ObjectsManager() 
{
    delete instance;
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
