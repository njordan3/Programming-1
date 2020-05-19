#include <iostream>
#include <cmath>

using namespace std;

double get_float(string prompt);
double sroot(double);
double calc_hypotenuse(double, double);
double calc_perimeter(double, double);
double calc_area(double, double);

int main()
{
    double side1, side2;
    double perimeter, area;

    side1 = get_float("Enter the length of one side ");
    side2 = get_float("Enter the length of the adjacent side ");

    perimeter = calc_perimeter(side1, side2);
    area = calc_area(side1, side2);

    cout << "A right triangle with sides " << side1 << " and ";
    cout << side2 << " has a perimeter of " << perimeter << " and an area of " << area; 
    cout << ". The length of the third side is " << calc_hypotenuse(side1, side2) << endl;

    

    return 0;
}
double get_float(string prompt)
{
    double number;
    
    do
    {
        cout << prompt;
        cin >> number;

    } while (number < 0);
    
    return number;
    
}

double sroot(double a)
{
    double sqrt;
    sqrt = pow(a, 0.5);

    return sqrt;
}

double calc_hypotenuse(double side1, double side2)
{
    double hyp;

    hyp = sroot(pow(side1, 2.0) + pow(side2, 2.0));
            
    return hyp;
}
double calc_perimeter(double side1, double side2)
{
    
    double per = side1 + side2 + calc_hypotenuse(side1, side2);


    return per;
}
double calc_area(double side1, double side2)
{
    double a = 0.5 * side1 * side2;
    return a;
}
