#include <iostream> //12.5-12.6
#include <cstring>
#include <exception>
using namespace std;

class A : public exception
{
    string a;

public:
    A()
    {
        setA("none");
    }
    A(string x)
    {
        setA(x);
    }
    ~A()
    {
        cout << "~A" << endl;
    }
    // set
    void setA(string x)
    {
        a = x;
    }
    // get
    string getA()
    {
        return a;
    }
    // show
    void showA()
    {
        cout << "\na = " << a << endl;
    }

    virtual const char *what() const noexcept
    {
        return "Hello my exception A";
    }
};

class B
{
    string b;

public:
    B()
    {
        setB("none");
    }
    B(string y)
    {
        setB(y);
    }
    ~B()
    {
        cout << "~B" << endl;
    }

    // set
    void setB(string y)
    {
        b = y;
    }
    // get
    string getB()
    {
        return b;
    }
    // show
    void showB()
    {
        cout << "\nb = " << b << endl;
    }

    // ถ้า b = "hello" จะโยน
    virtual void equalHello() noexcept(false)
    {
        if (b == "hello")
        {
            throw A();  // โยน obj A
        }
    }
};

class C : public B
{
    string c;

public:
    C()
    {
        setC("none");
    }
    C(string z)
    {
        setC(z);
    }
    C(string y, string z) : B(y)
    {
        setC(z);
    }
    ~C()
    {
        cout << "~C" << endl;
        ;
    }
    // set
    void setC(string z)
    {
        c = z;
    }
    // get
    string getC()
    {
        return c;
    }
    // show
    void showC()
    {
        showB();
        cout << "c = " << c << endl;
    }

    // override ลงมา
    void equalHello() noexcept(false)
    {
        if (getB() == "hello") {
            throw A("hello");  // โยน obj A
        } else {
            cout << getB() << endl;
        }
    }
};

main()
{
    // 12.5
    C c1;
    c1.showC();
    c1.setB("hi");
    c1.setC("pookie");
    cout << "--- get c1 ---" << endl;
    cout << "b = " << c1.getB() << endl;
    cout << "c = " << c1.getC() << endl;

    C c2("hello", "apin");
    c2.showC();

    try
    {
        c1.equalHello();
        c2.equalHello(); // โยน c2
    }
    catch (exception& e) {
        cout << "exception: " << e.what() << endl;
    }
    cout << "continue to next step" << endl;

    // test B class เรียกfunc ครบหมดแล้ว
    /*B b1;
    b1.showB();
    b1.setB("pookie");
    cout << "--- get b1 ---" << endl;
    cout << "b = " << b1.getB() << endl;

    B b2("hello");
    b2.showB();*/

    cout << "\n----- destruct ----- " << endl;
}
