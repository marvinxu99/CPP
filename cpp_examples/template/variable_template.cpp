#include <iostream>
using namespace std;

template <typename T = long double>
constexpr T pi_2{ 3.1415926536897932385L };  // note: long double literals end with L
 
int main () {

    auto circ = pi_2<float> * 2.0f * 1.5f;  // circ is of type float
    auto area = pi_2<double> * 1.5 * 1.5;   // area is of type double
    auto pi2 = pi_2<> * 2.0L;               // pi2 is of type long double

    cout << "pi<float> = " << pi_2<float> << endl;
    cout << "pi<double> = " << pi_2<double> << endl;
    cout << "pi<> = " << pi_2<> << endl;

   return 0;
}