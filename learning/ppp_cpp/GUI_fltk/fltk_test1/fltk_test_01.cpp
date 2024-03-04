#include "Simple_window.h" // get access to our window library
//#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities

int main()
try{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib

    Point tl{100, 100}; // to become top left corner of window

    Simple_window win{ tl,600,400,"Canvas" };   // screen coordinate tl for top left corner
                                                // window size(600*400)
                                                // title: Canvas

    // Axis X
    Axis xa{ Axis::x, Point{20,300}, 280, 10, "x axis" };   // make an Axis
                                                            // an Axis is a kind of Shape
                                                            // Axis::x means horizontal
                                                            // starting at (20,300)
                                                            // 280 pixels long
                                                            // 10 “notches”
                                                            // label the axis "x axis"
    xa.set_color(Color::black); // choose a color
    xa.label.set_color(Color::dark_red); // choose a color for the text
    win.attach(xa); // attach xa to the window, win
    win.set_label("Canvas #2"); // relabel the window

    // Axis Y
    Axis ya{ Axis::y, Point{20,300}, 280, 10, "y axis" };
    ya.set_color(Color::cyan); // choose a color
    ya.label.set_color(Color::dark_red); // choose a color for the text
    win.attach(ya);
    
    win.set_label("Canvas #3");

    win.wait_for_button(); // display!

    //struct Polygon poly;        // make a shape (a polygon)
    //poly.add(Point{300, 200});  // add a point
    //poly.add(Point{350, 100});  // add another point
    //poly.add(Point{400, 200});  // add a third point
    //poly.set_color(Color::red); // adjust properties of poly

    //win.attach(poly); // connect poly to the window

    //win.wait_for_button(); // give control to the display engine

}
catch (exception& e) {
    cout << "Caught error: " << e.what() << endl;
    return 1;

}
catch (...) {
    cout << "caught unknown error." << endl;
    return 2;
}