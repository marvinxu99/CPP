#include <iostream>
#include <string>
using namespace std;

struct Link
{
    string value;
    Link *prev;
    Link *succ;
    Link(const string &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}
};

Link *insert(Link *p, Link *n) // insert n before p; return n
{
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;

    n->succ = p; // p comes after n
    if (p->prev)
        p->prev->succ = n;
    n->prev = p->prev; // p’s predecessor becomes n’s predecessor
    p->prev = n;       // n becomes p’s predecessor

    return n;
}

int main()
{
    cout << "Norse gods:" << endl;

    Link *norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Freia"});

    while (norse_gods)
    {
        cout << norse_gods->value << endl;
        norse_gods = norse_gods->succ;
    }

    return 0;
}