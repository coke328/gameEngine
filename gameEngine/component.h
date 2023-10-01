#pragma once
#include <string>
#include <typeinfo>

class gameObject;

class component
{
protected:
	std::string componentName;
	gameObject* gameobject;

public:
	component();
	virtual ~component();//component delete in destructor of gameObject

	template<typename t>
	void setName(t n);

	void linkGameObject(gameObject* go);

	template<typename t>
	t* casting();

};

template<typename t>
inline void component::setName(t n)
{
	componentName = typeid(t).name();
}

template<typename t>
inline t* component::casting()
{
	return dynamic_cast<t*>(this);
}
