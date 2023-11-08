#include "Math.h"

bool operator==(const VECTOR& lhs, const VECTOR& rhs)
{
    if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
    {
        return true;
    }
    return false;
}