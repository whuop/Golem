#pragma once

namespace Golem::Math
{
	struct Vector2f
	{
		float X;
		float Y;

		Vector2f():
			X(0),
			Y(0)
		{}

		Vector2f(float x, float y) :
			X(x),
			Y(y) 
		{}
	};
}