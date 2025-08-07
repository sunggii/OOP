//ตัวอย่าง friend fuction
#include <iostream>
using namespace std;

class B;
class A{
    int a;

    public:
        A(){
            a = 1;
        }
        friend int add(A,B);
};

class B{
    int b;

    public:
        B(){
            b = 2;
        }
        friend int add(A,B);
};

int add(A x ,B y){
    A z;
    z.a = x.a + y.b;
    return z.a;
}

main(){
    A s;
    B t;
    cout << add(s ,t) << endl;
    return 0;
}