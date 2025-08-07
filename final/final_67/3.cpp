#include <iostream>
using namespace std;
class A
{
    static int count;
    int x;
    int y;

public:
    A()
    {
        x = ++count;
        y = 1;
        cout << *this;
    }
    A(int i)
    {
        x = ++count;
        y = i;
        cout << *this;
    }
    A(A &a)
    {
        x = ++count;
        y = a.y;
        cout << "copy A " << x << " " << y << endl;
    }
    ~A() { cout << "~A " << x << " " << y << endl; }
    void operator()()
    {
        cout << "x = " << x << " y = " << y << endl;
    }
    A &operator()(int i)
    {
        y += i;
        return *this;
    }
    A f1(A a)
    {
        y += a.y;
        return *this;
    }
    bool operator==(const A &x)
    {
        cout << "A::operator==" << endl;
        if (y == x.y)
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &os, A &a)
    {
        a();
        return os;
    }
};
int A::count;
class B
{
    A *a[2];

public:
    B()
    {
        cout << "create B()" << endl;
        a[0] = new A(2);
        a[1] = new A(3);
    }
    B(A *h, A *k)
    {
        cout << "create B(A*, A*)" << endl;
        a[0] = h;
        a[1] = k;
    }
    ~B()
    {
        cout << "B die" << endl;
        for (int i = 0; i < 2; i++)
            delete a[i];
    }
    A **getA() { return a; }
    A *operator[](int i)
    {
        cout << "B::operator[]" << endl;
        if (i == 0)
            return a[0];
        else
            return a[1];
    }
    bool operator==(B &y)
    {
        if (*a[0] == *y[0] && *a[1] == *y[1])
            return true;
        else
            return false;
    }
};
int main()
{
    A *a1 = new A;
    A *a2 = new A(4);
    B b1;
    B b2(a1, a2);
    for (int i = 0; i < 2; i++)
        cout << *b2[i];
    cout << "b1[0] " << (*b1.getA()[0])(5);
    b2[1]->f1(*b1[1]);
    if (b1 == b2)
        cout << "b1==b2" << endl;
    else
        cout << "b1!=b2" << endl;
    cout << "===== The End =====" << endl;
}