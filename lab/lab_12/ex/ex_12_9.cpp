#include <iostream>
#include <exception>
using namespace std;
class MyException : public exception
{
    virtual const char *what() const throw()
    {
        return "Hello my exception";
    }
};

main()
{
    MyException ex;
    try
    {
        cout << "My world" << endl;
        throw ex;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    cout << "Hello World" << endl;
}