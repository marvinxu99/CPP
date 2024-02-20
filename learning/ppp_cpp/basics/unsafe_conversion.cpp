#include "std_lib_facilities.h"

int main()
{
    // double d = 0;
    // while (cin >> d)
    // { // repeat the statements below
    //     // as long as we type in numbers
    //     int i{d};                       // try to squeeze a double into an int
    //     char c{i};                      // try to squeeze an int into a char
    //     int i2{c};                      // get the integer value of the character
    //     cout << "d==" << d              // the original double
    //          << " i==" << i             // converted to int
    //          << " i2==" << i2           // int value of char
    //          << " char(" << c << ")\n"; // the char
    // }

    double dc;
    dc = 10.1;

    double df1 = 9 / 5 * dc + 32; // Beware that it is easy to forget about integer division in an expression that also contains floating-point operands
    double df2 = 9.0 / 5 * dc + 32;

    cout << "df1 = " << df1 << endl; // 42.1
    cout << "df2 = " << df2 << endl; // 50.18

    keep_window_open();
}