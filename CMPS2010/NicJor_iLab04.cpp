#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void show_reversed(char []);
void extract_digits(char dest[], char source[]);
void get_first_word(char word[], char sentence[]);
void add_dots(char dotted[], char undotted[]);

int main()
{
    char text[100];
    char phone[50];
    char digits[50];
    char sentence[100];
    char word[20];
    char undotted[20];
    char dotted[50];
/*
    cout << "Enter words: ";
    cin.getline(text, 100);

    cout << "Enter a phone string: ";
    cin.getline(phone, 50);

    cout << "Enter a sentence: ";
    cin.getline(sentence, 100);
  */  
    cout << "Enter an acronym: ";
    cin.getline(undotted, 20);
/*
    show_reversed(text);    // no square brackets with the name 

    extract_digits(digits, phone);
    cout << "Phone: " << digits << endl;

    get_first_word(word, sentence);
    cout << "The first word is: " << word << endl;
*/
    add_dots(dotted, undotted);
    cout << dotted << endl;

    return 0;
}


void show_reversed(char text[100])
{
    int i = strlen(text) - 1;
    while(i >= 0)
    {
        cout << text[i];
        i--;
    }
    
    cout << endl;

}


void extract_digits(char dest[50], char source[50])
{
    int d = 0;

    for(int i = 0; i < strlen(source); i++)
    {
        if(isdigit(source[i]))
        {
            dest[d] = source[i];    // building up a string of digits within the destination array
            d++;                    // the first digit takes the postition of 0 within the destination array
        }
    }

    dest[d] = '\0';     // terminator needs to be placed because we made our own array

}


void get_first_word(char word[20], char sentence[100])
{
    int w = 0;

    for(int i = 0; i < strlen(sentence); i++)
    {
        if(isspace(sentence[i]))
        {
            word[w] = '\0';
            i = strlen(sentence);     
        }
        else
        {
            word[w] = sentence[i];
            w++;
        }     
    }
}

void add_dots(char dotted[50], char undotted[20])
{
    int d = 0;
    for(int i = 0; i < strlen(undotted); i++)
    { 
        dotted[d] = toupper(undotted[i]);
        d++;       
        if(i != strlen(undotted) - 1)
        {
            dotted[d] = '.';
            d++;
        }
    }   

    dotted[d] = '\0';
}



