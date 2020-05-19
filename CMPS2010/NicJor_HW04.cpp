//Nicholas Jordan
//10-12-2017
//HW04

#include <iostream>

using namespace std;

string show_ordinal(int num);
void show_verse(int num);

int main()
{   
    for (int day = 1; day <= 12; day++)     // counts the days of christmas starting at day 1
    {
        cout << "On the " << day << show_ordinal(day) << " day of Christmas,\nMy true love gave to me,\n"; // shows the starting lyrics and the ordinal 
        
        show_verse(day);    // shows the verse for a specific day
    }

    return 0;
}


string show_ordinal(int day)    // decides the ordinal suffix for a day's number
{
    string ord;
    
    if (day == 1 || day == 2 || day == 3)
    {
        switch(day)
        {
            case 1:
                ord = "st";
                break;
            case 2:
                ord = "nd";
                break;
            case 3:
                ord = "rd";
                break;
        }
    }
    else
    {
        ord = "th";
    }

    return ord;
}
void show_verse(int day)    // displays the verse according to what day it is
{
    if (day == 1)       // makes sure that the first day does not include "and"
    {
        cout << "A partridge in a pear tree.\n\n";
    }

    for (day; day > 1; day--)
    {   
        switch(day)
        {
            case 2:
                cout << "2 turtle doves,\nAnd a partridge in a pear tree.\n\n";
                break;
            case 3:
                cout << "3 french hens,\n";
                break;
            case 4:
                cout << "4 colly birds,\n";
                break;
            case 5:
                cout << "5 golden rings,\n";
                break;
            case 6:
                cout << "6 geese-a-laying,\n";
                break;
            case 7:
                cout << "7 swans-a-swimming,\n";
                break;
            case 8:
                cout << "8 maids-a-milking,\n";
                break;
            case 9:
                cout << "9 ladies dancing,\n";
                break;
            case 10:
                cout << "10 lords-a-leaping,\n";
                break;
            case 11:
                cout << "11 pipers piping,\n";
                break;
            case 12:
                cout << "12 drummers drumming,\n";
                break;
        }          
    }
}

