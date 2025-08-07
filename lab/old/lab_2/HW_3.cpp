#include <iostream>
#include <cmath> 
using namespace std;
class Rectangle {
    static int num;
    int width;
    int height;
    public:
    Rectangle(){set(0,0);num++;}
    Rectangle(int w){set(w,0);num++;}
    Rectangle(int w, int h){set(w,h);num++;}
    ~Rectangle(){num--;cout<<num<<" left"<<endl;}

    void set(int w,int h){width = w; height = h;}
    void setWidth(int w){width = w;}
    void setHeight(int h){width = h;}

    int getWidth(){return width;}
    int getHeight(){return height;}

     int area(){
        return width * height;
    }

    int lenght(){
        return 2*(width + height); //อีกวิธี
    }
    
    static int count(){return num;}
    void show(void);
};
int Rectangle::num;
void Rectangle::show(){
    cout<<"width = "<<width<<" height = "<<height<<endl;
    cout<<endl;
}
main(){
    cout<<"Oobject "<<Rectangle::count()<<endl; 
    cout<<endl;
    Rectangle aRectangle;
    cout<<"Oobject "<<Rectangle::count()<<endl;
    aRectangle.show();

    Rectangle bRectangle(2);
    cout<<"Oobject "<<Rectangle::count()<<endl;
    cout<<"Area = "<<bRectangle.area()<<endl;
    cout<<"Lenght = "<<bRectangle.lenght()<<endl;
    bRectangle.show();

    Rectangle cRectangle(2,5);
    cout<<"Oobject "<<Rectangle::count()<<endl;
    cout<<"Area = "<<cRectangle.area()<<endl;
    cout<<"Lenght = "<<cRectangle.lenght()<<endl;
    cRectangle.show();

    Rectangle dRectangle;
    cout<<"Oobject "<<Rectangle::count()<<endl;
    dRectangle.set(5,8);
    cout<<"bRectangle width = "<<dRectangle.getWidth()<<endl;
    cout<<"bRectangle height = "<<dRectangle.getHeight()<<endl;
    cout<<"Area = "<<dRectangle.area()<<endl;
    cout<<"Lenght = "<<dRectangle.lenght()<<endl;
    cout<<endl;

    Rectangle eRectangle;
    cout<<"Oobject "<<Rectangle::count()<<endl;
    eRectangle.setWidth(5);
    cout<<"bRectangle width = "<<eRectangle.getWidth()<<endl;
    cout<<"Area = "<<eRectangle.area()<<endl;
    cout<<"Lenght = "<<eRectangle.lenght()<<endl;
    cout<<endl;

    Rectangle fRectangle;
    cout<<"Oobject "<<Rectangle::count()<<endl;
    fRectangle.setHeight(5);
    cout<<"bRectangle height = "<<fRectangle.getHeight()<<endl;
    cout<<"Area = "<<fRectangle.area()<<endl;
    cout<<"Lenght = "<<fRectangle.lenght()<<endl;
    cout<<endl;
    

    cout<<"----------Test get -----------"<<endl;
    cout<<"bRectangle width = "<<bRectangle.getWidth()<<endl;
    cout<<"bRectangle height = "<<bRectangle.getHeight()<<endl;
    cout<<endl;

    


    

    

}