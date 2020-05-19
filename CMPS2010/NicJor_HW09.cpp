//Nicholas Jordan
//HW09
//MW

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

class Card
{
    private:
        int suit;
        int value;
    public:
        Card()
        {
        } 
        void set(int s, int v)
        {
            suit = s;
            value = v;
        }
        string as_string()
        {
            string suits[5] = { "", "Diamonds", "Hearts", "Clubs", "Spades" };
            string faces[14] = { "" , "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" }; 

            return faces[value] + " of " + suits[suit]; 
        }
        bool operator<=(Card c)
        {
            if(c.value == 1)
            {
                c.value = c.value + value;                  
            }
            else if(value == 1)
            {
                value = value + c.value;
            }
            return this->value <= c.value; 
        }
        friend ostream & operator<<(ostream & out, Card & c)
        {
            out << c.as_string();
            return out;
        }

};

class Deck
{
    private:
        Card cards[52];
        bool inplay[52];
    public:
        Deck()
        {
            int i = 0;

            for(int j = 1; j < 5; j++)
            {
                for(int k = 1; k < 14; k++)
                {      
                    cards[i].set(j, k);

                    i++;                                
                }
            }                   
        }
        void unplay()
        {
            for(int i = 0; i < 52; i++)
            {
                inplay[i] = false;
            }
        }
        void shuffle()
        {

            for(int l = 51; l >= 0; l--)
            {
                int random = rand() % (l + 1);    

                Card temp = cards[l];

                cards[l] = cards[random];

                cards[random] = temp;
            }

            unplay();  //set all cards to "not in play"
        }
        Card draw()
        {
            Card drawn;
            int random = rand() % 52;
            drawn = cards[random];

            if(inplay[random] == false)
            {
                inplay[random] = true;
            }
            else if(inplay[random] == true)
            {
                while(inplay[random] == true)
                {
                    random = rand() % 52;
                    drawn = cards[random];
                }
            }

            return drawn;
        }

};

class Game
{
    private:
        Deck deck;
    public:
        Game()
        {
            deck.shuffle();
        }
        bool is_flush(Card hand[])
        {

            int h_counter = 0;
            int s_counter = 0;
            int d_counter = 0;
            int c_counter = 0;

            bool result = false;

            for(int i = 0; i < 5; i++)
            {
                const char * q;
                int p = 0, counter = 0; 
                string temp = hand[i].as_string();
                const char * t = temp.c_str();
                for(int j = 0; j < strlen(t); j++)
                {
                    if(isspace(*(t + j)))
                    {   
                        counter++;     
                    }
                    else if(counter == 2)
                    {   
                        q = (t + j);
                        j = strlen(t);
                    }
                }

                if(*q == 'H')
                {
                    h_counter++;                  
                }
                else if(*q == 'S')
                {
                    s_counter++;
                }
                else if(*q == 'D')
                {
                    d_counter++;   
                }
                else if(*q == 'C')
                {
                    c_counter++;
                }

                if(h_counter == 4|| s_counter == 4|| d_counter == 4|| c_counter == 4)
                {
                    result = true;
                }

            }

            return result;
        }
        void deal(Card hand[])
        {

            for(int i = 0; i < 5; i++)
            {   
                hand[i] = deck.draw();
            }
        }
};

int main()
{
    srand(time(NULL));
    Game poker;
    Card hand[5];

    poker.deal(hand);

    cout << "Your Hand: \n\n";
    cout << "--------------------\n";

    for(int i = 0; i < 5; i++)
    {
        cout << hand[i] << endl;
    }

    cout << endl;

    if(poker.is_flush(hand))
    {
        cout << "Your hand is a flush\n";
    }
    else
    {
        cout << "No flush\n";
    }

    cout << "--------------------\n\n";

    Deck deck1;
    deck1.shuffle();

    Card card1, card2;

    card1 = deck1.draw();
    card2 = deck1.draw();
    
    if(card1 <= card2)
    {
        cout << card2 << " beats or matches " << card1 << endl;
    }   
    else
    {
        cout << card1 << " beats " << card2 << endl;
    }

    cout << endl;

    return 0;
}
