#include <iostream>
using namespace std; 
class Box{
    int width;
    int height;
    int lenght;
    public:
        Box():width(0),height(0),lenght(0){}
        Box(int x):width(x),height(0),lenght(0){}
        Box(int x ,int y):width(x),height(y),lenght(0){}
        Box(int x, int y, int z):width(x),height(y),lenght(z){}
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
    aBox.show();
    
    Box bBox(2);
    bBox.show();

    Box cBox(3,4);
    cBox.show();

    Box dBox(5,6,7);
    dBox.show();
}