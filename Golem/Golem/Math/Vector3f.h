#pragma once
#include "bx/math.h"

namespace Golem::Math
{
	struct Vector3f
	{
	public:
		float X;
		float Y;
		float Z;

		Vector3f():
			X(0),
			Y(0),
			Z(0)
		{}

		Vector3f(float x, float y, float z):
			X(x),
			Y(y),
			Z(z)
		{}

		operator bx::Vec3() const {
			return bx::Vec3(X, Y, Z);
		}

	};
}



