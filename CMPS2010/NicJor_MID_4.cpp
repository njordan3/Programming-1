//Nicholas Jordan
//MID 4

#include <iostream>

using namespace std;

string get_battery_status(int level);

int main()
{
    int battery_level;

    cout << "Enter a number: ";
    cin >> battery_level;

    cout << get_battery_status(battery_level);

    return 0;
}


string get_battery_status(int level)
{
    string response;

    if(level == 100)
    {
        response = "Fully Charged\n";
    }
    else if(level == 0)
    {
        response = " \n";
    }
    else if(level <= 2)
    {
        response = "Critical\n";
    }
    else if(level <= 15)
    {
        response = "Low\n";
    }
    else
    {
        response = "Discharging\n";
    }


    return response;
}
