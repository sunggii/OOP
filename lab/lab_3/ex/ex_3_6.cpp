#include <iostream>
using namespace std;
//class 1
class myObj{
    int width;
    int lenth;
    float price;
    public:
        myObj(){
            cout<<"myObj"<<endl;
        }
        ~myObj(){
            cout<<"bye bye"<<endl;
        }
};

//calss 2
class myObjArray{
    myObj *p; //p เป็นสมากชิกของอีก class ก็ได้
    int num;
    //fuc ก็อยู่ใน private ได้
    void set(int n){
        num  = n;
        p = new myObj[n];
    }
    public:
        myObjArray(){
            set(0);
        }
        myObjArray(int n){
            set(n);
        }
        ~myObjArray(){
            delete[] p;
        }
};

main(){
    myObjArray a;
    myObjArray b(3);
    myObjArray c(0);
    return 0;
}