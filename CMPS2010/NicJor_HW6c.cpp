#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void decode(char after[], char before[]);

int main()
{
    char before[50];
    char after[50];

    cout << "Enter a phone number: ";
    cin.getline(before, 50);

    decode(after, before);

    cout << before << " is actually " << after << endl;   

    return 0;
}


void decode(char after[], char before[])
{
    int i = 0;

    for(i; i <= strlen(before); i++)
    {
        if(isdigit(before[i]) || ispunct(before[i]))
        {
            after[i] = before[i];
        }
        else if(isalpha(before[i]))
        {
            switch(before[i])
            {
                case 'a' :
                case 'A' :
                case 'b' :
                case 'B' :
                case 'c' :
                case 'C' : after[i] = '2';
                           break;
                case 'd' :
                case 'D' :
                case 'e' :
                case 'E' :
                case 'f' :
                case 'F' : after[i] = '3';
                           break;
                case 'g' :
                case 'G' :
                case 'h' :
                case 'H' :
                case 'i' :
                case 'I' : after[i] = '4';
                           break;
                case 'j' :
                case 'J' :
                case 'k' :
                case 'K' :
                case 'l' :
                case 'L' : after[i] = '5';
                           break;
                case 'm' :
                case 'M' :
                case 'n' :
                case 'N' :
                case 'o' :
                case 'O' : after[i] = '6';
                           break;
                case 'p' :
                case 'P' :
                case 'q' :
                case 'Q' :
                case 'r' :
                case 'R' :
                case 's' :          
                case 'S' : after[i] = '7';
                           break;
                case 't' :
                case 'T' :
                case 'u' :
                case 'U' :
                case 'v' :
                case 'V' : after[i] = '8';
                           break;
                case 'w' :
                case 'W' :
                case 'x' :
                case 'X' :
                case 'y' :
                case 'Y' :
                case 'z' :          
                case 'Z' : after[i] = '9';
                           break;
            }
        }
        else if(i == strlen(before))
        {
            after[i] = '\0';
            i = strlen(before);
        }
    }
}

