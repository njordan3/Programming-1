//Nicholas Jordan
//09-28-2017
//HW03

#include <iostream>
using namespace std;
int main()
{
    int n1;
    int n2;
    char letter;
    int sum;
    int number;
    int first = 0;
    int second = 1;
    int fib;
    int i;

    cout << "Enter a number: ";
    cin >> n1;
    cout << "Enter a number: ";
    cin >> n2;
    cout << endl;


    cout << "a - Display all odd numbers between n1 and n2.\n";
    cout << "b - Determine if a number is in the Fibonacci sequence.\n";
    cout << "c - The sum of all integers between n1 and n2 inclusively.\n";
    cout << "q - Quit the program.\n";

    do
    {



        cout << "Enter a command: ";
        cin >> letter;



        if (letter == 'a' || letter == 'b' || letter == 'c' || letter == 'q')
        {
            switch (letter)
            {

                case 'a':
                    cout << "All odd: ";
                    i = n1;
                    while (i <= n2)
                    {
                        if (i % 2 != 0)
                        {
                            cout << i << " ";
                        } 
                        i = i + 1;
                    }

                    cout << endl;
                    break;

                case 'b':
                    cout << "Enter a number: ";
                    cin >> number;

                    do
                    {

                        fib = first + second;
                        first = second;
                        second = fib;

                    } while (fib < number);                 

                    if (number == fib)
                    {
                        cout << number << " is in the fibonacci sequence.\n";
                    }
                    else
                        cout << number << " is not in the fibonacci sequence.\n";

                    break;  

                case 'c':
                    sum = 0;
                    i = n1;
                    while (i <= n2)
                    {
                        sum = sum + i;
                        i = i + 1;
                    }             
                    cout << "Sum = " << sum << endl;
                    break;
            }



        }     
        else
        {
            cout << "<UNKNOWN COMMAND>\n";

        }



    } while (letter != 'q');



    return 0;
}

