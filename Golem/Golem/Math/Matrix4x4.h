#pragma once
#include <bx/math.h>
#include "bgfx/bgfx.h"
#include "Math/Vector3f.h"

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

		void SetToIdentity()
		{
			bx::mtxIdentity(Data);
		}

		void LookAt(const Vector3f& eye, const Vector3f& lookAt)
		{
			bx::mtxLookAt(Data, eye, lookAt);
		}

		void Projection(float fovY, float aspect, float nearPlane, float farPlane)
		{
			bx::mtxProj(Data, fovY, aspect, nearPlane, farPlane, bgfx::getCaps()->homogeneousDepth);
		}

		void Translate(float x, float y, float z)
		{
			bx::mtxTranslate(Data, x, y, z);
		}

		void Scale(float scale)
		{
			bx::mtxScale(Data, scale);
		}

		void Scale(float x, float y, float z)
		{
			bx::mtxScale(Data, x, y, z);
		}

		void RotateX(float x)
		{
			bx::mtxRotateX(Data, x);
		}

		void RotateY(float y)
		{
			bx::mtxRotateY(Data, y);
		}

		void RotateZ(float z)
		{
			bx::mtxRotateZ(Data, z);
		}

		void RotateXYZ(float x, float y, float z)
		{
			bx::mtxRotateXYZ(Data, x, y, z);
		}
		
		void RotateXY(float x, float y)
		{
			bx::mtxRotateXY(Data, x, y);
		}
	};
}