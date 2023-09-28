#pragma once
#include <string>
#include <typeinfo>

enum componentType
{

};

class component
{
protected:
	std::string componentName;
	component* childComponent;

public:
	component(component* c);
	virtual ~component();

	template<typename t>
	t* casting();

};

template<typename t>
inline t* component::casting()
{
	return static_cast<t*>(childComponent);
}
