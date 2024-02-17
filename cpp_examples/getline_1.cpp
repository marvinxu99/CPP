// 08-line1.cpp : obtain a line of input from the user and display it
 
#include <iostream>
using namespace std;
 
int main() {
    cout << "Please enter your full name:\n";
    char line[32];
    cin.getline(line, size(line));
    cout << "You entered: \'" << line << "\'\n";
    /*
    Any characters that do not fit into the C-style array are left in the input 
    buffer and are left unprocessed; also the fail-bit is set in the input 
    stream’s flags, meaning any further calls to getline() will return an 
    empty string. The stream fail-bit for cin can be unset with cin.clear(), 
    after which the unprocessed characters can be read with further call(s) to getline(). 
    Optionally, the ignore() member function can be used to skip one or more input characters.  
    */

    cout << "Please enter your full name AGAIN:\n";
    string s;
    getline(cin, s);
    cout << "You entered: \'" << s << "\'\n";
}

