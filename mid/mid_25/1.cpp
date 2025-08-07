#include <iostream>
using namespace std;

class A
{
    int a;

protected:
    int f1(int i)
    {
        a += i;
        return a;
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
    A f2(A &a)
    {
        return A(this->a + a.a);
    }
    int f3() { return a * a; }
};

class B : public A
{
    int b1;

protected:
    int b2;
    int f4(int i) { return f1(i); }

public:
    B() { b1 = b2 = 2; }
    B(int i, int j) : A(i + j)
    {
        b1 = i;
        b2 = j;
    }
    B f5(A a)
    {
        set(a.f3());
        return *this;
    }
    void f6(B b) { b2 = b.f4(1); }
    B set(int i)
    {
        b1 = i;
        return *this;
    }
};

class C : public B
{
    B b;

protected:
    //int f7(int i) { return b.f4(i); }//1
    int f8() { return b.f3() + 1; }

public:
    C() { b.set(3); }
    //int g1(int i) { return b.f1(i); }//2
    B g2(A a) { return b.set(a.get()); }
    int g3(A a) { return b.f5(a).get(); }
    friend void g5(A a);
};

void g5(A k)
{
    B b;
    // b.set(k.a);//3
    C c;
    c.b = b.f5(k);
    // c.b.b2=k.get(); //4
    cout << c.b.get() << endl;
}

int main()
{
    A a;
    cout << a.set(6).get() << endl;
    B b(1, 2);
    cout << b.f5(a).set(a.get()).get() << endl;
    C c;
    cout << c.g2(a).set(b.get()).f3() << endl;
    // cout<<b.set(c.g3(a)).f2(a)<<endl;//5
    cout << c.g3(b.f2(a)) << endl;
}