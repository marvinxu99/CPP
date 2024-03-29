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

    // Grid
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

    // Grid example 2
    if (true) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win3{ tl,1000,1000,"Grid2" };   // screen coordinate tl for top left corner
        int x_size = 800; // get the size of our window
        int y_size = 800;
        int x_grid = 100;
        int y_grid = 100;
        
        Lines grid;
        
        for (int x = 0; x <= x_size; x += x_grid)
            grid.add(Point{ x,0 }, Point{ x,y_size }); // vertical line
        for (int y = 0; y <= y_size; y += y_grid)
            grid.add(Point{ 0,y }, Point{ x_size,y }); // horizontal line

        grid.move(50, 50);

        grid.set_color(Color::red);
        //grid.set_style(Line_style::dot);
        grid.set_style(Line_style{ Line_style::dash, 2 });

        win3.attach(grid);

        win3.wait_for_button(); // give control to the display engine
    }

    // Open polyline
    if (false) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win3{ tl,600,400,"Open_polyline" };   // screen coordinate tl for top left corner
        
        Open_polyline opl = {
            Point{100,100}, Point{150,200}, Point{250,250}, Point{300,200}
        };
        opl.set_color(Color::red);

        win3.attach(opl);

        win3.wait_for_button(); // give control to the display engine
    }

    // Closed polyline
    if (false) {
        Point tl{ 100, 100 };                             // to become top left corner of window
        Simple_window win3{ tl,600,400,"Closed_polyline" };   // screen coordinate tl for top left corner

        Closed_polyline cpl = {
            Point{100,100}, Point{150,200}, Point{250,250}, Point{300,200}
        };
        cpl.set_color(Color::red);

        cpl.add(Point{ 100,250 });   // Lines can cross while in Polygons we don�t allow lines to cross

        Text t{ Point{200,200},"A closed polyline that isn't a polygon" };
        t.set_color(Color::blue);

        win3.attach(cpl);
        win3.attach(t);

        win3.wait_for_button(); // give control to the display engine
    }

    // Polygon
    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Polygon" };    // screen coordinate tl for top left corner

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

    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Circle c1{ Point{100,200},50 };
        Circle c2{ Point{150,200},100 };
        Circle c3{ Point{200,200},150 };

        c1.set_color(Color::red);
        c2.set_color(Color::dark_cyan);
        c3.set_color(Color::dark_green);

        win3.attach(c1);
        win3.attach(c2);
        win3.attach(c3);

        win3.wait_for_button(); // give control to the display engine
    }

    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Graph_lib::Ellipse e1{ Point{200,200},50,50 };
        Graph_lib::Ellipse e2{ Point{200,200},100,50 };
        Graph_lib::Ellipse e3{ Point{200,200},100,150 };

        e1.set_color(Color::red);
        e2.set_color(Color::dark_yellow);
        e3.set_color(Color::dark_green);

        win3.attach(e1);
        win3.attach(e2);
        win3.attach(e3);

        win3.wait_for_button(); // give control to the display engine
    }

    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Marked_polyline mpl{ "1234",{{100,100}, {150,200}, {250,250}, {300,200}} };

        mpl.set_color(Color::red);

        win3.attach(mpl);

        win3.wait_for_button(); // give control to the display engine
    }

    // Marks
    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Marks pp{ "x",{{100,100}, {150,200}, {250,250}, {300,200}} };

        win3.attach(pp);

        win3.wait_for_button(); // give control to the display engine
    }

    // Mark
    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win3{ tl,600,400,"Mark" };    // screen coordinate tl for top left corner

        Circle c1{ Point{100,200},50 };
        Circle c2{ Point{150,200},100 };
        Circle c3{ Point{200,200},150 };

        Mark m1{ Point{100,200},'x' };
        Mark m2{ Point{150,200},'y' };
        Mark m3{ Point{200,200},'z' };

        c1.set_color(Color::red);
        c2.set_color(Color::dark_cyan);
        c3.set_color(Color::dark_green);

        win3.attach(m1);
        win3.attach(m2);
        win3.attach(m3);

        win3.attach(c1);
        win3.attach(c2);
        win3.attach(c3);

        win3.wait_for_button(); // give control to the display engine
    }

    // Image
    if (false) {
        Point tl{ 100, 100 };                       // to become top left corner of window
        Simple_window win{ tl,600,400,"Grid" };    // screen coordinate tl for top left corner

        Image rita{ Point{0,0},"rita.jpg" };
        Image path{ Point{0,0},"rita_path.gif" };
        
        //path.set_mask(Point{ 50,250 }, 600, 400); // select likely landfall
        path.set_mask(Point{ 50,100 }, 600, 400); // select likely landfall

        win.attach(path);
        win.attach(rita);

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