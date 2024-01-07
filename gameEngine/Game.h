#pragma once
#include <SDL2/SDL.h>
#include "global_Classes.h"
#include <iostream>
#include <string>
#include <chrono>
#include "loopsManager.h"
#include "ObjectsManager.h"

class Game
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;
	bool running;

	int screenTargetFps;

public:
	void init(int screenWidth,int screenHeight,int screenFps);
	void render();
	void events();
	void dest();
	void loop();
};

