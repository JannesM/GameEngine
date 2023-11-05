#include "scene.h"
#include "definitions.h"

#include "SDL.h"

namespace Game {

	void Scene::HandleInput()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				printf("Received termination signal...\n");
				exit(0);

				break;
			default:
				break;
			}
		}
	}

	void Scene::Update(time_t elapsed)
	{
		// update game state here
		for (GameObject* obj : objects)
		{
			obj->Update(elapsed);
		}
	}

	void Scene::Render()
	{
		// paint background white
		SDL_SetRenderDrawColor(sdlGlobals.renderer, 255, 255, 255, 255);
		SDL_RenderClear(sdlGlobals.renderer);

		// paint everything else black
		SDL_SetRenderDrawColor(sdlGlobals.renderer, 0, 0, 0, 255);

		// do frame computation here
		for (GameObject* obj : objects)
		{
			camera.RenderObject(*obj);
		}

		SDL_RenderPresent(sdlGlobals.renderer);

	}

	void Scene::Add(GameObject* object)
	{
		objects.push_back(object);
		printf("Added object %p to scene\n", object);
	}

	void Scene::Remove(GameObject* object)
	{
		auto it = std::find(objects.begin(), objects.end(), object);

		if (it != objects.end())
		{
			int index = it - objects.end();
			objects.erase(objects.begin() + index);
		}

		printf("Removed object %p from scene\n", object);
	}
}