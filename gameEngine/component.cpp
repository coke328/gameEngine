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

template<typename t>
t* component::casting()
{
	return dynamic_cast<t*>(this);
}