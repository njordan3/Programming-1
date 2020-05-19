//Nicholas Jordan
//MID 3

#include <iostream>
#include <fstream>

using namespace std;

string save(string s1, string s2);

int main()
{
    string s1, s2;

    cout << "Enter a string: ";
    cin >> s1;

    cout << "Enter a string: ";
    cin >> s2;

    save(s1, s2);   

    return 0;
}


string save(string s1, string s2)
{
    string better;

    ofstream fout;

    fout.open("better.txt");

    if(fout.is_open())
    {
        better = s1 + " is better than " + s2;

        fout << better << endl;
        
        fout.close();
    }

    return better;
}
