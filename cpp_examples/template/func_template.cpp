#include <iostream>
//#include <string>

using namespace std;

template <typename T>
inline T const& Max (T const& a, T const& b) { 
   return a < b ? b:a; 
}

template <typename T>
T minimum(const T& a, const T& b) {
    return (a < b) ? a : b;
}
 
int main () {
   int i = 39;
   int j = 20;
   cout << "Max(i, j): " << Max(i, j) << endl; 

   double f1 = 13.5; 
   double f2 = 20.7; 
   cout << "Max(f1, f2): " << Max(f1, f2) << endl; 

   string s1 = "Hello"; 
   string s2 = "World"; 
   cout << "Max(s1, s2): " << Max(s1, s2) << endl; 


   //auto m1 = minimum(3, 2.5);        // Error! minimum<int> or minimum<double>?
   auto m1 = minimum<double>(3, 2.5);  // This one works
   cout << "minimum<double>(3, 2.5) = " << minimum<double>(3, 2.5) << endl;

   auto m2 = minimum(-2, 1);         // m2 is an int with value -2
   cout << "minimum(-2, 1) = " << minimum(-2, 1) << endl;

   auto m3 = minimum(-5.5, -6.5);    // m3 is a double with value -6.5
   cout << "minimum(-5.5, -6.5) = " << minimum(-5.5, -6.5) << endl;

   return 0;
}