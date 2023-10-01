#include "testObject2.h"

testObject2::testObject2()
{
	setLoopFPS(1);//must do if you not do it fps will be 144
	setName(this);//must do to use this as component
}

void testObject2::Start()
{
	std::cout << "tObject2Start" << std::endl;
}

void testObject2::Loop()
{
	std::cout << "tObject2Loop" << std::endl;
}
