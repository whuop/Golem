#pragma once

namespace Golem::Math
{
	struct Vector4f
	{
	public:
		float X;
		float Y;
		float Z;
		float W;

		Vector4f():
			X(0),
			Y(0),
			Z(0),
			W(0)
		{
		}

		Vector4f(float x, float y, float z, float w):
			X(x),
			Y(y),
			Z(z),
			W(w)
		{}

		
	};
}


