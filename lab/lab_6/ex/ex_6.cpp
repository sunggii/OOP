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
};

class C: protected B{
    int c1;

    protected:
        int c2;
    
    public:
        int c3;
};

main(){
    //เทสการเข้าถึง
    A w;
    //w.a1 = 1;
    //w.a2 = 1;
    w.a3 = 1;

    B x;
    //x.a1 = 1;
    //x.a2 = 1;
    //x.a3 = 1;
    //x.b1 = 1;
    //x.b2 = 1;
    x.b3 = 1;

    C y;
    //y.a1 = 1;
    //y.a2 = 1;
    //y.a3 = 1;
    //y.b1 = 1;
    //y.b2 = 1;
    //y.b3 = 1;
    //y.c1 = 1;
   // y.c2 = 1;
    y.c3 = 1;
    return 0;
}