#include "std_lib_facilities.h"

double str_to_double(string s)
// if possible, convert characters in s to floating-point value
{
    istringstream is{s}; // make a stream so that we can read from s
    double d;
    is >> d;
    if (!is)
        error("double format error: ", s);
    return d;
}

void my_code(string label, Temperature temp)
{
    // . . .
    ostringstream os; // stream for composing a message
    os << setw(8) << label << ": "
       << fixed << setprecision(5) << temp.temp << temp.unit;
    someobject.display(Point(100, 100), os.str().c_str());
    // . . .
}

int main()
try
{
    double d1 = str_to_double("12.4"); // testing
    double d2 = str_to_double("1.34e-3");
    double d3 = str_to_double("twelve point three"); // will call error()

    // A simple use of an ostringstream is to construct strings by concatenation. For example:
    int seq_no = get_next_number(); // get the number of a log file
    ostringstream name;
    name << "myfile" << seq_no << ".log"; // e.g., myfile17.log
    ofstream logfile{name.str()};         // e.g., open myfile17.log
}
catch (exception e)
{
    cout << "Caught an error: " << e.what() << endl;
}
