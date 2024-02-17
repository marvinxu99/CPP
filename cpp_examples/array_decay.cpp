// 05-array-decay.cpp : demonstrate equivalence of pointer vs array parameters
 
#include <iostream>
using namespace std;
 
void print_arr(char s[]) {
    while (*s) {
        cout << *s++;
    }
    cout << '\n';
}
 
//void print_ptr(const char * const s) {    // Causes compiling Error
void print_ptr(const char * s) {
    while (*s) {
        cout << *s++;
    }
    cout << '\n';
}
 
int main() {
    char hello[] = { "Hello" };
    char world[] = { "World" };
    print_arr(hello);
    print_ptr("World");
}