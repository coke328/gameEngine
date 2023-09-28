#include "component.h"

component::component(component* c)
{
	componentName = typeid(c).name();
	childComponent = c;
}

component::~component()
{
}
