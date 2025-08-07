#include <iostream>
using namespace std;
double divide(double x, double y) noexcept(false) // ระบุได้ว่าอาจจะโยน exception
{
    if(y == 0){
        throw 0;
    } 
    return x / y;
}
main()
{
    try
    {
        cout << divide(10, 2) << endl;
        cout << divide(10, 0) << endl;
        cout << divide(10, 5) << endl;
    }
    catch (int i)
    {
        cout << "divide by zero" << endl;
    }
    cout << "Hello World" << endl;
}