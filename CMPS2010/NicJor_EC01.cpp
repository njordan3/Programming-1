//Nicholas Jordan
//10-04-2017
//EC01

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int v2;
    double wager, amount = 20.00;
    int guess;
    char again = 'y';

    srand(time(NULL));

    do
    {

        v2 = rand() % 100 + 1;      // v2 in the range 1 to 100
        
        cout << fixed << setprecision(2);
        cout << "You have $" << amount << " in your account.\n"; 
        cout << "You must guess my number (it is between 1 and 100).\n"; 
        cout << "You have a maximum of seven tries to guess my number.\n\n";
        cout << "Ok, I have my number.\n";
        cout << "How much do you want to wager that you can guess it in seven attempts? ";
        cin >> wager;
        cout << endl;

        if (wager <= amount)    // you can't wager more than you have
        {
            for (int i = 7; i > 0; i--)     // user has 7 tries to guess the number
            {
                cout << "Ok, guess my number: ";
                cin >> guess;

                if (guess == v2)    // user is correct so they gain their wager and are asked to play again
                {
                    amount = amount + wager;
                    cout << "You guessed it! You now have $" << amount << " in your account!\n";
                    i = 0;   
                }
                else if (guess > v2)    // user guessed too high
                {
                    if (i - 1 == 1)
                    {
                        cout << "Your number is higher than mine. You have " << i - 1 << " attempt left.\n\n";
                    }
                    else if (i - 1 != 1 && i - 1 != 0)
                    {                        
                        cout << "Your number is higher than mine. You have " << i - 1 << " attempts left.\n\n";
                    }
                    
                    else if (i == 1)     // money is subtracted if they are out of tries
                    {
                        amount = amount - wager;
                        cout << "Your number is higher than mine.\n\n";
                        cout << "You failed to guess my number.\n\n";
                        cout << "You now have $" << amount << " in your account.\n";
                    }
                }
                else if (guess < v2)    // user guessed too low
                {
                    if (i - 1 == 1)
                    {
                        cout << "Your number is lower than mine. You have " << i - 1 << " attempt left.\n\n";    
                    }
                    else if (i - 1 != 1 && i - 1 != 0)
                    {
                        cout << "Your number is lower than mine. You have " << i - 1 << " attempts left.\n\n";
                    }
                    else if (i - 1 == 0)     // money is subtracted if they are out of tries
                    {   
                        amount = amount - wager;
                        cout << "Your number is lower than mine.\n\n";
                        cout << "You failed to guess my number.\n\n";
                        cout << "You now have $" << amount << " in your account.\n";
                    }
                }
            }

            if (amount > 0)
            {
                cout << "Play again? (y/n): ";
                cin >> again;
                cout << endl;
            }
            else    // if the user has no more money they can't play again
            {
                cout << "You have no more money to wager.\n\n";
            }
        }
        else
        {
            cout << "WAGER IS TOO HIGH.\n";
        }
    } while (again == 'y' && amount > 0);   // loop continues as long as user enters 'y' and has money

    return 0;
}
