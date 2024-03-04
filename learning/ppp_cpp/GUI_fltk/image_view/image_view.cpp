#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_box.H>
#include <FL/Fl_JPEG_Image.H>
#include <string>
#include <exception>
#include <iostream>
using namespace std;


class ImageView {
public:
    ImageView(const std::string& filename, int x, int y, int width, int height)
        : x_(x), y_(y), width_(width), height_(height) {
        load(filename);
    }

    void show() {
        if (!image_) {
            // Error handling: Image not loaded
            cout << "Error: Image not loaded" << std::endl;
            return;
        }

        window_ = new Fl_Window(width_, height_);
        box_ = new Fl_Box(x_, y_, width_, height_);
        box_->image(image_);
        window_->end();
        window_->show();
    }

private:
    void load(const std::string& filename) {
        image_ = new Fl_JPEG_Image(filename.c_str());
        if (!image_) {
            // Error handling: Failed to load image
            cout << "Error: Failed to load image" << std::endl;
            return;
        }
    } 

    Fl_JPEG_Image* image_;
    Fl_Window* window_;
    Fl_Box* box_;
    int x_;
    int y_;
    int width_;
    int height_;
};


int main() 
try {
    // Create an ImageView instance to display a JPEG image
    ImageView imageView("Winter and tennis.JPG", 0, 0, 600, 600);
    imageView.show();

    // Run the FLTK event loop
    return Fl::run();
}
catch (exception e) {
    cout << "Error: " << e.what() << endl;
}