#include <iostream> //rectagle
using namespace std;

class Rectangle{
    static int count;
    int width;
    int height;
    public:
        Rectangle():width(0),height(0){count++;}
        Rectangle(int w):width(w),height(0){count++; }
        Rectangle(int w, int l):width(w),height(l){count++;}

        /*Rectangle(int a, int s){
            set(a,s);
        }*/

        void set(int w, int h){
            width = w;
            height = h;
        }

        int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }

        ~Rectangle(){
            count--;
            cout<<"count ~Obj = "<<count<<endl;
        }
        
        static int countObj(){
            return count;
        }
        void show();
        //process
        int area();
        int lenth();
};
int Rectangle::count;

void Rectangle::show(){
    cout<<"\n======== show ========"<<endl;
    cout<<"count Obj = "<<count<<endl;
    cout<<"Width  = "<<width<<endl;
    cout<<"Height = "<<height<<endl;
    cout<<"area   = "<<area()<<endl;
    cout<<"Lenth  = "<<lenth()<<endl;
}

int Rectangle::area(){
            return  width * height;
}

int Rectangle::lenth(){
             return 2 * (width + height);
}

main(){
    cout<<"count obj = "<<Rectangle::countObj()<<endl;

    Rectangle a;
    a.show();
    cout<<"count obj = "<<Rectangle::countObj()<<endl;
    cout<<"======== get ========"<<endl;
    cout<<"wintd  = "<<a.getWidth()<<endl;
    cout<<"Height = "<<a.getHeight()<<endl;
    cout<<"Area   = "<<a.area()<<endl;
    cout<<"Lenth  = "<<a.lenth()<<endl;

    {
        Rectangle b(5);
    b.show();
    cout<<"count obj = "<<Rectangle::countObj()<<endl;
    cout<<"======== get ========"<<endl;
    cout<<"wintd  = "<<b.getWidth()<<endl;
    cout<<"Height = "<<b.getHeight()<<endl;
    cout<<"Area   = "<<b.area()<<endl;
    cout<<"Lenth  = "<<b.lenth()<<endl;
    }

    Rectangle c(5,6);
    c.show();
    cout<<"count obj = "<<Rectangle::countObj()<<endl;
    cout<<"======== get ========"<<endl;
    cout<<"wintd  = "<<c.getWidth()<<endl;
    cout<<"Height = "<<c.getHeight()<<endl;
    cout<<"Area   = "<<c.area()<<endl;
    cout<<"Lenth  = "<<c.lenth()<<endl;
    

    cout<<"\n===== destructor ====="<<endl;
    return 0;
}