#include "includes/include_engine.h"

sfVector2i define_vectori(int x, int y)
{
    sfVector2i vec;

    vec.x = x;
    vec.y = y;
    return vec;
}

sfVector2f define_vectorf(float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return vec;
}

sfVector3f define_vectortf(float x, float y, float z)
{
    sfVector3f vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}