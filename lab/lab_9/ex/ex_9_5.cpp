#include <iostream> //operator << , >> กรฌีเป็น freind
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

    //กรฌีเป็น freind
    friend ostream& operator<<(ostream &os,const Rectangle &r); //ใส่ const เพราะแค่าจะ cout ไม่อยากให้แก้ไขค่า
    friend istream& operator>>(istream &is, Rectangle &r);
};

//-----------------
//ostream
ostream& operator<<(ostream &os,const Rectangle &r){
    os<<r.width<<" x "<<r.height<< " = " <<r.area<<endl;
    return os;
}

//istream
istream& operator>>(istream &is, Rectangle &r){
    cout<<"Enter width:  "; is>>r.width;
    cout<<"Enter height: "; is>>r.height;
    r.area = r.width * r.height;
    return is;
}
//-----------------

main(){
    Rectangle r1(3.0,4.0) , r2;
    //cin>>r2;
    operator>>(cin,r2);

    //cout<<r2<<r1;
    cout<<"r2: ";
    operator<<(cout,r2);
    cout<<"r1: ";
    operator<<(cout,r1);
}