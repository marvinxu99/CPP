#include "std_lib_facilities.h"

int main()
{
    try
    {
        // our program
        // error("I am an error. catch me");

        // int x1 = narrow_cast<int>(2.9);    // throws
        // int x2 = narrow_cast<int>(2.0);    // OK
        // char c1 = narrow_cast<char>(1066); // throws
        // char c2 = narrow_cast<char>(85);   // OK

        string s = "ape";
        if (s == "ape")
            cout << "Success!\n";

        return 0; // 0 indicates success
    }
    catch (exception &e)
    {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1; // 1 indicates failure
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2; // 2 indicates failure
    }
}
