#include <iostream>
using namespace std;

class Box {
   public:
      Box() { 
         cout << "Constructor called!" <<endl; 
      }
      ~Box() { 
         cout << "Destructor called!" <<endl; 
      }
};
int main() {

   Box* myBoxArray = new Box[4];
   delete [] myBoxArray; // Delete array

   // double
   double *pdouble = NULL;
   pdouble = new double;
   * pdouble = 23.45;
   cout << *pdouble << endl;

   // Array
   char* pvalue  = NULL;         // Pointer initialized with null
   pvalue  = new char[20];       // Request memory for the variable
   delete [] pvalue;            // Delete array pointed to by pvalue


   // multi-dimensional array
   using d4 = double[4];
   d4* pvalue2  = NULL;      // Pointer initialized with null 
   pvalue2 = new double [3][4];  // Allocate memory for a 3x4 array 
   delete [] pvalue2;            // Delete array pointed to by pvalue

   return 0;
}