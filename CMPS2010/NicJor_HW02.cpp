//Nicholas Jordan
//09-17-2017
//HW02

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double monthly;
    double apr;
    double apr_monthly;
    double start_bal;
    double interest;
    double end_bal;
    int months;

    cout << "What is the outstanding balance? ";
    cin >> start_bal;
    cout << "What is the APR? ";
    cin >> apr;
    cout << "How much do you pay every month? ";
    cin >> monthly;

    while (monthly < 0)
    {
        cout << "How much do you pay every month? ";
        cin >> monthly;
    }
    
    cout << endl << "The table shows how long it will take to pay:\n\n";
    cout << fixed << setprecision(2);
    cout << setw(5) << "Month" << setw(10) << "Start" << setw(10) << "Interest" << setw(15) << "Monthly" << setw(10) << "End" << endl;

    apr_monthly = (apr / 12) / 100;
    interest = start_bal * apr_monthly;
    end_bal = start_bal + interest - monthly;

    while (end_bal > 0)
    {
       
        months = months + 1;
        interest = start_bal * apr_monthly;
      
        cout << setw(5) << months << setw(10) << start_bal << setw(10) << interest;
        
        apr_monthly = (apr / 12) / 100;
        end_bal = start_bal + interest - monthly;

        cout  << setw(15) << monthly << setw(10) << end_bal << endl;
  
        start_bal = end_bal;
    }

    return 0;

}
