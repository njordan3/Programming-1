#include <iostream>

class Degree
{
    private:
        int years;
        char * description;
    public:
        Degree(int y, char * d)
        {
            years = y;
            description = d;
        }
        int get_years(){ return years; }
        std::string get_description(){ return description; }

};

int main()
{
    char description[] = "Computer Science";
    Degree degree(4, description);   

    std::cout << degree.get_description() << " should be completed in " << degree.get_years() << " years.\n";

    return 0;
}
