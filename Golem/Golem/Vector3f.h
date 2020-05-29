#pragma once

namespace Golem::Math
{
	struct Vector3f
	{
	public:
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

		float X;
		float Y;
		float Z;
	};
}



