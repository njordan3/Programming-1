//Nicholas Jordan
//Lab11
//MW

#include <iostream>

using namespace std;

void fill(int * array, int start, int end);
int sum(int * array);
int gauss_sum(int * fw, int * bw);

int main()
{
    int forward[100], backward[100];
    int total, gauss_total;    

    fill(forward, 1, 100);
    fill(backward, 100, 1);

    total = sum(forward);

    cout << total << endl;

    gauss_total = gauss_sum(forward, backward);

    cout << gauss_total << endl;

    cout << "Gauss was ";
    cout << ((total == gauss_total) ? "right" : "wrong" ) << endl;

    return 0;
}


void fill(int * array, int start, int end)
{
    if(start > end)
    {
        for(int i = 99; i >= 0; i--)
        {
            *(array + i) = start;
            start--;
        }

    }
    else if(start < end)
    {
        for(int j = 0; j <= 99; j++)
        {
            *(array + j) = start;
            start++;
        }

    }

}   

int sum(int * array)
{
    int value = 0;

    for(int i = 0; i < 100; i++)
    {
        value = value + (*(array + i));        
    }      

    return value;
}


int gauss_sum(int * fw, int * bw)
{
    int value = 0;

    for(int i = 0; i < 100; i++)
    {
        value = value + (*(fw + i)) + (*(bw + i));      
    }

    value = value / 2;

    return value;
}
