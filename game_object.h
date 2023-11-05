#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "common.h"

#include <vector>
#include <string>
#include <time.h>

namespace Game {

	class GameObject {

	public:
		GameObject() {};

		Mesh mesh;
		void LoadMesh();
		void LoadDefaultCube();

		Vector3 position{ 0.0f, 0.0f, 0.0f };
		Vector3 rotation{ 0.0f, 0.0f, 0.0f };

		void AddTag(std::string tag);
		bool HasTag(std::string tag);
		void RemoveTag(std::string tag);

		virtual void Update(time_t elapsed) {};

	private:
		std::vector<std::string> tags;

	};


}

#endif // !GAME_OBJECT_H
