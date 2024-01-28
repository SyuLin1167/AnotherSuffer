#include "Math.h"

namespace math
{
    bool operator==(const VECTOR& lhs, const VECTOR& rhs)
    {
        if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
        {
            return true;
        }
        return false;
    }

    VECTOR operator*=(const VECTOR& lhs, const VECTOR& rhs)
    {
        VECTOR vec{};
        vec.x = lhs.x * rhs.x;
        vec.y = lhs.y * rhs.y;
        vec.z = lhs.z * rhs.z;
        return vec;
    }
};

