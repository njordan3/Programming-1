#include <iostream>

using namespace std;

int main()
{
    char letter;
    int health = 100;
    int points = 0;
    int life = 3;
    bool invincible = false;
    string cheats = "yes";
    do //do while is good for making menus
    {

        cout << "-------------------\n";
        cout << "Best Game Ever v1.0\n";
        cout << "-------------------\n";
        cout << "h - Get hit\n";
        cout << "s - Get slammed\n";
        cout << "t - Find token\n";
        cout << "m - Find magical token\n";
        cout << "i - Gain invinsibility\n";
        cout << "f - Find a mushroom\n";
        cout << "q - Quit Best Game Ever\n";
        cout << "Enter choice: ";
        cin >> letter;   
        cout << endl;

        switch (letter)
        {
            case 'i':
                invincible = !invincible;    //toggle invincibility
                break;

            case 'h':
                if (!invincible)
                {
                    health = health - 2;     //lose 2 health points
                    if (health <= 0)
                    {
                        health = 0;
                    }


                }
                break;

            case 's':
                if (!invincible)
                {
                     health = health - 15;   //lose 15 health points   
                     if (health <= 0)
                     {
                         health = 0;
                     }
                }     
                break;
                
            case 't':
                points = points + 5;     //gain 5 points
                break;

            case 'm':
                points = points + 20;   //gain 20 points
                health = health + 5;

                if (health > 100)
                    health = 100;
                break;
            
            case 'f':
                health = health + 20;   //gain 20 health
            break;
            
            case 'x':
                cout << "Enter cheatcode: ";    //enter cheatcode for 100 lives
                cin >> cheats;
                cout << endl;

                if (cheats == "yes")
                {
                    life = life + 100;
                    cout << "You gain 100 lives!\n\n";
                }
                else
                {
                    life = 0;
                }
            break;

        }    

            if (health <= 0)
            {
                cout << "You lose one life!\n\n";
                life = life - 1;
                health = 100;
            }


        cout << "Health: " << health << endl << endl;
        cout << "Points: " << points << endl << endl;
        cout << "Lives: " << life <<endl << endl;

        } while (letter != 'q' && letter != 'Q' && life > 0);




    return 0;
}
