#include "Simple_window.h" // get access to our window library
//#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities

class mmm {
private: 
    int _d1{ 0 };

public:
    int d1() const { return _d1; }
    void d1(int value) { _d1 = value; }

};

double one(double) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }


int main()
try{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib

    mmm m;
    m.d1(2);
    cout << m.d1() << endl;


    if (false) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win1{ tl,600,400,"Two Lines" };   // screen coordinate tl for top left corner
        // window size(600*400)
        // title: Two Lines

        constexpr Point x{ 100,100 };

        Line horizontal{ x,Point{200,100} }; // make a horizontal line
        Line vertical{ Point{150,50},Point{150,150} }; // make a vertical line

        horizontal.set_color(Color::red);
        vertical.set_color(Color::green);

        win1.attach(horizontal); // attach the lines to the window
        win1.attach(vertical);

        win1.wait_for_button(); // give control to the display engine
    }

    if (true) {
        constexpr int xmax = 600; // window size
        constexpr int ymax = 400;

        constexpr int x_orig = xmax / 2; // position of (0,0) is center of window
        constexpr int y_orig = ymax / 2;
        constexpr Point orig{ x_orig,y_orig };
        
        constexpr int r_min = -10; // range [–10:11)
        constexpr int r_max = 11;
        
        constexpr int n_points = 400; // number of points used in range
        
        constexpr int x_scale = 30; // scaling factors
        constexpr int y_scale = 30;
        
        Simple_window win{ Point{100,100},xmax,ymax,"Function graphing" };
        
        Function s{ one,r_min,r_max,orig,n_points,x_scale,y_scale };
        //Function s{ one,r_min,r_max,orig };
        Function s2{ slope,r_min,r_max,orig,n_points,x_scale,y_scale };
        Function s3{ square,r_min,r_max,orig,n_points,x_scale,y_scale };
        win.attach(s);
        win.attach(s2);
        win.attach(s3);
        
        Text ts{ Point{100,y_orig - 40},"one" };
        Text ts2{ Point{100,y_orig + y_orig / 2 - 20},"x/2" };
        Text ts3{ Point{x_orig - 100,20},"x*x" };
        win.set_label("Function graphing: label functions");
        win.attach(ts);
        win.attach(ts2);
        win.attach(ts3);

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

        Function s4{ cos,r_min,r_max,orig,400,30,30 };
        s4.set_color(Color::blue);
        win.attach(s4);

        //Function s5{ sloping_cos, r_min,r_max,orig,400,30,30 };
        // Function s5{ [](double x) { return cos(x) + slope(x); },
        //        r_min,r_max,orig,400,30,30 };
        Function s5{ [](double x) -> double { return cos(x) + slope(x); },
                r_min,r_max,orig,400,30,30 };

        win.attach(s5);
     
        Function f1{ log,0.000001,r_max,orig,200,30,30 }; // log() logarithm, base e
        Function f2{ sin,r_min,r_max,orig,200,30,30 }; // sin()
        f2.set_color(Color::blue);
        Function f3{ cos,r_min,r_max,orig,200,30,30 }; // cos()
        Function f4{ exp,r_min,r_max,orig,200,30,30 }; // exp() exponential e^x
        win.attach(f1);
        win.attach(f2);
        win.attach(f3);
        win.attach(f4);


        win.wait_for_button();
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