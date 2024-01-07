#pragma once
#include <string>
#include <typeinfo>
#include <iostream>

class gameObject;

class component
{
protected:
	gameObject* gameobject;

public:
	component();
	virtual ~component();//component delete in destructor of gameObject

	void linkGameObject(gameObject* go);

	template<typename t>
	t* casting();

};
