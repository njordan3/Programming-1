//Nicholas Jordan
//HW05
//MW

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

string create_password();

int main()
{
    int counter = 0;
    int repititions = 0;
    srand(time(NULL));

    string test_password = create_password();   // the variable is initialized as the password creating function

    for(repititions; repititions < 100000; repititions++)     // creates 100000 passwords and compares them to the original password
    {
        string comparison = create_password();

        if(comparison == test_password)     // counts how many times the original password is generated
        {
            counter++;
        }
    }

    cout << test_password << " was generated " << counter << " times out of " << repititions << " repititions.\n\n";

    return 0;
}

string create_password()
{
    string colors [6] = { "Puce", "Fuchsia", "Sarcoline", "Falu", "Wenge", "Sinopia" };
    string animals [8] = { "Zebu", "Ibex", "Kudu", "Lynx", "Fugu", "Tarsier", "Narwhal", "Okapi" };
    string numbers [9] = { "31", "41", "59", "26", "53", "863", "5309", "117" };
    string symbols [4] = { "!$", "$$", "~!~", "^#^" };
    
    int color_index = rand() % 6;
    int animal_index = rand() % 8;
    int number_index = rand() % 9;
    int symbol_index = rand() % 4;    


    return colors[color_index] + animals[animal_index] + numbers[number_index] + symbols[symbol_index];
}

