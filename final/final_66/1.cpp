#include <iostream>
using namespace std;
class B;
class A
{
    int a;

protected:
    int f1(int i) { a = i; }

public:
    A() { a = 0; }
    A(int x) { a = x; }
    A f2(int i)
    {
        a = i;
        return *this;
    }
    int f3() { return a; }
    A operator+(A &x) { return a + x.a; }
    A f4(int a) { return A(a + 5); }
    operator int() { return f3(); }
    friend A f(B &, A &);
};
class B
{
    A aa;

protected:
    B g1(int x)
    {
        aa = x;
        return *this;
    }

public:
    B() { aa.f2(4); }
    B(A x) { aa = x; }
    //void g2(A x) { aa.a = x.a; }  //1
    int g3(B y) { return aa + y.aa; }
    B g4(int x)
    {
        aa = x;
        return *this;
    }
    A g5(B y, int i) { return A(y.aa.f2(i)); }
    B g6(int i)
    {
        //aa.f4(i).f1(i);  //2
        return *this;
    }
    A g7() { return aa; }
};
A f(B &y, A &x)
{
    int i = x.a;
    A a = y.g7() + i;
    //return a + y.g1(i).g7();  //3
}
class C
{
    B b;

protected:
    int h1(B y, int i)
    {
        return b.g5(y, i) + 1;
    }

public:
    A h2(int i, int j)
    {
        return b.g4(i).g3(b) + j;
    }
    B h3(A x)
    {
        return B(b.g5((*this).b, x.f3()));
    }
    C h4(B y)
    {
        int i = b.g3(y);
        h1(y, i);
        return *this;
    }
    int h5(A x) { return h1(b, x); }
    int h6(A x, B y)
    {
        //return x.f3() + y.b.f3();  //4
    }
    B &h7() { return b; }
    operator B() { return b; }
};
class D : public C
{
    int d;

public:
    D() { d = 3; }
    B r1(int i) { return h7().g4(i); }
    B r2(A x, B y)
    {
        return h3(x + y.g5(*this, x));
    }
    C r3(C x) { return h4(x); }
    A r4(int i)
    {
        //return h2(h7().f3(), i);  //5
    }
};
int main()
{
    A a;
    a.f2(3);
    B b;
    cout << b.g4(6).g7() << endl;
    cout << b.g5(B(a), 8).f3() << endl;
    C c;
    int i = c.h4(b).h2(a, b.g7());
    //C c2 = b.g4(i);  //6
    b = c.h4(b);
    D d;
    //A a2 = d.r3(c).h3(b.g7()).g4(i);  //7
    cout << d.r2(a, c).g3(b) << endl;
    //a2 = d.r1(a.f3()).f4(i);  //8
    i += c.h7().g5(b, 2);
    //cout << d.h3(c.h2(a, c.h7().g7())) << endl;  //9
    //cout << d.g5(b, i).f3() << endl;  //10
    cout << c.h3(9).g3(b) << endl;
}