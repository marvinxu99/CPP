// STRING VECTOR EXAMPLE
// CPP program to illustrate
// Implementation of begin() function
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main()
{
    // declaration of vector container
    vector<string> myvector{ "This", "is",
                             "Geeksforgeeks" };
 
    // using begin() to print vector
    for (auto it = myvector.begin();
         it != myvector.end(); ++it)
        cout << ' ' << *it;
    return 0;
}