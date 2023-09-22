#include "Game.h"

void Game::init() {
	std::cout << "start" << std::endl;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		//printf("Could not initialize SDL! (%s)\n", SDL_GetError());
		std::cout << "Could not initialize SDL! " + (std::string)SDL_GetError() << std::endl;
		running = false;
	}

	// Create window
	window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Data.SCREEN_WIDTH, Data.SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
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
}

void Game::render() {
	// Clear renderer
	SDL_SetRenderDrawColor(renderer, Data.backgroundColor.r, Data.backgroundColor.g, Data.backgroundColor.b, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	// Draw rect (red)
	SDL_Rect r = { 50, 50, 100, 100 };
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(renderer, &r);

	// Update screen
	SDL_RenderPresent(renderer);
}

void Game::event() {
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
	std::chrono::system_clock::time_point start;
	std::chrono::nanoseconds nano;
	while (running) 
	{
		start = std::chrono::system_clock::now();

		event();



		render();

		nano = std::chrono::system_clock::now() - start;
	}
}