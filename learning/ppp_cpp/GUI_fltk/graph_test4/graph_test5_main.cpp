#include "Simple_window.h" // get access to our window library
//#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities
#include <functional> // Include <functional> for std::function


struct Distribution {
    int year, young, middle, old;
};

istream& operator>>(istream& is, Distribution& d)
// assume format: ( year : young middle old )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;
    if (is >> ch1 >> dd.year
        >> ch2 >> dd.young >> dd.middle >> dd.old
        >> ch3) {
        if (ch1 != '(' || ch2 != ':' || ch3 != ')') {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
        return is;
    d = dd;
    return is;
}


int main()
try{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib


    if (true) {
        constexpr int xmax = 600; // window size
        constexpr int ymax = 400;

        constexpr int xoffset = 100; // distance from left-hand side of window to y axis
        constexpr int yoffset = 60; // distance from bottom of window to x axis
        
        constexpr int xspace = 40; // space beyond axis
        constexpr int yspace = 40;
        
        constexpr int xlength = xmax - xoffset - xspace; // length of axes
        constexpr int ylength = ymax - yoffset - yspace;


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