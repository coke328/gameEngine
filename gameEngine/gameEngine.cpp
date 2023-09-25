#include <iostream>
#include "SDL.h"

#include "Game.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")


int SDL_main(int argc, char* argv[])
{

	Game game;

	game.init();

	game.loop();

	game.dest();

	return 0;
}