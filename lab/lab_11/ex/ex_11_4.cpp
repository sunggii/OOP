#include <iostream>
using namespace std;

class A{
    int a, b;
    public:
        A(int i, int j){
            a=i; b=j;
        }
        /*bool operator==(A t){
            return ((a==t.a && b==t.b)? 1: 0);
        }*/
       friend bool operator>(A t, int k)
};
bool operator>(A t, int k){
    return (t.a == k);
}