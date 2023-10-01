#include "testObject.h"



testObject::testObject()
{
	setLoopFPS(1);//must do if you not do it fps will be 144
	setName(this);//must do to use this as component
}

void testObject::Start()
{
	//setLoopFPS(LoopFPS);

	//std::cout << "Fps : " << LoopFPS << std::endl;
}

void testObject::Loop()
{
	std::cout << "tObjectLoop" << std::endl;
}

