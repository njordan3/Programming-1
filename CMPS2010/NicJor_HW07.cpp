//Nicholas Jordan
//HW07
//MW

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

bool is_word_valid(string word);
int get_uses(string word);
void save_uses(string word, int count);


int main()
{
    string word;
    int uses;

    do
    {
        cout << "Play a word: ";
        cin >> word;

        if(is_word_valid(word))
        {
            uses = get_uses(word);
            uses++;

            cout << "You've played " << word << " " << uses << " times\n";

            save_uses(word, uses);
        }
        else
        {
            if(word == "+")
            {
                cout << "Thank you for playing!\n";
            }
            else
            {
                cout << "That is not a valid word\n";
            }
        }

    }while(word != "+");

    return 0;
}


bool is_word_valid(string word)
{
    bool result = false;
    string line;

    ifstream fin;

    fin.open("enable1.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            getline(fin, line);

            if(fin.good() && line == word)
            {
                result = true;
            }
        }       

        fin.close();
    }

    return result;
}


int get_uses(string word)
{
    int uses;
 
    ifstream fin;

    fin.open((word + ".uses").c_str());

    if(fin.is_open())
    {
        fin >> uses;

        fin.close();
    }
    else
    {
        uses = 0;
    }

    return uses;
}
void save_uses(string word, int count)
{
    ofstream fout;

    fout.open((word + ".uses").c_str());

    if(fout.is_open())
    {
        fout << count << endl;

        fout.close();
    }
}
