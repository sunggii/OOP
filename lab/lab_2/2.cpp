#include <iostream>
#include <string.h>
using namespace std;

class Point{
    static int num; 
    float x , y;
    char name1[20];
    string name2;
    public:
        Point():x(0),y(0),name2("noname1_Point"){
            num++;
        }

        Point(float a):x(a),y(0),name2("noname2_Point"){
            num++;
            cout<<"\ncount Obj = "<<num<<endl;
            cout<<"Hi:"<<name2<<endl;
        }

        Point(float a, float b):x(a),y(b),name2("noname3_Point"){
            num++;
            cout<<"\ncount Obj = "<<num<<endl;
            cout<<"Hi:"<<name2<<endl;
        }

        Point(float a, float b,string n):x(a),y(b),name2(n){
            num++;
            cout<<"\ncount Obj = "<<num<<endl;
            cout<<"Hi:"<<name2<<endl;
        }
        /*
        Point(float a){
            num++;
            setX(a);
            cout<<"\ncount Obj = "<<num<<endl;
            cout<<"Hi:"<<name2<<endl;
        }*/

        void setAll(float setX, float setY,string n){
            x = setX;
            y = setY;
            name2 = n;
        }
        /*
        void setX(float a){
            x = a;
        }
         void setY(float b){
            y = b;
        }
        void setName1(char *n){
            strcpy(name1, n);
        }
        void setName2(string n){
            name2 = n;
        }*/
       
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

        void show2();
        void show1();

        ~Point(){
            num--;
            cout<<"count Obj = "<<num<<endl;
            //cout<<"bye bye : "<<name1<<endl;
        }
        static int count(){
            return num;
        }
};
int Point :: num;

void Point::show2(){
    cout<<"======== show ========"<<endl;
    cout<<"name : "<<name2<<endl;
    cout<<"Hi:"<<name2<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
    cout<<"count Obj = "<<num<<endl;
}
void Point::show1(){
    cout<<"======== show ========"<<endl;
    cout<<"name : "<<name1<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
}

main(){
    cout<<"count Obj = "<<Point::count()<<endl;
    Point a_Point;
    a_Point.show2();
    cout<<"======== get ========"<<endl;
    cout<<"name : "<<a_Point.getName2();cout<<endl;
    cout<<"X  = "<<a_Point.getx();cout<<endl;
    cout<<"Y  = "<<a_Point.getY();cout<<endl;

   Point b_Point(4);
   b_Point.show2();
   cout<<"======== get ========"<<endl;
   cout<<"name : "<<b_Point.getName2();cout<<endl;
   cout<<"X  = "<<b_Point.getx();cout<<endl;
   cout<<"Y  = "<<b_Point.getY();cout<<endl;

  
   Point c_Point(4,3.3);
   c_Point.show2();
   cout<<"======== get ========"<<endl;
   cout<<"name : "<<c_Point.getName2();cout<<endl;
   cout<<"X  = "<<c_Point.getx();cout<<endl;
   cout<<"Y  = "<<c_Point.getY();cout<<endl;

   Point d_Point(4,3.3,"d point");
   d_Point.show2();
   cout<<"======== get ========"<<endl;
   cout<<"name : "<<d_Point.getName2();cout<<endl;
   cout<<"X  = "<<d_Point.getx();cout<<endl;
   cout<<"Y  = "<<d_Point.getY();cout<<endl;

   //Point e_Point;
   //e_Point.show2();

   cout<<"\n===== destructor ====="<<endl;

    return 0;
}
