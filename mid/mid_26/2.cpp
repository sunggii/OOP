#include <iostream>
using namespace std;

class A{
    int a;

    public:
        A(){
            set(3);
        }
        A(int i){
            set(i); 
            cout << "AA ";
            show();
        }
        ~A(){
            cout << "~A ";
            show();
        }

        //set
        void set(int i){
            a = i;
        }
        //get
        int get(){
            return a;
        }
        //show
        void show(){
            cout << a <<endl;
        }

        A add(A& x){
            return A( a+ x.a);
        }
        int plusOne(){
            cout << "pluse one " << endl;
            a++;
            return a;
        }
};

class B: public A{
    static int k;
    int b;

    public:
        B(){
            b = ++k;
            A::set(b + 1);
            cout << "B ";
            show();
        }
        B(A& a){
            b = 1+a.get();
            cout << "BB " ;
            show(); 
        }
        ~B(){
            cout << "~B ";
            show();
        }

        //set
        void set(int i){
            b = i;
        }
        //get
        int get(){
            return b;
        }
        //show
        void show(){
            cout << b << " " <<A::get() <<endl;
        }

        void plusOne(){
            A::plusOne();
            b++;
        }
};
int B::k;

class C{
    B *b;
    int n;
    
    public:
        C(){
            b = new B[1];
        }
        C(B *y, int k){
            n = k;
            b = new B[k];
            for(int i = 0; i<n ; i++){
                b[i] = y[i];
            }
        }
        ~C(){
            delete[] b;
        }

        B getB(int i){
            return b[i];
        }
};

main(){
    A a;
    B b(a);
    C c1;
    cout << endl;
    /*B bb[2];
    //cout<<"bb[0] " << "value " <<bb[0].get() <<" " << bb[0].A::get() <<endl;
    //cout<<"bb[1] " << "value " <<bb[1].get() <<" " << bb[1].A::get() <<endl;
 
    for (int i = 0; i < 2; i++)
    {
        bb[i].plusOne();
        //cout<<"bb["<< i <<"] " << "value " <<bb[i].get() <<" " << bb[i].A::get() <<endl;
    }

    b.set(bb[0].add(a).get());
    cout << "value " <<b.get() <<" " << b.A::get() <<endl;

    C c2(bb,2);
    c2.getB(0).show();
    c2.getB(1).show();
               //cout << endl;
    cout << "-------END---------" <<endl;*/
    
}