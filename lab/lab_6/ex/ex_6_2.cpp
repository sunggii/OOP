#include <iostream>
using namespace std;

class A{
    int a1;

    protected:
        int a2;
    
    public:
        int a3;
};

class B: protected A{
    int b1;

    protected:
        int b2;
    
    public:
        int b3;

        void f3(){
            //b1 = a1;
            b1 = a2;
            b1 = a3;
        }
};