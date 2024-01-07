#include "gameObject.h"

void gameObject::setChild(gameObject* c)
{
	gameObject* tmpParent = this->parent;
	while (tmpParent != nullptr) {
		if (c->childs.size() == 0) {
			if (c == tmpParent) {
				break;
			}
		}
		else if(c->isChild(tmpParent)){
			break;
		}
		tmpParent = tmpParent->parent;
	}
	if (!tmpParent) {
		childs.push_back(c);
		c->parent = this;
		return;
	}
	std::cout << "setChild : Child is ancestor" << std::endl;
}

bool gameObject::isChild(gameObject* c)
{
	for (int i = 0; i < childs.size(); i++) {
		if (childs[i] == c) {
			return true;
		}
		else if(childs[i]->childs.size() != 0) {
			if (childs[i]->isChild(c)) {
				return true;
			}
		}
	}
	return false;
}

int gameObject::getIdxFromChilds(gameObject* c)
{
	for (int i = 0; i < childs.size(); i++) {
		if (childs[i] == c) {
			return i;
		}
	}
	return -1;
}

gameObject* gameObject::getChildByIdx(int idx)
{

	if (idx < childs.size()) {
		return childs[idx];
	}

	return nullptr;
}

void gameObject::setName(std::string n)
{
	name = n;
}

std::string gameObject::getName()
{
	return name;
}

template<typename t>
t* gameObject::addComponent()//use script component  :  transform* tf = gameObject->addComponent<transfrom>();
{
	t* com = new t();
	if (dynamic_cast<component*>(com) != nullptr) {
		components.push_back(com);
		com->linkGameObject(this);
		return com;
	}
	else {
		std::cout << "addcomponent error : '" << typeid(com).name() << "' is not component" << std::endl;
		return nullptr;
	}
}

template<typename t>
t* gameObject::getComponent()
{
	for (int i = 0; i < components.size(); i++) {
		if (typeid(*components[i]).name().compare(typeid(t).name())) {
			return components[i]->casting<t>();

		}
	}
	std::cout << "there is no '" << typeid(t).name() << "' component match" << std::endl;

	return nullptr;
}

gameObject::~gameObject()
{
	for (component* c : components) {
		delete c;
	}
	components.clear();
}
