#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    string name{"test.dat"};

    fstream fs{name}; // open for input and output
    if (!fs)
        error("can't open ", name);

    fs.seekg(5); // move reading position (g for “get”) to 5 (the 6th character)
    char ch;
    fs >> ch; // read and increment reading position
    cout << "character[5] is " << ch << ' (' << int(ch) << ")\n";

    fs.seekp(1); // move writing position (p for “put”) to 1
    fs << 'y';   // write and increment writing position
}
/*
Note that seekg() and seekp() increment their respective positions, so the figure represents the state of the program after
execution.
Please be careful: there is next to no run-time error checking when you use positioning. In particular, it is undefined what
happens if you try to seek (using seekg() or seekp()) beyond the end of a file, and operating systems really do differ in what
happens then.
*/
