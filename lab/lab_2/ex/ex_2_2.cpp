#include <iostream>
using namespace std;
class Box{
    private:
        int width;
        int height;
        int length;
    public:
        Box(){//default constructor
            width  = 0;
            height = 0;
            length = 0;
            cout<<"My constuctor"<<endl;
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
};

main(){
    Box aBox;
    Box bBox, cBox;
    return 0;
}