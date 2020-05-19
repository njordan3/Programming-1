//Nicholas Jordan
//MID 8

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    char phrase[100];
    char abbrev[100];

    int j = 0;

    cout << "Enter a phrase: ";
    cin.getline(phrase, 100);

    for(int i = 0; i < strlen(phrase); i++)
    {
        if(i == 0)
        {
            abbrev[j] = phrase[i];
            abbrev[j] = toupper(abbrev[j]);
            j++;
        }    
        else if(isspace(phrase[i - 1]))
        {
            abbrev[j] = phrase[i];
            abbrev[j] = toupper(abbrev[j]);
            j++;
        }
        
    }

    cout << abbrev << endl;


    return 0;
}
