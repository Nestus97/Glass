#include "lustro.h"
#include <cmath>

Lustro::Lustro(int xx,int yy):
    x(xx),y(yy)
{
    mirror_angle = 60;
    mirror_width = 50;
}

float Lustro::getSlope()
{
    if((mirror_angle==90)||(mirror_angle==270))
        return 100.0;
    else
    return -tan(mirror_angle);
}
