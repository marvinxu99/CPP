#include "Simple_window.h" // get access to our window library
//#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities

int main()
try{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib

    if (false) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win1{ tl,600,400,"Two Lines" };   // screen coordinate tl for top left corner
        // window size(600*400)
        // title: Two Lines

        constexpr Point x{ 100,100 };

        Line horizontal{ x,Point{200,100} }; // make a horizontal line
        Line vertical{ Point{150,50},Point{150,150} }; // make a vertical line

        win1.attach(horizontal); // attach the lines to the window
        win1.attach(vertical);

        win1.wait_for_button(); // give control to the display engine
    }

    if (true) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win1{ tl,600,400,"Lines +" };   // screen coordinate tl for top left corner

        Lines x1;
        x1.add(Point{ 100,100 }, Point{ 200,100 }); // first line: horizontal
        x1.add(Point{ 150,50 }, Point{ 150,150 }); // second line: vertical

        Lines x2 = {
            {Point{200,100}, Point{300,100}}, // first line: horizontal
            {Point{250,50}, Point{250,150}} // second line: vertical
        };
        x2.set_color(Color::red);

        Lines x3 = {
            Point{300,100}, Point{400,100},      // first line: horizontal
            Point{350,50}, Point{350,150}       // second line: vertical
        };
        x3.set_color(Color::cyan);


        win1.attach(x1);
        win1.attach(x2);
        win1.attach(x3);

        win1.wait_for_button(); // give control to the display engine

    }


    if (false) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };   // screen coordinate tl for top left corner
        int x_size = win3.x_max(); // get the size of our window
        int y_size = win3.y_max();
        int x_grid = 80;
        int y_grid = 40;
        Lines grid;
        for (int x = x_grid; x < x_size; x += x_grid)
            grid.add(Point{ x,0 }, Point{ x,y_size }); // vertical line
        for (int y = y_grid; y < y_size; y += y_grid)
            grid.add(Point{ 0,y }, Point{ x_size,y }); // horizontal line

        win3.attach(grid);


        win3.wait_for_button(); // give control to the display engine

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