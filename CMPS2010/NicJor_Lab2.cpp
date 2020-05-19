#include <iostream>

using namespace std;

int main()
{
    double cost;
    double total;
    int quantity;
    string item;
    char is_gift;

    cout << "Welcome to Walmart\n";
    cout << "What item are you buying today? ";
    cin >> item;

    cout << "Cost of " << item << "? ";
    cin >> cost;

    cout << "How many are you buying? ";
    cin >> quantity;

    cout << "Is this a gift (y/n)? ";
    cin >> is_gift;
    if (is_gift == 'y' || is_gift == 'Y')
    {   
        cout << "Thank you for your purchase. Please pay $" << quantity * cost << ".\n";
        cout << "Remember that gifts can be returned or exchanged with the gift receipt before 30 days.\n";
    }
    else
    {    
        cout << "Thank you for your purchase. Please pay $" << quantity * cost << ".\n";
    }   

    return 0;
}

