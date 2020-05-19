//Nicholas Jordan
//Nov 15, 2017
//MW

#include <iostream>
#include <fstream>

using namespace std;

class Engine
{
    private:
        int rpm, speed;
        int drive_mode, rpm_gain, max_speed;
        string drive_modes[4];
        string filename;

        void set_drive_modes();
        int load_drive_mode();
        void save_drive_mode();
        void prep_engine();

    public:

        void decelerate();
        void accelerate();
        void increase_drive_mode();
        void lower_drive_mode();
        void show_status();

        Engine(string name)     //Engine class default constructor
        {
            filename = name;
            set_drive_modes();
            drive_mode = load_drive_mode();
            prep_engine();
            rpm = 0;
            speed = 0;
        }

};

void Engine::set_drive_modes()      //names the indidivdual elements of drive_modes[]
{ 
    drive_modes[0] = "Eco Pro";
    drive_modes[1] = "Comfort";
    drive_modes[2] = "Sport";
    drive_modes[3] = "Sport Plus";       
}
int Engine::load_drive_mode()       //reads the integer representation for the last drive mode used from bmwx3.txt
{
    int result, dm = 1;

    ifstream fin;    
    fin.open((filename + ".txt").c_str());

    if(fin.is_open())
    {
        fin >> dm;

        if(fin.good())
        {
            result = dm;
        }
    

        fin.close();
    }
    else
    {
        result = dm;
    }


    return result;
}
void Engine::save_drive_mode()      //saves the integer representation of the current drive mode to a bmwx3.txt
{
    ofstream fout;
    fout.open((filename + ".txt").c_str());

    if(fout.is_open())
    {
        fout << drive_mode << endl;
        fout.close();
    }
}
void Engine::prep_engine()      //sets the rpm_gain and max_speed depending on drive mode
{
    if(drive_mode == 0)
    {
        rpm_gain = 100;
        max_speed = 65;
    }
    else if(drive_mode == 1)
    {
        rpm_gain = 300;
        max_speed = 85;
    }
    else if(drive_mode == 2)
    {
        rpm_gain = 1000;
        max_speed = 185;
    }
    else if(drive_mode == 3)
    {
        rpm_gain = 1500;
        max_speed = 185;
    }
}

void Engine::accelerate()       //increase speed and rpm
{
    rpm = rpm + rpm_gain;
    speed = speed + 10;
    if(speed > max_speed)
    {
        speed = max_speed;
    }   
}
void Engine::decelerate()       //reduce speed and rpm
{
    rpm = rpm - 200;
    speed = speed - 10;
    if(speed < 0)
    {
        speed = 0;
    }
    if(rpm < 0)
    {
        rpm = 0;
    }    
}
void Engine::increase_drive_mode()      //increase drive mode
{
    drive_mode = drive_mode + 1;
    if(drive_mode > 3)
    {
        drive_mode = 3;
    }
    prep_engine();
    save_drive_mode();
}
void Engine::lower_drive_mode()     //lower drive mode
{
    drive_mode = drive_mode - 1;
    if(drive_mode < 0)
    {
        drive_mode = 0;
    }
    prep_engine();
    save_drive_mode();
}
void Engine::show_status()      //shows car status to user in console
{
    cout << "Dashboard: \nDrive Mode: " << drive_modes[drive_mode] << endl << "Speed: " << speed << endl<< "RPM: " << rpm << endl << endl;
}

int main()
{
    Engine engine("bmwx3");
    char action;

    do      //shows menu for actions with car
    {

        cout << "A - accelerate\n";
        cout << "D - decelerate\n";
        cout << "M - increase drive mode\n";
        cout << "N - lower drive mode\n";
        cout << "Q - park the car (quit)\n";
        cout << "Action? ";
        cin >> action;
        cout << endl;
        if(action == 'a')
        {
            engine.accelerate();
        }
        else if(action == 'd')
        {
            engine.decelerate();
        }
        else if(action == 'm')
        {
            engine.increase_drive_mode();
        }
        else if(action == 'n')
        {
            engine.lower_drive_mode();
        }
        
        engine.show_status();

    } while(action != 'q');

    return 0;
}
