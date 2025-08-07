#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        a = 2;
        cout << "Hello" << endl;
    }
    A(int i)
    {
        a = i;
        cout << a << endl;
    }
    virtual ~A() { cout << "A : " << a << endl; }
    A set(int i)
    {
        a = i;
        return *this;
    }
    virtual int get() { return a; }
    A *add(A *x, A *y)
    {
        this->a = x->get() + y->get();
        return this;
    }
    virtual ostream &print() { return cout << a; }
};
ostream &operator<<(ostream &o, A &a)
{
    return a.print();
}
class B : public A
{
    int b;

public:
    B() : A(4)
    {
        b = 2;
        cout << b << endl;
    }
    B(int i, int j) : A(j)
    {
        b = i;
        cout << b << endl;
    }
    ~B() { cout << "B : " << *this << endl; }
    B set(int i)
    {
        b = i;
        return *this;
    }
    int get() { return b; }
    B *plusTwo()
    {
        set(get() + 2);
        return this;
    }
    ostream &print()
    {
        return cout << A::get() << " " << b;
    }
};
class C : virtual public B
{
    int c;

public:
    C()
    {
        c = 6;
        cout << c << endl;
    }
    ~C() { cout << "C : " << *this << endl; }
    C set(int i)
    {
        c = i;
        return *this;
    }
    int get() { return c; }
    C plus(B x)
    {
        c += x.get();
        return *this;
    }
    ostream &print()
    {
        B::print();
        return cout << " " << c;
    }
};
class D : virtual public B
{
    int d;

public:
    D() : B(8, 9)
    {
        d = 7;
        cout << d << endl;
    }
    ~D() { cout << "D : " << *this << endl; }
    D set(int i)
    {
        d = i;
        return *this;
    }
    int get() { return d; }
    ostream &print()
    {
        B::print();
        return cout << " " << d;
    }
};
class E : public C, public D
{
    int e;

public:
    E()
    {
        e = 1;
        cout << e << endl;
    }
    ~E() { cout << "E : " << *this << endl; }
    E set(int i)
    {
        e = i;
        return *this;
    }
    int get() { return e; }
    ostream &print()
    {
        C::print();
        return cout << " " << D::get() << " " << e;
    }
};
int main()
{
    A a;
    B b(2, 1);
    C c;
    D d;
    E e;
    cout << "c+b=" << c.plus(b).get() << endl;
    cout << "b+c=" << e.add(&b, &c)->get() << endl;
    cout << "e : " << e << endl;
    cout << "++d=" << d.plusTwo()->get() << endl;
    cout << "d : " << d << endl;
    cout << "... bye ..." << endl;
}