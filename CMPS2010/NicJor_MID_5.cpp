//Nicholas Jordan
//MID 5

#include <iostream>
#include <cstring>

using namespace std;

void show_mangled(char original[]);
bool isvowel(char c);

int main()
{
    char original[200];

    cout << "Enter a sentence: ";
    cin.getline(original, 200);

    show_mangled(original);

    return 0;
}


void show_mangled(char original[])
{
    

    for(int i = strlen(original); i > 0; i--)
    {
        if(!isvowel(original[i]))
        {
            cout << original[i];
            
        } 

                 
    }
    for(int j = 0; j < strlen(original); j++)
    {
        if(isvowel(original[j]))
        {
            cout << original[j];  
                      
        }

       
    }

    cout << endl;    

}

bool isvowel(char c)
{
    c = toupper(c);

    return (c == 'A' || c =='E' || c == 'I' || c == 'O' || c == 'U');
}
