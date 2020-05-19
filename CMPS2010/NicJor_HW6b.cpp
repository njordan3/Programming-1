#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void smallify(char before[], char after[]);

int main()
{   
    char before[20], after[30];

    cout << "Enter a string: ";
    cin.getline(before, 20);

    smallify(before, after);
    
    cout << after << endl;

    return 0;
}  


void smallify(char before[], char after[])
{
    int j = 0;
    int i = 0;
    int f = (strlen(before) - 2);

    if(before[f] == 'c' && before[f + 1] == 'o')
    {
        strncpy(after, before, strlen(before) - 2);

        strcat(after, "quito");
    }
    else if(before[f] == 'c' && before[f + 1] == 'a')
    {
        strncpy(after, before, strlen(before) - 2);
          
        strcat(after, "quita");
    }
    else if(before[f] != 'c' && (before[f + 1] != 'o' || before[f + 1] != 'a'))
    {
        strcpy(after, before);
    }
}

