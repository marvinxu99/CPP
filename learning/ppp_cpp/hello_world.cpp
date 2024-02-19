#include "std_lib_facilities.h"

int main() // C++ programs start by executing the function main
{
    cout << "Hello, World!\n"; // output “Hello, World!”

    string name = "Marvin";

    string temp = name.substr(2);

    cout << temp << endl;

    // cout << "Please enter a int value: ";
    // int n;
    // cin >> n;
    // cout << "n == " << n
    //      << "\nn+1 == " << n + 1
    //      << "\nthree times n == " << 3 * n
    //      << "\ntwice n == " << n + n
    //      << "\nn squared == " << n * n
    //      << "\nhalf of n == " << n / 2
    //      << "\nsquare root of n == " << sqrt(n)
    //      << '\n'; // another name for newline (“end of line”) in output

    double x; // we “forgot” to initialize:
    // the value of x is undefined
    double y = x;       // the value of y is undefined
    double z = 2.0 + x; // the meaning of + and the value of z are undefined
    cout << y << endl;

    keep_window_open(); // wait for a character to be entered

    return 0;
}