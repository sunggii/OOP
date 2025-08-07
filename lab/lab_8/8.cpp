#include <iostream> //rectagle
using namespace std;

class Rectangle{
    static int count;
    double width;
    double height;
    public:
        Rectangle(){
            count++;
            width = height = 0;
        }
        Rectangle(int w){
            count++;
            setRectangle(w,0);
        }
        Rectangle(int w, int h){
            count++;
            setRectangle(w,h);
        }
        //--------- cast -----------
        //double to Rectangle
        Rectangle(double d){
            width  = d;
            height = d;
            //cout << "d = " << d <<endl;
        }
        //--------------------------
        ~Rectangle(){
            count--;
            cout<<"count ~Obj = "<<count<<endl;
        }

        //set
        void setRectangle(int w, int h){
            width = w;
            height = h;
        }

        //get
        double getWidth(){
            return width;
        }
        double getHeight(){
            return height;
        }

        //show
        void show(){
            cout<<"\n======== show ========"<<endl;
            cout<<"count Obj = "<<count<<endl;
            cout<<"Width  = "<<width<<endl;
            cout<<"Height = "<<height<<endl;
            cout<<"Lenth  = "<<lenth()<<endl;
            cout<<"area   = "<<area()<<endl;
            
        };
        //process
        double area(){
            return  width * height;
        }
        double lenth(){
            return 2 * (width + height);
        }

        //----------8--------------
        Rectangle operator++ (); //prefix height++
        Rectangle operator++ (int); //postfix  width++

        friend Rectangle operator-- (Rectangle& x); //prefix
        friend Rectangle operator-- (Rectangle& x , int);//postfix 

        bool operator < (Rectangle);
        bool operator <= (Rectangle);
        bool operator > (Rectangle);
        bool operator >= (Rectangle);

        int operator[] (int);
        double& operator() (); //ถ้ามาเรียกจะให้ cout ค่า r1 
        double& operator() (int);

        //--------- cast -----------
        //Rectangle to double
        operator double(){
            return area();
        }
        //-------------------------- 
        //-------------------------

        static int countObj(){
            return count;
        }
};
int Rectangle::count;

//prefix height++
Rectangle Rectangle::operator++ (){
    height++;
    return *this;
}
//postfix  width++
Rectangle Rectangle::operator++ (int){
    Rectangle a;
    a.width = getWidth();
    a.height = getHeight();

    width++;

    return a;
}

//prefix height--
Rectangle operator-- (Rectangle& r){
    //จะไม่ลบถ้าลบแล้วเหลือ 0
    if (r.height != 1)
    {
        r.height--;
    }
    return r;
}
//postfix width--
Rectangle operator-- (Rectangle& r , int){
    Rectangle b;
    b.width  = r.getWidth();
    b.height = r.getHeight();

    if (r.width != 1)
    {
        r.width--;
    }
    
    return b;
}

bool Rectangle::operator < (Rectangle r){
    return (area() < r.area()? true : false);
}
bool Rectangle::operator <= (Rectangle r){
    return (lenth() <= r.lenth()? true : false);
}
bool Rectangle::operator > (Rectangle r){
    return (getWidth() > r.getWidth()? true : false);
}
bool Rectangle::operator >= (Rectangle r){
    return (getHeight() >= r.getHeight()? true : false);
}

int Rectangle::operator[] (int i){
    switch (i)
    {
    case 1: return width;
    case 2: return height;
    case 3: return lenth();
    case 4: return area();
    default: return 0;
    }
}

double& Rectangle::operator() (){
    return width = 0.0;  
}
double& Rectangle::operator() (int i){
    //Rectangle r;
    //r.width = i;
    return width = i;
}


main(){
    Rectangle r1(4,5);
    r1.show();

    Rectangle r2;
    r2.show();

    Rectangle r3;
    r3.show();

    Rectangle r4;
    r4.show();

    Rectangle r5;
    r5.show();

    Rectangle r6(1,1);
    r6.show();

    cout<<"\n===== Test operator ++ =====" <<endl;
    r2 = ++r1;
    r1.show();
    cout <<"\nPrefix : r2" <<endl;
    cout << "width  = " <<r2.getWidth() <<endl;
    cout << "heigth = " <<r2.getHeight() <<endl;
    cout << "Lenth  = " <<r2.lenth() <<endl;
    cout << "heigth = " <<r2.area() <<endl;
    

    r2 = r1.operator++();
    r1.show();
    cout <<"\nPrefix : r2" <<endl;
    cout << "width  = " <<r2.getWidth() <<endl;
    cout << "heigth = " <<r2.getHeight() <<endl;
    cout << "Lenth  = " <<r2.lenth() <<endl;
    cout << "heigth = " <<r2.area() <<endl;

    r3 = r1++;
    r1.show();
    cout <<"\nPostfix : r3" <<endl;
    cout << "width  = " <<r3.getWidth() <<endl;
    cout << "heigth = " <<r3.getHeight() <<endl;
    cout << "Lenth  = " <<r3.lenth() <<endl;
    cout << "heigth = " <<r3.area() <<endl;
    

    r3 = r1.operator++(0);
    r1.show();
    cout <<"\nPostfix  : r3" <<endl;
    cout << "width  = " <<r3.getWidth() <<endl;
    cout << "heigth = " <<r3.getHeight() <<endl;
    cout << "Lenth  = " <<r3.lenth() <<endl;
    cout << "heigth = " <<r3.area() <<endl;


    cout<<"\n===== Test operator -- =====" <<endl;
    r4 = --r1;
    r1.show();
    cout <<"\nPrefix : r4" <<endl;
    cout << "width  = " <<r4.getWidth() <<endl;
    cout << "heigth = " <<r4.getHeight() <<endl;
    cout << "Lenth  = " <<r4.lenth() <<endl;
    cout << "heigth = " <<r4.area() <<endl;
    

    r4 = operator--(r6);
    r6.show();
    cout <<"\nPrefix : r4" <<endl;
    cout << "width  = " <<r4.getWidth() <<endl;
    cout << "heigth = " <<r4.getHeight() <<endl;
    cout << "Lenth  = " <<r4.lenth() <<endl;
    cout << "heigth = " <<r4.area() <<endl;


    r5 = r1--;
    r1.show();
    cout <<"\nPostfix : r5" <<endl;
    cout << "width  = " <<r5.getWidth() <<endl;
    cout << "heigth = " <<r5.getHeight() <<endl;
    cout << "Lenth  = " <<r5.lenth() <<endl;
    cout << "heigth = " <<r5.area() <<endl;
    
    r5 = operator--(r6,0);
    r6.show();
    cout <<"\nPostfix : r5" <<endl;
    cout << "width  = " <<r5.getWidth() <<endl;
    cout << "heigth = " <<r5.getHeight() <<endl;
    cout << "Lenth  = " <<r5.lenth() <<endl;
    cout << "heigth = " <<r5.area() <<endl;

    cout<<"\n===== Test operator < =====" <<endl;
    cout <<"Compare areas" <<endl;
    cout << "area of r1 = " <<r1.area() <<endl;
    cout << "area of r2 = " <<r2.area() <<endl;
    if (r1 < r2) //false
    {
        cout << "r1 < r2";
    } else
    {
        cout << "r2 < r1";
    }
    (r2.operator<(r1)? cout << "\nr2 < r1" : cout << "\nr1 < r2"); //true
    cout<<endl;

    cout<<"\n===== Test operator <= =====" <<endl;
    cout << "Compare Lenth" <<endl;
    cout << "lenth of r1 = " <<r1.lenth() <<endl;
    cout << "lenth of r3 = " <<r3.lenth() <<endl;
    cout << "lenth of r4 = " <<r4.lenth() <<endl;
    cout << "lenth of r5 = " <<r5.lenth() <<endl;
    if (r4 <= r5)
    {
        cout << "r4 <= r5";
    } else
    {
        cout << "not equal";
    }
    (r1.operator<=(r3)? cout << "\nr1 <= r3" : cout << "\nnot equal");
    (r3.operator<=(r1)? cout << "\nr1 <= r3" : cout << "\nnot equal");
    cout<<endl;

    cout<<"\n===== Test operator > =====" <<endl;
    cout << "Compare Width" <<endl;
    cout << "Width of r3 = " <<r3.getWidth() <<endl;
    cout << "Width of r6 = " <<r6.getWidth() <<endl;
    if (r3 > r6) //true
    {
        cout << "r3 > r6";
    } else
    {
        cout << "r6 > r3";
    }
    (r6.operator>(r3)? cout << "\nr6 > r3" : cout << "\nr3 > r6"); //false
    cout<<endl;

    cout<<"\n===== Test operator >= =====" <<endl;
    cout << "Compare Height" <<endl;
    cout << "Height of r1 = " <<r1.getHeight() <<endl;
    cout << "Height of r2 = " <<r2.getHeight() <<endl;
    cout << "Height of r4 = " <<r4.getHeight() <<endl;
    cout << "Height of r6 = " <<r6.getHeight() <<endl;

    if (r4 >= r5)
    {
        cout << "r4 >= r5";
    } else
    {
        cout << "not equal";
    }
    (r2.operator>=(r1)? cout << "\nr2 >= r1" : cout << "\nnot equal");
    (r1.operator>=(r2)? cout << "\nr2 >= r1" : cout << "\nnot equal");
    cout<<endl;

   cout<<"\n===== Test operator [] =====" <<endl;
   cout << "r1" <<endl;
   cout << "width  = "<< r1[1] <<endl;
   cout << "height = "<< r1[2] <<endl;
   cout << "lenth  = "<< r1[3] <<endl;
   cout << "area   = "<< r1[4] <<endl;

   cout << "\nr2" <<endl;
   cout << "width  = "<< r2[1] <<endl;
   cout << "height = "<< r2[2] <<endl;
   cout << "lenth  = "<< r2[3] <<endl;
   cout << "area   = "<< r2[4] <<endl;

   cout << "\nr3" <<endl;
   cout << "width  = "<< r3[1] <<endl;
   cout << "height = "<< r3[2] <<endl;
   cout << "lenth  = "<< r3[3] <<endl;
   cout << "area   = "<< r3[4] <<endl;

   cout << "\nr4" <<endl;
   cout << "width  = "<< r4[1] <<endl;
   cout << "height = "<< r4[2] <<endl;
   cout << "lenth  = "<< r4[3] <<endl;
   cout << "area   = "<< r4[4] <<endl;

   cout << "\nr5" <<endl;
   cout << "width  = "<< r5[1] <<endl;
   cout << "height = "<< r5[2] <<endl;
   cout << "lenth  = "<< r5[3] <<endl;
   cout << "area   = "<< r5[4] <<endl;

   cout << "\nr6" <<endl;
   cout << "width  = "<< r6[1] <<endl;
   cout << "height = "<< r6[2] <<endl;
   cout << "lenth  = "<< r6[3] <<endl;
   cout << "area   = "<< r6[4] <<endl;


   cout<<"\n===== Test operator () =====" <<endl;
   //------------------
   cout << "Befor operator()" <<endl;
   cout << "r5" <<endl;
   cout << "width  = "<< r5[1] <<endl;
   cout << "height = "<< r5[2] <<endl;
   cout << "lenth  = "<< r5[3] <<endl;
   cout << "area   = "<< r5[4] <<endl;

   cout << "\nr6" <<endl;
   cout << "width  = "<< r6[1] <<endl;
   cout << "height = "<< r6[2] <<endl;
   cout << "lenth  = "<< r6[3] <<endl;
   cout << "area   = "<< r6[4] <<endl;

   r5.operator()();
   r6();

   cout << "\nAftter operator()" <<endl;
   cout << "r5" <<endl;
   cout << "width  = "<< r5[1] <<endl;
   cout << "height = "<< r5[2] <<endl;
   cout << "lenth  = "<< r5[3] <<endl;
   cout << "area   = "<< r5[4] <<endl;

   cout << "\nr6" <<endl;
   cout << "width  = "<< r6[1] <<endl;
   cout << "height = "<< r6[2] <<endl;
   cout << "lenth  = "<< r6[3] <<endl;
   cout << "area   = "<< r6[4] <<endl;
   //------------------
 cout<<"\n=====================" <<endl;

   //------------------
   r5.operator()(1);
   cout << "\nr5" <<endl;
   cout << "width  = "<< r5[1] <<endl;
   cout << "height = "<< r5[2] <<endl;
   cout << "lenth  = "<< r5[3] <<endl;
   cout << "area   = "<< r5[4] <<endl;

   r4(5);
   cout << "\nr4" <<endl;
   cout << "width  = "<< r4[1] <<endl;
   cout << "height = "<< r4[2] <<endl;
   cout << "lenth  = "<< r4[3] <<endl;
   cout << "area   = "<< r4[4] <<endl;
   //------------------ 


    cout<<"\n===== Test cast =====" <<endl;
    cout<<"double to Rectangle :" <<endl;
    double d1 = 5.2 , d2 = 4.3, d3 ,d4;

    cout << "Befor cast" <<endl;
    cout << "r5" <<endl;
    cout << "width  = "<< r5[1] <<endl;
    cout << "height = "<< r5[2] <<endl;
    cout << "lenth  = "<< r5[3] <<endl;
    cout << "area   = "<< r5[4] <<endl;

    cout << "\nr6" <<endl;
    cout << "width  = "<< r6[1] <<endl;
    cout << "height = "<< r6[2] <<endl;
    cout << "lenth  = "<< r6[3] <<endl;
    cout << "area   = "<< r6[4] <<endl;

    r5 = d1;
    r6 = Rectangle(d2);

    cout << "\nAftter cast" <<endl;
    cout << "r5" <<endl;
    cout << "width  = "<< r5.getWidth() <<endl;
    cout << "height = "<< r5.getHeight() <<endl;
    cout << "lenth  = "<< r5.lenth() <<endl;
    cout << "area   = "<< r5.area() <<endl;

    cout << "\nr6" <<endl;
    cout << "width  = "<< r6.getWidth() <<endl;
    cout << "height = "<< r6.getHeight() <<endl;
    cout << "lenth  = "<< r6.lenth() <<endl;
    cout << "area   = "<< r6.area() <<endl;
   

   cout<<"\nRectangle to double :" <<endl;
   d3 = r5;
   cout << "d3 = " << d3 <<endl; //area r5

   d4 = double(r6);
   cout << "d4 = " << d4 <<endl; //area r6

   cout<<"\n===== destructor ====="<<endl;
    return 0;
}
