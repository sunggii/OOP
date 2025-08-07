#include <iostream>
using namespace std;
class Rectangle {
    static int num;
    int width;
    int height;
    public:
    Rectangle(){set(0,0);num++;}
    Rectangle(int w, int h){set(w,h);num++;}

    ~Rectangle(){
        num--;
        cout<<num<<" left"<<endl;
    }

    void set(int w, int h){
        width = w; height = h;
    }
    int getWidth(){return width;}
    int getLenght(){return height;}

    void area(int w, int h){
        int area;
        area = width * height;
        //return area;
        cout<<"Area = "<<area<<endl;
    }

    void lenght(int w, int h){
        int lenght;
        lenght = 2*(width + height);
        //return lenght;
        cout<<"Lenght = "<<lenght<<endl;
    }
    static int count(){return num;}
    void show(void);
};
int Rectangle::num;
void Rectangle::show(){
    cout<<"width = "<<width<<" height = "<<height<<endl;
    //cout<<"Area = "<<area<<" Lenght = "<<lenght<<endl;
    cout<<endl;
}
main(){
    Rectangle aRectangle;
    cout<<"Oobject "<<Rectangle::count()<<endl;  
    aRectangle.show();
    
    Rectangle bRectangle(5,2);
    cout<<"Oobject "<<Rectangle::count()<<endl;  
    bRectangle.area(5,2);
    bRectangle.lenght(5,2);
    bRectangle.show();
    

    Rectangle cRectangle(10,2);
    cout<<"Oobject "<<Rectangle::count()<<endl; 
    cRectangle.area(10,2);
    cRectangle.lenght(10,2);
    cRectangle.show();
    
}//output ค่อนข้างมั่ว