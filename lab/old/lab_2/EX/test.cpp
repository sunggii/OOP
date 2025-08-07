#include <iostream>
using namespace std;
class A {
   int x;
   public:
      A(){x=1;cout<<x<<endl;}
      A(int i){x=i;cout<<x<<endl;}
};

class B {
   int y;
   public:
      A n;
      B(){y=0;cout<<y<<endl;}
      B(int i){y=i;cout<<y<<endl;}
};

main(){
   A a;
   B b;
   A c(5);
   B d(10);
}