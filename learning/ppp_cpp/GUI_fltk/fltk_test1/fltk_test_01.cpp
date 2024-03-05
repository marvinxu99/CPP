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

    Function sine{ sin,0,100,Point{20,150},1000,50,50 }; // sine curve
    // plot sin() in the range [0:100) with (0,0) at (20,150)
    // using 1000 points; scale x values *50, scale y values *50
    win.attach(sine);
    win.set_label("Canvas #4");
  
    // Polygon
    struct Polygon poly;        // make a shape (a polygon)
    poly.add(Point{300, 200});  // add a point
    poly.add(Point{350, 100});  // add another point
    poly.add(Point{400, 200});  // add a third point
    poly.set_color(Color::red); // adjust properties of poly
    win.attach(poly); // connect poly to the window

    struct Rectangle r{ Point{200,200}, 100, 50 }; // top left corner, width, height
    win.attach(r);
    win.set_label("Canvas #6");

    struct Closed_polyline poly_rect;
    poly_rect.add(Point{ 100,50 });
    poly_rect.add(Point{ 200,50 });
    poly_rect.add(Point{ 200,100 });
    poly_rect.add(Point{ 100,100 });
    poly_rect.add(Point{ 50,75 });
    win.attach(poly_rect);

    // Fill
    r.set_fill_color(Color::yellow); // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Canvas #7");

    // Text
    struct Text t{ Point{150,150}, "Hello, graphical world!" };
    win.attach(t);
    win.set_label("Canvas #8");

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("Canvas #9");

    // Load image
    Image ii{ Point{100,50},"images.jpg" }; // 400*212-pixel jpg
    win.attach(ii);
    win.set_label("Canvas #10");

    ii.move(100, 200);
    win.set_label("Canvas #11");

    win.wait_for_button(); // give control to the display engine

}
catch (exception& e) {
    cout << "Caught error: " << e.what() << endl;
    return 1;

}
catch (...) {
    cout << "caught unknown error." << endl;
    return 2;
}