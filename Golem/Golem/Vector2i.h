#pragma once

namespace Golem::Math
{
	struct Vector2i
	{
		int X;
		int Y;

		Vector2i() :
			X(0),
			Y(0)
		{}

		Vector2i(int x, int y):
			X(x),
			Y(y)
		{}
	};
}