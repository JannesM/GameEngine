#ifndef SCENE_H
#define SCENE_H

#include "game_object.h"
#include "common.h"
#include "camera.h"

#include <vector>
#include <time.h>

namespace Game {

	class Scene
	{
	public:
		Scene(float far, float near, float fov) : camera(far, near, fov) {}

		void HandleInput();
		void Update(time_t elapsed);
		void Render();
		
		void Add(GameObject* object);
		void Remove(GameObject* object);


	private:
		Camera camera;
		std::vector<GameObject*> objects;
	};


}


#endif // !SCENE_H
