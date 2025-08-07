#include <iostream>
using namespace std;
class A
{
    int a;
    static int k;

public:
    A()
    {
        set(++k);
        cout << "Hello A" << endl;
    }
    A(int i)
    {
        set(i);
        ++k;
        cout << "AA ";
        show();
    }
    ~A()
    {
        cout << "~A ";
        show();
    }
    void set(int i) { a = i; }
    int get() { return a; }
    A plusTwo()
    {
        a = a + 2;
        return *this;
    }
    void show()
    {
        cout << "a = " << a << endl;
    }
};
class B : public A
{
    int b;

public:
    B()
    {
        set(2);
        cout << "B ";
        show();
    }
    B(A &a)
    {
        b = a.get();
        show();
    }
    ~B()
    {
        cout << "~B ";
        show();
    }
    void set(int i) { b = i; }
    int get() { return b; }
    void show()
    {
        cout << "b = " << b << endl;
    }
};
int A::k;
class C
{
    B **b;
    int n;

public:
    C()
    {
        n = 1;
        b = new B *[1];
        cout << "I like it" << endl;
        b[0] = new B;
        cout << "ha ha" << endl;
    }
    C(B **y, int n)
    {
        this->n = n;
        b = new B *[this->n];
        for (int i = 0; i < this->n; i++)
        {
            b[i] = new B;
            *b[i] = *y[i];
        }
    }
    ~C()
    {
        for (int i = 0; i < n; i++)
            delete b[i];
        delete[] b;
    }
    B *getB(int i) { return b[i]; }
};
int main()
{
    A a1;
    A a2(7);
    C c1;
    B *b1[3];
    c1.getB(0)->plusTwo().show();
    cout << "---wow---" << endl;
    b1[0] = new B(a1);
    b1[1] = new B(a2);
    b1[2] = new B;
    a1.plusTwo().plusTwo().show();
    a1.show();
    cout << "---hey---" << endl;
    C c2(b1, 3);
    delete b1[1];
    b1[1] = new B;
    b1[2]->set(4);
    for (int i = 0; i < 3; i++)
        cout << c2.getB(i)->get() << endl;
    for (int i = 0; i < 3; i++)
        delete b1[i];
    cout << "---finish--" << endl;
}