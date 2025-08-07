#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout << "A" <<endl;
        }
        void f(){
            cout << "f() in A" <<endl;
        }
        ~A(){
            cout << "delete A" <<endl;
        }
};

class B: virtual public A{
    public:
        B(){
            cout << "B" <<endl;
        }
        void f(){
            cout << "f() in B" <<endl;
        }
        ~B(){
            cout << "delete B" <<endl;
        }
};

class C: virtual public A{
    public:
        C(){
            cout << "C" <<endl;
        }
        ~C(){
            cout << "delete C" <<endl;
        }
};

class D: public B, public C{
    public:
        D(){
            cout << "D" <<endl;
        }
        void show(){
            f();
        }
        ~D(){
            cout << "delete D" <<endl;
        }
};

main(){
    D m;
    m.show();

    cout<<"\n===== destructor ====="<<endl;
    return 0;
}