#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void translate(char human[], char dog[]);

int main()
{
    char human[100], dog[100];

    cout << "Enter a string: ";
    cin.getline(human, 100);

    translate(human, dog);

    return 0;
}


void translate(char human[100], char dog[100])
{
    int i = 0;
    int w = 0;
   
    cout << human << endl;    

    for(i; i < strlen(human); i++)
    {
        if(isspace(human[i]) || ispunct(human[i]))
        {
            dog[w] = human[i];      
        }
        else if(w == 0 || isspace(human[i - 1]))
        {
            dog[w] = 'w';

            if(isupper(human[i]))
                dog[w] = 'W';  
        }
        else if(w > 0 && w < strlen(human) - 1 && !isspace(human[i + 1]) && !ispunct(human[i + 1]))
        {
            dog[w] = 'o';
            
            if(isupper(human[i]))
                dog[w] = 'O';   
        }
        else if((w == strlen(human) - 1) || isspace(human[i + 1]) || ispunct(human[i + 1]))
        {
            dog[w] = 'f';
            if(isupper(human[i]))
            {
                dog[w] = 'F';
            }    
        }
        
        w++;

        if(w == strlen(human))
        {
            dog[w] = '\0';
            i = strlen(human);
        }
        
    }
    cout << dog << endl;

}


