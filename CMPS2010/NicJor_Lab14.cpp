#include <iostream>
#include <cstdlib>

class Mammal
{
    public:
        Mammal(std::string age)
        {
            age_word = get_age(age);
            weight = get_weight(age);   
        }
        std::string get_age(std::string age)
        {
            std::string age_number;

            if(age == "puppy")
            {
                age_number = "1";           
            }
            else if(age == "adult")
            {
                age_number = "5";   
            }

            return age_number;
        }
        std::string get_weight(std::string age)
        {
            std::string weight_number;

            if(age == "puppy")
            {
                weight_number = "20";
            }
            else if(age == "adult")
            {
                weight_number = "50";
            }

            return weight_number;
        }        
    protected:
        std::string age_word, weight;

};
class Canine : public Mammal
{
    public:
        Canine(std::string age, std::string color) : Mammal(age)
        {
            trained = get_if_trained();
            fur_color = color;
        }
        bool get_if_trained()
        {
            bool result;

            if(age_word == "1")
            {
                result = false;    
            }   
            else if(age_word == "5")
            {
                result = true;
            }

            return result;
        }
        
    protected:
        bool trained;
        std::string fur_color; 
};
class Lab : public Canine
{
    public:
        Lab(std::string age, std::string color) : Canine(age, color)
        {
        }

        std::string get_details(std::string age)
        {
            return "Your labrador is " + get_trained_value(trained) + " and is " + age_word + " year(s) old, weighs " + weight + " pounds, and has " + fur_color + " fur.";                   
        }

        std::string get_trained_value(bool t)
        {
            std::string result;

            if(t == true)
            {
                result = "trained";
            }
            else
            {
                result = "not trained";
            }

            return result;
        }      
};

int main()
{
    std::string age;    
    std::string color;

    do
    {
        std::cout << "Do you want your labrador to be a puppy or adult? ";
        std::cin >> age;

    }while(age != "puppy" && age != "adult");

    do
    {
        std::cout << "Do you want your labrador to be brown, black, gray, or gold? ";
        std::cin >> color;

    }while(color != "brown" && color != "black" && color != "gray" && color != "gold");
    
    Lab * dog = new Lab(age, color);

    std::cout << dog -> get_details(age) << std::endl;   

    delete dog;

    return 0;
}

