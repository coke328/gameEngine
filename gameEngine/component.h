#pragma once
#include <string>
#include <typeinfo>



class component
{
protected:
	std::string componentName;
	component* childComponent;

public:
	component(component* c);
	virtual ~component();//component delete in destructor of gameObject

	template<typename t>
	t* casting();

};

template<typename t>
inline t* component::casting()
{
	return dynamic_cast<t*>(childComponent);
}
