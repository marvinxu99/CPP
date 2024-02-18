// 07-string-upper.cpp : function to make a std::string uppercase in-place
 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
// Inplace change
void string_to_uppercase(string &s) {
    for (auto& c : s) {
        c = toupper(c);
    }
}

// return a string object
const string string_to_upper(string &s) {
    string result{};
    for (auto it = s.begin(); it != s.end(); ++it) {
        result += *it;
    }
    return result;
}


const string_view str_to_upper(string &s) {
    string result{};
    for (auto it = s.begin(); it != s.end(); ++it) {
        result += *it;
    }
    return result;
}


int main() {
    cout << "Please enter some text in lower-, mixed- or upper-case:\n";
    
	string input;
    
	getline(cin, input);
    
	string_to_uppercase(input);
    cout << "The same text in uppercase is:\n" << input << '\n';
	
	const auto alpha1 = ""s + "ABCDEF" + ' ' + "abcde" + 'f';
	cout << alpha1 << endl;
	
    string c_str1 = input.c_str();
    string data1 = input.data(); 

    string test1{"WERTsddfg"};
    string changed1 = string_to_upper(test1);
    cout << changed1 << endl;

    auto changed2 = str_to_upper(test1);
    cout << changed2 << endl;
}