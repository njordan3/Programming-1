#include "areas.h"

Areas::Areas(double l, double h, double r)
{
    length = l;
    height = h;
    radius = r;   
}
double Areas::area_square()
{
    return length * height;
}
double Areas::area_circle()
{
    return 3.14159 * radius * radius; 
}
double Areas::area_triangle()
{
    return 0.5 * length * height;
}
