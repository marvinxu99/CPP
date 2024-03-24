// 07-vector.cpp : read integers from user, sort them and then output
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
 
int main() {
    
    //vector<int> v;
    // for (;;) {
    //     cout << "Please enter a number (99 to quit): ";
    //     int i{};
    //     cin >> i;
    //     if (i == 99) {
    //         break;
    //     }
    //     v.push_back(i);
    // }
    vector<int> v = {34, 5, 23, 6, 88};
    vector<int> v2 = {1, 5, 9, 6, 10};

    // "Append" elements in another vector
    v.insert(v.end(), v2.begin(), v2.end());

    // Sort
    sort(begin(v), end(v));
    copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
    cout << '\n';

    cout << "Highest to lowerest..." << endl;
    //sort(v.rbegin(), v.rend());
    copy(v.crbegin(), v.crend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    cout << "Using subscription..." << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Using iterator..." << endl;
    for (auto iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

}