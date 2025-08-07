#include <iostream>
#include <string.h>
using namespace std;
class Point {
    static int num;
    float x;
    float y;
    string name1;
	char name2[20];
    public:
     Point(){set(0.0,0.0,"no_nameString",strcpy(name2,"no_nameChar"));num++;}
     Point(float X){set(X,0.0,"no_nameString",strcpy(name2,"no_name"));num++;}
     Point(float X, float Y){set(X,Y,"no_nameString",strcpy(name2,"no_name"));num++;}
     Point(float X, float Y,string S1){set(X,Y,S1,strcpy(name2,"no_name"));num++;}
     Point(float X, float Y,string S1,  char* p){set(X,Y,S1,strcpy(name2, p));num++;}

     ~Point(){
       num--;
       cout<<name2<<" "<<num<<" left"<<endl;
    }
    void setX(double X){this->x = X;}
    void setY(double Y){this->y = Y;}
    void setName1(string S1){this->name1 = S1;}
    void setName2(char* p){strcpy(name2 , p);}
    void set(float X, float Y,string S1,char * p){
        this->x=X; this->y=Y; this->name1=S1; strcpy(name2 , p);
    }
    int getX(){return x;}
    int getY(){return y;}
    string getName1(){return name1;}
    char* getName2(){return name2;}

    static int count(){return num;}
    void show(void);
};
int Point::num;
void Point::show(){
    cout<< "string name : "<< name1 << endl;
    cout<< "char name : "<< name2 <<endl;
	cout<< "x = "<< x << endl;
	cout<< "y = "<< y << endl;
    cout<<endl;
}
main(){
    cout<<"Oobject "<<Point::count()<<endl; 
    cout<<endl;

    Point aPoint;
    cout<<"Oobject "<<Point::count()<<endl; 
    aPoint.show();

    Point bPoint(3.0);
    cout<<"Oobject "<<Point::count()<<endl; 
    bPoint.show();

    Point cPoint(3.0,5.0);
    cout<<"Oobject "<<Point::count()<<endl; 
    cPoint.show();

    Point dPoint(3.0,5.0,"yourPoint");
    cout<<"Oobject "<<Point::count()<<endl; 
    dPoint.show();

    Point ePoint(3.0,5.0,"yourPoint",(char *)"mypoint");
    cout<<"Oobject "<<Point::count()<<endl; 
    ePoint.show();


    cout<<"String name = "<<bPoint.getName1()<<endl;
    cout<<"Char name = "<<bPoint.getName2()<<endl;
    cout<<"Point X = "<<bPoint.getX()<<endl;
    cout<<"Point Y = "<<bPoint.getY()<<endl;
    
}