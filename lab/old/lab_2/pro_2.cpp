#include <iostream>
#include <string.h>
using namespace std;
class Point {
    static int num;
    float x;
    float y;
    char name[20];
    public:
     Point(){set(0,0,strcpy(name,"no_name"));num++;}
     Point(float X, float Y, char* p){set(X,Y,strcpy(name, p));num++;}

    ~Point(){
       num--;
       cout<<name<<" "<<num<<" left"<<endl;
    }

    void set(float X, float Y,char* p){
        this->x = X; this->y = Y;
     }
    int getX(){return x;}
    int getY(){return y;}
    char* getName(){return name;}

    static int count(){return num;}
    void show(void);
};
int Point::num;
void Point::show(){
	cout<< "x = "<< x << endl;
	cout<< "y = "<< y << endl;
    cout<< "Point name : "<< name <<endl;
    cout<<endl;
}
main(){
    Point aPoint;
    cout<<"Oobject "<<Point::count()<<endl; 
    aPoint.show();

    Point bPoint(3.0,5.0,(char *)"mypoint");
    cout<<"Oobject "<<Point::count()<<endl; 
    bPoint.show();
}