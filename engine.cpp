#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

class Engine
{
private:
    string engine_no;
    float max_power, max_torque;
    string fuel_type;

public:
    Engine(string engineNo, float maxPower, float maxTorque, string fuelType)
    { /*manufacturer assigns information about the engine*/
        engine_no = engineNo;
        max_power = maxPower;
        max_torque = maxTorque;
        fuel_type = fuelType;
    }
    //constructor overloading
    Engine()
    {
    }
    void set_engine_no(string engineNo)
    {
        engine_no = engineNo;
    }
    string get_engine_no()
    {
        return engine_no;
    }
    void set_max_power(float maxPower)
    {
        max_power = maxPower;
    }
    float get_max_power()
    {
        return max_power;
    }
    void set_max_torque(float maxTorque)
    {
        max_torque = maxTorque;
    }
    float get_max_torque()
    {
        return max_torque;
    }
    void set_fuel_type(string fuelType)
    {
        fuel_type = fuelType;
    }
    string get_fuel_type()
    {
        return fuel_type;
    }

    void print_engine_details()
    { /*manufacturer displays information about the engine*/
        cout << "engine no:" << engine_no << endl;
        cout << "max torque" << max_torque << endl;
        cout << "max power" << max_power << endl;
        cout << "fuel type" << fuel_type << endl;
    }

    void write_engine_details()
    { /*manufacturer write engine details to a file*/
        ofstream myFile;
        myFile.open("details.txt", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << "-----engine details------------" << endl;
            myFile << "engine no:" << engine_no << endl;
            myFile << "max torque" << max_torque << endl;
            myFile << "max power" << max_power << endl;
            myFile << "fuel type" << fuel_type << endl;
        }
        myFile.close();
    }
};

int main()
{
    Engine engine;
    string str;
    float flt;
    cout << "----Enter engine details----" << endl;

    cout << "Enter engine no:" << endl;
    cin >> str;
    engine.set_engine_no(str);

    cout << "Enter max torque" << endl;
    cin >> flt;
    engine.set_max_torque(flt);

    cout << "Enter max power" << endl;
    cin >> flt;
    engine.set_max_power(flt);

    cout << "Enter fuel type" << endl;
    cin >> str;
    engine.set_fuel_type(str);

    cout << "Summery of the engine details you just entered" << endl;
    engine.print_engine_details();

    cout << "saving the engine details" << endl;
    engine.write_engine_details();
    cout << "saving success" << endl;

    return 0;
}
