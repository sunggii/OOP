#include <iostream>
using namespace std;
class A
{
    int a;

protected:
    A plus()
    {
        a++;
        return *this;
    };

public:
    A() { a = 1; }
    A(int i) { set(i); }
    A set(int i)
    {
        a = i;
        return *this;
    }
    int get() { return a; }
    A add(A x) { return A(a + x.a); }
    friend int g(A x);
};
class B
{
    int b;

protected:
    int f1(A a) { return a.add(a).get() + b; }

public:
    B() { b = 2; }
    //A f2(A a) { return a.plus(); } //1
    A f3() { return A(b); }
    B *f4(int y)
    {
        this->b = y;
        return this;
    }
    B f5(B y)
    {
        b = y.b;
        return *this;
    }
    A f6() { return A(b++); }
};
class C : public A
{
    B b;

protected:
    B g1()
    {
        b.f6();
        return b;
    }

public:
    C(int i) { b.f4(i); }
    C g2(A a)
    {
        //add(b.f1(a)); //2
        return *this;
    }
    A g3(int i)
    {
        return add(A(plus().get() + i));
    }
    B g4()
    {
        g1().f5(b);
        return b;
    }
    A g5(int i) { return b.f4(i)->f6(); }
    A g6(A a) { return set(a.get()); }
    friend int g(A x);
};
int g(A x)
{
    C c(1);
    int i;
    i = x.add(c.g1().f3()).a;
    i += x.a + c.b.f6().a;
    //return c.g4().b.a;3
}
int main()
{
    A a;
    B b;
    C c(3);
    a = c.g6(b.f3());
    int i;
    i = c.set(b.f6().get()).add(a).get();
    //a = c.g5(b.f4(i)->get()); //4
    a.set(b.f5(c.g4()).f4(a.get())->f3().get());
    //a = c.g3(b.f4(i)->f5(b).f6()); //5
    c.g4().f5(b).f4(a.set(i).get());
}