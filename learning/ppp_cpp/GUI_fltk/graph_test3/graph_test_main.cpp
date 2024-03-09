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

int main()
try{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib

    mmm m;
    m.d1(2);
    cout << m.d1() << endl;


    if (true) {
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


}
catch (exception& e) {
    cout << "Caught error: " << e.what() << endl;
    return 1;

}
catch (...) {
    cout << "caught unknown error." << endl;
    return 2;
}