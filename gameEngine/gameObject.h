#pragma once
#include <deque>
#include <vector>
#include "component.h"

class gameObject
{
	std::string name;

	gameObject* parent;
	std::deque<gameObject*> childs;

	std::vector<component*> components;

public:
	gameObject();
	gameObject(gameObject* p);
	virtual ~gameObject();
	void setChild(gameObject* c);//
	template<typename t>
	t* addComponent();
	template<typename t>
	t* getComponent();
	bool isChild(gameObject* c);//find c in childs and return idx in childs
	int getIdxFromChilds(gameObject* c);//return -1 : not found
	gameObject* getChildByIdx(int idx);
	void setName(std::string n);
	std::string getName();
};


