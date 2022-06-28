#include "../../includes/includes.h"

float to_rad(float deg)
{
    return ((PI /180) * deg);
}

float dcos(float deg)
{
    return cos(to_rad(deg));
}

float dsin(float deg)
{
    return sin(to_rad(deg));
}