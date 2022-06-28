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

double dist_points(sfVector2f pa, sfVector2f pb)
{
    return sqrt(((pb.x - pa.x) * (pb.x - pa.x)) + ((pb.y - pa.y) * (pb.y - pa.y)));
}