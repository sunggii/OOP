#include <iostream> //cast ระหว่าง obj กับ bbj
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

        double getMin(){
            return (width < height ?width : height);
        }

        void show(){
            cout << "Ractangle: "<<width <<" x " <<height <<" = " <<area <<endl;
        }
};

class Cube{
    double width;
    double volume;

    public:
        Cube(){
            width = volume = 0.0;
        }
        Cube(double w){
            width = w;
            volume = Volum(w);
        }
        //cast to Cube
        Cube(Rectangle r){
            width = r.getMin();
            volume = Volum(width);
        }
        //cast to Rectangle
        operator Rectangle(){
            return Rectangle(width , width);
        }

        double Volum(double w){
            return volume = w*w*w;
        }

        void show(){
            cout << "Cube: " <<width << " x " <<width;
            cout << " x " <<width << " = " <<volume <<endl;
        }
};

main(){
    Rectangle r1(3.0,4.0) , r2(2.5,3.5);
    Cube c1(5.0) , c2;

    //r2 = c1;
    r2 = c1.operator Rectangle();
    r2.show();

    //c2 = r1;
    c2 = Cube(r1);
    c2.show();
    return 0;
}