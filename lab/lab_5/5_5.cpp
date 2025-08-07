#include <iostream>
#include <cstring>
#include <cmath> //sqrt
using namespace std;

class Circle;
class Point{
    double x , y;
    char name1[20];
    string name2;
    static int num; 

    public:
        Point(){
            set1(0,0,"no_name");
            num++;
        }
        Point(float a, float b){
            setX(a);
            setY(b);
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
            cout<<"delete  = "<<name1<<endl;
        }
        //friend fuction
        friend bool inCircle(Circle&, Point&);
        friend int a(Circle c, Point p);

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
        void setX(float a){
            x = a;
        }
        void setY(float b){
            y = b;
        }
        void setNmae(char *n){
            strcpy(name1 ,n);
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
        float dot(Point&); //pass by reference
        Point midPoint(Point& a, Point& b); 
        void show();

        static int count(){
            return num;
        }
};
int Point :: num;

float Point :: dot(Point& a){
    //(x1 * x2) + (y1 * y2)
    float result = (x * a.x) + (y * a.y); 
    return result;
}

Point Point :: midPoint(Point& a, Point& b){
    //x = ((x1 + x2)/2)   y = ((y1 + y2)/2)
    x = ((a.x + b.x)/2);  y = ((a.y + b.y)/2); //x , y  ของ mid 
    return Point(x,y,"m");  //return แบบนี้ก็ได้เขียนแค่บรรทัดเดียว
    //return *this;  //this ของ mid

}
void Point ::  show(){
    cout<<"======== show ========"<<endl;
    cout<<"count Obj = "<<num<<endl;
    cout<<"Point name = "<<name1<<endl;
    cout<<"X  = "<<x<<endl;
    cout<<"Y  = "<<y<<endl; 
    cout<<"====================="<<endl;
}

//---------------------------------------//
class Circle{
    double radius;
    Point mid;
    char nameC[20];

    public:
        Circle():nameC("nomane"){
            radius = 0;
            mid.setX(0);
            mid.setY(0);
        }
        Circle(double r, Point& x , char *n){
            setCircle(r,x,n);
        }
        Circle(double r, Point& x){
            setRadius(r);
            setMid(x);
        }
        Circle(double r){
            setRadius(r);
        }

        ~Circle(){
            cout << "delete circle "<< nameC <<endl;
        }

        //friend fuction
        friend bool inCircle(Circle&, Point&);
        friend  int a(Circle c, Point p);

        //set
        void setCircle(double a, Point& b, char *n){
            radius = a;
            mid = b;
            strcpy(nameC , n);
        };
        void setRadius(double a){
            radius = a;
        }
        void setMid(Point& b){
            mid = b;
        }
        void setNameC(char *n){
            strcpy(nameC , n);
        }

        //get
        double getRadius(){
            return radius;
        }
        Point getMid(){
            return mid;
        }
        char* getnmaeC(){
            return nameC;
        }


        void showCircle(){
            cout<<"\n====== show Circl ======"<<endl;
            cout<<"Circle " << nameC << " mid point "<< endl;
            cout << "X = " << mid.getx() << " Y = " << mid.getY() << endl;
            cout << "radius = " << radius << endl;
        };
};

//friend fuction
bool inCircle(Circle& c , Point& p){
    //d = sqrt(((x2 - x1)^2) + ((y2 - y1)^2));
    double d;
    d = sqrt(((p.x - c.mid.x) *(p.x - c.mid.x))  +  
    ((p.y - c.mid.y) * (p.y - c.mid.y)));
    /*
    d = sqrt(((p.x - c.getMid().x) *(p.x - c.getMid().x))  +  
             ((p.y - c.getMid().y) * (p.y - c.getMid().y)));*/

    /*
    cout<< "\ndistance = " << d <<endl;
    cout<< "c.getMid().x = " << c.getMid().x <<endl;
    cout<< "getMid().y = " << c.getMid().y <<endl;
    cout<< "c.getRadius() = " << c.getRadius() <<endl;*/

    if(d <= c.getRadius()){
        return true;
    } else{
        return false;
    }
};

int a(Circle c, Point p){
    c.mid.x;
    p.x;
    p.y;
};


main(){
    //------ เทสแบบ 1 ------//
    cout<<"count Obj = "<<Point::count()<<endl;
    Point midA(0,0,"midA");
    midA.show();

    double r1;
    cout<<"input radius : ",cin>>r1;
    Circle a(r1,midA,"a");
    a.showCircle();

    //Point ที่จะตรวจ
    Point n(3,4,"n"); //อยู่ในวงกลง
    n.show();
    
    
    cout<<"\nradius = " << a.getRadius() <<endl;
    bool resultN;
    resultN = inCircle(a, n);
    if(resultN == 1){
        cout<<"Point "<<n.getName1()<<" is in the circle "<<endl;
    } else {
        cout<<"Point "<<n.getName1()<<" is out side the circle "<<endl;
    }
    cout<<"\n====================="<<endl;
    //----------------------//

    
    //------ Create mid point  ------//
    cout<<"\n======== Create mid point ========"<<endl;
    float i , j;
    char n1[20];
    cout<<"input name point : ",cin>>n1;//p
    cout<<"input x1 : ",cin>>i;//2
    cout<<"input y1 : ",cin>>j;//3
    Point p(i,j,n1);
    cout<<"Obj = "<<Point::count()<<endl;
    p.show();

    char n2[20] ;
    cout<<"input name point : ",cin>>n2;//p
    cout<<"input x2 : ",cin>>i;//4
    cout<<"input y2 : ",cin>>j;//2
    Point q(i,j,n2);
    cout<<"Obj = "<<Point::count()<<endl;
    cout<<"======== get ========"<<endl;
    cout<<"Point name = "<<q.getName2()<<endl;
    cout<<"X = "<<q.getx()<<endl;
    cout<<"Y = "<<q.getY()<<endl; 
    cout<<"====================="<<endl;


    cout<<"==== Before fuction midPoint ====" << endl;
    Point mid(0,0,"mid"); //เอาไว้เรียกใช้ midPoint
    cout<<"Obj = "<<Point::count()<<endl;
    mid.show();

    Point resultMid(0,0,"resultMid"); //เอาไว้ดูที่ return
    cout<<"Obj = "<<Point::count()<<endl;
    resultMid.show();

    resultMid  =  mid.midPoint(p,q);
    
    cout<<"==== Aftter fuction midPoint ====" << endl;
    cout<<"Ponit name  = " << mid.getName1() << endl; //ที่ออกมาแล้วชื่อไม่เปลี่ยนเพราะ &x ,&y name ไม่ได้ &
    cout<<"Obj = "<<Point::count()<<endl;
    cout<< "X = "<< mid.getx() << endl;
    cout<< "Y = "<< mid.getY() << endl;

    cout<<"\nPonit name  = " << resultMid.getName1() << endl; //m มีไร resultMid มีด้วย
    cout<<"Obj = "<<Point::count()<<endl;
    cout<< "X = "<< resultMid.getx() << endl;
    cout<< "Y = "<< resultMid.getY() << endl;
    
    
    cout<<"====================="<<endl;
    cout<<"\nMid point of "<<p.getName1()<<q.getName1()<<endl;
    cout<<"x = "<<resultMid.getx()<<" y = "<<resultMid.getY()<<endl;

    //-------------------------------//

    cout<<"\n======== Circle ========"<<endl;
    double r2;
    cout<<"input radius : ",cin>>r2;
    Circle b;
    //b.setCircle(r2,resultMid,"b");
    b.setRadius(r2);
    b.setMid(resultMid);
    b.setNameC("b");
    cout<<"\n======== get Circle ========"<<endl;
    cout<<"Circle "<< b.getnmaeC()<< " mid point "<< endl;
    cout << "X = " << resultMid.getx() << " Y = " << resultMid.getY() << endl;
    cout << "radius = " << b.getRadius() << endl;

    //Point ที่จะตรวจ
    Point v(8,10,"v"); //ไม่อยู่ในวงกลม
    cout<<"\n======== get ========"<<endl;
    cout<<"count Obj = "<<Point::count()<<endl;
    cout<<"Point name = "<<v.getName1()<<endl;
    cout<<"X  = "<<v.getx()<<endl;
    cout<<"Y  = "<<v.getY()<<endl; 
    cout<<"====================="<<endl;
 
    cout<<"\nradius = " << b.getRadius() <<endl;
    bool resultM;
    resultM = inCircle(b, v);
    if(resultM == 1){
        cout<<"Point "<<v.getName1()<<" is in the circle "<<endl;
    } else {
        cout<<"Point "<<v.getName1()<<" is out side the circle  "<<endl;
    }
    cout<<"\n====================="<<endl;


    cout<<"\n===== destructor ====="<<endl;
    return 0;
}

