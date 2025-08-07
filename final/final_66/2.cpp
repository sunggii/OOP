#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        a = 5;
        cout << "A" << endl;
    }
    A(int i)
    {
        a = i;
        cout << "AA" << endl;
    }
    virtual ~A()
    {
        cout << "ByeA " << a << endl;
    }
    A *f1(A &x) { return x.f2(); }
    virtual A *f2()
    {
        a += 2;
        return this;
    }
    virtual int get() { return a; }
};
class B : public A
{
    int b;

public:
    B() : A(6)
    {
        b = 4;
        cout << "B" << endl;
    }
    B(int i, int j) : A(j)
    {
        b = i;
        cout << "BB" << endl;
    }
    ~B()
    {
        cout << "ByeB " << b << endl;
    }
    A *f2()
    {
        b += 3;
        A::f2();
        return this;
    }
    int get() { return b; }
    int operator[](int i)
    {
        return i ? get() : -1;
    }
};
class C : virtual public B
{
    int c;

public:
    C()
    {
        c = 3;
        cout << "C" << endl;
    }
    C(int i, int j) : B(i, i + j)
    {
        c = i;
        cout << "CC" << endl;
    }
    ~C() { cout << "ByeC " << c << endl; }
    A *f2()
    {
        c += 4;
        return this;
    }
    int get() { return c; }
};
class D : virtual public B
{
    int d;

public:
    D() : B(7, 8)
    {
        d = 2;
        cout << "D" << endl;
    }
    ~D() { cout << "ByeD " << d << endl; }
    A *f2()
    {
        d += 5;
        B::f2();
        return this;
    }
    int get() { return d; }
};
class E : public C, public D
{
    int e;

public:
    E()
    {
        e = 1;
        cout << "E" << endl;
    }
    ~E() { cout << "ByeE " << e << endl; }
    A *f2()
    {
        e += 6;
        return this;
    }
    int get() { return e; }
};
int main()
{
    A **p = new A *[4];
    C c(2, 3);
    p[0] = new A;
    p[1] = &c;
    p[2] = new B(3, 4);
    p[3] = p[1];
    A *d = new D;
    for (int i = 0; i < 4; i++)
    {
        cout << "result " << p[i]->get() << endl;
        cout << "sum " << p[i]->f2()->get() << endl;
    }
    E e;
    cout << "ha ha " << e.f1(*d)->get() << endl;
    /*cout << "x=" << c[3] << endl;
    delete p[0];
    delete d;
    A a;
    cout << "oh wow " << a.f1(*p[2])->get() << endl;
    delete p[2];
    delete[] p;*/
    cout << "Hello World" << endl;
}