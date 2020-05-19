#include <iostream>

using namespace std;

class Calculator
{
    private:
        int value1, value2; //class properties
        
    public:
        void set_value1(int v) { value1 = v; } //setters
        void set_v2(int v) { value2 = v; } //name doesn't matter   
        
        double get_sum() //member function
        {
            return value1 + value2; //private variables can be seen by other class members
        }
        
        double get_prod()
        {
            return value1 * value2;
        }
        
        double get_diff();        
        
        double get_div();

        Calculator() { } //a default constructor is not needed until an overloaded constructor is introduced

        Calculator(int v1, int v2); //once an overloaded constructor is introduced, a default constructor must be placed       
};

double Calculator::get_diff()
{
    return value1 - value2;
}

double Calculator::get_div()
{
    return value1 / value2;
}

Calculator::Calculator(int v1, int v2)
{
    value1 = v1;
    value2 = v2;
}

int main()
{
    Calculator calc; //instatiate an object calc from Calculator
    Calculator calc2(50, 50); //instatiate an object calc2 from Calculator. Looks for the constructor with the parameters that match.
    //calc.value1 = 10; //can't access private variables from object scope   
    
    calc.set_value1(10);
    calc.set_v2(20);    

    cout << calc.get_sum() << endl;
    cout << calc.get_prod() << endl;
    cout << calc.get_diff() << endl;
    cout << calc.get_div() << endl;

    return 0;
}
