#include <iostream>
using namespace std;
class MyObj {
    static int num; //static data
    int width;
    int height;
    float price;
    public:
     MyObj(){
        num++;
        set(0,0,0.0);
        cout<<num<<endl;
     }
     MyObj(int w, int h){
        num++;
        set(w,h,0.0);
        cout<<num<<endl;
     }
     MyObj(float p){
        num++;
        set(0,0,p);
        cout<<num<<endl;
     }
     MyObj(int w, int h, float p){
        num++;
        set(w,h,p);
        cout<<num<<endl;
     }
     ~MyObj(){
        num--;
        cout<<num<<endl;
     }
    void set(int w,int h, float p){
        width = w; height = h; price = p;
    }

};
int MyObj::num; //syntax static data
main(){
    MyObj book;
    {
        MyObj pencil(1,4), table(3500.0);
    }
    MyObj mobile(4,10,15000.0);
}