#include "std_lib_facilities.h"

namespace X
{
    int var = 7;
    void print() // print X’s var
    {
        cout << "X:var = " << var << endl;
    }
}

namespace Y
{
    int var = 7;
    void print() // print X’s var
    {
        cout << "Y:var = " << var << endl;
    }
}

namespace Z
{
    int var = 7;
    void print() // print X’s var
    {
        cout << "Z:var = " << var << endl;
    }
}

int main()
{
    X::var = 7;
    X::print(); // print X’s var
    using namespace Y;
    var = 9;
    print(); // print Y’s var
    {
        using Z::print;
        using Z::var;
        var = 11;
        print(); // print Z’s var
    }
    print();    // print Y’s var
    X::print(); // print X’s var
}