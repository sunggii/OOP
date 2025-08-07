#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << 'A' << endl; }
};
class B : public A
{
public:
    B() { cout << 'B' << endl; }
};
class C : public B
{
public:
    C() { cout << 'C' << endl; }
};
void f() noexcept(false)
{
    B b;
    throw b;
}

main()
{
    try
    {
        f();
        cout << "in try block" << endl;
    }
    catch (C)
    {
        cout << "catch C" << endl;
    }
    catch (B)
    {
        cout << "catch B" << endl;
    }
    catch (A)
    {
        cout << "cath A" << endl;
    }
    catch (...)
    {
        cout << "no cath" << endl;
    }
    cout << "hello World" <<endl;
}