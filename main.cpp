#include "init.h"
#include "scene.h"
#include "game_object.h"

#include <stdlib.h>
#include <time.h>

using namespace Game;

constexpr int MS_PER_UPDATE = 100;

int main(int argc, char* argv[])
{

	// setup SDL
	InitSDL();
	atexit(Cleanup);

	// setup scene
	Scene scene(1000.0f, 0.1f, 90.0f);

	GameObject cube = GameObject();
	scene.Add(&cube);

	cube.LoadDefaultCube();
	cube.position.z = 3.0f;

	time_t previous = time(NULL);
	time_t lag = 0;

	while (true)
	{
		time_t current = time(NULL);
		time_t elapsed = current - previous;
		previous = current;
		lag += elapsed;

		scene.HandleInput();

		while (lag >= MS_PER_UPDATE)
		{
			scene.Update(elapsed);
			lag -= MS_PER_UPDATE;
		}

		scene.Render();
	}


	return 0;
}