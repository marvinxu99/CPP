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

        horizontal.set_color(Color::red);
        vertical.set_color(Color::green);

        win1.attach(horizontal); // attach the lines to the window
        win1.attach(vertical);

        win1.wait_for_button(); // give control to the display engine
    }

    if (false) {
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

        grid.set_color(Color::red);
        //grid.set_style(Line_style::dot);
        grid.set_style(Line_style{ Line_style::dash, 2 });

        win3.attach(grid);

        win3.wait_for_button(); // give control to the display engine
    }

    // Open polyline
    if (false) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };   // screen coordinate tl for top left corner
        
        Open_polyline opl = {
            Point{100,100}, Point{150,200}, Point{250,250}, Point{300,200}
        };
        opl.set_color(Color::red);

        win3.attach(opl);

        win3.wait_for_button(); // give control to the display engine
    }

    // Closed polyline
    if (true) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };   // screen coordinate tl for top left corner

        Closed_polyline cpl = {
            Point{100,100}, Point{150,200}, Point{250,250}, Point{300,200}
        };
        cpl.set_color(Color::red);

        cpl.add(Point{ 100,250 });   // Lines can cross while in Polygons we don’t allow lines to cross

        Text t{ Point{200,200},"A closed polyline that isn't a polygon" };
        t.set_color(Color::blue);

        win3.attach(cpl);
        win3.attach(t);

        win3.wait_for_button(); // give control to the display engine
    }

    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Graph_lib::Polygon poly {
            Point{ 100, 100 }, Point{ 150,200 }, Point{ 250,250 }, Point{ 300,200 }
        };
        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);

        win3.attach(poly);

        win3.wait_for_button(); // give control to the display engine
    }
 
    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Graph_lib::Rectangle rect00{ Point{150,100},200,100 };
        Graph_lib::Rectangle rect11{ Point{50,50},Point{250,150} };
        Graph_lib::Rectangle rect12{ Point{50,150},Point{250,250} }; // just below rect11
        Graph_lib::Rectangle rect21{ Point{250,50},200,100 }; // just to the right of rect11
        Graph_lib::Rectangle rect22{ Point{250,150},200,100 }; // just below rect21

        rect00.set_fill_color(Color::yellow);
        rect11.set_fill_color(Color::blue);
        rect12.set_fill_color(Color::red);
        rect21.set_fill_color(Color::green);

        win3.attach(rect00);
        win3.attach(rect11);
        win3.attach(rect12);
        win3.attach(rect21);
        win3.attach(rect22);

        rect11.move(400, 0); // to the right of rect21
        rect11.set_fill_color(Color::white);

        win3.put_on_top(rect00);
        
        rect00.set_color(Color::invisible);
        rect11.set_color(Color::invisible);
        rect12.set_color(Color::invisible);

        win3.set_label("rectangles 2");

        win3.wait_for_button(); // give control to the display engine
    }

    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Vector_ref<Graph_lib::Rectangle> vr;
        for (int i = 0; i < 16; ++i)
            for (int j = 0; j < 16; ++j) {
                vr.push_back(new Graph_lib::Rectangle{ Point{i * 20, j * 20},20,20 });
                vr[vr.size()-1].set_fill_color(Color{ i * 16 + j });
                win3.attach(vr[vr.size()-1]);
            }

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