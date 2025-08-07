#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        a = 0;
        cout << "A " << a << endl;
    }
    A(int i)
    {
        a = i;
        cout << "AA " << a << endl;
    }
    virtual ~A() { cout << "a=" << a << endl; }
    virtual A *operator++()
    {
        a += 3;
        return this;
    }
    void hello()
    {
        cout << "hello " << world() << endl;
    }
    virtual int world() { return a; }
    string hi() { return "hi"; }
    A *plus() { return ++*this; }
};
class B : virtual public A
{
    int b;

public:
    B()
    {
        b = 1;
        cout << "B " << b << endl;
    }
    B(int i) : A(4)
    {
        b = i;
        cout << "BB " << b << endl;
    }
    ~B() { cout << "b=" << b << endl; }
    int world() { return b; }
    virtual string hi() { return "ha ha"; }
    A *operator++()
    {
        b += 4;
        return this;
    }
};
class C : virtual public A
{
    int c;

public:
    C()
    {
        c = 2;
        cout << "C " << c << endl;
    }
    C(int i, int j) : A(i)
    {
        c = j;
        cout << "CC " << j << endl;
    }
    ~C() { cout << "c=" << c << endl; }
    int world() { return c; }
    string hi() { return "555"; }
    A *operator++()
    {
        c += 5;
        return this;
    }
};
class D : public B, public C
{
    int d;

public:
    D()
    {
        d = 3;
        cout << "D " << d << endl;
    }
    ~D() { cout << "d=" << d << endl; }
    int world() { return d; }
    string hi() { return "la la"; }
    A *operator++()
    {
        d += 1;
        return this;
    }
};
class E
{
    B *b;
    int e;

public:
    E()
    {
        e = 0;
        b = 0;
    }
    E(B *i, int j)
    {
        e = j;
        b = i;
    }
    ~E() { cout << "e=" << e << endl; }
    E set(B *b)
    {
        this->b = b;
        return *this;
    }
    string hi() { return b->hi(); }
    B *getB() { return b; }
};
int main()
{
    A *a;
    B *b = new B(7);
    E *e = new E(b, 9);
    cout << e->hi() << endl;
    e->getB()->hello();
    a = new D;
    a->hello();
    cout << a->hi() << endl;
    delete b;
    b = new D;
    b->hello();
    cout << b->hi() << endl;
    e->set(b);
    cout << e->getB()->plus()->world() << endl;
    delete a;
    a = new C(5, 6);
    cout << (++*a)->world() << endl;
    delete b;
    delete e;
    delete a;
}