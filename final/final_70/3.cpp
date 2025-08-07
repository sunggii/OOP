#include <iostream>
using namespace std;
class ID
{
    static int count;
    int x;

public:
    ID()
    {
        x = ++count;
        cout << !*this << endl;
    }
    ID(ID &a)
    {
        x = ++count;
        cout << "copy ID" << endl;
    }
    ~ID()
    {
        cout << "x=" << !*this << endl;
    }
    int operator!() { return x; }
    static int getCount() { return count; }
};
int ID::count;
class B
{
    ID id;
    int y;

public:
    B() { y = 1; }
    B(B &b)
    {
        y = b.y;
        cout << "copy B" << endl;
    }
    ~B()
    {
        cout << !id << " y=" << y << endl;
    }
    B operator()(int y)
    {
        this->y = y;
        return *this;
    }
    ID &operator!() { return id; }
    int operator++()
    {
        ++y;
        return y++;
    }
    ID add(int i)
    {
        y += i;
        return id;
    }
    int getY() { return y; }
};
int main()
{
    B b[2];
    b[1] = b[0](7);
    B *b1;
    B b2;
    b1 = new B;
    cout << "wow " << !b2.add(5) << endl;
    cout << "b2.id=" << !!b2 << endl;
    cout << "++*b1=" << ++*b1 << endl;
    cout << "b1.y=" << b1->getY() << endl;
    delete b1;
    b1 = new B;
    (*b1)(9);
    cout << ID::getCount() << endl;
    delete b1;
    cout << "==TheEnd==" << endl;
}