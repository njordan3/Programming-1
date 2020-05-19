#include <iostream>

using namespace std;

void say_hello();   // prototypes
void say_something(string);
int get_pos_num();
int prod(int num1, int num2);
void show_date(int month, int day, int year, int format);

int main()
{
    say_hello();    //calls
    say_something("C++");
    
    int num1, num2;
    cout << "Enter num1: ";
    num1 = get_pos_num();

    cout << "Enter num2: ";
    num2 = get_pos_num();

    cout << "Product: " << prod(num1, num2) << endl;
    
    show_date(12,25,2017, 1);   // shows mm/dd/yyyy
    show_date(12,25,2017, 2);   // shows dd/mm/yyyy
    show_date(12,25,2017, 3);   // shows yyyy/mm/dd
    show_date(12,25,2017, 4);
    return 0;
}

void say_hello()    // definitions
{
    cout << "Hello, world\n";
}

void say_something(string something)
{
    cout << something << endl;

}

int get_pos_num()
{
    int num;
    do
    {
        cin >> num;
    } while (num < 0);

    return num;
}

int prod(int num1, int num2)
{
    return num1 * num2;
}

void show_date(int m, int d, int y, int format)
{
    if (format == 1)
    {
        cout << m << "/" << d << "/" << y << endl;
    }

    if (format == 2)
    {
        cout << d << "/" << m << "/" << y << endl;
    }

    if (format == 3)
    {
        cout << y << "/" << m << "/" <<  d << endl;
    }

    if (format == 4)
    {
        if (m == 1)
            cout << "Jan ";
        else if (m == 2)
            cout << "Feb ";
        else
        cout << "Dec "; 
        cout << d << ", " << y << endl;
    }
}


