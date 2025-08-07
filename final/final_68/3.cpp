#include <iostream>
using namespace std;
class A
{
    int a;
    int b;

public:
    A()
    {
        a = b = 1;
        cout << *this << endl;
    }
    A(int i, int j)
    {
        a = i;
        b = j;
    }
    A(A &x)
    {
        (*this)(x.a, x.b + 1);
        cout << "hey" << endl;
    }
    ~A() { cout << "~A " << *this << endl; }
    A &operator()(int i, int j)
    {
        cout << "hi" << endl;
        a = i;
        b = j;
        return *this;
    }
    int operator[](int i)
    {
        if (i == 1)
            return a;
        else
            return b;
    }
    friend ostream &operator<<(ostream &os, A &a)
    {
        os << "a=" << a.a << " b=" << a.b;
        return os;
    }
};
class B
{
    A s;
    A t;

public:
    B()
    {
        s(2, 3);
        t(4, 5);
    }
    B(A x, A y)
    {
        cout << "hello" << endl;
        s = x;
        t = y;
    }
    ~B() { cout << "~B" << endl; }
    friend ostream &operator<<(ostream &os, B &b)
    {
        os << b.s << endl
           << b.t;
        return os;
    }
    A getS() { return s; }
    A &getT() { return t; }
};
int main()
{
    A x;
    A y(4, 5);
    cout << x[1] + y[2] << endl;
    B p;
    B q(x, y);
    cout << q.getS()(7, 8) << endl;
    /*cout << p.getT()(12, 13) << endl;
    cout << p << endl;
    cout << q << endl;*/
    cout << "---- End Program -----" << endl;
}