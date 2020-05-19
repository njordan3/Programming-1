// Nick Jordan
// 08-30-2017
// Lab 1

#include <iostream>

using namespace std;

int main()
{
    string movie = "Forrest Gump";
    
    string title;

    int sequence1 = 1;

    int sequence2 = 2;

    double price = 9.99;

    int units = 2;

    title = "The Final Episode.";

    cout << movie << endl;

    cout << movie << " " << sequence1 << endl;

    cout << movie << " " << sequence2 << endl;

    cout << "Two movies cost " << price * units << endl;

    cout << movie << " " << sequence1 + units << " - The Final Episode \n";

    return 0;
}

