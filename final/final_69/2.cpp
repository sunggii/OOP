#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        a = 4;
        cout << "hi A" << endl;
    }
    A(int i)
    {
        a = i;
        cout << "hi AA" << endl;
    }
    virtual ~A()
    {
        cout << "a = " << a << endl;
    }
    A *f1(int i) { return cal(i); }
    virtual A *cal(int i)
    {
        a += i;
        return this;
    }
    virtual int get() { return a; }
    int operator!() { return get(); }
};
class B : virtual public A
{
    int b;

public:
    B()
    {
        b = 2;
        cout << "hello B" << endl;
    }
    B(int i) : A(i + 1)
    {
        b = i;
        cout << "hello BB" << endl;
    }
    ~B() { cout << "b = " << b << endl; }
    A *cal(int i)
    {
        b *= i;
        return this;
    }
    int get() { return b; }
};
class C : virtual public A
{
    int c;

public:
    C() : A(5)
    {
        c = 1;
        cout << "hey C" << endl;
    }
    C(int i, int j) : A(j)
    {
        c = i;
        cout << "hey CC" << endl;
    }
    ~C() { cout << "c = " << c << endl; }
    A *cal(int i)
    {
        c -= i;
        return this;
    }
    int get() { return c; }
};
class D : public B, public C
{
    int d;

public:
    D() : C(7, 8), B(9)
    {
        d = 1;
        cout << "D" << endl;
    }
    ~D() { cout << "d = " << d << endl; }
    A *cal(int i)
    {
        d += i + i;
        return this;
    }
    int get() { return d; }
    void show()
    {
        cout << A::get() << endl;
        cout << B::get() << endl;
        cout << C::get() << endl;
        cout << get() << endl;
    }
};
class E
{
    A **a;
    D *d;
    ;

public:
    E() { a = new A *[3]; }
    ~E() { delete[] a; }
    A *&operator[](int i)
    {
        cout << "[]" << endl;
        return a[i];
    }
    D operator()(D *d)
    {
        cout << "d in E" << endl;
        this->d = d;
        return *(this->d);
    }
    D get() { return *d; }
};

int main()
{
    B b(8);
    C c(5, 6);
    D d;
    E e;
    e[0] = &b;
    e[1] = &c;
    e[2] = &d;
    for (int i = 0; i < 3; i++)
        cout << !*e[i] << endl;
    D *d2 = new D;
    cout << d2->cal(3)->get() << endl;
    e(d2).show();
    for (int i = 0; i < 3; i++)
        cout << !*(e[i]->f1(i)) << endl;
    delete d2;
    cout << "Hello OOP" << endl;
}