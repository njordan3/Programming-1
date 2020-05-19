//Nicholas Jordan
//MID 2

#include <iostream>

using namespace std;

int mult(int a, int b);

int main()
{
    int a = 4;
    int b = 3; 

    cout << mult(a, b) << endl;  

    return 0;
}


int mult(int a, int b)
{
    int i = 1;
    int j = 0;

    while(i <= a)
    {
        j = j + b;

        i++;
    }

    return j;
}
