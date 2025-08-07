#include <iostream> //binary op
using namespace std;

class Tree{
    int a ,b ,c;

    public:
        Tree(){
            a = b = c = 0;
        }
        Tree(int i, int j , int k){
            a = i; b = j; c = k;
        }
        Tree operator +(Tree m){
            return Tree(a+m.a, b+m.b, c+m.c);
        }

        friend Tree operator - (Tree n, Tree m){
            return Tree(n.a-m.a, n.b-m.b, n.c-m.c);
        }
        void show(){
            cout << "a = " <<a <<" b = "<< b <<" c = " <<c <<endl;
        }
};

main(){
    Tree x(1,2,3) , y(4,5,6), z , m;
    //z = x + y;
    z = x.operator+(y);
    z.show();

    //z = y - x;
    z = operator-(y,x);
    z.show();

    //m = x + y + z;
    m = x.operator+(y).operator+(z);
    m.show();

}