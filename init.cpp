#include "init.h"
#include "definitions.h"

#include "SDL.h"
#include <stdio.h>

namespace Game {

	// shared variable
	SDLGlobals sdlGlobals;

	void InitSDL() {

		int renderFlags, windowFlags;

		renderFlags = SDL_RENDERER_ACCELERATED;
		windowFlags = 0;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("Couldn't initialize SDL: %s\n", SDL_GetError());
			exit(1);
		}

		sdlGlobals.window = SDL_CreateWindow("Chess SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

		if (!sdlGlobals.window)
		{
			printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
			exit(1);
		}

		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

		sdlGlobals.renderer = SDL_CreateRenderer(sdlGlobals.window, -1, renderFlags);

		if (!sdlGlobals.renderer)
		{
			printf("Failed to create renderer: %s\n", SDL_GetError());
			exit(1);
		}

	}

	void Cleanup()
	{
		SDL_DestroyRenderer(sdlGlobals.renderer);
		SDL_DestroyWindow(sdlGlobals.window);

		printf("Destroyed renderer and window!\n");
	}

}