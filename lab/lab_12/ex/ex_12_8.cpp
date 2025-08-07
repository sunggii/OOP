#include <iostream> 
#include <exception> 
using namespace std;
int main()
{
    try
    {
        int *a = new int[1000000000000000];
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    cout << "Hello World" << endl;
}