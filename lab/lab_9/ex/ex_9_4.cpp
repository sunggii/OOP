#include <iostream> //operator << , >>
using namespace std;
class Rectangle
{
    double width, height;
    double area;

public:
    Rectangle()
    {
        width = height = area = 0.0;
    }
    Rectangle(double w, double h)
    {
        width = w;
        height = h;
        area = width * height;
    }
    // show
    void show()
    {
        cout << width << " x " << height << " = " << area << endl;
    }

    //ostream
    void print(ostream& os){
        os<<width<<" x "<<height<< " = " <<area<<endl;
    }

    //istream
    void input(istream &is){
        cout<< "add width = " << &width <<endl;
        cout<<"Enter width:  "; is>>width;
        cout<< "add width after is>> = " << &width <<endl;
        cout<<"Enter height: "; is>>height;
        area = width * height;
    }
};

//-----------------

/*เราเตรียมการใน class เสร็จแล้วก็สามารถสร้าง func 
เพื่อใช้ cout , cin ได้แล้ว*/

//ostream
ostream& operator<<(ostream &os, Rectangle &r){
    r.print(os);
    return os;
}

//istream
istream& operator>>(istream &is, Rectangle &r){
    r.input(is);
    return is;
}
//-----------------

main(){
    Rectangle r1(3.0,4.0) , r2;
    cin>>r2;
    cout<<r2<<r1;
}