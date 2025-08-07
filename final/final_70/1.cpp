#include <iostream>
using namespace std;
class A
{
    int a;

protected:
    A f1(int x)
    {
        a = x;
        return *this;
    }

public:
    A() { f1(4); }
    int f2(int i) { return a = i; }
    int f3(A &a) { return this->a = a.a + 1; }
    operator int() { return (*this)(); }
    int operator()() { return a; }
};
class B : public A
{
    int b;

protected:
    A *f4(int i)
    {
        b = i;
        return this;
    }

public:
    B() { f4(3)->f2(5); }
    B(int i) { b = i; }
    A *f5()
    {
        //f1(b).f4(b + 1); //1
        return this;
    }
    B *f6(A x)
    {
        b = x + 3;
        return this;
    }
    int f7(B *y) { return b = y->f3(*this); }
    int f8(int i)
    {
        *this = i;
        return b;
    }
    A f9(int i)
    {
        b = i + 20;
        //return b; //2
    }
    int f10()
    {
        b++;
        return *this;
    }
    B f11(int i) { return f2(i); }
};
class C : public B
{
    int c;

protected:
    A *g1(int i)
    {
        c = i;
        return this;
    }

public:
    C() { f8(g1(7)->f2(8)); }
    C(B b) { c = b(); }
    C g2(A a)
    {
        c = a;
        return *this;
    }
    A *g3(C x) { return x.f4(c); }
    //A g4(B y) { return y.f1(c); } //3
    B *g5(A *x) { return f6(*x); }
    //A g6(int i) { return f11(i).f1(i); } //4
    int g7(int i) { return f1(i)(); }
    operator A() { return f1(c); }
    friend C hiFriend(B);
};
C hiFriend(B b)
{
    int i;
    C y;
    //i = b.f4(5)->f2(6); //5
    y.c = b.f2(b() + 5);
    y.f1(i);
    return y;
}
int main()
{
    A a;
    B b;
    C c(b);
    cout << c.g5(&a)->f11(a())() << endl;
    //cout << c.g2(a).f10().f2(1) << endl; //6
    cout << c.f6(a)->f7(&c) << endl;
    int i = b.f11(c())();
    //cout << c.g2(b.f3(a))() << endl; //7
    C c2;
    cout << c2.f6(c)->f2(i) << endl;
    cout << a + b + c << endl;
    //cout << b.f7(c.g5(c.g2(a))) << endl; //8
    i = b.f10() * c;
    //cout << b.g2(a).f11(i).f2(i + 1) << endl; //9
    cout << c2.g2(c)() << endl;
    i += c2.g7(b);
    //a = c.f7(&b); //10
}