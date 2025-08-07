#include <iostream>
using namespace std;
class Box{
    private:
        int width;
        int height;
        int lenght;
    public:
        Box(){
            width = 0;
            height = 0;
            lenght = 0;
            cout<<"My constructor"<<endl;
        }
        /*void set (int w, int h, int l){
            width = w; height = h; lenght = l;
        }*/
        int getWidth(){return width;}
        int getHeight(){return height;}
        int getLenght(){return lenght;}
        //void show(void);
}; 
main (){
    Box aBox;
    Box bBox , cBox;
} 