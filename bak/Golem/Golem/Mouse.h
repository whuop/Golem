#pragma once
#include <Math/Vector2i.h>

namespace Golem::Input
{
	using namespace Math;
	class Mouse
	{
	public:
		Vector2i Position;
		bool LeftButton;
		bool RightButton;
		bool MiddleButton;

		Mouse():
		Position(0, 0),
		LeftButton(false),
		RightButton(false),
		MiddleButton(false)
		{
		}
	};
}


