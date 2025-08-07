#include <iostream>
using namespace std;

class Point {
    float x , y;
    public:
        Point(){x = y = 0;}
        /*Point(float i,float j){
            x = i * i;
            y = j * j;
        }*/
        Point(float i){
            x = i;
            y = ++i;
        }

        Point &dot(Point &obj){
            return obj;
        }

        void show();
};

void Point ::show(){
    cout<<"x = "<<x<<" y = "<<y<<endl; 
}

int main()
{
    Point a ;
    Point b;
    //float pointX , pointY;
    //cout<<"input x : ",cin>>pointX;
    //cout<<"input y : ",cin>>pointY;

    /*b.show(); 
    a.dot(b); 
    b.show();*/

    cout<<"=======show a ======="<<endl;
    a.show();
    b.dot(a) = 4;
    a.show();
    
    cout<<"=======show b ======="<<endl;
    b.show();
    a.dot(b) = 2; 
    b.show();



    return 0;
}
