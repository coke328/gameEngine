#include "gameObject.h"

void gameObject::resisterChild(gameObject* c)
{
	childs.push_back(c);
}

void gameObject::addComponent(component* c)
{
	components.push_back(c);
}
