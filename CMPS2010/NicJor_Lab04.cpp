//Nicholas Jordan
//
//



#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    for (int i = 0; i < 100 && i % 2 == 0; i += 2)
    {
        cout << i << " \n";
    }
    
    cout << endl << "-------------------------------------\n\n";

    for (int i = 1; i < 100; i++)
    {
        if (i % 3 == 0)
        {
            cout << i << " Alpha\n";

            if ((i + 1) % 10 == 0)
            {
                cout << "Omega\n";
            }
        }
    }

    cout << endl << "-------------------------------------\n\n";

    double daypay = 0.01;    
    double total = 0;

    for (int i = 1; i <= 30; i++)
    {
       
        cout << "On day " << i << ", you made $" << daypay << endl << endl;
        
        total = daypay + total;
        daypay = daypay * 2;
           
    }

    cout << "After 30 days, you made $" << total << endl << endl;

    return 0;
}
