//ตัยวอย่าง friend class
#include <iostream>
using namespace std;

class A{
    int a;

    public:
        A(){
            a = 1;
        }
        friend class B;
};

class B{
    int b;

    public:
        B(){
            b = 2;
        }
        int f1(A &x){
            return ++x.a;
        }
        int f2(A &x){
            return --x.a;
        }
        int f3(A x){
            return b + x.a;
        }
};

main(){
    A s;
    B t;
    cout << t.f1(s)  << endl;
    cout << t.f3(s)  << endl;
    cout << t.f2(s)  << endl;
    return 0;
}