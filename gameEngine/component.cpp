#include "component.h"

component::component()
{
	
}

component::~component()
{
}

void component::linkGameObject(gameObject* go)
{
	gameobject = go;
}
