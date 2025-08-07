#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        setA(3);
        show();
    }
    A(int i)
    {
        setA(i);
        cout << "AA ";
        show();
    }
    ~A()
    {
        cout << "~A ";
        show();
    }
    A &setA(int i)
    {
        a = i;
        return *this;
    }
    int getA() { return a; }
    A square() { return A(a * a); }
    A addTwo()
    {
        cout << "addTwo" << endl;
        a += 2;
        return *this;
    }
    void show()
    {
        cout << "a=" << a << endl;
    }
};
class B : public A
{
    static int k;
    int id;
    int b;

public:
    B()
    {
        id = ++k;
        b = 1 + getA();
        cout << "B ";
        show();
    }
    B(int a)
    {
        cout << "BB ";
        b = k;
        id = ++k;
        setA(a).show();
        show();
    }
    ~B()
    {
        cout << "~B ";
        show();
    }
    B &setB(int i)
    {
        b = i;
        return *this;
    }
    int getB() { return b; }
    void show()
    {
        cout << "id=" << id << " b=" << b << endl;
    }
    B &addThree()
    {
        cout << "addThree" << endl;
        b += 3;
        return *this;
    }
};
int B::k;
class C : public B
{
    int c;

public:
    C()
    {
        c = 2;
        show();
    }
    C(B x, int k)
    {
        c = x.getA() + x.getB();
        setB(k).show();
        setA(k + 1).show();
        show();
    }
    ~C() { cout << "~C " << c << endl; }
    C &setC(int i)
    {
        c = i;
        return *this;
    }
    int getC(int i) { return c; }
    void show()
    {
        cout << "c=" << c << endl;
    }
};
int main()
{
    A a1;
    A a2(4);
    B b1;
    B b2(2);
    C c1(b1, 5);
    C c2;
    c2.setC(6).setB(5).setA(8).show();
    c2.addThree().addTwo().show();
    b1.addTwo().setA(9);
    cout << "b1=" << b1.getA() << endl;
    a2.square().show();
    cout << "a2=" << a2.getA() << endl;
    cout << "---Bye---" << endl;
}