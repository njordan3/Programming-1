#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void make_safe(char safetext[], char rawtext[]);

int main()
{
    char safetext[255];
    char rawtext[255];

    cout << "Enter a string: ";
    cin.getline(rawtext, 255);

    make_safe(safetext, rawtext);

    cout << "Safe version: " << safetext << endl;

    return 0;
}


void make_safe(char safetext[], char rawtext[])
{
    int i = 0;
    int j = 0;

    for(i; i <= strlen(rawtext); i++)
    {
        if(isalpha(rawtext[i]) || isdigit(rawtext[i]))
        {
            safetext[j] = rawtext[i];

            if(isupper(safetext[j]))
            {
                safetext[j] = tolower(safetext[j]);
            }

            j++;
        }
        else if(isspace(rawtext[i]) || ispunct(rawtext[i]))
        {
            safetext[j] = '-';

            while(isspace(rawtext[i + 1]) || ispunct(rawtext[i + 1]))
            {
                i++;
            }

            j++;
        }
        else if(i == strlen(rawtext))
        {
            safetext[j] = '\0';
            i = strlen(rawtext);
        }


    }

}
