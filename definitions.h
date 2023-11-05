#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800


#include "SDL.h"

struct SDLGlobals
{
	SDL_Renderer* renderer;
	SDL_Window* window;
};

namespace Game {

	extern SDLGlobals sdlGlobals;

}


#endif // !DEFINITIONS_H
