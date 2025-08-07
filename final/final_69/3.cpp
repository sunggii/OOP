#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        a = 1;
        cout << *this << endl;
    }
    A(int i)
    {
        a = i;
        cout << "A" << endl;
    }
    A(A &x)
    {
        a = 0;
        (*this)((x.a != 0) ? "Hello" : "");
    }
    ~A()
    {
        cout << "~A " << *this << endl;
    }
    int operator()(string s)
    {
        cout << s << endl;
        a += (s != "") ? 10 : 1;
        return a;
    }
    int operator[](int i) { return a * i; }
    A &operator=(A &x)
    {
        if (this == &x)
            return *this;
        a = x.a + 1;
        cout << "operator=" << endl;
    }
    friend ostream &operator<<(ostream &os, A &a)
    {
        os << "a=" << a.a;
        return os;
    }
};
class B
{
    A s;

public:
    B() { s("Good Morning"); }
    B(B &y) { s = y.s; }
    ~B() { cout << "~B " << endl; }
    int operator[](string n)
    {
        return s(n);
    }
    friend ostream &operator<<(ostream &os, B &b)
    {
        os << b.s;
        return os;
    }
    A getS() { return s; }
    B &setS(A &x)
    {
        s = x;
        return *this;
    }
};
int main()
{
    A a1;
    A a2(5);
    cout << "a2=" << a2("OOP") << endl;
    A a3 = a1;
    cout << a3[2] << endl;
    B b1;
    B b2(b1);
    cout << b1.setS(a2).getS()("hi") << endl;
    cout << b2["I like OOP"] << endl;
    cout << b2 << endl;
}

//output------------------
/*a=1
A
a2=OOP
15
Hello
20
a=1
Good Morning
a=1
operator=
operator=
Hello
hi
20
~A a=20
I like OOP
22
a=22
~B 
~A a=22
~B 
~A a=16
~A a=10
~A a=15
~A a=1*/
//------------------------