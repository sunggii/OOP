#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        a = 1;
        cout << "A" << endl;
    }
    ~A() { cout << "bye A " << (*this)() << endl; }
    A operator+(A &p)
    {
        A x;
        x() = a + p.a;
        return x;
    }
    int &operator()()
    {
        cout << "get " << a << endl;
        return a;
    }
    A operator!()
    {
        a--;
        return *this;
    }
    friend ostream &operator<<(ostream &os, A &a)
    {
        os << "a=" << a.a;
        return os;
    }
};
class B
{
    A a[2];

public:
    B() { a[0]() = 3; }
    B(B &b) { *this = b; }
    ~B() { cout << "all died" << endl; }
    A &getA(int i) { return a[i]; }
    B &operator=(B &x)
    {
        if (&x == this)
            return *this;
        a[0] = x.a[1];
        a[1] = x.a[0];
        cout << "operator=" << endl;
        return *this;
    }
};
int main()
{
    A a;
    a() = 5;
    B b;
    cout << b.getA(0) << endl;
    B c(b);
    cout << "!b.a[1] " << (!b.getA(0))() << endl;
    cout << "sum " << (c.getA(0) + c.getA(1))() << endl;
    cout << "bye bye OOP" << endl;
}