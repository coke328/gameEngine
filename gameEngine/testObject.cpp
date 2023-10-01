#include "testObject.h"



testObject::testObject()
{
	setLoopFPS(1);//must do if you not do it fps will be 144
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

