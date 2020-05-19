#include <iostream>

using namespace std;

class Game
{
    private:
        int lives;
        int health;

    public:
        bool game_over()
        {
            if(lives == 0)
            {
                cout << "YOU DIED\n\n";
                return true;
            }
            else
            {
                return false;
            }
        }
        Game() //default constructor to set health to 100 and lives to 3
        {
            health = 100;
            lives = 3;
        }
        Game(int h, int l) //overloaded constructor to set health to 100 and lives to 3
        {
            health = h;
            lives = l;
        }
        void find_token();
        void find_special_token();
        void get_hit();
};

void Game::find_token()
{
    health = health + 10;
    if(health > 100)
    {
        health = 100;
    }
    cout << "Health: " << health << endl << "Lives: " << lives << endl << endl;
}
void Game::find_special_token()
{
    health = health + 20;
    if(health > 100)
    {
        health = 100;
    }    
    cout << "Health: " << health << endl << "Lives: " << lives << endl << endl;
}
void Game::get_hit()
{
    health = health - 15;
    if(health < 0)
    {
        lives--;
        if(lives != 0)
        {
            health = 100;
        }
        else if(lives == 0)
        {
            health = 0;
        }
    }
    else if(lives == 0)
    {
        game_over();
    }
    
    cout << "Health: " << health << endl << "Lives: " << lives << endl << endl;
}


int main()
{
    Game got(100, 3);

    char choice;

    do
    {
        cout << "t - Token\n";
        cout << "s - Special Token\n";
        cout << "q - Quit\n";
        cout << "h - Get Hit\n";
        cin >> choice;

        switch (choice)
        {
            case 't': got.find_token();
                      break;
            case 's': got.find_special_token();
                      break;
            case 'h': got.get_hit();
                      break;   
        }

    } while(!got.game_over() && choice != 'q');   

    return 0;
}
