#pragma once

namespace Golem::Math
{
    template <class T>
    struct Vector2
    {
        T X;
        T Y;

        Vector2() : X(0), Y(0) {}

        Vector2(T x, T y) : X(x), Y(y) {}
    };

    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;
}


