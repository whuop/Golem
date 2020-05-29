#pragma once

namespace Golem::Graphics
{
	struct Color
	{
	public:
		Color() :
			R(1.0f),
			G(1.0f),
			B(1.0f),
			A(1.0f)
		{
		}

		Color(float r, float g, float b, float a) :
			R(r),
			G(g),
			B(b),
			A(a)
		{
		}

		float R;
		float G;
		float B;
		float A;
	};
}


