#include <iostream>
using namespace std;
class A
{
private:
    int a;
public:
    A() {
        a = 10;
    }
    void setA(int x){
        a = x;
    }
    void showA(){
        cout << "a = " << a << endl;
    }
    ~A() {
        cout << "~A "; showA();
    }
};

class B
{
private:
    int num;
    A **a;
    int b;
public:
    B() {
        num = b = 0;
        a = 0;
    }
    B(B& x){
        cout << "\n----- copyB -----" <<endl;
        num = 0;
        a = 0;
        setB(x.getB());
        setNum(x.getNum());
        for (int i = 0; i < num; i++)
        {
            setA(i , x.getA(i));
        }
    }
    ~B() {
        cout << "~B" <<endl;
        show();
        delete[] a;
    }

    //set
    void setB(int x){
        b = x;
    }
    void setNum(int n){
        if(n == num){
            return;
        }
        if (n<0)
        {
            num = 1;
        }

        delete[] a;
        num = n;
        a = new A*[num]; 
    }
    void setA(int i, A* y){
        a[i] = y;
    }
    //get
    int getB(){
        return b;
    }
    int getNum(){
        return num;
    }
    A *getA(int i){
        return a[i];
    }
    //show
    void show(){
        cout << "b = " << b <<endl;
        cout << "num = " <<num <<endl;
        for (int i = 0; i < num; i++)
        {
            a[i]->showA();
        }
        
    }
};

int main(){
    //-------------------
    A a1, a2 ,a3;
    B *boy = new B();
    boy->show();cout <<endl;

    boy->setB(20);
    boy->setNum(2);
    boy->setA(0,&a1);
    boy->setA(1,&a3);
    boy->show();

    B *bb = new B(*boy);
    bb->show();
    cout << "-------------------" <<endl;

    a3.setA(33);
    cout << "a3: " ; a3.showA();
    bb->setNum(1);
    bb->setA(0,&a3);

    cout << "\n*boy :" <<endl;
    boy->show();
    cout << "\n*bb :" <<endl;
    bb->show();
    //-------------------

    cout << "\n--- delete B ---" <<endl;
    delete boy;
    delete bb;
    
    cout << "\n--- end ---" <<endl;
}

//num = x.getNum();
//a = new A*[num];
