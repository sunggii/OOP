#include <iostream> //cast ระหว่าง obj กับ data type ทั่วไป
using namespace std;

class Rectangle{
    double width , height;
    double area;

    public:
        Rectangle(){
            width = height = area = 0.0;
        }
        Rectangle(double w, double h){
            width = w;
            height = h;
            area  = width * height;
        }

        Rectangle(double d){
            width = 1;
            height = d;
            area = d;
        }

        //op loding
        Rectangle operator ++(){
            return Rectangle(width+1 , height+1);
        }

        //cast to double
        operator double(){
            return area;
        }

        void show(){
            cout << "\nwidth = " << width <<endl;
            cout << "height = " << height <<endl;
            cout << "area = " << area <<endl;
        }
};

main(){
    Rectangle r1(3.0,4.0) , r2(2.5,3.5);
    double a,b,c;

    a = double(r1); //เขีบยเต็ม
    cout << "a = " << a <<endl;
    b = r2; //เขียนย่อ
    cout << "b = " << b <<endl;

    //c = ++r1;
    c = r1.operator++(); //cast Rectangle to double
    cout << "c = " << c <<endl;

    Rectangle r3 = 4.5; //cast double to Rectangle
    r3.show();

    r3 = 2.0; //cast double to Rectangle
    r3.show();

    return 0;
}