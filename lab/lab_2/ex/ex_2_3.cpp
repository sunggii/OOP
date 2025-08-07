#include <iostream>
using namespace std;
class Box{
    private:
        int width;
        int height;
        int length;
    public:
        //overloding
        Box(){//default constructor
            set(0,0,0);
        }
        Box(int x){
            set(x,0,0);
        }
        Box(int x, int y){
            set(x,y,0);
        }
        Box(int x, int y, int z){
            set(x,y,z);
        }

        void set(int w,int h,int l){
            width = w;
            height = h;
            length = l;
        }
        int getWidth(){
        return width;
        }
        int getHeight(){
        return height;
        }
        int getLength(){
        return length;
        }

        void show();
        void addWidth(Box);
};

void Box::show(){
    cout<<"================"<<endl;
    cout<<"Width  = "<<width<<endl;
    cout<<"Height = "<<height<<endl;
    cout<<"Length = "<<length<<endl;
    
}

void Box::addWidth(Box b){
    int total;
            total = b.width + width;
            cout<<"b.width = "<<b.width<<endl;
            cout<<"width = "<<width<<endl;
            cout<<"total = "<<total<<endl;
}

main(){
    Box aBox;
    Box bBox(2), cBox(3,4,1);
    Box dBox(5,6,7);
    dBox.addWidth(cBox);
    cout<<"total cBox = "<<cBox.getHeight()*cBox.getLength()*cBox.getWidth()<<endl;
    return 0;
}