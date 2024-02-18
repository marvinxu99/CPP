#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string s{ "Hello, world!" }; // s makes a copy of its initializer
    std::cout << s << '\n';

    int x {1 };
    cout << x << endl;

    
    return 0;
}