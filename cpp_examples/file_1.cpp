// 08-file1.cpp : echo disk file to console
 
#include <iostream>
#include <fstream>
using namespace std;
 
int main(int argc, const char *argv[]) {
    if (argc != 2) {
        cerr << "Syntax: " << argv[0] << " <text file name>\n";
        return 1;
    }

    ifstream infile{ argv[1] };
 
    // int c = infile.get();
    // while (c != ifstream::traits_type::eof()) {
    //     //cout << static_cast<char>(c);
    //     cout.put(c);

    //     c = infile.get();
    // }

    char c;
    while (!infile.eof()) {
        infile >> noskipws >> c;
        cout << c;
    } 
    
    // An explicit call to close the input file is not needed, 
    // this happens automaticalls whien infile goes out of scope
    //infile.close();
}
