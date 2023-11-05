#include "common.h"
#include "definitions.h"

#include "SDL.h"

namespace Game {

	void MultiplyMatrixVector(Matrix4& mat, Vector3& v, Vector3& out)
	{
		out.x = v.x * mat.data[0][0] + v.y * mat.data[1][0] + v.z * mat.data[2][0] + mat.data[3][0];
		out.y = v.x * mat.data[0][1] + v.y * mat.data[1][1] + v.z * mat.data[2][1] + mat.data[3][1];
		out.z = v.x * mat.data[0][2] + v.y * mat.data[1][2] + v.z * mat.data[2][2] + mat.data[3][2];

		float w = v.x * mat.data[0][3] + v.y * mat.data[1][3] + v.z * mat.data[2][3] + mat.data[3][3];

		if (w != 0.0f)
		{
			out.x /= w;
			out.y /= w;
			out.z /= w;
		}
	}


	void DrawTriangle(Triangle& tri)
	{
		SDL_RenderDrawLineF(sdlGlobals.renderer, tri.verts[0].x, tri.verts[0].y, tri.verts[1].x, tri.verts[1].y);
		SDL_RenderDrawLineF(sdlGlobals.renderer, tri.verts[1].x, tri.verts[1].y, tri.verts[2].x, tri.verts[2].y);
		SDL_RenderDrawLineF(sdlGlobals.renderer, tri.verts[2].x, tri.verts[2].y, tri.verts[0].x, tri.verts[0].y);
	}
}