#include "std_lib_facilities.h"

int main()
{
    string name;
    getline(cin, name);   // input: Dennis Ritchie
    cout << name << '\n'; // output: Dennis Ritchie

    // Parse the line
    stringstream ss{name};
    string first_name;
    string second_name;
    ss >> first_name; // input Dennis
    ss >> second_name;

    string command;
    getline(cin, command); // read the line
    stringstream ss{command};
    vector<string> words;
    for (string s; ss >> s;)
        words.push_back(s); // extract the individual words
}
