#include "ObjectsManager.h"

ObjectsManager::ObjectsManager() 
{
    tObject = new testObject();
    tObject2 = new testObject2();
}

ObjectsManager::~ObjectsManager() 
{
    delete instance;

    delete tObject;
    delete tObject2;

    if (Objects.size() > 0) {
        for (int i = 0; i < Objects.size(); i++) {
            delete Objects[i];
        }
    }
}

void ObjectsManager::resisterObject(gameObject* o)
{
    Objects.push_back(o);
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

gameObject::gameObject()
{
    parent = nullptr;
    ObjectsManager::getInstance().resisterObject(this);
}

gameObject::gameObject(gameObject* p)
{
    parent = p;
    parent->resisterChild(this);

    ObjectsManager::getInstance().resisterObject(this);
}

