/*
    Simple calculator

    Revision history:
        Revised by Bjarne Stroustrup November 2013
        Revised by Bjarne Stroustrup May 2007
        Revised by Bjarne Stroustrup August 2006
        Revised by Bjarne Stroustrup August 2004
        Originally written by Bjarne Stroustrup
            (bs@cs.tamu.edu) Spring 2004.

    This program implements a basic expression calculator.
    Input from cin; output to cout.
    The grammar for input is:

    Statement:
        Expression
        Print
        Quit

    Print:
        ;

    Quit:
        q

    Expression:
        Term
        Expression + Term
        Expression – Term

    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary

    Primary:
        Number
        ( Expression )
        – Primary
        + Primary

    Number:
        floating-point-literal

    Input comes from cin through the Token_stream called ts.
*/

#include "std_lib_facilities.h"

const char NUMBER = '8'; // t.kind==number means that t is a number Token
const char QUIT = 'q';   // t.kind==quit means that t is a quit Token
const char PRINT = ';';  // t.kind==print means that t is a print Token
const string PROMPT = "> ";
const string RESULT = "= "; // used to indicate that what follows is a result

class Token
{ // a very simple user-defined type
public:
    char kind;    // what kind of token
    double value; // for numbers: a value
};

class Token_stream
{
public:
    Token get();           // get a Token (get() is defined in §6.8.2)
    void putback(Token t); // put a Token back
    void ignore(char c);   // discard characters up to and including a c
private:
    bool full{false}; // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer = t;  // copy t to buffer
    full = true; // buffer is now full
}

void Token_stream::ignore(char c)
// c represents the kind of Token
{
    // first look in buffer:
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

Token Token_stream::get()
{
    if (full)
    {                 // do we already have a Token ready?
        full = false; // remove Token from buffer
        return buffer;
    }
    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)
    switch (ch)
    {
    case PRINT: // for “print”
    case QUIT:  // for “quit”
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return Token{ch}; // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch); // put digit back into the input stream
        double val;
        cin >> val;                // read a floating-point number
        return Token{NUMBER, val}; // let ‘8’ represent “a number”
    }
    default:
        error("Bad token");
    }
}

Token_stream ts;
double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(': // handle ‘(‘ expression ‘)’
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return d;
    }
    case NUMBER:        // we use ‘8’ to represent a number
        return t.value; // return the number’s value
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        // case '%':    // prohibit the use of % on a floating-point argument. We check if the floating-point operands have
        // fractional parts and give an error message if they do.
        // {
        //     int i1 = narrow_cast<int>(left);
        //     int i2 = narrow_cast<int>(primary());
        //     if (i2 == 0)
        //         error("%: divide by zero");
        //     left = i1 % i2;
        //     t = ts.get();
        //     break;
        // }
        default:
            return left;
        }
    }
}

double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get();   // get the next token from the Token stream
    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            return left; // finally: no more + or –; return the answer
        }
    }
}

void clean_up_mess() // naive
{
    ts.ignore(PRINT);
}

void calculate() // expression evaluation loop
{
    while (cin)
        try
        {
            cout << PROMPT;
            Token t = ts.get();

            while (t.kind == PRINT)
                t = ts.get(); // first discard all “prints”

            if (t.kind == QUIT)
                return;

            ts.putback(t);
            cout << RESULT << expression() << '\n';
        }
        catch (exception &e)
        {
            cerr << e.what() << '\n'; // write error message
            clean_up_mess();
        }
}

int main()
try
{
    cout << "Welcome to our simple calculator." << endl
         << "Please enter expressions using floating-point numbers."
         << endl;

    calculate();
    keep_window_open();
    return 0;
}
catch (exception &e)
{
    cerr << e.what() << '\n';
    keep_window_open("~~"); // keep_window_open():
    // cout << "Please enter the character ~ to close the window\n";
    // for (char ch; cin >> ch;) // keep reading until we find a ~
    //     if (ch == '~')
    //         return 1;
    return 1;
}
catch (...)
{
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}
