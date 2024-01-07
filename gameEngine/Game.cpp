#include "Game.h"

void Game::init(int screenWidth, int screenHeight,int fps) {
	std::cout << "start" << std::endl;

	screenTargetFps = fps;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		//printf("Could not initialize SDL! (%s)\n", SDL_GetError());
		std::cout << "Could not initialize SDL! " + (std::string)SDL_GetError() << std::endl;
		running = false;
	}

	// Create window
	window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	if (window == NULL) {
		//printf("Could not create window! (%s)\n", SDL_GetError());
		std::cout << "Could not initialize window! " + (std::string)SDL_GetError() << std::endl;
		running = false;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	if (renderer == NULL) {
		//printf("Could not create renderer! (%s)\n", SDL_GetError());
		std::cout << "Could not create renderer! " + (std::string)SDL_GetError() << std::endl;
		running = false;
	}

	ObjectsManager::getInstance();//create ObjectManager , start 

	loopsManager::getInstance().init(fps);//loop clock set to now,start function call
	ThreadLoopsManager::getInstance().init(fps);
}

void Game::render() {
	// Clear renderer
	SDL_SetRenderDrawColor(renderer, g_Data.backgroundColor.r, g_Data.backgroundColor.g, g_Data.backgroundColor.b, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	// Draw rect (red)
	SDL_Rect r = { 50, 50, 100, 100 };
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(renderer, &r);

	// Update screen
	SDL_RenderPresent(renderer);
}

void Game::events() {
	while(SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			running = false;
			break;
		}
	}
}

void Game::dest(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "end" << std::endl;
}

void Game::loop() {
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	std::chrono::nanoseconds deltaT;
	while (running) 
	{
		
		events();

		loopsManager::getInstance().update();

		deltaT = std::chrono::system_clock::now() - start;
		if (deltaT.count() > Math::FpsToNanoSec(screenTargetFps)) {

			
			render();

			//std::cout << "render dt : " << Math::NanoSecToSec(deltaT.count()) << std::endl;

			start = std::chrono::system_clock::now();
		}
			
	}
}