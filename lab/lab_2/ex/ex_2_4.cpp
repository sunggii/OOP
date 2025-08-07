#include <iostream>
using namespace std;
class Box{
    private:
        int width;
        int height;
        int length;
    public:
        //overloding
        //default constructor
        Box():width(0),height(0),length(0){
            cout<<"Width  = "<<width<<endl;
            cout<<"Height = "<<height<<endl;
            cout<<"Length = "<<length<<endl;
        }
        Box(int x):width(x),height(0),length(0){}
        Box(int x, int y):width(x),height(y),length(0){}
        Box(int x, int y, int z):width(x),height(y),length(z){}

        void show();
};

void Box::show(){
    cout<<"================"<<endl;
    cout<<"Width  = "<<width<<endl;
    cout<<"Height = "<<height<<endl;
    cout<<"Length = "<<length<<endl;
    
}

main(){
    Box aBox; //test deflaut
    
    Box bBox(2);
    bBox.show();

    Box cBox(2,3);
    cBox.show();

    Box dBox(2,3,4);
    dBox.show();
    return 0;
}