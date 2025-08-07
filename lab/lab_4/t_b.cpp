#include <iostream>
#include <cstring>
using namespace std;

class Point{
    float x , y;
    char name1[20];
    string name2;
    static int num; 

    public:
        Point(){
            set1(0,0,"no_name");
            num++;
        }
        Point(float a, float b, char *n1){
            set1(a,b,n1);
            num++;
        }
        Point(float a, float b, string n2){
            set2(a,b,n2);
            num++;
        }
         ~Point(){
            num--;
            cout<<"~Obj = "<<num<<endl;
        }

        //set
        void set1(float a, float b,char *n1){
            x = a;
            y = b;
            strcpy(name1, n1);
        }
        void set2(float a, float b,string n2){
            x = a;
            y = b;
            name2 = n2;
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

        //-------------------//
        float& dot(Point&); //return reference
        void midPoint(Point& a, Point& b); //pass by reference
        void show();

        static int count(){
            return num;
        }
};
int Point :: num;

float&  Point :: dot(Point& a){
    //(x1 * x2) + (y1 * y2)
    static float result = (x * a.x) + (y * a.y); //กรณี return& ตัวแปรต้องใส่เป็น static ด้วย
    return result;
}

void Point :: midPoint(Point& a, Point& b){
    //x = ((x1 + x2)/2)   y = ((y1 + y2)/2)
    x = ((a.x + b.x)/2);  y = ((a.y + b.y)/2);
}
void Point ::  show(){
    cout<<"======== show ========"<<endl;
    cout<<"Point name = "<<name1<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
    cout<<"====================="<<endl;
}

main(){
    cout<<"Obj = "<<Point::count()<<endl;

    float a , b;
    char n1[20];
    cout<<"input nmae point : ",cin>>n1;//p
    cout<<"input x1 : ",cin>>a;//2
    cout<<"input y1 : ",cin>>b;//3
    Point p(a,b,n1);
    cout<<"Obj = "<<Point::count()<<endl;
    p.show();

    string n2;
    cout<<"input nmae point : ",cin>>n2;//p
    cout<<"input x2 : ",cin>>a;//4
    cout<<"input y2 : ",cin>>b;//2
    Point q(a,b,n2);
    cout<<"Obj = "<<Point::count()<<endl;
    cout<<"======== get ========"<<endl;
    cout<<"Point name = "<<q.getName2()<<endl;
    cout<<"x2 = "<<q.getx()<<endl;
    cout<<"y2 = "<<q.getY()<<endl; 
    cout<<"====================="<<endl;


    Point mid(0,0,"mid");
    cout<<"Obj = "<<Point::count()<<endl;
    mid.show();
    

    mid.midPoint(p,q);
    cout<<"\nMid point of PQ"<<endl;
    cout<<"x = "<<mid.getx()<<" y = "<<mid.getY();
    float r = p.dot(q);
    cout<<"\nsacalar product =  "<<r<<endl;
    

    cout<<"\n===== destructor ====="<<endl;
    return 0;
}
