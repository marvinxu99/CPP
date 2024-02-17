// alg_all_of.cpp
// compile with: /EHsc
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
 list<int> li { 50, 40, 11, 20, 20 };
 list<int>::iterator iter;

 cout << "li = ( ";
 for (iter = li.begin(); iter != li.end(); iter++)
 	cout << *iter << " ";
 cout << ")" << endl;

 // Check if all elements in li are even.
 auto is_even = [](int elem){ return !(elem % 2); };
 if (all_of(li.begin(), li.end(), is_even))
 	cout << "All the elements are even numbers.\n";
 else
 	cout << "Not all the elements are even numbers.\n";
}