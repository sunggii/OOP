#include <iostream>
#include <string.h>
using namespace std;

class Point{
    float x , y;
    char name1[20];
    string name2;
    public:
        void setAll(float setX, float setY,char *n){
            x = setX;
            y = setY;
            strcpy(name1, n);
        }
        void setX(float a){
            x = a;
        }
        void setY(float b){
            y = b;
        }
        void setName1(char *n){
            strcpy(name1, n);
        }
        void setName2(string  n){
            name2 = n;
        }
        //get
        float getx(){
            return x;
        }
        float getY(){
            return y;
        }
        char* getName1(){
            return name1;
        }
        string getName2(){
            return name2;
        }

        void show2(); //name char
        void show1(); //name string
};

void Point::show2(){
    cout<<"\n======== show ========"<<endl;
    cout<<"name : "<<name2<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
}
void Point::show1(){
    cout<<"\n======== show ========"<<endl;
    cout<<"name : "<<name1<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
}

main(){
    Point noy,pookie,boo;

    noy.setAll(2,3,"noy Point");
    noy.show1();
    cout<<"======== get ========"<<endl;
    cout<<"name : "<<noy.getName1();cout<<endl;
    cout<<"X  = "<<noy.getx();cout<<endl;
    cout<<"Y  = "<<noy.getY();cout<<endl;
    
    //test get/set name2(string)
    pookie.setName2("pookei Point");
    pookie.setX(4);
    pookie.setY(8);
    pookie.show2();
    cout<<"======== get ========"<<endl;
    cout<<"name : "<<pookie.getName2();cout<<endl;
    cout<<"X  = "<<pookie.getx();cout<<endl;
    cout<<"Y  = "<<pookie.getY();cout<<endl;

    //test get/set name1(char)
    boo.setName1("boo Point");
    boo.setX(0.1);
    boo.setY(5.9);
    boo.show1();
    cout<<"======== get ========"<<endl;
    cout<<"name : "<<boo.getName1();cout<<endl;
    cout<<"X  = "<<boo.getx();cout<<endl;
    cout<<"Y  = "<<boo.getY();cout<<endl;

    
    return 0;
}
