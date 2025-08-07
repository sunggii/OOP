#include <iostream>
using namespace std;
class A
{
    int a;

public:
    A()
    {
        a = 3;
        cout << "A " << a << endl;
    }
    A(int i)
    {
        a = i;
        cout << "AA " << a << endl;
    }
    virtual ~A() { cout << "a= " << a << endl; }
    virtual A *set(int i)
    {
        a = i;
        return this;
    }
    A plus1()
    {
        a++;
        return *this;
    }
    virtual int get() { return a; }
};
class B : virtual public A
{
    int b;

public:
    B() : A(3)
    {
        b = 2;
        cout << "B " << b << endl;
    }
    B(int i)
    {
        b = i;
        cout << "BB " << b << endl;
    }
    ~B() { cout << "b= " << b << endl; }
    A *set(int i)
    {
        b = i;
        return this;
    }
    int get() { return b; }
    B plus2()
    {
        b += 2;
        plus1();
        return *this;
    }
};
class C : virtual public A
{
    int c;

public:
    C()
    {
        c = 2;
        cout << "C " << c << endl;
    }
    ~C() { cout << "c= " << c << endl; }
    A *set(int i)
    {
        c = i;
        return this;
    }
    int get() { return c; }
    C plus3()
    {
        c += 3;
        plus1();
        return *this;
    }
};
class D : public B, public C
{
    int d;

public:
    D() : A(7), B(8)
    {
        d = 1;
        cout << "D " << d << endl;
    }
    ~D() { cout << "d= " << d << endl; }
    A *set(int i)
    {
        d = i;
        return this;
    }
    int get() { return d; }
    D plus4()
    {
        d += 4;
        plus3();
        B::set(B::get() + 2);
        return *this;
    }
    void show()
    {
        cout << d << " " << C::get() << " ";
        cout << B::get() << " " << A::get() << endl;
    }
};
int main()
{
    A *m[4] = {new A, new B, new C, new D};
    for (int i = 0; i < 4; i++)
    {
        cout << "m[" << i << "] ";
        cout << m[i]->set(i)->get() << endl;
    }
    D d;
    d.plus4().show();
    cout << "--- delete ---" << endl;
    for (int i = 0; i < 4; i++)
        delete m[i];
    cout << "... bye ..." << endl;
}