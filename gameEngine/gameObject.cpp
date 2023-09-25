#include "gameObject.h"

void gameObject::resisterChild(gameObject* c)
{
	childs.push_back(c);
}
