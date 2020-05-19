// Nicholas Jordan
// Final C
// 12/15/2017

#include <iostream>
#include <fstream>

class Account 
{
    public:
        Account(){}
    protected:
        std::string number;
        double balance;
};
class Checking : public Account
{
    public:
        Checking(std::string account, std::string rout)
        {
            number = account;
            routing = rout;
            get_trans_total();
        }
    private:
        std::string routing;
        double get_trans_total()
        {
            balance = 0;
            std::string line;
            char character;
            double number;

            std::ifstream fin;
            fin.open("account.dat");

            if(fin.is_open())
            {
                while(!fin.eof())
                {
                    fin >> line >> character >> number;
                    if(fin.good())
                    {        
                        if(character == 'C')
                        {
                            balance = balance + number;   
                        }
                        else if(character == 'D')
                        {
                            balance = balance - number;
                        }
                    }
                }   
            } 

            fin.close();  
        }
    public:
        void create_statement()
        {
            std::ofstream fout;
            fout.open("statements.txt");

            if(fout.is_open())
            {
                fout << number << std::endl;
                fout << routing << std::endl;
                fout << balance << std::endl;
            }

            fout.close();        
        }

};

int main()
{
    Checking acct("01234567", "333444000");
    acct.create_statement();

    return 0;
}
