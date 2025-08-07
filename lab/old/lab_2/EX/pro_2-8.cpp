#include <iostream>
using namespace std;
class MyObj {
    static int num;
    int width;
    int height;
    float price;
    public:
    MyObj(){
        num++; set(0,0,0.0);
    }
    MyObj(int w, int h, float p){
        num++;set(w,h,p);
    }
    ~MyObj(){
        num--;
        cout<<num<<endl;
    }
    void set(int w,int h, float p){
        width = w; height = h; price = p;
    }
    static int count(){return num;} //static function
};

int MyObj::num; //syntax static data
main(){
    cout<<MyObj::count()<<endl; //syntax การเรียกใช้ static function
    MyObj book;
    cout<<MyObj::count()<<endl; 
    {
       MyObj pencil(1,14,20.0), table(50,60,1500.0); 
        cout<<MyObj::count()<<endl; 
    }
    MyObj mobile(4,10,15000.0);
    cout<<MyObj::count()<<endl; 
}