#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main()
{

    int ai[] = {1, 2, 3, 4, 5, 6};                 // array of 6 ints
    int ai2[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // the last 90 elements are initialized to 0
    double ad[100] = {};                           // all elements initialized to 0.0

    char chars[] = {'a', 'b', 'c'};
    cout << "Type of chars: " << typeid(chars).name() << endl;
    cout << chars << endl;

    const char *pc = "Howdy";
    const char pc2[] = "Howdy";

    cout << strlen(pc) << endl;
    cout << strlen(pc2) << endl;

    string pc3 = "Howdy";
    cout << pc3.length() << endl;
    cout << pc3.c_str() << endl;
}
