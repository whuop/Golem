#pragma once
#include <bx/math.h>

namespace Golem::Math
{
	struct Matrix4x4
	{
		float Data[16];

		Matrix4x4():
			Data{1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1}
		{}

		Matrix4x4(float data[16]):
			Data{data[0],data[1],data[2], data[3],
				data[4], data[5], data[6], data[7],
				data[8], data[9], data[10], data[11], 
				data[12], data[13], data[14], data[15]}
		{
		}
	};
}