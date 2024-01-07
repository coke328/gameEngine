#include "ObjectsManager.h"

ObjectsManager::ObjectsManager() 
{
}

ObjectsManager::~ObjectsManager() 
{

    Objects.clear();

    delete instance;
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

void ObjectsManager::destroyGameObject(gameObject* go)
{
    int idx = getIdxOfGameObject(go);
    if (idx != -1) {
        Objects.erase(Objects.begin() + idx);
        delete go;
    }
    std::cout << "no GameObject deleted" << std::endl;
}

int ObjectsManager::getIdxOfGameObject(gameObject* go)
{
    for (int i = 0; i < Objects.size(); i++) {
        if (Objects[i] == go) {
            return i;
        }
    }
    std::cout << "can't find idx of GameObject" << std::endl;
    return -1;
}

gameObject* ObjectsManager::getGameObjectByName(std::string name)
{

    for (int i = 0; i < Objects.size(); i++) {
        if (Objects[i]->getName() == name) {
            return Objects[i];
        }
    }

    std::cout << "getGameObjectByName : nothing match '" << name << "'" << std::endl;

    return nullptr;
}

ObjectsManager *ObjectsManager::instance;

gameObject::gameObject()
{
    name = "";

    parent = nullptr; 
    ObjectsManager::getInstance().resisterObject(this);
}

gameObject::gameObject(gameObject* p)
{
    name = "";

    parent->setChild(this);

    ObjectsManager::getInstance().resisterObject(this);
}



