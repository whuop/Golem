#pragma once

namespace Golem::Math
{
	template<class T>
	struct Vector3
	{
    public:
        T X;
        T Y;
        T Z;

		Vector3() : X(0), Y(0), Z(0) {}

		Vector3(T x, T y, T z) : X(x), Y(y), Z(z)
		{

		}
	};
    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;
    typedef Vector3<double> Vector3d;
}

