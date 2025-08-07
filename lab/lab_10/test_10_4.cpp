#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.14;
class Shape{
    public:
    virtual double area() = 0; //Pure virtual function
    //virtual double volume() = 0;
    // ostream ,istream
    virtual void print(ostream &os) = 0; 
    virtual void input(istream &is) = 0; 
    virtual ~Shape(){
        cout << "~Shape" <<endl;
    }
};

class TwoDimensional: public Shape{
    //ไม่เขียนไว้มันก็รู้ว่ามี double area() = 0
    public:
    ~TwoDimensional(){
        cout << "~TwoDimensional" <<endl;
    }
}; 
class ThreeDimensional: public Shape{
    public:
    ~ThreeDimensional(){
        cout << "~ThreeDimensional" <<endl;
    }
    virtual double volume() = 0;
   
};

class Rectangle: public TwoDimensional{
    double width;
    double height;

    public:
        Rectangle(){
            width = height = 0;
        }
        Rectangle(int w, int h){
            setRectangle(w,h);
        }
         ~Rectangle(){
            cout<<"\n~Rec"<<endl;
        }
        //-------------------
        double area(){
            return  width * height;
        }
        
        void print(ostream &os){
            os <<"\n----- print Rectangle ------" <<endl;
            os <<"Width  = "<<width<<endl;
            os <<"Height = "<<height<<endl;
        }
        void input(istream &is){
            cout <<"------ input Rectangle  ------" <<endl;
            cout<<"Width:  "; is>>width;
            cout<<"Height: "; is>>height;
        }
        //-------------------

        //set
        void setRectangle(double w, double h){
            setWidth(w); setHeight(h);
        }
        void setWidth(double w){
            width = w;
        }
        void setHeight(double h){
            height = h;
        }

        //get
        double getWidth(){
            return width;
        }
        double getHeight(){
            return height;
        }
};

class Triangle: public TwoDimensional{
    double base;
    double height;

    public:
        Triangle(){
            base = height = 0;
        }
        Triangle(double b , double h){
            setTringle(b,h);
        }
        ~Triangle(){
            cout << "\n~Triangle" <<endl;
        }
        //---------------
        double area(){
            return (base * height) / 2.0;

        }

        void print(ostream &os){
            os <<"----- print Triangle ------" <<endl;
            os <<"Base   = "<<base<<endl;
            os <<"Height = "<<height<<endl;
        }
        void input(istream &is){
            cout <<"------ input Triangle ------" <<endl;
            cout<<"Base :  "; is>>base;
            cout<<"Height: "; is>>height;
        }
        //---------------

        //set
        void setTringle(double b, double h){
            setBase(b); setHeight(h);
        }
        void setBase(double b){
            base = b;
        }
        void setHeight(double h){
            height = h;
        }

        //get
        double getBase(){
            return base;
        }
        double getHeight(){
            return height;
        }
};

class Circle: public TwoDimensional{
    double radius;

    public:
        Circle(){
            setRadius(0);
        }
        Circle(double r){
           setRadius(r);
        }
        ~Circle(){
            cout << "\n~Circle" <<endl;
        }
        //---------------
        double area(){
            return pi * (pow(radius , 2));
        }
        
        void print(ostream &os){
            os <<"----- print Circle ------" <<endl;
            os <<"radius = "<<radius<<endl;
        }
        void input(istream &is){
            cout <<"------ input Circle  ------" <<endl;
            cout <<"radius : "; is>>radius;
        }
        //---------------

        //set
        void setRadius(double r){
            radius = r;
        }

        //get
        double getRadius(){
            return radius;
        }
};

class Cylinder: public ThreeDimensional{
    double radius;
    double height;

    public:
        Cylinder(){
            setCylinder(0,0);
        }
        Cylinder(double r, double h){
            setCylinder(r,h);
        }
        ~Cylinder(){
            cout << "\n~Cylinder" <<endl;
        }
        //---------------
        double area(){
            return (2 * pi *radius *height) + (2 * pi * pow(radius , 2));
        }
        double volume() {
            return pi * pow(radius , 2) * height;
        }
        void print(ostream &os){
            os <<"----- print Cylinder ------" <<endl;
            os <<"radius = "<<radius<<endl;
            os <<"height = "<<height<<endl;
        }
        void input(istream &is){
            cout <<"------ input Cylinder ------" <<endl;
            cout <<"radius : "; is>>radius;
            cout <<"height : "; is>>height;
        }
        //---------------
        //set
        void setCylinder(double r, double h){
            setRadius(r); setHeight(h);
        }
        void setRadius(double r){
            radius = r;
        }
        void setHeight(double h){
            height = h;
        }
        //get
        double getRadius(){
            return radius;
        }
        double getHeight(){
            return height;
        }
};

class Sphere: public ThreeDimensional{
    double radius;

    public:
        Sphere(){
            setRadius(0);
        }
        Sphere(double r){
            setRadius(r);
        }
        ~Sphere(){
            cout << "\n~Sphere" <<endl;
        }
         //---------------
        double area(){
            return  4 * pi * pow(radius, 2);
        }
        double volume() {
            return (4 * pi *pow(radius, 3))/3;
        }
        void print(ostream &os){
            os <<"----- print Sphere ------" <<endl;
            os <<"radius = "<<radius<<endl;
        }
        void input(istream &is){
            cout <<"------ input Sphere ------" <<endl;
            cout <<"radius : "; is>>radius;
        }
        //---------------

        //set
        void setRadius(double r){
            radius = r;
        }
        //get
        double getRadius(){
            return radius;
        }
};

//เกิด dynamic binding ที่ a
double getArea(Shape* a){
    return a->area();
}
double getVolume(ThreeDimensional* a){ 
    return a->volume();
}
//-----------
/*double getVolume(ThreeDimensional& a){ 
    return a.volume();
}*/
//-----------
void show(Shape* a){
    a->print(cout);
}
//-----------------------
ostream &operator<<(ostream &os, Shape &a)
{
    a.print(os);
    return os;
}
istream &operator>>(istream &is, Shape &a)
{
    a.input(is);
    return is;
}
//-----------------------

main(){
    Shape *s[5];
    //2D
    cout << "\n2D:" <<endl;
    Rectangle r1; cin>>r1;
    Triangle  t1; cin>>t1;
    Circle    c1; cin>>c1;
    s[0] = &r1;
    s[1] = &t1;
    s[2] = &c1;

    for (int i = 0; i < 3; i++)
    {
        show(s[i]);
        double area  = getArea(s[i]); cout << "area   = " << area <<endl;
    }
    
    //3D
    cout << "\n3D:" <<endl;
    Cylinder  cy1; cin>>cy1;
    Sphere    sp1; cin>>sp1;
    s[3] = &cy1;
    s[4] = &sp1;

    ThreeDimensional *threeD; //แบบที่ 1
    for (int i = 3; i < 5; i++)
    {
        show(s[i]);
        double area   = getArea(s[i]); cout << "area   = " << area <<endl;
        if (i == 3)
        {
            double volume  = getVolume(threeD = &cy1); cout << "volume = " << volume <<endl;
        } else {
            double volume  = getVolume(threeD = &sp1); cout << "volume = " << volume <<endl;
        }
    }

    //test Sphere-----
    /*Sphere sp2 , sp3;
    cout << sp2 << "area = " << sp2.area() <<endl;

    sp3.setRadius(14);
    cout << "---- get Sphere ---- "<<endl;
    cout << "Radius  = "<< sp3.getRadius() <<endl;
    cout << "area    = "<< sp3.area() <<endl;
    cout << "volume  = "<< sp3.volume() <<endl;

    Sphere sp4(7);
    cout << "\nsp4: " <<endl;
    cout<<sp4 << "area = " << sp4.Sphere::area() <<"\nvolume = "<< sp4.volume() <<endl; 
    cin >> sp4;
    cout << "\nsp4: " <<endl;
    cout<<sp4 << "area = " << sp4.Sphere::area() <<"\nvolume = "<< sp4.volume() <<endl;*/
    //-------------

    //test Cylinder-----
    /*Cylinder cy2 , cy3;
    cout << cy2 << "area = " << cy2.area() <<endl;

    cy3.setCylinder(14,2.2);
    cout << "---- get Cylinder ---- "<<endl;
    cout << "Radius  = "<< cy3.getRadius() <<endl;
    cout << "Heighe  = "<< cy3.getHeight() <<endl;
    cout << "area    = "<< cy3.area() <<endl;
    cout << "volume  = "<< cy3.volume() <<endl;

    Cylinder cy4(7,2);
    cout << "\ncy4: " <<endl;
    cout<<cy4 << "area   = " << cy4.Cylinder::area() <<"\nvolume = "<< cy4.volume() <<endl; 
    cin >> cy4;
    cout << "\ncy4: " <<endl;
    cout<<cy4 << "area   = " << cy4.Cylinder::area() <<"\nvolume = "<< cy4.volume() <<endl;*/
    //-------------

   //test Circle-----
    /*Circle c2 , c3;
    cout << c2 << "area = " << c2.area() <<endl;

    c3.setRadius(14);
    cout << "---- get Circle ---- "<<endl;
    cout << "Radius  = "<< c3.getRadius() <<endl;
    cout << "area    = "<< c3.area() <<endl;

    Circle c4(7.4);
    cout << "\nc4: " <<endl;
    cout<<c4 << "area = " << c4.area() <<endl;
    cin >> c4;
    cout << "\nc4: " <<endl;
    cout<<c4 << "area = " << c4.area() <<endl;*/
    //-------------

    //test Tringle-----
    /*Triangle t2 , t3;
    cout << t2 << "area = " << t2.area() <<endl;

    t3.setTringle(5,2.2);
    cout << "---- get Triangle ---- "<<endl;
    cout << "Base   = "<< t3.getBase() <<endl;
    cout << "Height = "<< t3.getHeight() <<endl;
    cout << "area   = "<< t3.area() <<endl;

    Triangle t4(2,5);
    cout << "\nt4: " <<endl;
    cout<<t4 << "area = " << t4.area() <<endl;
    cin >> t4;
    cout << "\nt4: " <<endl;
    cout<<t4 << "area = " << t4.area() <<endl;*/
    //-------------

    //test Rec-----
    /*Rectangle r2, r3;
    cout << r2 << "area = " << r2.area() <<endl;

    r3.setRectangle(4.2,8);
    cout << "---- get Rectangle ---- "<<endl;
    cout << "Width  = "<< r3.getWidth() <<endl;
    cout << "Height = "<< r3.getHeight() <<endl;
    cout << "area   = "<< r3.area() <<endl;

    Rectangle r4(2,5);
    cout << "\nr4: " <<r4 << "area   = " << r4.area() <<endl;
    cin >> r4;
    cout << "\nr4: " <<r4 << "area   = " << r4.area() << endl;*/
    //-------------
    cout << "\n------ destructor ------";
}