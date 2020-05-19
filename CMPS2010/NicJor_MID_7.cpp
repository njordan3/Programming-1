//Nicholas Jordan
//MID 7

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

int count_chars(char filename[], char c);

int main()
{
    char filename[100];
    char c;
    int hashtags, semi;


    cout << "Enter the name of a text file: ";
    cin.getline(filename, 100);

    hashtags = count_chars(filename, '#');   
    semi = count_chars(filename, ';');

    cout << filename << " contains " << hashtags << " hashtags and " << semi << " semicolons.\n";

    return 0;
}


int count_chars(char filename[], char c)
{
    int count = 0;    
    char correct;

    ifstream fin;
    fin.open(filename);

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            correct = fin.get();

            if(fin.good() && correct == c)
            {
                count++;
            }

        }

        fin.close();
    }


    return count;
}
