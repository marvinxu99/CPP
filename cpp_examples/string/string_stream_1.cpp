// 08-stringstream1.cpp : write to string stream
 
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <iostream>
using namespace std;
 
int main() {
    ostringstream oss{};
    oss.precision(3);
    oss << fixed << 1 << '+' << 3.2 << " = " << 1 + 3.2;

    cout << "Using cout (recommended):" << endl;
    cout << oss.str() << endl;

    puts("Using puts (not recommended):");
    puts(oss.str().c_str());

    printf("Using printf (not recommended):\n");
    printf_s(oss.str().c_str());
}