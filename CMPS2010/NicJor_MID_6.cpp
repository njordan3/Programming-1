//Nicholas Jordan
//MID 6

#include <iostream>

using namespace std;

void show_episodes(int episodes[]);

int main()
{
    int episodes[10] = { 8, 6, 13, 16, 16, 16, 16, 16, 2, 0 };

    show_episodes(episodes);

    return 0;
}


void show_episodes(int episodes[])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 1; j <= episodes[i] && i != 0; j++)
        {
            cout << "S" << i << "E" << j;
            if(j < episodes[i])
            {
                cout << ", ";
            } 
        }

        cout << endl;      
    }

}
