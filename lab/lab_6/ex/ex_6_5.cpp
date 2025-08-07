//เราสามารถเลือก con ที่อยากให้ obj เกิดได้ด้วย
#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout << "A" << endl;
        }
        A(int i){
            cout << i << endl;
        }
};

class B: public A{
    public:
        B(){
            cout << "B" << endl;
        }
        B(int i, int j) :A(i) {
            cout << j << endl;
        }
};

class C: public B{
    public:
        C(){
            cout << "C" << endl;
        }
        C(int i, int j, int k) :B(i,j) {
            cout << k << endl;
        }
};

main(){
    B m(4,5);
    C n;
    C p(6,7,8);
    return 0;
}