#include "camera.h"
#include "definitions.h"

#include "SDL.h"

#include <math.h>

namespace Game {

	Camera::Camera(float far, float near, float fov)
	{
		UpdateProjectionMatrix(far, near, fov);
	}

	void Camera::UpdateProjectionMatrix(float far, float near, float fov)
	{
		int w, h;
		SDL_GetWindowSize(sdlGlobals.window, &w, &h);

		float aspectRatio, fovRad;
		aspectRatio = (float)h / (float)w;
		fovRad = 1.0f / tanf(fov * 0.5f / 180.0f * 3.14159f);

		//					  x  y
		projectionMatrix.data[0][0] = aspectRatio * fovRad;
		projectionMatrix.data[1][1] = fovRad;
		projectionMatrix.data[2][2] = far / (far - near);
		projectionMatrix.data[3][2] = (-far * near) / (far - near);
		projectionMatrix.data[2][3] = 1.0f;
		projectionMatrix.data[3][3] = 0.0f;

	}

	void Camera::RotationMatrixX(float theta, Matrix4& out)
	{
		out.data[0][0] = 1.0f;
		out.data[1][1] = cosf(theta);
		out.data[1][2] = sinf(theta);
		out.data[2][1] = -sinf(theta);
		out.data[2][2] = cosf(theta);
		out.data[3][3] = 1.0f;
	}

	void Camera::RenderObject(GameObject& object)
	{
		Matrix4 rotationX, rotationY, rotationZ;

		RotationMatrixX(object.rotation.x, rotationX);


		for (Triangle tri : object.mesh.surfaces)
		{
			Triangle translated{}, projected{};

			for (int i = 0; i < 3; i++)
			{
				float PI_half = 3.1415f / 2;

				MultiplyMatrixVector(rotationX, tri.verts[i], translated.verts[i]);

				translated.verts[i].x += tri.verts[i].x + object.position.x;
				translated.verts[i].y += tri.verts[i].y + object.position.y;
				translated.verts[i].z += tri.verts[i].z + object.position.z;

				MultiplyMatrixVector(projectionMatrix, translated.verts[i], projected.verts[i]);

				projected.verts[i].x += 1.0f;
				projected.verts[i].y += 1.0f;

				projected.verts[i].x *= 0.5f * (float)SCREEN_WIDTH;
				projected.verts[i].y *= 0.5f * (float)SCREEN_HEIGHT;
			}

			DrawTriangle(projected);
		}
	}
}