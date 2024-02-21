#include "std_lib_facilities.h"

int main()
{
    try
    {
        vector<int> v{1, 2, 3, 4, 5}; // a vector of ints
        // for (int x; cin >> x;)
        //     v.push_back(x);                 // set values
        for (int i = 0; i < v.size(); ++i) // print values
            cout << "v[" << i << "] == " << v[i] << '\n';

        cout << v.at(7) << endl; // bounds-checked member access functions (e.g. std::vector::at and std::map::at).
    }
    catch (out_of_range)
    {
        cout << "Oops! Range error\n";
        return 1;
    }
    catch (...)
    { // catch all other exceptions
        cout << "Exception: something went wrong\n";
        return 2;
    }
}