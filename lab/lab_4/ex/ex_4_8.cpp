#include <iostream>
using namespace std; //return แบบต่างๆ

int f1(){
    int x;
    x = 3;
    return x;
}

int* f2(){
    int *x  = new int;
    *x = 3;
    return x;
}

int& f3(){
    static int x;
    x = 3;
    return x;
}

/*
int& f3(){
    int x;
    x = 3;
    return x;
}*/

main(){
    int p;
    p = f1();
    cout<<"f1() = "<<p<<endl;

    int *y;
    y = f2();
    cout<<"f2() = "<<*y<<endl;
    delete y;

    int q;
    q = f3();
    cout<<"f3() = "<<q<<endl;
    return 0;
}