#include <iostream>
#include <iomanip>
using namespace std;
class Box
{
private:
    int width;
    int height;
    int length;
public:
    void set(int w, int h,int l){
        width  = w;
        height  = h;
        length  = l;
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

void Box::show(){
    cout<<"================"<<endl;
    cout<<"Width  = "<<setw(2)<<width<<endl;
    cout<<"Height = "<<setw(2)<<height<<endl;
    cout<<"Length = "<<setw(2)<<length<<endl;
    
}

main(){
    Box myBox, yourBox;
    myBox.set(4,5,6);
    yourBox.set(8,6,10);

    myBox.show();
    yourBox.show();
    
    cout<<"================"<<endl;
    cout<<"myBox volume   = "<<myBox.getHeight()*myBox.getLength()*myBox.getWidth()<<endl;
    cout<<"yourBox volume = "<<yourBox.getHeight()*yourBox.getLength()*yourBox.getWidth()<<endl;
    return 0;
}


