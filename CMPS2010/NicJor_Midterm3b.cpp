#include <iostream>
#include <cstring>

class Flight
{
    private:
        int count;
        std::string from;
        std::string to;
        std::string * passengers;
        void create_manifest()
        {
            passengers = new std::string[100];
        }

    public:
        Flight()
        {
            count = 0; 
            from = "BFL";
            to = "PHX";
            create_manifest();
        }

        Flight(std::string f, std::string t)
        {
            count = 0;
            from = f;
            to = t;
            create_manifest();   
        }
        Flight(const Flight & l)
        {
            passengers = new std::string[100];

            from = l.from;
            to = l.to;
            count = l.count;

            for(int i = 0; i < 100; i++)
            {
                passengers[i] = l.passengers[i];
            }
        }
        ~Flight()
        {
            delete [] passengers;
        }
        void add_passenger(std::string name)
        {                       
            *(passengers + count) = name;
            count++;     
        }
        void add_destination(std::string dest)
        {
            from = to;
            to = dest;
        }
        friend std::ostream & operator<<(std::ostream & out, Flight & l)
        {
            out << l.from << "-" << l.to << " (" << l.count << " passengers: ";
            for(int i = 0; i < 3; i++)
            {
                out << l.passengers[i];
                if(i + 1 != 3)
                {
                    out << ", ";
                }
            } 
            out << ")";

            return out;
        }

};

int main()
{
    std::string name;

    Flight leg1("BFL", "PHX");
       
    std::cout << "Enter 3 passenger names: ";
    
    std::cin >> name;

    leg1.add_passenger(name);

    std::cin >> name;

    leg1.add_passenger(name);

    std::cin >> name;
    leg1.add_passenger(name);

    Flight leg2 = leg1;
    leg2.add_destination("RDU");

    std::cout << "Leg 1: " << leg1 << std::endl;
    std::cout << "Leg 2: " << leg2 << std::endl;

    return 0;
}
