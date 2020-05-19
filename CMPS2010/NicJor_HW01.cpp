//Nicholas Jordan
//09-08-2017
//HW1

#include <iostream>

using namespace std;

int main()
{
    double previous_price;
    double current_price;
    string symbol;
    string company;
    
    cout << " -- Welcome to CSUB Brokerage -- \n";
    cout << "What is the stock symbol? ";
    cin >> symbol;

    cout << "What is the company name? ";
    cin >> company;

    cout << "What was the previous stock price? ";
    cin >> previous_price;

    cout << "What is the current stock price? ";
    cin >> current_price;

    if (current_price > previous_price)
    {
        cout << "It's a bull market! " << company << " (" << symbol << ") went up " << ((current_price / previous_price) - 1) * 100 << "%" << endl;
    }

    if (previous_price > current_price)
    {   
        cout << "It's a bear market! " << company << " (" << symbol << ") went down " << (1 - (current_price / previous_price)) * 100 << "%" << endl;
    }

    if (current_price == previous_price)
    {
        cout << "It's a flat market! " << company << " (" << symbol << ") stock price didn't change." << endl;
    }













    return 0;
}

