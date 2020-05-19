#include <iostream>
#include "areas.h"

int main()
{
    Areas a(3,5,9);

    std::cout << "Area of a square: " << a.area_square() << std::endl; 
    std::cout << "Area of a circle: " << a.area_circle() << std::endl;
    std::cout << "Area of a triangle: " << a.area_triangle() << std::endl;
    
    return 0;
}
