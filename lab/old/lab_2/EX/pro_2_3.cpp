#include <iostream>
using namespace std;
class Box{
    int width;
    int height;
    int lenght;
    public:
        Box(){set(0,0,0);} //defult constructor
        Box(int x){set(x,0,0);}
        Box(int x, int y){set(x,y,0);}
        Box(int x, int y, int z){set(x,y,z);}

    void set(int w, int h, int l){
        width = w; height = h; lenght =l;
    }
    int getWidth(){return width;}
    int getHeight(){return height;}
    int getLenght(){return lenght;}

        void addWidth(Box b){
            int total;
            total = width + b.width;
            cout<<"total = "<<total<<endl;
        }
        void show(void);
};
void Box::show(){
    cout<<"Width = "<<width<<endl;
    cout<<"Height = "<<height<<endl;
    cout<<"Lenght = "<<lenght<<endl;
    cout<<endl;
}

main(){
    Box aBox;
    Box bBox(2);
    Box cBox(3,4);
    Box dBox(5,6,7);
    dBox.addWidth(cBox);

    aBox.show();
    bBox.show();
    cBox.show();
    dBox.show();
}