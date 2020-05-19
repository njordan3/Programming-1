#include <iostream>

using namespace std;

int main()
{
    char letter;
    string name;
    int  number;

    cout << "g - Gryffindor" << endl;
    cout << "h - Hufflepuff" << endl;
    cout << "r - Ravenclaw" << endl;
    cout << "s - Slytherin" << endl;
    cout << "Enter choice: ";
    cin >> letter;
    
    cin.ignore();   //discards the Enter Keystroke
                    //stuck in the keyboard buffer
   
   
    switch (letter)
    {
        case 'G':
        case 'g': cout << "Welcome to Gryffindor House!\n";
                  cout << "What is your name? \n";
                  getline(cin, name);   //accepts spaces in strings. works like cin

                  if (name == "Harry Potter" || name == "Hermione Granger" || name == "Ron Weasley")
                  {
                      cout << "Enter a number: ";
                      cin >> number;

                      if (number >= 37 && number <= 47 || number >=81 && number <= 93 || number == 177)
                      { 
                           cout << "TEN POINTS TO GRYFFINDOR!!!\n";
                      }
                      else
                      {
                           cout << "GET OUT OF MY CLASS!!!\n";
                      }

                  }
                  else
                  {    
                      cout << "Get out of my sight.\n";
                  }

                 
                 
                  break;
        case 'H':
        case 'h': cout << "Welcome to Hufflepuff House!\n";
                break;
        case 'R':
        case 'r': cout << "Welcome to Ravenclaw House!\n";
                break;
        case 'S':
        case 's': cout << "Welcome to Slytherin House!\n";
                break;
    }






    return 0;
}

