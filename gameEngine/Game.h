#pragma once
#include "SDL.h"
#include "global_Classes.h"
#include <iostream>
#include <string>
#include <chrono>
#include "loopsManager.h"

class Game
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;
	bool running;

public:
	void init();
	void render();
	void event();
	void dest();
	void loop();
};

