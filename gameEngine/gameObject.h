#pragma once
#include <vector>
#include "component.h"

class gameObject
{
	
	gameObject* parent;
	std::vector<gameObject*> childs;

	std::vector<component*> components;

public:
	gameObject();
	gameObject(gameObject* p);
	void resisterChild(gameObject* c);
	void addComponent(component* c);
	template<typename t>
	t* getComponent();
};

template<typename t>
inline t* gameObject::getComponent()
{
	for (int i = 0; i < components.size(); i++) {
		if (components[i]->componentName == typeid(t*).name()) {
			return components[i]->casting<t>();

		}
	}

	return nullptr;
}