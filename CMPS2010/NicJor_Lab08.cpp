//Nicholas Jordan
//Lab08
//HW

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void parse_name(char full[], char first[], char last[]);
void create_timecard(double hours[], char first[], char last[]);

int main()
{
    char full[40], first[20], last[20];
    double hours[5];
    int day = 1;

    cout << "Enter your full name: ";
    cin.getline(full, 40);

    parse_name(full, first, last);

    for(day; day < 6; day++)
    {
        cout << "Enter hours for day " << day << ": ";
        cin >> hours[day];
    }

    create_timecard(hours, first, last);

    return 0;
}


void parse_name(char full[], char first[], char last[])
{
    int f = 0;
    int i = 0;
    int l = 0;

    for(i; i <= strlen(full); i++)
    {
        if(isspace(full[i]))
        {
            first[f] = '\0';
            i = strlen(full);
        }
        else
        {
            first[f] = full[i];
            f++;
        }    
    }

    
    i = f;

    for(i; i < strlen(full); i++)
    {   
        if(isspace(full[i]))
        {
            last[f] = '\0';
            i = f;
        }
        else if(isalpha(full[i]))
        {       
            last[l] = full[i];
            l++;
        }    
    }



}

void create_timecard(double hours[], char first[], char last[])
{
    double sum = 0;

    ofstream fout;
    fout.open("timecard.txt");

    fout << "First Name: " << first << endl;
    fout << "Last Name: " << last << endl;

    for(int day = 1; day < 6; day++)
    {
        fout << "Day " << day << " : " << hours[day] << endl;
        sum = sum + hours[day];
    }

    fout << "Total: " << sum;

}
