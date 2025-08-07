#include <iostream>
using namespace std;
class A
{
    int a;

protected:
    A f1(int i)
    {
        a = i;
        return *this;
    };

public:
    A() { a = 0; }
    A(int i) { f1(i); }
    A f2(A i)
    {
        a = i.a;
        return *this;
    }
    int f3() { return a; }
    A f4(A &a, A b)
    {
        this-> a = a.f1(b.a).a;
        return *this;
    }
};
class B : public A
{
    int b;

protected:
    //int g1(B y) { return b = y.a; } //1
    B g2(int i)
    {
        f1(i);
        return *this;
    }

public:
    B() { b = 2; }
    B(int i, int j) : A(i) { b = j; }
    B g3(A a)
    {
        b = f2(a).f3();
        return *this;
    }
    A g4(int i, int j)
    {
        A a(i);
        return f4(a, A(j));
    }
    int g5() { return b; }
    B g6(B b)
    {
        this->b = b.b;
        //b.g2(2);
        return *this;
    }
};
class C : public B
{
    int c;

protected:
    int h1() { return c *= c; }

public:
    C() { h2(2); }
    C &h2(int i)
    {
        c = i;
        return *this;
    }
    C h3(B &b, A a)
    {
        //c = c.g2(a.f3()).g5();//2
        return *this;
    }
    void h4(C c) { h2(c.f3() + c.g5()); }
};
class D
{
    C c;

public:
    D k1(C c)
    {
        this->c.h4(c);
        return *this;
    }
    C k2() { return c; }
    B k3(int i) { return c.h2(i).g3(A(i)); }
    A k4(B &b)
    {
        return b.g6(b).g4(c.f3(), c.g5());
    }
    D k5(int i)
    {
        c.h2(i).g3(A(i)).f3();
        return *this;
    }
    friend int k6(C c, D &d);
};
int k6(C c, D &d)
{
    d.c = c;
    //return d.c.b;//3
    //return d.c.g5();
}
int main()
{
    A a;
    B b;
    C c;
    D d;
    cout << d.k1(c).k2().f2(a).f3() << endl;
    //cout << d.k5(b.f3()).k3(c.f3()) << endl; //4
    //เรา cout obj ไม่ได้อยู่แล้ว
    c.h2(b.g5()) = d.k2();
    b = c.g6(b);
    d = d.k5(c.h2(b.g5()).f3());
    a = d.k4(b).f2(a);
    //d.k3(c.f2(a)); //5
    cout << b.g6(c.g3(a)).g5() << endl;
}