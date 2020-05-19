#include <iostream>

using namespace std;

int main()
{
    string input;
    int repititions;
    int ones = 1;
    int tens = 100;
    int number = 1;
    string input2;
   
   
    cout << "Enter a string to be repeated: ";
    cin >> input;
    
    cout << "How many times to show? ";
    cin >> repititions;

    while (repititions > 0)
    {
        cout << input << " " << endl;
        repititions = repititions - 1;
    }

cout << endl;

while (ones < 21)
{
    cout << ones << " ";
    ones = ones + 1;
    
    if (ones == 21)
    {
        cout << endl;
    
    }
}

cout << endl;

while (tens % 10 == 0)
{
    cout << tens << "   ";
    tens = tens - 10;

    if (tens < 10)
        tens = tens + 1;
}

cout << endl;
cout << endl;

while (number > 0)
{
    cout << "Enter a number: ";
    cin >> number;
   
    if (number > 0)
    {
        cout << number * 2 << endl;
    }
}

while (input2 != "bye")
{
    cout << "Enter a string: ";
    cin >> input2;
}
    return 0;
}

