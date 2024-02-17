// 10-throw2.cpp : throw and catch exceptions from within and outside std::exception hierarchy
 
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
 

class FatalError : public runtime_error 
{
private:    
    int m_error_code;

public:
    FatalError(const int error_code) : runtime_error{"Fatal Error"}, m_error_code(error_code) {}

    int getRC() {
        return m_error_code;
    }

};


int throwing() {
    cout << 1+R"(
Please choose:
    1) throw std::runtime_error
    2) throw std::exception
    3) throw int
    4) throw FatalError
    5) quit
Enter 1-5: )";
    int option;
    cin >> option;
    switch(option) {
    case 1:
        throw runtime_error{"std::runtime_error thrown"};
    case 2:
        throw exception{};
    case 3:
        throw 99;
    case 4:
        throw FatalError{4};
    case 5:
        return 1;
    default:
        cout << "Error: unrecognized option\n";
    }
    return 0;
}
 
int main() {
    for (;;) {
        int action{};
        try {
            action = throwing();
        }
        catch (FatalError& e) {
            cerr << "FatalError = (" << e.what() << ", error_code = " << e.getRC() << ")\n";
        } catch (runtime_error& e) {
            cerr << "Caught std::runtime_error! (" << e.what() << ")\n";
        }
        catch (exception& e) {
            cerr << "Caught std::exception: " << e.what() << endl;
        }
        catch (int& e) {
            cerr << "Caught int exception: " << e << endl;
        }
        catch (...) {
            cerr << "Caught something other than std::exception! Quitting.\n";
            return 1;
        }
        if (action) {
            break;
        }
    }
}
