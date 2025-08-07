#include <iostream>
using namespace std;
class A
{
    string a;

public:
    A()
    {
        set("hello");
        show();
    }
    A(string i)
    {
        set(i);
        show();
    }
    ~A()
    {
        cout << "die " << a << endl;
    }
    void set(string i) { a = i; }
    string get() { return a; }
    void show()
    {
        cout << "a = " << a << endl;
    }
};
class B
{
    int num;
    A *a;
    void setA(int n)
    {
        num = n;
        a = new A[num];
    }

public:
    B()
    {
        setA(1);
        a[0].set("hi");
    }
    B(A &k)
    {
        setA(1);
        a[0].set(k.get());
    }
    B(int i) { setA(i); }
    ~B() { delete[] a; }
    void set(B &k)
    {
        delete[] a;
        setA(k.getNum());
        for (int i = 0; i < num; i++)
            a[i].set(k.get(i).get());
    }
    void set(int i, string s)
    {
        a[i].set(s);
    }
    A get(int i) { return a[i]; }
    int getNum() { return num; }
};
class C : public B
{
    int c;

public:
    C() { c = 1; }
    C(A &a) : B(a) { c = 2; }
    ~C() { cout << "C" << endl; }
    int getC() { return c; }
};

int main()
{
    A a("good");
    C c(a);
    cout << c.get(0).get() << endl;
    B b1;
    B b2(2);

    b2.set(0, "a");
    b2.set(1, "b");
    c.set(b2);
    b2.get(1).set("c"); //set ให้กับตัวที่ get ออกมาเป็น obj ใหม่

    cout << b2.get(1).get() << endl;
                //cout << endl;
    cout << b2.get(1).get() << endl;
                   //  cout << endl;
    cout << "bye bye" << endl;
}