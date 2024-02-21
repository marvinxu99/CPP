#include "std_lib_facilities.h"

int main()
{
    try
    {
        // . . . our program . . .
        error("test my error!");

        return 0; // 0 indicates success
    }
    catch (runtime_error &e)
    {
        cerr << "runtime error: " << e.what() << '\n';
        keep_window_open();
        return 1; // 1 indicates failure
    }
}