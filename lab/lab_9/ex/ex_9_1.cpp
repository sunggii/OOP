#include <iostream> //operator =, + ,+=
using namespace std;
class Rectangle{
    double width , height;
    double area;

    public:
        Rectangle(){
            width=height=area=0.0;
        }
        Rectangle(double w, double h){
            width = w; height = h;
            area = width*height;
        }
        //show
        void show(){
            cout << width <<" x " <<height << " = " <<area<<endl;
        }

        //binary op เอา obj 2 ตัวมาบวกกัน
        Rectangle operator +(Rectangle r){
            return Rectangle(width + r.width , height + r.height);
        }

        //op =
        Rectangle& operator = (const Rectangle& r ){
            if (this == &r) return *this; //check add ว่าตรงกันป่าวถ้าตรงกันแปลว่ามันเท่ากันอยู่แล้ว
            width = r.width;
            height = r.height;
            area = r.area;
            return *this;
        }

        //op +=
        Rectangle& operator += (const Rectangle& r){
            width += r.width;
            height += r.height;
            area = width*height;
            return *this;
        }
};

main(){
    Rectangle r1(1,2), r2(3,4), r3(5,6), r4, r5;
    r5=r4=r2; //r5.operator= (r4.operator=(r2));
    cout << "r2: "; r2.show();
    cout << "r5: "; r5.show();
    cout << "r4: "; r4.show();
    cout <<"--------------"<<endl;
    r4+=r3+=r2; //r4.operator= (r3.operator=(r2));
    cout << "r4: "; r4.show();
    cout << "r3: "; r3.show();
}