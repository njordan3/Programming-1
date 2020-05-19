//Nicholas Jordan
//Hangman
//MW

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>

class Words
{
    private:
        int minlen, maxlen;
        int count;
        std::string * choices;

    public:
        Words(int min, int max)
        {
            count = 0;
            minlen = min;
            maxlen = max;
            count_candidates();
            load_words();
        }
        ~Words()
        {
            delete [] choices;
        }
        int count_candidates();
        void load_words(); 
        std::string pick_word(); 
        void reset(int min, int max);     
};

void Words::reset(int min, int max)
{
    count = 0;
    minlen = min;
    maxlen = max;

    if(choices != NULL)
    {
        delete [] choices;
    }
    count_candidates();
    load_words();
}    
int Words::count_candidates()
{
    std::string line;

    std::ifstream fin;
    fin.open("enable1.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            getline(fin, line);

            if(fin.good())
            {
                if(strlen(line.c_str()) <= maxlen && strlen(line.c_str()) >= minlen)
                {
                    count++;   
                }                
            }
        }
    }
    fin.close();

    return count;
}
void Words::load_words()
{   
    int valid_word_counter = 0;
    choices = new std::string[count]; 
    std::string line;

    std::ifstream fin;
    fin.open("enable1.txt");

    if(fin.is_open())
    {
        while(!fin.eof())
        {
            getline(fin, line);

            if(fin.good())
            {
                if(strlen(line.c_str()) <= maxlen && strlen(line.c_str()) >= minlen)
                {
                    *(choices + valid_word_counter) = line;
                    valid_word_counter++;                    
                }                
            }  
        }
    }

    fin.close();
}
std::string Words::pick_word()
{
    std::string word_choice;

    int random_word = rand() % count;

    word_choice = *(choices + random_word);

    return word_choice;
}

class Hangman
{
    private:
        char word[40], progress[40];
        int word_length;
        void clear_progress(int length);
    public:
        char guess;
        void initialize(std::string start);
        std::string get_word() { return word; }
        std::string get_progress() { return progress; }
        int get_remaining() { return remaining; }
        bool is_word_complete() { return (strcmp(word, progress) == 0); }

        Hangman(std::string w)
        {
            initialize(w);
        }

    protected:
        int matches, wrong_guesses, remaining;
        char last_guess;
        std::string chars_guessed;

        bool check(char user_guess);

};
void Hangman::clear_progress(int length)
{
    int i = 0;

    while(i < length)
    {
        progress[i] = '-';

        i++;
    }
    progress[i] = '\0';
}
void Hangman::initialize(std::string start)
{

    chars_guessed;
    wrong_guesses = 0;
    remaining = 6;

    strcpy(word, start.c_str());

    word_length = strlen(word);

    clear_progress(word_length);
}
bool Hangman::check(char user_guess)
{   
    matches = 0;
    bool result, check;
    const char * c_str = chars_guessed.c_str();

    for(int j = 0; j < strlen(c_str); j++)
    {
        if(*(c_str + j) == user_guess)
        {
            j = strlen(c_str);
            check = true;
        }
        else
        {
            check = false;    
        }
    }   

    if(!check)
    {
        chars_guessed += user_guess;

        for(int i = 0; i < strlen(word); i++)
        {
            if(user_guess == word[i])
            {
                result = true;
                progress[i] = word[i];
                matches++;
            }
        }
        if(matches == 0)
        {
            result = false;
            wrong_guesses++;
            remaining--;
        }
    }
    return result;   
}

class HangmanConsole : public Hangman
{
    public:
        HangmanConsole(std::string start) : Hangman(start)
    {   
    }
        void show_status(int stage)
        {
            switch (stage)
            {
                case 0:
                    std::cout << " +----|\n";
                    std::cout << " |    O\n";
                    std::cout << " |   -|-\n";
                    std::cout << " |    /\\ \n";
                    std::cout << " | \n";
                    std::cout << " ----- \n";
                    std::cout << "YOU ARE DEAD\n";
                    break;
                case 1:
                    std::cout << " +-----|\n";
                    std::cout << " |     O\n";
                    std::cout << " |    -|-\n";
                    std::cout << " |     /\n";
                    std::cout << " | \n";
                    std::cout << " ----- \n";
                    break;
                case 2:
                    std::cout << " +-----|\n";
                    std::cout << " |     O\n";
                    std::cout << " |    -|-\n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " ----- \n";
                    break;
                case 3:
                    std::cout << " +-----|\n";
                    std::cout << " |     O\n";
                    std::cout << " |     |-\n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " ----- \n";
                    break;
                case 4:
                    std::cout << " +-----|\n";
                    std::cout << " |     O\n";
                    std::cout << " |     |\n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " ----- \n";
                    break;
                case 5:
                    std::cout << " +-----|\n";
                    std::cout << " |     O\n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " ----- \n";
                    break;
                case 6:
                    std::cout << " +-----|\n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " | \n";
                    std::cout << " ----- \n";
                    break;
            }
        }
        void show_info()
        {
            std::cout << "Your Progress: " << get_progress() << std::endl;;
            show_status(remaining);
            std::cout << "Your last guess, " << last_guess << ", had " << matches << " matches.\n";
            std::cout << "You've made " << wrong_guesses << " wrong guesses.\n";
            std::cout << "You have " << remaining << " tries left.\n";
            std::cout << "You've guessed the following characters: " << chars_guessed << std::endl;
        }

        friend std::istream &operator>>(std::istream & in, HangmanConsole & game)
        {
            in >> game.last_guess;

            game.check(game.last_guess);

            return in;
        }

};
void get_range_num(std::string prompt, int min, int max, int & number)
{
    do
    {
        std::cout << prompt;
        std::cin >> number;

    }while(number < min || number > max);
}
int show_menu()
{
    int answer;

    do
    {
        std::cout << "1. Play the computer (auto select random range)\n";
        std::cout << "2. Play the computer (min: 7, max: 12)\n";
        std::cout << "3. Play the computer (user selects/changes range)\n";
        std::cout << "4. Play the computer (use same range stored in 3)\n";
        std::cout << "5. Play the computer (user1 enters the word, user2 guesses)\n\n";
        std::cout << "Enter a choice: ";
        std::cin >> answer;
    }while(answer < 1 && answer > 5);

    return answer;
}
void set_game_settings(int number, int & min, int & max, bool & did_3_run, int & is_show_menu, int & min_3, int & max_3)
{
    switch(number)
    {
        case 1:
            do
            {
                min = rand() % 29;
                max = rand() % 29;
            }while(min >= max);
            is_show_menu = 1;           
            break;
        case 2:
            min = 7;
            max = 12;
            is_show_menu = 2;          
            break;
        case 3:
            do
            {
                get_range_num("Enter a minimum value: ", 1, 28, min_3);
                get_range_num("Enter a maximum value: ", 1, 28, max_3);
                if(min_3 > max_3 || (min_3 == 1 && max_3 == 1))
                {
                    std::cout << std::endl << "You need new minimum and maximum values.\n\n";   
                }
            }while(min_3 > max_3 || (min_3 == 1 && max_3 == 1));
            is_show_menu = 3;          
            did_3_run = true;
            min = min_3;
            max = max_3;
            break;
        case 4:
            if(did_3_run)
            {
                min = min_3;
                max = max_3;   
            }           
            else
            {
                do
                {
                    get_range_num("Enter a minimum value: ", 1, 28, min);
                    get_range_num("Enter a maximum value: ", 1, 28, max);
                    if(min > max || (min == 1 && max == 1))
                    {
                        std::cout << std::endl << "You need new minimum and maximum values.\n\n";
                    }       
                }while(min > max || (min == 1 && max == 1));
            }
            is_show_menu = 4;           
            break;
        case 5:
            is_show_menu = 5;          
            break;

    }
}
int main()
{
    std::string again;
    bool did_3_run = false;
    srand(time(NULL));
    int min, max, number, is_show_menu, min_3, max_3;

    do
    {
        Words words(min, max);

        set_game_settings(show_menu(), min, max, did_3_run, is_show_menu, min_3, max_3);

        if(is_show_menu != 5)
        {   
            words.reset(min, max);

            HangmanConsole game(words.pick_word());

            std::cout << "HANGMAN" << std::endl << "-------\n\n";
            std::cout << "Your word is: " << game.get_progress() << std::endl;

            while(!game.is_word_complete() && game.get_remaining() > 0)
            {
                std::cout << std::endl;
                std::cout << "Enter your guess: ";
                std::cin >> game;

                game.show_info();

            }
        }
        
        else if(is_show_menu == 5)
        {
            std::string player1_word;
            std::cout << "Player 1, enter a word: ";
            std::cin >> player1_word;

            HangmanConsole game_option5(player1_word);

            std::cout << "HANGMAN" << std::endl << "-------\n\n";
            std::cout << "Your word is: " << game_option5.get_progress() << std::endl;

            while(!game_option5.is_word_complete() && game_option5.get_remaining() > 0)
            {
                std::cout << std::endl;
                std::cout << "Player 2, enter your guess: ";
                std::cin >> game_option5;

                game_option5.show_info();

            }

        } 
        
        std::cout << std::endl;
        std::cout << "Do you want to play again(y/n)? ";
        std::cin >> again;

    }while(again == "y");  
    
    std::cout << std::endl << std::endl;
    
    return 0;
}
