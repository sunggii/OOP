#include <iostream>
using namespace std;
class A
{
    int a;

protected:
    int f1() { a += a; }

public:
    A() { a = 1; }
    A(int a) { this->a = a; } //ไม่มีก็ this-> ก็ไม่ error
    A f2(A a)
    {
        return A(a.a + this->a);
    }
    A f3(int n)
    {
        for (int i = 0; i < n; i++)
            f1();
        return *this;
    }
    int f4() { return a; }
};

class B : public A
{
    int b;

protected:
    int g1(A x) { b = x.f4(); }

public:
    B() { b = 5; }
    B(int b) : A(b) { this->b = b; }

    // void g2(A a) { this->a=a; }//1

    B g3(B y)
    {
        b = y.b;
        return B(b);
    }
    A g4(int k)
    {
        b = k;
        return *this;
    }
    A g5(A x) { return f2(x); }
};

class C : public B
{
    int c;

protected:
    C h1(int k)
    {
        c = k;
        return *this;
    }

public:
    C() { c = f1(); }
    C(int x, int y) : B(x) { c = y; }
    C h2(B *x) { return h1(g3(*x).f4()); }
    //C h2(B *x) { return h1(g3(x).f4()); } ระวังโดนดักแบบนี้

    C h3(C x, B y)
    {
        c = x.c;
        g1(y);
        return *this;
    }
    // C h4(B b, int i) { return b.h1(i);} //2
    // A h5(B y, A x) { return g4(y.g1(x)); } //3
    int &h6() { return c; }
};

int main()
{
    A a(4);
    B b(2);
    C *c;
    cout << a.f3(b.g4(1).f4()).f4() << endl;
    int k = b.g5(a).f3(9).f4();
    A d = c->h2(&b).f2(a);
    // k = c->h3(*c).g1(a);
    d = c->g3(b).f2(a.f3(1));
    c->h6() = b.g3(c->g3(b)).f4();
    // cout<<c->g5(d.f2(a)).g3(b).f4()<<endl;
}