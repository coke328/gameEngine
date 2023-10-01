#include "gameObject.h"

void gameObject::resisterChild(gameObject* c)
{
	childs.push_back(c);
}

template<typename t>
void gameObject::addComponent()
{
	t* com = new t();
	if (dynamic_cast<component*>(com) != nullptr) {
		components.push_back(com);
		com->linkGameObject(this);
		com.setName(com);
	}
}

gameObject::~gameObject()
{
	for (component* c : components) {
		delete c;
	}
	components.clear();
}
