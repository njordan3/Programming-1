#include <iostream>
#include <iomanip>

void show_time(int start_hour, int end_hour, std::string period);

int main()
{
    
    show_time(6, 8, "AM");

    return 0;
}


void show_time(int start_hour, int end_hour, std::string period)
{   
    for(start_hour; start_hour <= 8; start_hour++)
    {
        for(int minutes = 0; minutes < 60; minutes++)
        {   
            if(start_hour == end_hour)
            {
                std::cout << start_hour << ":" << std::setfill('0') << std::setw(2) << minutes << period << std::endl;   
                minutes = 60;   
            }
            else
            {
                std::cout << start_hour << ":" << std::setfill('0') << std::setw(2) << minutes << period << std::endl;   
            }
        }
            
    }

}
