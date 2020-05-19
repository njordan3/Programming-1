#include <iostream>
#include <fstream>

using namespace std;

int read_airports(string cities[], int threshold);

int main()
{
    string cities[20];
    int count, threshold, i = 0;
    
    cout << "Enter a threshold number: ";
    cin >> threshold;

    count = read_airports(cities, threshold);

    cout << "The following airports have at least " << threshold << " terminals:\n";
    
    for(i; i < count; i++)
    {
        cout << cities[i] << endl;
    }

    return 0;
}


int read_airports(string cities[], int threshold)
{
    int terminals;
    string abbrev;   
    int i = 0;
    string city;

    ifstream fin;

    fin.open("airports.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            fin >> abbrev >> city >> terminals;

            if(fin.good())
            {
                if(threshold <= terminals)
                {
                    cities[i] = city;
                    i++;              
                }                 
            }            
        }

        fin.close();
    }

    return i;
}
