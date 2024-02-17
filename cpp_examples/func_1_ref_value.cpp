#include <iostream>

using namespace std;


// Pass object as value
void display(int num) {
   cout << "num = " << num << endl;
   num -= 1;
}

// Pass object as pointer
void display2(int *num) {
   cout << "num = " << *num << endl;
   *num -= 1;
}

// Pass object as reference
void display3(int &num) {
   cout << "num " << num << endl;
   num -= 1;
}

// Main function for the program
int main() {

   int number = 10;

   display(number);   // Pass as value so copy constructor is called
   cout << "After display (pass as value)" << endl;

   display2(&number);
   cout << "After display (pass as pointer)" << endl;

   display3(number);
   cout << "After display (pass as reference)" << endl;

   display(number);   // Pass as value so copy constructor is called
   cout << "After display (pass as value)" << endl;

   return 0;
}
