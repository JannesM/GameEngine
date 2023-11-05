#ifndef COMMON_H
#define COMMON_H

#include <vector>

struct Vector3
{
	float x, y, z;
};

struct Matrix4
{
	float data[4][4]{ 0.0f };
};

struct Triangle
{
	Vector3 verts[3];
};

struct Mesh
{
	std::vector<Triangle> surfaces;
};

namespace Game {

	extern void MultiplyMatrixVector(Matrix4& m, Vector3& v, Vector3& out);

	extern void DrawTriangle(Triangle& tri);
}

#endif // !COMMON_H
