#include "Simple_window.h" // get access to our window library
//#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities
#include <functional> // Include <functional> for std::function

// There is a faster algorithm 
// https://github.com/python/cpython/blob/ffcc7cd57f6a52c6074ecc9f0a9f0177fb1dbfee/Modules/mathmodule.c#L1905
int fac(int n) // factorial(n); n!
{
    int r = 1;
    while (n > 1) {
        r *= n;
        --n;
    }
    return r;
}

double term(double x, int n) { // nth term of series
    return pow(x, n) / fac(n); 
} 

double expe(double x, int n) // sum of n terms for x
{
    double sum = 0;
    for (int i = 0; i < n; ++i) sum += term(x, i);
    return sum;
}

int main()
try{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib


    if (true) {

        constexpr int xmax = 600; // window size
        constexpr int ymax = 400;

        constexpr int x_orig = xmax / 2; // position of (0,0) is center of window
        constexpr int y_orig = ymax / 2;
        constexpr Point orig{ x_orig,y_orig };

        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win{ Point{100,100},xmax,ymax,"Function graphing" };

        constexpr int r_min = -10; // range [–10:11)
        constexpr int r_max = 11;
        constexpr int n_points = 400; // number of points used in range
        constexpr int x_scale = 30; // scaling factors
        constexpr int y_scale = 30;

        constexpr int xlength = xmax - 40; // make the axis a bit smaller than the window
        constexpr int ylength = ymax - 40;
        Axis x{ Axis::x,Point{20,y_orig}, xlength, xlength / x_scale, "one notch == 1" };
        x.set_color(Color::red);
        x.label.move(-160, 0);
        x.notches.set_color(Color::dark_red);

        Axis y{ Axis::y,Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1" };
        y.set_color(Color::red);
        win.attach(x);
        win.attach(y);

        // The “real” exponential - the standard library exp(),
        //Function real_exp{ exp,r_min,r_max,orig,200,x_scale,y_scale };
        //real_exp.set_color(Color::blue);
        //win.attach(real_exp);

        for (int n = 0; n < 50; ++n) {
            ostringstream ss;
            ss << "exp approximation; n==" << n;
            
            win.set_label(ss.str());

            // Define a function object that wraps the lambda function
            //Fct fct_obj = [&](double x) -> double { return expe(x, n); };
            // Define a function object that wraps the lambda function
            auto fct_obj = [&](double x) -> double { return expe(x, n); };
            //function<double(double)> fct_obj = [n](double x) { return expe(x, 10); };            
            //double fct_obj(double) = [n](double x) -> double { return expe(x, 10); };
            cout << fct_obj(5) << endl;


            // get next approximation:
            Function fe{ [](double x) { return expe(x, 3); }, r_min,r_max,orig,200,x_scale,y_scale };
            //Function fe{ fct_obj, r_min,r_max,orig,200,x_scale,y_scale};
            win.attach(fe);
            
            win.wait_for_button();
            
            win.detach(fe);
        }

        win.wait_for_button(); // give control to the display engine
    }

}
catch (exception& e) {
    cout << "Caught error: " << e.what() << endl;
    return 1;

}
catch (...) {
    cout << "caught unknown error." << endl;
    return 2;
}