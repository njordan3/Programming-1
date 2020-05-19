#include <iostream>

using namespace std;

class Contact
{
    private:
        string first;
        string last;
        string * aliases;
    public:
        Contact()
        {
            aliases = new string[3];
        }
        Contact(const Contact & contact)
        {
            aliases = new string[3];
            last = contact.last;
            first = contact.first;

            for(int i = 0; i < 2; i++)
            {
                aliases[i] = contact.aliases[i];
            }           
        }
        ~Contact()
        {
            delete [] aliases;
        }

        string get_fullname() { return first + " " + last; }
        void set_first(string f) { first = f; }
        void set_last(string l) { last = l; }
        string get_aliases() { return aliases[0] + ", " + aliases[1] + ", " + aliases[2]; }
        void set_alias(string alias, int i) { aliases[i] = alias; }  
};

int main()
{
    string alias;
    string first;
    string last;

    Contact person1;

    cout << "First name: ";
    cin >> first;
    
    person1.set_first(first);

    cout << "Last name: "; 
    cin >> last;

    person1.set_last(last);

    for(int i = 0; i < 3; i++)
    {
        cout << "Alias " << i << ": ";
        cin >> alias;
        person1.set_alias(alias, i);
    }   
    
    Contact person2 = person1;

    for(int j = 0; j < 3; j++)
    {
        cout << "Alias " << j << ": ";
        cin >> alias;
        person2.set_alias(alias, j);
    }   

    cout << person1.get_fullname() << ": ";    
    cout << person1.get_aliases();  
    cout << endl;

    cout << person2.get_fullname() << ": ";
    cout << person2.get_aliases();   
    cout << endl;

    return 0;
}


