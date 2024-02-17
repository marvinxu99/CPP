// 02-references.cpp : introducing l-value references
 
#include <iostream>
using namespace std;
 
//int alice_age{ 9 };
auto alice_age{ 9 };
 
int main() {
    cout << "Alice\'s age is " << alice_age << '\n';
    //into& alice_age_ref = alice_age;
    auto& alice_age_ref = alice_age;
    alice_age_ref = 10;
    cout << "Alice\'s age is now " << alice_age << '\n';


   const auto a{ 10 };  // define a as constant
   auto b = a;          // define b as variable copy of a
   const auto c = a;    // define c as constant copy of a

   const auto d{ 11 };  // define d as constant
   auto e{ 12 };        // define e as variable
   const auto& f{ 12 }; // define f as constant reference (to a literal constant value)
   const auto& g = d;   // define g as constant reference to d
   auto& h = e;         // define h as reference to e
   const auto& i = e;   // define i as constant reference to e
   auto& j = d;         // define j as reference to d
   auto& k = f;         // define k as reference to f
}
