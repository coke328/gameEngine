#pragma once
#include <vector>

class gameObject
{
	
	gameObject* parent;
	std::vector<gameObject*> childs;

public:
	gameObject();
	gameObject(gameObject* p);
	void resisterChild(gameObject* c);
};

