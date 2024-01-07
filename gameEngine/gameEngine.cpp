#define SDL_MAIN_HANDLED

#include <iostream>
#include "Game.h"


int main(int argc, char* argv[])
{

	Game game;

	game.init(800,600,144);
	//-------------------------make objects--------------
	testObject* to = new testObject();



	//---------------------------
	game.loop();

	game.dest();

	return 0;
}