#include <iostream>
using namespace std;

class A
{
    double a;

public:
    A() { setA(5.5); show(); }
    A(double i) { setA(i); show(); }
    ~A() { cout << "A" << endl; }
    void setA(double i) { a = i; }
    double getA() { return a; }
    void show() { cout << "a=" << a << endl; }
};

class B
{
    A a;

public:
    B() { a.setA(2.2); show(); }
    B(A a) { this->a = a; }
    B(double i) { a.setA(i); }
    ~B() { cout << "B" << endl; }
    void set(double i) { a.setA(i); }
    A get() { return a; }
    void show() { cout << "in B "; a.show(); }
    B &plusPlus()
    {
        set(a.getA() + 1);
        return *this;
    }
};

class C
{
    B b;

public:
    C() { b.set(1.1); }
    C(A a) { b.set(a.getA()); }
    ~C() { cout << "C" << endl; }
    void set(double i) { b.set(i); }
    B get() { return b; }
    C &plus(C &c)
    {
        b.set(c.b.get().getA() + b.get().getA());
        return *this;
    }
};

int main()
{
    C c2;
    cout << "c2 = " << c2.get().get().getA() << endl;
    cout <<"-------------------- "<<endl;
    return 0;
}
