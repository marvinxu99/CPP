#include "std_lib_facilities.h"

struct B
{
	virtual void f() const { cout << "B::f "; }
	void g() const { cout << "B::g "; } // not virtual
};

struct D : B
{
	void f() const { cout << "D::f "; } // overrides B::f
	void g() { cout << "D::g "; }
};

struct DD : D
{
	void f() { cout << "DD::f "; } // doesn�t override D::f (not const)
	void g() const { cout << "DD::g "; }
};

void call(const B &b)
// a D is a kind of B, so call() can accept a D
// a DD is a kind of D and a D is a kind of B, so call() can accept a DD
{
	b.f();
	b.g();
}

// Using "override" to explicitly declare that a function is meant to override.
// struct B
// {
// 	virtual void f() const { cout << "B::f "; }
// 	void g() const { cout << "B::g "; } // not virtual
// };
// struct D : B
// {
// 	void f() const override { cout << "D::f "; } // overrides B::f
// 	void g() override { cout << "D::g "; }		 // error: no virtual B::g to override
// };
// struct DD : D
// {
// 	void f() override { cout << "DD::f "; } // error: doesn’t override
// 	// D::f (not const)
// 	void g() const override { cout << "DD::g "; } // error: no virtual D::g
// 	// to override
// };

int main()
{
	B b;
	D d;
	DD dd;

	call(b);  // B::f B::g
	call(d);  // D::f B::g
	call(dd); // D::f B::g

	b.f(); // B::f B::g
	b.g();

	d.f(); // D::f D::g
	d.g();

	dd.f(); // DD::f DD::g
	dd.g();
}