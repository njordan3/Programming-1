//Nicholas Jordan
//Oct 11, 2017
//Lab07

#include <iostream>

using namespace std;

string get_date(int day);

int main()
{
    int day;

    cout << "Enter the nth day of the year: ";
    cin >> day;

    cout << "Day " << day << " is " << get_date(day) << endl;

    return 0;
}

string get_date(int day)
{
    int i = 0;
    int month = 0;
    string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    while(day - days[i] >= 0 && i < 12)
    {
        if(day - days[i] < 0)
        {
            day = days[i] - day;
            i++;
            month = i;
        }
        else if(day - days[i] > 0)
        {
            day = day - days[i];
            i++;
            month = i;
        }
        else if(day - days[i] == 0)
        {
            day = day; 
            month = i;
            i = month;
            i++;
        }
    }
    
    

    return months[month] + " " + to_string(day);
}

