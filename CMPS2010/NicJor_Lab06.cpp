#include <iostream>

using namespace std;

double get_money(string prompt);
void calc_change(double change, int & quarters, int & dimes, int & nickels, int & pennies);
double calc_premium(int gender, int age, bool smoker = false);
double calc_premium(int year);

int main()
{
    double total, tendered, change;
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;    

    total = get_money("Enter a total: ");

    tendered = get_money("Enter amount tendered: ");

    change = tendered - total;

    cout << "Your change is $" << change << endl;

    calc_change(change, quarters, dimes, nickels, pennies);
    cout << "You should have " << quarters << " quarter(s), " << dimes << " dime(s), " << nickels << " nickel(s), and " << pennies << " pennies.\n";
    cout << "----------------------------------------------------------------------------------------------\n\n";

    
    cout << calc_premium(1, 18) << endl;  // male, 18 yrs , nonsmoker
    cout << calc_premium(1, 30) << endl;  // male, 30 yrs, nonsmoker
    cout << calc_premium(1, 58) << endl;  // male, 58 yrs, nonsmoker
    cout << calc_premium(2, 18) << endl;  // female, 18 yrs, nonsmoker  
    cout << calc_premium(2, 30) << endl;  // female, 30 yrs, nonsmoker
    cout << calc_premium(2, 58) << endl;  // female, 58 yrs, nonsmoker
    cout << calc_premium(1, 18, true) << endl;  // male, 18 yrs, smoker 
    cout << calc_premium(1, 30, true) << endl;  // male, 30 yrs, smoker
    cout << calc_premium(1, 58, true) << endl;  // male, 58 yrs, smoker
    cout << calc_premium(2, 18, true) << endl;  // female, 18 yrs, smoker 
    cout << calc_premium(2, 30, true) << endl;  // female, 30 yrs, smoker
    cout << calc_premium(2, 58, true) << endl;  // female, 58 yrs, smoker

    // AUTO INSURANCE
    cout << calc_premium(2000) << endl; // OLD car
    cout << calc_premium(2015) << endl; // NEW cari




    return 0;
}


double get_money(string prompt)
{
    double money;

    do
    {
        cout << prompt;
        cin >> money;

    } while(money < 0);

    return money;
}


void calc_change(double change, int & quarters, int & dimes, int & nickels, int & pennies)
{
    while(change > .99)
    {
        change--;
    }

    for(change; change > .24; change = change - .25)
    {
        quarters++;
    }   
    for(change; change > .09; change = change - .1)
    {
        dimes++;
    }   
    for(change; change > .04; change = change - .05)
    {
        nickels++;
    }   
    for(change; change > 0; change = change - .01)
    {
        pennies++; 
    } 

}

double calc_premium(int gender, int age, bool smoker)
{
    double premium = 50.00;
    if (gender == 1)
    {
        premium = premium + 25;

    }

    if (age < 25)
    {
        premium = premium + 50;
    }

    else if (age > 55)
    {
        premium = premium + 30;
    }

    if (smoker != false)
    {
        premium = premium * 2;
    }

    return premium;
}

double calc_premium(int year)
{
    double base_rate = 33.00;
    
    if (year < 2010)
    {
        base_rate = base_rate * .0125;
    }  
    else if (year >=2010)
    {
        base_rate = base_rate * .95;
    }
    return base_rate; 

} 
