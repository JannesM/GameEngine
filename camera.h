#ifndef CAMERA_H
#define	CAMERA_H

#include "common.h"
#include "game_object.h"

namespace Game {

	class Camera {

	public:

		Camera(float far, float near, float fov);

		void UpdateProjectionMatrix(float far, float near, float fov);
		void RotationMatrixX(float theta, Matrix4& out);
		void RotationMatrixY(float theta, Matrix4& out);
		void RotationMatrixZ(float theta, Matrix4& out);

		void RenderObject(GameObject& object);

	private:
		Matrix4 projectionMatrix;

	};


}


#endif // !CAMERA_H
