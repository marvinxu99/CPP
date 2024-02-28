// #include <fstream>
// #include <iostream>
// #include <vector>
// using namespace std;
#include "std_lib_facilities.h"

struct Reading
{                       // a temperature reading
    int hour;           // hour after midnight [0:23]
    double temperature; // in Fahrenheit
};

int main()
{
    vector<Reading> temps; // store the readings here
    ifstream ist("temp.dat");
    if (!ist)
        error("error: Open dat file");

    int hour;
    double temperature;
    while (ist >> hour >> temperature)
    {
        if (hour < 0 || 23 < hour)
            error("hour out of range");
        temps.push_back(Reading{hour, temperature});
    }
    for (Reading t : temps)
    {
        cout << t.hour << " " << t.temperature << endl;
    }
}