#include <filesystem>

#include "Simple_window.h" // get access to our window library
//#include "window.h" // get access to our window library
#include "Graph.h"         // get access to our graphics library facilities


struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title);
    Open_polyline lines;
private:
    Button next_button; // add (next_x,next_y) to lines
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    void next();
    void quit();
};

int main()
try{
    using namespace Graph_lib; // our graphics facilities are in Graph_lib

    cout << "Current path is " << filesystem::current_path() << endl; // (1)
    //filesystem::current_path(filesystem::temp_directory_path());            // (3)
    //std::cout << "Current path is " << filesystem::current_path() << endl;


    if (true) {
        constexpr int xmax = 600; // window size
        constexpr int ymax = 400;

        constexpr int xoffset = 100; // distance from left-hand side of window to y axis
        constexpr int yoffset = 60; // distance from bottom of window to x axis
        
        constexpr int xspace = 40; // space beyond axis
        constexpr int yspace = 40;
        
        constexpr int xlength = xmax - xoffset - xspace; // length of axes
        constexpr int ylength = ymax - yoffset - yspace;

        constexpr int base_year = 1960;
        constexpr int end_year = 2040;

        constexpr double xscale = double(xlength) / (end_year-base_year);
        constexpr double yscale = double(ylength) / 100;

        Simple_window win{ Point{100,100},xmax,ymax,"Aging Japan" };


        Axis x{ Axis::x, Point{xoffset, ymax-yoffset}, xlength, 
                (end_year-base_year) / 10, 
                "year    1960    1970     1980     1990     "
                "  2000      2010      2020      2030      2040" };
        x.label.move(-100, 0);
        //x.notches.set_color(Color::dark_red);
        win.attach(x);

        Axis y{ Axis::y, Point{xoffset, ymax - yoffset}, ylength, 10, "% of population" };
        //y.set_color(Color::red);
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