#include <iostream>
using namespace std;
int x; //globol ค่าเริ่มต้นถึงไม่กำหนดก็ = 0 เสมอ

int f1(){
    return ++x;
}

int f2(){
    int y = 0; //locol ต้องกำหนดค่าเริ่มต้น
    return ++y;
}

int f3(){
    static int z;//ค่าเริ่มต้นของ static = globol
    return ++z;
}

int main(){
    cout<<"f1 = "<<f1()<<endl;
    cout<<"f1 = "<<f1()<<endl;
    ++x;
    cout<<"f1 = "<<f1()<<endl;

    cout<<"f2 = "<<f2()<<endl;
    cout<<"f2 = "<<f2()<<endl;
    //++y;

    cout<<"f3 = "<<f3()<<endl;
    cout<<"f3 = "<<f3()<<endl;
    cout<<"f3 = "<<f3()<<endl;
    //++z;
}