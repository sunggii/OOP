#include <iostream>
using namespace std;

class A{
    int row,col;
    int **a;
    public:
        A(){
            a = 0; row = col = 0;
        }
        A(int r, int c);

        ~A();
        void set();
        void show();

};

//constructor อยู่นอก class
A::A(int r, int c){
    row = r; col = c;
    a = new int *[row];  //จองที่ row
    for (int i = 0; i < row; i++)
    {
        a[i] = new int [col]; //จองที่ col สังเกตว่าไม่มี * หน้า[] กรณีเป็นมิติสุดท้าย
    }
}

A::~A(){
    if (a != 0)
    {
        for (int i = 0; i < row; i++)
        {
            delete[] a[i];
        }
        delete[] a;
        
    }
    
}

//fuc นอก class สังเกคว่าแค่เพิ่ม data type เข้าไป
void A::set(){//ใส่ข้อมูลลงในพท. ที่จองไว้ตอน constructor
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"input a["<<i<<"]["<<j<<"] :",cin>>a[i][j];
        }
        cout<<endl;
    }
}

void A::show(){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl;
        }
        cout<<endl;
    }
}

main(){
    A x(3,3);
    x.set();
    x.show();

    A d; //ไม่มีไรเกิดเพราะไม่ได้จองที่ 
    d.set();
    d.show();
    return 0;
}