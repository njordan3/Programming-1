#ifndef AREAS_H
#define AREAS_H

class Areas
{
    private:
        double length, height, radius;
    public:
        Areas(double l, double h, double r);
        double area_square();
        double area_circle();
        double area_triangle();

};

#endif
